#include <bits/stdc++.h>
using namespace std;
#define ll long long

/**

Proxy Design Pattern
**/
 
class DatabaseTable {
  // abstract class
  
public:
  
  virtual void createEntry(string client) = 0;
  virtual void deleteEntry(string client) = 0;
  virtual void read(string client) = 0;
  
};

class ConcreteDatabaseTable : public DatabaseTable {
  
public:
  
  void createEntry(string client) {
    
    cout << "Created an entry in database successfully\n";
    
  }
  
  void deleteEntry(string client) {
    
    cout << "Erased an entry from database successfully\n";
  }
  
  void read(string client) {
    
    cout << "Read an entry successfully\n";
    
  }
  
};

class ProxyDatabaseTable : public DatabaseTable {
  
public:
  
  ConcreteDatabaseTable cdt;
  
  void createEntry(string client) {
    
    
    if(client == "User") {
      cout << "Access Denied\n";
    } else {
      cdt.createEntry(client);
    }
    
  }
  
  void deleteEntry(string client) {
    
    
    if(client == "User") {
      cout << "Access Denied\n";
    } else {
      cdt.deleteEntry(client);
    }
    
  }
  
  void read(string client) {
    cdt.read(client);
  }
  
};

 
int main() {
  
  
  ProxyDatabaseTable pdt;
  
  pdt.createEntry("User");
  pdt.createEntry("Admin");
  pdt.read("User");
  pdt.read("Admin");
  
  
  
  return 0;
}


