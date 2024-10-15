#include <iostream>
#include <thread>
#include <chrono>
#include <mutex>
using namespace std;

/**
https://www.youtube.com/watch?v=UgcyOBUaR6M&list=PLk6CEY9XxSIAeK-EAh3hB4fgNvYkYmghp&index=7

Mutex try_lock in c++

Few points to remember about the try_lock is as follows:

0. try_lock() Tries to lock the mutex and returns immediately.
            jaise lock() ke time pe agar kisi ne already lock kar rakha hota hai, to jisko lock karna hota hai vo BLOCK ho jaata hai.
            But try_lock() me agar kisi ne already lock kar rakha hota hai, to jisko lock karna hai vo aage badh jaata hai program. Vo kisi waiting me nahi jaata. Vo uss section ko skip kar deta hai jispe lock hai.
            
            
     On successful lock acquisition returns true otherwise returns false. 
     i.e ye ek boolean function hai, agar lock available hai to true return karta hai and lock kar deta hai,
                                     agar lock unavailable hai to false return karta hai bass.
     
     
1. If try_lock() is not able to lock mutex, then it doesn't get blocked that's why it is called non-blocking.

2. If try_lock is called again by the same thread which owns the mutex, the behaviour is undefined.

    that is agar try_lock kiya hua hai already and firse wahi thread try lock call karta hai to undefined behaviour.
    
   It is a dead lock situation with undefined behaviour. (if you want to be able to lock the same mutex by same thread more than one time the go for recursive_mutex)
**/


int cntr = 0;
std::mutex mtx;

void fun() {
    
    for(int i=0; i<10000; i++) {
        
        if(mtx.try_lock()) {
            ++cntr;
            mtx.unlock();
        }
    }
}

int main() {
    
    std::thread t1(fun);
    std::thread t2(fun);
    
    t1.join();
    t2.join();
    
    cout << cntr << '\n';
    
    
    return 0;
}

/**

in the above case both t1 and t2 runs parallely.
when t1 locks the CS and t2 wants to acquire lock, then mtx.try_lock() returns false and t2 continues it's execution.
and vice versa

Hence cntr ki final value alag alag aati rahegi.

but if CS was like
    mtx.lock();
    cntr++;
    mtx.unlock();
    
then when one thread is in CS and other wants to enter CS, the other goes in blocking state.
and vice versa.

Hence cnts ki final value is case me humesha 20000 hogi at end.

**/
