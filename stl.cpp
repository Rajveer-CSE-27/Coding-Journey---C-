//......................PAIRS..............................................................................

void explainPairs() {
	
	// pair<dataType, dataType> pr;
	pair<int,int> pr = {1,3};
	cout << p.first << " " << p.second;
	
	//Nested pairs
	pair<int , pair<int, int>> p2 = {1,{2,3}};
	int firstfirst = p2.first;
	int secondfirst = p2.second.first
	int secondsecond = p2.second.second
	
	// Array of pairs
	pair<int , int> arr[] = {{1,2} , {2,3} , {3,4}};
	cout << arr[0].first;
	
}

//....................VECTORS.............................................................................

void explainVector() {
	
	vector <int> vc;
	
	// add at end
	vc.push_back(1);
	vc.emplace_back(2);  // slightlt faster
	
	vector<int> vc2(5); // empty vector of size 5
	
	vector<int> vc3(10,2); // vector of size 10 with all values = 2
	
	vector<int> vc4(vc3); // copy of vector into a new vector
	
	// access the elements
	cout << vc[0] << " or " << vc.at(0);
	
	// iterator in vector
	
	for(vector<int>::iterator it = vc.begin(); it != vc.end(); it++) {
		cout << *(it) << " ";
	}
	
	for(auto it = vc.begin(); it != vc.end(); it++) {
		cout << *(it) << " ";
	}
	
	//for each loop
	for(auto it : v) {
		cout << it << " ";
	}
	
	for(int i=0; i<vc.size(); i++) {
		cout << vc[0] <<" ";
	}
	
	// more iterators
	vector<int>::iterator it = vc.end(); // pointer to the next of the last element
	vector<int>::iterator it = vc.rbegin(); // pointer to the last element
	vector<int>::iterator it = vc.rend(); // to previous of first element
	
	 
	// erasing in vector
	vc.erase(vc.begin() + 1); // deletes the second element in the vector
	vc.erase(vc.begin() + 2, vc.begin() + 5); // deletes 2,3,4 th element from vector. NOTE:: humehsa last me end pointer + 1 rakhna hota hai
	
	
	// Insert function in vector
	vector<int> v(2,100); // {100, 100}
	v.insert(v.begin() 300); // {300, 100, 100} inserts 300 at the start
	
	v.insert(v.begin() + 1, 2, 10); // (first position , number of elements need to insert, value of element) {300, 10 , 10, 100 , 100}
	
	//inserting a whole vector inside another vector 
	vector<int> cpy(3,50);
	v.insert(v.begin(), cp.begin(), cp.end()); // {50, 50, 50, 300, 10, 10, 100, 100}
	
	cout << vc.size(); // size of the vector
	vc.pop_back(); // deletes last element
	
	// if v1 = {1,2} and v2 = {3,4}
	v1.swap(v2); // swaps 2 vectors
	
	vc.clear(); // erases whole vector]
	
	bool b = vc.empty(); // true if empty else false
	
}

//..........................................LIST...........................................................

void explainList() {
	// similar to vectors but gives us front operations as well
	
	list<int> ls;
	ls.push_back(2);
	ls.emplace_back(4);
	
	ls.push_front(1);
	ls.emplace_front(0);
	
	//rest functions are similar
	//begin , end , rbegin , rend, size , clear , empty
	
	//vectors implement SLL therefore insert is costlier whereas lists implements DLL therefore its fast

}

//..............................................DEQUEUE...............................................................

void explainDequeue() {
	// similar to lists and vectors 
	deque<int> dq;
	dq.push_back(2);
	dq.emplace_back(4);
	
	dq.push_front(1);
	dq.emplace_front(0);
	
	dq.pop_back();
	dq.pop_front(); // we can pop from front also i dequeue
	
	//rest functions are similar
	//begin , end , rbegin , rend, size , clear , empty
	
}

//...............................................STACK...................................................

void explainStack() {
	//LIFO
	
	stack<int> st;
	st.push(1);
	st.push(2);
	st.emplace(3);
	
	cout << st.top();
	st.pop();
	
	cout << st.size();
	cout << st.empty();
	
	stack<int> st1, st2;
	st1.swap(st2);
}

//..................................................QUEUE.................................................

void explainQueue() {
	//FIFO
	
	queue<int> q;
	q.push(1);
	q.push(2);
	q.emplace(3); // {1,2,3}
	
	q.back() += 5; // {1,2,8};
	
	q.pop(); // {2,8}
	cout << q.front(); // prints 2
	
	// size , swap, empty same as stack
	
}

//..................................................PRIORITY QUEUE............................................

void explainPriorityQueue() {
	
	// here the largest integer , or char or largest string have the highest priority and will always be on front
	
	priority_queue<int> pq;
	pq.push(5); // {5}
	pq.push(2); // {5,2}
	pq.push(8); // {8,5,2}
	pq.push(10); // {10,8,5,2}
	
	cout << pq.top(); // 10
	
	pq.pop(); // {8,5,2}
	
	// size , swap, empty same as stack
	
	// MINIMUM HEAP USING PQ
	
	priority_queue<int, vector<int> , greater<int>> pq;
	pq.push(5); // {5}
	pq.push(2); // {2,5}
	pq.push(8); // {2,5,8}
	pq.push(10); // {2,5,8,10}
	
	cout << pq.top(); // 2
	pq.pop(); {5,8,10}
}

//...................................................SET......................................................

void explainSet() {
	
	// stores everything in sorted order and stores only unique elements
	
	// a tree maintains the structure . Majority of things happen in logN time
	set<int> st;
	st.insert(1); // {1}
	st.emplace(2); // {1,2}
	st.insert(4); // {1,2,4}
	st.insert(2); // {1,2,4}
	st.insert(3); // {1,2,3,4}
	
	// begin , end , rbegin , rend , size , ()
	//empty() , swap()
	
	auto it = st.find(3); // returns pointer to 3
	auto it2 = st.find(6); // return st.end() if element not present in the set 
	
	st.erase(3); // {1,2,4} take logarithmic time
	auto it = st.find(4);
	st.erase(it); // {1,2}
	
	int cnt = st.count(2); // gives 0 if not present else 1
	
	auto it1 = st.find(2);
	auto it2 = st.find(4);
	st.erase(it1, it2); // erases all btw it1 and it2 not including it2 i.e [it1, it2)
	
	// finds lowerbound and upperbound of the element in set
	
	auto it = st.lower_bound(2);
	auto it = st.upper_bound(3); 
	
	
}

//................................................MULTI SET................................................

void explainMultiSet() {
	// everything same as set , sorted
	// just stores dupplicate elements also
	
	multiset<int> ms;
	
	ms.insert(1);
	ms.insert(1);
	ms.insert(1);
	ms.insert(3); //{1,1,1,3}
	
	int cnt = ms.count(3); // gives # of occurences of 3
	
	ms.erase(1); // all 1's are erased
	
	ms.erase(ms.find(1)); // only a single 1 is erased
}

//...............................................UNORDERED SET...............................................

void explainUnorderedSet() {
	// not sorted order but randomized ordered
	// only stores unique elements
	
	//lower_bound and upper_bound does not works
	// majority of operations have time complexity O(1)
	// in worst case very very rare the complexityt O(n)
}

//...........................................MAP...........................................................

void explainMap() {
	
	// key value pair
	// stores unique key in sorted order
	
	map<int , int> mp;
	map<int, pair<int , int>> mp1;
	map<pair<int, int>, int> mp2;
	
	// insert in map
	mp[1] = 2;
	mp.emplace({2,3}); // {key , value}
	
	for(auto it : mp) {
		cout << it.first << " " << it.second;
	}
	
	cout << mp[3];
	
	auto it = mp.find(2);
	cout << *(it).second;
	
	auto it = mp.find(0); // if 0 not a key in map then it = mp.end()
	
	auto it = mp.lower_bound(2);
	auto it = mp.upper_bound(4);
	
	
	// rest many functions same
	
	// we also have multimap which can store duplicate keys and mp[key] does not work
	
	// we also have unordered map which has similar difference to as set and unordered_set
	
}

//............................SORT......................................................

void explainSort() {
	
	sort(a , a+n);
	sort(v.begin() , v.end()); // we can sort any container like this
	
	sort(a+2, a+4); // (begin , end + 1)
	
	// sorting in descending order
	sort(a , a+n , greater<int>);
	// greater<int> is an inbuilt comparator used to sort in descending fashion
	
	//..................COMPARATORS........................
	pair<int , int> arr[] = {{1,2} , {2,1} , {4,1}};
	// sort it acc to second element
	// is 2nd element is same then sort it acc to 1st element in descending order
	
	sort(arr , arr + n , comp); // {{4,1} , {2,1} , {1,2}} 
}


bool comp(pair<int, int> p1 , pair<int, int> p2) {
	if(p1.second < p2.second) {
		return true; // i.e p1 and p2 in correct order 
	}
	if(p1.second > p2.second) {
		return false; // p1 and p2 will not be in correct order and will be swapped
	}
	
	// they are same
	if(p1.second > p2.second) return true;
	
	return false;
}


//.................................BUILT IN POPCOUNT..............................................

void explainBuiltInPopcount() {
	
	int n = 7;
	int cnt = __builtin_popcount(n); // it will return number of set bits here = 3 
	
	long long l = 12345678987;
	int cnt2 = __builtin_popcountll(); // for ll numbers use this
}


//.....................................MAX element.............................................

// to get a max element from any container
int maxi = *max_element(a, a+n);
// max_element(begin , end) will return address of the max element in the container