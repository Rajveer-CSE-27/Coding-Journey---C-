#include <bits/stdc++.h>
using namespace std;
#define ll long long

/**
Logger system desing

  -> Use chain of responsibility desgin pattern
**/
 
 
enum LogLevel {
  INFO = 1,
  DEBUG,
  ERROR
};
 
class LogProcessor {
// abstract class
  
public:
    
  // it is not necessary to declare a variable const in abstract class. Without const will also work fine
  
  LogProcessor* next;
  
  // we will input the next in constructor itself
  LogProcessor(LogProcessor* next = nullptr) {
    this->next = next;
  }
  
  virtual void log(int logLevel, string message) = 0;
  
};

class InfoLogProcessor : public LogProcessor {
  
public:
  
  InfoLogProcessor(LogProcessor* next = nullptr) : LogProcessor(next) {}
  // agar humne InfoLogProcessor ka object banaya to uske constructor me hum next dedenge pehle se hi
  
  void log(int logLevel, string message) {
    
    if(logLevel == INFO) { // that is current log is of INFO type then
      cout << "INFO LOG : " << message << '\n';
      
    } else {
      
        next->log(logLevel, message);
        // warna next jo humne iske constructor me liya tha usme log call karke dekhlo
      
    }
    
  }
  
};

class DebugLogProcessor : public LogProcessor {
  
public:
  
  DebugLogProcessor(LogProcessor* next = nullptr) : LogProcessor(next) {}
  
  void log(int logLevel, string message) {
    
    if(logLevel == DEBUG) { // that is current log is of INFO type then
      cout << "DEBUG LOG : " << message << '\n';
      
    } else {
      
        next->log(logLevel, message);
        // warna next jo humne iske constructor me liya tha usme log call karke dekhlo
      
    }
    
  }
  
  
};

class ErrorLogProcessor : public LogProcessor {
  
public:
  
  ErrorLogProcessor(LogProcessor* next = nullptr) : LogProcessor(next) {}
  
  void log(int logLevel, string message) {
    
    if(logLevel == ERROR) { // that is current log is of INFO type then
      cout << "ERROR LOG : " << message << '\n';
      
    } else {
      
        next->log(logLevel, message);
        // warna next jo humne iske constructor me liya tha usme log call karke dekhlo
      
    }
    
  }
  
};

 
 
int main() {
  
  
  
  // Actual chain of responsibility should be defined in MAIN.
  LogProcessor* obj = new InfoLogProcessor(new DebugLogProcessor(new ErrorLogProcessor()));
  // because humne upar LogProcessor* next = nullptr liya hai to uski default value NULL hogi
  
  obj->log(ERROR, "exception hota rehta hai");
  /** Explanation :: 
        
        sabse pehle InfoLogProcessor me jaega
        uska next already DebugLogProcessor ka object hoga.
        
        uske log function ko call karega
        and logLevel != ERROR 
        hence next me chala jaega
        
        
        then DebugLogProcessor me jaega
        and so on....
  **/
  
  
  
  
  
  obj->log(DEBUG, "jaldi se dekho kya hai");
  obj->log(INFO, "just for information");
  
  return 0;
}


