// bounded_blocking_queue.hpp
#pragma once
#include <condition_variable>
#include <mutex>
#include <vector>

template <typename T>
class BoundedBlockingQueue {
public:
  explicit BoundedBlockingQueue(size_t cap) : cap_(cap) { buf_.reserve(cap); }

  void push(T v) {
    std::unique_lock<std::mutex> lk(m_);
    not_full_.wait(lk, [&]{ return buf_.size() < cap_; });
    buf_.push_back(std::move(v));
    not_empty_.notify_one();
  }

  T pop() {
    std::unique_lock<std::mutex> lk(m_);
    not_empty_.wait(lk, [&]{ return !buf_.empty(); });
    T v = std::move(buf_.front());
    buf_.erase(buf_.begin());
    not_full_.notify_one();
    return v;
  }

private:
  size_t cap_;
  std::vector<T> buf_;
  std::mutex m_;
  std::condition_variable not_full_, not_empty_;
};
