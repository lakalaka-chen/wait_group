#pragma once 

#include <mutex>
#include <condition_variable>

namespace wait_group {
    
class WaitGroup {
public:
    explicit WaitGroup(int count);
    WaitGroup(const WaitGroup&) = delete;
    WaitGroup & operator=(const WaitGroup&) = delete;

    void Add(int delta);
    void Done();
    void Wait();

private:
    int count_;
    std::mutex mu_;
    std::condition_variable cv_;

};

} // namespace wait_group

