#include <iostream>
#include <thread>
#include <chrono>
#include <mutex>
using namespace std;

/**
https://www.youtube.com/watch?v=r-PDHNWYdes&list=PLk6CEY9XxSIAeK-EAh3hB4fgNvYkYmghp&index=6

std::try_lock()

Earlier we studied mutex try_lock i.e m.try_lock();
Vo sirf single mutex ke liye kaam aata hai

0. std::try_lock() tries to lock all the mutex/lockable things passed in it one by one in given order.
    SYNTAX :: std::try_lock(m1,m2,m3,.....mn);
    

1. On success this function returns -1. i.e if it is able to lock all the items inside it then it would return -1.
    otherwise it will return 0-based mutex index number which it could not lock.
    
    ex. agar m3 nahi lock kar payi to first it will unlock all previous locked things/mutexes and then it will return value = 2.
    
    
2. If it fails to lock any of the mutex then it will release all the mutex it locked before.

3. If a call to try_lock results in an exception, unlock is called for any locked objects before re-throwing.
**/

/**

In the below example we have 3 threads.
t1 is trying to increment value of variable x. For 5 iterations.
t2 is trying to increment value of variable y. For 5 iterations.
t3 is trying to increment value of variable xPlusy with values of x and y and make x=0 and y=0. For 5 iterations.


t3 would only be able to execute when both t1 and t2 not in their CS, i.e m1 and m2 are not locked.


**/


std::mutex m1, m2;

int X=0, Y=0;

void doSomeWorkForSeconds (int seconds) { std:: this_thread:: sleep_for(std:: chrono:: seconds (seconds) ); }

void increment(int& var, std::mutex& m, const char* c) { // const char* jo hai vo string ko pass karne ka ek aur tareeka hai
    
    for(int i=0; i<5; i++) {
        
        m.lock(); // normal lock hence BLOCKING behaviour
        var++;
        cout << c << var << '\n';
        m.unlock();
        doSomeWorkForSeconds(1);
    }
}

void consumeXY() {
    
    int iteration = 5;
    
    int xPlusy = 0;
    
    while(1) {// yaha for(int i=0; i<5; i++) nahi lagaya becuase hume compulsory 5 iterations of addition chahiye.
        
        int lockResult = std::try_lock(m1,m2);
        
        if(lockResult == -1) { // successfully locked both mutexes
            
            if(X != 0 and Y != 0) {
                iteration--;
                xPlusy += X + Y;
                
                X = 0;
                Y = 0;
                
                cout << "X Plus Y : " << xPlusy << '\n'; 
            }
            
            // we need to explicitly unlock the locked mutexes ***********
            m1.unlock();
            m2.unlock();
            
            if(iteration == 0) {
                break;
            }
        }
    }
}

int main() {
    
    std::thread t1(increment, std::ref(X), std::ref(m1), "X "); // std::ref() reference pass karne ka ek aur tareeka hai
    std::thread t2(increment, std::ref(Y), std::ref(m2), "Y ");
    
    std::thread t3(consumeXY);
    
    t1.join();
    t2.join();
    t3.join();
    
    return 0;
}
