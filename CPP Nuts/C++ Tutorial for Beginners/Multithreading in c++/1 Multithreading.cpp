
/**
https://www.youtube.com/watch?v=TPVH_coGAQs&list=PLk6CEY9XxSIAeK-EAh3hB4fgNvYkYmghp&index=1



-> What do you understand by thread ?

0. In every application there is a default thread which is main(), in side this we create other threads.

1. A thread is also known as lightweight process. Idea is achieve parallelism {that is threads run parallely hence achive parallelism by dividing our program into multiple threads} by dividing a process into multiple threads. 
   For example:
   (a) The browser has multiple tabs that can be different threads. 
   (b) MS Word must be using multiple threads, one thread to format the text {that is jo aapne type kara hai usko format me laana ex. design, fonts, etc}, another thread to process inputs (spell checker) {i.e jo aapne likha hai uss word ko inbuilt dictionary se compare karke spell check karna}
   (c) Visual Studio code editor would be using threading for auto completing the code.
   
   Ye sab threads independently work karte hai.
   
2. In C++ threads will work for versions >= C++11

Hence to compile any cpp file having threads use : g++ -std=c++11 -pthread
   
-> WAYS TO CREATE THREADS IN C++11

1. Function Pointers
2. Lambda Functions
3. Functors
4. Member Functions
5. Static Member functions

We'll learn all these types one by one.
**/


// Program 
// Find the addition of all odd number from 1 to 1900000000 and all even number from 1 to 1900000000


/**
Explaination :: 
    
    Our main function is the main thread that starts running when we run the program.
    
    If we do not use thread then program flow will be :: (uncomment from WITHOUT THREAD LINE)
            main() -> findOddSm() -> findEvenSm() -> return 0
            
            Let total time = 4 seconds.
    
    If we use threads that we created here : (uncomment from WITH THREAD LINE)
    
        here we created 2 threads one for each function.
        We passed function pointers along with parameters of that function to create thread -> std::thread t1(findOddSm, first, last, &(oddSm));
        
        Now we need to join the 2 created threads with the main thread. Why do we do this ? 
                    We join each created thread with main or parent thread so that if execution of parent thread completes then it waits for the child thread to complete the excution.
                    If we do not join then it is possible that parent thread completes execution and stops running even though child thread is still executing.
                    
                    When we do t1.join() we join thread t1 with main thread of program.
                    Hence when program flow reached t1.join() line it checks whether t1 has completed executing or not. If not then program waits for it to complete and then only move forward.
        
        Now program flow :: 
            main() -> t1 starts   -> t1 ends    ->return 0
                    -> t2 starts   -> t2 ends
                    
            when program reaches t1 it starts executing t1 independently and moves forward.
            Then it reaches t2 it starts executing t2 independently and moves forward.
            
            when it reaches t1.join it waits for t1 to finish. After that it moves forward.
            when it reaches t2.join it waits for t2 to finish. After that it moves forward.
            
        
            Total time = 2 seconds.
            
            Becuase our threads worked independently.
            
**/

#include <iostream>
#include <thread>
#include <chrono>
#include <algorithm>
using namespace std;
using namespace std::chrono;

typedef long long int ull;

void findOddSm(ull first, ull last, ull& oddSm) {
    
    for(ull i = first; i<=last; i++) {
        if(i&1) {
            oddSm += i;
        }
    }
}

void findEvenSm(ull first, ull last, ull& evenSm) {
    
    for(ull i = first; i<=last; i++) {
        if(!(i&1)) {
            evenSm += i;
        }
    }
}


int main() {
    
    ull first = 0, last = 1900000000;
    
    ull oddSm = 0;
    ull evenSm = 0;
    
    auto startTime = high_resolution_clock::now();
    
    // WITH THREAD
    // std::thread t1(findOddSm, first, last, &(oddSm));
    // std::thread t2(findEvenSm, first, last, &(evenSm));
    
    // t1.join();
    // t2.join();
    
    
    // WITHOUT THREAD
    // findOddSm(first, last, oddSm);
    // findEvenSm(first, last, evenSm);
    
    auto stopTime = high_resolution_clock::now(); 
    
    cout << oddSm << " " << evenSm << '\n';
    
    auto duration = duration_cast<microseconds>(stopTime - startTime);
    cout << "Sec: " << duration.count()/1000000 << '\n';
    
    
    return 0;
}
