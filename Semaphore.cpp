#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include<vector>

using namespace std;

class CountingSemaphore {
public:
    CountingSemaphore(int count) : count_(count) {}

    void acquire() {
        unique_lock<mutex> lock(mutex_);
        while (count_ <= 0) {
            condition_.wait(lock);
        }
        count_--;
    }

    void release() {
        unique_lock<mutex> lock(mutex_);
        count_++;
        condition_.notify_one();
    }

private:
    int count_;
    mutex mutex_;
    condition_variable condition_;
};

int main() {
    CountingSemaphore semaphore(4); // Create a CountingSemaphore with an initial count of 4

    vector<thread> threads;
    int prc;
    cout<<"Process :";
    cin>>prc;
    for (int i = 0; i < prc; ++i) {
        threads.emplace_back([&semaphore, i] {
            semaphore.acquire(); // Acquire the semaphore
            cout << "Thread " << i << " acquired the semaphore\n";
            this_thread::sleep_for(chrono::seconds(1)); // Simulate work
            semaphore.release(); // Release the semaphore
            cout << "Thread " << i << " released the semaphore\n";
        });
    }

    for (auto& t : threads) {
        t.join();
    }

    return 0;
}
