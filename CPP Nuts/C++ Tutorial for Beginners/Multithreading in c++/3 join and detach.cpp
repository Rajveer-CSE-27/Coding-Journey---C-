#include <iostream>
#include <thread>
#include <chrono>
using namespace std;

/**
https://www.youtube.com/watch?v=q3-5sDe6lzg&list=PLk6CEY9XxSIAeK-EAh3hB4fgNvYkYmghp&index=3

Join and Detach in threads.

**/


// join()

/**
0. Once a thread is started we wait for this thread to finish by calling join() function on thread object.
    
    That is agar join kar diya to jab tak child thread execute  nahi ho jata to current thread join wali line se aage nhi badhega.

1. Double join will result into program termination.

    agar t.join() kiya hai and firse kahi t.join() kiya to program will terminate there itself giving RUN TIME ERROR.

2. If needed we should check thread is joinable before joining. ( using joinable() function)

    This is a boolean function which returns true if thread was not joined earlier. Else false
**/


void fun(int x) {
    
    while(x != 0) {
        cout << x << '\n';
        x--;
    }
    
    std::this_thread::sleep_for(chrono::seconds(5)); // here we are making this thread sleep for 5 seconds taaki isko complete hone me time lage
}


int main () {
    
    std::thread t(fun, 10);
    
    cout << "main() running after calling thread\n"; // ye wali line to turant execute ho jaegi cause thread abhi parallely chal raha hai
    
    t.join();
    cout << "main() running after thread executed\n"; // ye wali line thread execute hone ke baad hi execute hogi. Cause iske upar join hai. Hence main() ka thread aage nhi badhega jab tak t wala thread complete na ho jaye.
    
    t.join(); // Ye karne pe yhi program terminate ho jaega and will give run time error.
    
    if(t.joinable()) {
        t.join(); // hence agar joinable hai to hi join karega warna nahi
    }
    
     
    return 0;
}

// detach()

/**

0. This is used to detach newly created thread from the parent thread.
        
        agar parent thread ka execution independent rakhna hai from current thread to uss thread ko detach kardo.
        Then child thread and parent thread will execute parallely and it can also happen that parent thread ka execution pehle ho gaya and process terminate ho gai and still child thread would be running

1. Always check before detaching a thread that it is joinable otherwise we may end up double detaching and 
   double detach() will result into program termination.
        
        agar joinable hai to hi detach karo warna mat karo else RUN TIME ERROR.
   
   
2. If we have detached thread and main function is returning then the detached thread execution is suspended.
        
        That is agar parent thread ka execution khatam ho gaya hai to all the child threads would be destructed whether executing or not.
**/

void fun(int x) {
    
    while(x != 0) {
        cout << x << '\n';
        x--;
    }
    
    std::this_thread::sleep_for(chrono::seconds(5)); // here we are making this thread sleep for 5 seconds taaki isko complete hone me time lage
}

int main() {
    
    std::thread t(fun, 10);
    
    cout << "main before detach\n";
    t.detach();
    
    cout << "main after detach\n";
    
    
    // here there could be many output possible as thread runs parallel to main thread.
    // to baed upon execution times of both threads the output would be printed accordingly.
    
    // agar main thread chota hua to t complete hone se pehle hi main function terminate ho jaega and aisa bhi ho sakta hai t ke andar ka kuch print na bhi ho.
    
    // agar thread t ka time bohot chota hua to vo pehle output de sakta hai.
    
    if(t.joinable()) { // this is a good practice to detach a thread.
        t.detach(); 
    }
    
    
    
    return 0;
}

/**

har thread pe ya to join ya to detach to call karna hi chahiye jisse thread not joinable ban jaega.

Either join() or detach() should be called on thread object, otherwise during thread object's destructor it will terminate the program.
Because inside destructor it checks if thread is still joinable? if yes then it terminates the program.

Becuase destructor call karte time agar thread joinable raha to program wahi terminate ho jaega.
**/
