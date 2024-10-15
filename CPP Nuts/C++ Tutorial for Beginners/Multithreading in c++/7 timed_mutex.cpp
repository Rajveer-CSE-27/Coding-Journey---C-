#include <iostream>
#include <thread>
#include <chrono>
#include <mutex>
using namespace std;

/**
https://www.youtube.com/watch?v=x0sHzDyETUc&list=PLk6CEY9XxSIAeK-EAh3hB4fgNvYkYmghp&index=7

Timed mutex.

We have learned Mutex, Race Condition, Critical Section till now.

And few points to remember about timed mutex is as follows:

0. std::timed_mutex is blocked till timeout_time or the lock is acquired and returns true if success 
   otherwise false.
   
   That is when a thread comes to acquire a lock and if it is already locked, then thread waits for a specified amount of time.
   That is thread goes into BLOCKING state for a specified amount of time.
   Till then if the other thread unlocks the  lock, then the BLOCKED thread acquires it.
   If till timeout the unlock do not occur then, the BLOCKED thread continues it's further execution and does not move further.
   
   
1. Member Function of timed lock
   a. lock 
   b. try_lock
   c. try_lock_for    ---\ These two functions makes it different from mutex. Rest all are same
   d. try_lock_until  ---/ 
   e. unlock
   
   
try_lock_for();
Waits until specified timeout_duration has elapsed or the lock is acquired, whichever comes first.
On successful lock acquisition returns true, otherwise returns false.

try_lock_until();

Waits until a specific time has reached in global clock.
If till that time the unlock occurs then lock acquisition successfull and returns true. Else returns false.
**/

int cnt = 0;
std::timed_mutex m;

void increment(int i) {
    
    if(m.try_lock_for(std::chrono::seconds(1))) { // here if m is already locked then the thread would wait for 1 second. If till that m unlocks, then thread acquisition would occur else the thread would continue it's execution
        cnt++;
        
        std::this_thread::sleep_for (std::chrono::seconds(2));
        cout << "Thread " << i << " entered\n";
        
        m.unlock();
    } else {
        cout << "Thread " << i << " Couldn't enter\n";
    }
    
    
    // Example of try_lock_until
    auto currTime = std::chrono::steady_clock::now();
    
    if(m.try_lock_until(currTime + std::chrono::seconds(1))) { // here if m is already locked then the thread would wait for 1 more second from current time. If till that m unlocks, then thread acquisition would occur else the thread would continue it's execution
        cnt++;
        
        std::this_thread::sleep_for (std::chrono::seconds(2));
        cout << "Thread " << i << " entered\n";
        
        m.unlock();
    } else {
        cout << "Thread " << i << " Couldn't enter\n";
    }
    
}

int main() {
    
    std::thread t1(increment, 1);
    std::thread t2(increment, 2);
    
    t1.join();
    t2.join();
    
    cout << cnt << '\n';
    
    
    return 0;
}
