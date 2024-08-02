// || जय जय जय बजरंग बली ||

#include <bits/stdc++.h>
using namespace std;
#define ll long long

// line 1
void * operator new(size_t size) { 
	
	cout << "overloaded new operator size: " << size << '\n';
	void *p = malloc(size);
	
	return p;
}

// line 2
void operator delete(void *p) {
	cout << "overloaded delete operator\n";
	free(p);
}

// line 3
void * operator new(size_t size, int val) {
	cout << "with value overloaded new operator size: " << size << '\n';
	void *p = malloc(size);
	
	// because void pointer cannot store any value, hence modifying it to store integer value 
	if(p != nullptr) {
		*static_cast<int*>(p) = val; // with this line it will cast the pointer to store integer values
		// still p will be of type void
		
	}
	return p;
}

int main() {
	
	int *x = new int; // this will call function at line 1
	delete x; // this will call function at line 2
	
	int *y = new(69) int;// this will call function at line 3
	// NOTE :: jo value doge vo new(yaha do).
	delete y;// this will call function at line 2
	
	return 0;
}
