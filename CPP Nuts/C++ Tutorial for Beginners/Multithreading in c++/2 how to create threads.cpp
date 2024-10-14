#include <iostream>
#include <thread>
using namespace std;

/**
https://www.youtube.com/watch?v=hCvc9y39RDw&list=PLk6CEY9XxSIAeK-EAh3hB4fgNvYkYmghp&index=3

There are 5 different types we can create threads in c++11

NOTE :: If we create multiple threads at the same time it doesn't guarantee which one will start first.
        Explained in the first example
**/

// TYPE 1 :: Using Function Pointer 

void fun(int x) {
    while(x != 0) {
        cout << x << '\n';
        x--;
    }
}

int main() {
    
    std::thread t1(fun, 11); // by passing the function pointer {name of function, parameters} we can create a thread
    std::thread t2(fun, 13);
    
    // here thread t1 and t2 are created at same time hence it doesn't guarantee which one will start first.
    
    t1.join();
    t2.join();
    
    return 0;
}

// TYPE 2 :: Using lambda function

int main() {
    
    // we can directly inject the variable having lambda at thread creation time
    
    auto fun = [](int x) {
        while(x != 0) {
            cout << x << '\n';
            x--;
        }
    };
    
    std::thread t(fun, 10);
    t.join();
    
    
    // instead of writing lambda variable (fun) we can directly write lambda itself
    
    std::thread t([](int x) {
        while(x != 0) {
            cout << x << '\n';
            x--;
        }
    }, 10);
    t.join();
    // this is also valid
    
    return 0;
}

// TYPE 3 :: Using Functor (also called Function object)

class Base {
public:
    
    void operator ()(int x) {
        while(x != 0) {
            cout << x << '\n';
            x--;
        } 
    }
    // here we are overloading () operator inside a class is called functor.
};

int main() {
    
    
    std::thread t((Base()), 10);
    t.join();
    
    return 0;
}


// TYPE 4 :: Non-static member function

class Base {
public:
    
    void fun(int x) { // this is a non-static member function of a class
        while(x != 0) {
            cout << x << '\n';
            x--;
        }
    }
};

int main() {
    
    // calling a non-static function requires object of that class
    Base b;
    
    std::thread t(&Base::fun, &b, 10); // syntax :: t(reference_of_class::reference_of_non_static_function, reference of object on which function needs to be called, parameters);
    t.join();
    
    return 0;
}

// TYPE 5 :: Static member function

// only no need to pass object here. Because static member function do not need any object to run

class Base {
public:
    
    static void fun(int x) { // this is a static member function of a class
        while(x != 0) {
            cout << x << '\n';
            x--;
        }
    }
};

int main() {
    
    // calling a static function do not require object of that class
    
    
    std::thread t(&Base::fun, 10); // syntax :: t(reference_of_class::reference_of_non_static_function, parameters);
    t.join();
    
    return 0;
}
