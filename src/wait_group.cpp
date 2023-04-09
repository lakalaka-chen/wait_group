#include "wait_group.h" 

namespace wait_group {


WaitGroup::WaitGroup(int count): count_(count) {

}

void WaitGroup::Add(int delta) {
    std::unique_lock<std::mutex> lock(mu_);
    count_ += delta; 
    if (count_ <= 0) {
        cv_.notify_all();
    }
}

void WaitGroup::Done() {
    Add(-1);
}

void WaitGroup::Wait() {
    std::unique_lock<std::mutex> lock(mu_);
    cv_.wait(lock, [this] { return count_ <= 0; });
}

}