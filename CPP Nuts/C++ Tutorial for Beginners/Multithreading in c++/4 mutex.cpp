#include <iostream>
#include <thread>
#include <chrono>
#include <mutex>
using namespace std;

/**
https://www.youtube.com/watch?v=eZ8yKZo-PGw&list=PLk6CEY9XxSIAeK-EAh3hB4fgNvYkYmghp&index=5

Mutex in c++.
#include <mutex>

Mutex stands for Mutual exclusion.

RACE CONDITION:
0. Race condition is a situation where two or more threads/process happens to change a COMMON data at the same time.
1. If there is a race condition then we have to protect it and the protected section is  called critical section/region.

Example :: 
    Let two threads want to access a variable x.
    And both want to perform x += 1
    
    Now sequence of operation would be :: 
            LOAD variable x
            INCREEMENT it
            STORE it in memory.
            
    Each thread follows these 3 operations to change the value of x.
    
    Let both threads start at same time and initially x = 0.
    
        Thread t1, t2
        
        t1.LOAD will load 0
        t2.LOAD will load 0
        
        t1.INCREEMENT will lead to value = 1 in local memory of t1
        t2.INCREEMENT will lead to value = 1 in local memory of t2
        
        t1.STORE will give value 1 to x
        t2.STORE will give value 1 to x
        
        Final value of x = 1 but it should be 2.
        This is due to parallelism of threads and race condition. i.e both want to access the critical section at same time.

MUTEX:
0. Mutex is used to avoid race condition.
1. We use lock() , unlock() on mutex to avoid race condition.

Mutex helps in executing the CS part mutually exclusively.
i.e if one thread/process is inside CS then no other thread/process can enter that CS and need to wait till the current thread exits the CS part.

Note :: Race condition only occurs when multiple threads wants to update/change COMMON data.

NOTE :: When multiple threads/processes are executing paralllely, it would reach the CPU with a slight time difference always, because CPU could run 1 thing at a time.

**/


/**

Here if t1 gets the lock and makes m = 1.
Now if t2 comes to execute the CS then it tries to get lock, but m is already 1 this means lock is acquired by another thread (here t1).

So t2 goes into BLOCKING STATE, and can only progress further when it gets lock that is t1 comes out of CS.
When t1 comes out of CS, it unlocks the CS and makes m = 0.
t2 who was waiting would now acquire lock and make m = 1 and execute it's CS.
When t2 comes out of CS, it unlocks the CS and makes m = 0.

**/

int totalMoney = 0;
std::mutex m; // initializing a mutex

int addMoney() {
    
    m.lock(); // giving the lock to current thread. Hence making CS locked and m = 1.
    ++totalMoney;
    m.unlock(); // taking the lock from current thread. Hence making CS free and m = 0.
}

int main() {
    
    std::thread t1(addMoney);
    std::thread t2(addMoney);
    
    t1.join();
    t2.join();
    
    cout << totalMoney << '\n';
    
    return 0;
}
