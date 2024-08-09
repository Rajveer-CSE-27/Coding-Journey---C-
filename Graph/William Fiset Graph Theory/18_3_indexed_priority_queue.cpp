
//.....................................MIN Indexed Priority Queue.................................
#include <cstdio>


/*
 * Indexed min priority queue
 * Supports insertion in O(log N), deletion of any key (regardless of whether
 * the key is the minimum key or not) in O(log N) and changes to key values
 * in O(log N), where N is the number of
 * elements currently in the PQ
 */
class MinIndexedPQ {
    int NMAX, N, *heap, *index, *keys;

    void swap(int i, int j) {
        int t = heap[i]; heap[i] = heap[j]; heap[j] = t;
        index[heap[i]] = i; index[heap[j]] = j;
    }

    void bubbleUp(int k)    {
        while(k > 1 && keys[heap[k/2]] > keys[heap[k]])   {
            swap(k, k/2);
            k = k/2;
        }
    }

    void bubbleDown(int k)  {
        int j;
        while(2*k <= N) {
            j = 2*k;
            if(j < N && keys[heap[j]] > keys[heap[j+1]])
                j++;
            if(keys[heap[k]] <= keys[heap[j]])
                break;
            swap(k, j);
            k = j;
        }
    }

public:
    // Create an empty MinIndexedPQ which can contain atmost NMAX elements
    MinIndexedPQ(int NMAX)  {
        this->NMAX = NMAX;
        N = 0;
        keys = new int[NMAX + 1];
        heap = new int[NMAX + 1];
        index = new int[NMAX + 1];
        for(int i = 0; i <= NMAX; i++)
            index[i] = -1;
    }
	
    ~MinIndexedPQ() {
        delete [] keys;
        delete [] heap;
        delete [] index;
    }

    // check if the PQ is empty
    bool isEmpty()  {
        return N == 0;
    }

    // check if i is an index on the PQ
    bool contains(int i)    {
        return index[i] != -1;
    }

    // return the number of elements in the PQ
    int size()  {
        return N;
    }

    // associate key with index i; 0 < i < NMAX
    void insert(int i, int key) {
        N++;
        index[i] = N;
        heap[N] = i;
        keys[i] = key;
        bubbleUp(N);
    }

    // returns the index associated with the minimal key
    int minIndex()  {
        return heap[1];
    }

    // returns the minimal key
    int minKey()    {
        return keys[heap[1]];
    }

    // delete the minimal key and return its associated index
    // Warning: Don't try to read from this index after calling this function
    int deleteMin() {
        int min = heap[1];
        swap(1, N--);
        bubbleDown(1);
        index[min] = -1;
        heap[N+1] = -1;
        return min;
    }

    // returns the key associated with index i
    int keyOf(int i)    {
        return keys[i];
    }

    // change the key associated with index i to the specified value
    void changeKey(int i, int key)  {
        keys[i] = key;
        bubbleUp(index[i]);
        bubbleDown(index[i]);
    }

    // decrease the key associated with index i to the specified value
    void decreaseKey(int i, int key)    {
        keys[i] = key;
        bubbleUp(index[i]);
    }

    // increase the key associated with index i to the specified value
    void increaseKey(int i, int key)    {
        keys[i] = key;
        bubbleDown(index[i]);
    }

    // delete the key associated with index i
    void deleteKey(int i)   {
        int ind = index[i];
        swap(ind, N--);
        bubbleUp(ind);
        bubbleDown(ind);
        index[i] = -1;
    }
};

int main()  {
    MinIndexedPQ pq(10);
    for(int i=0; i<10; i++)
        pq.insert(i, 10 - i);

    printf("%d %d\n", pq.minKey(), pq.size());
    pq.deleteKey(8);
    printf("%d %d\n", pq.minKey(), pq.size());
    pq.deleteMin();
    printf("%d %d\n", pq.minKey(), pq.size());

    return 0;
}

//...................................................................................................................

//.............................................MAX indexed priority queue............................................

// C++ program for the above approach

#include <bits/stdc++.h>
using namespace std;

template <class T1, class T2,
		class Comparator = less<T2>,
		class Hash = hash<T1> >

class indexed_priority_queue {

	// Storing indices of values using key
	unordered_map<T1, long long int, Hash> m;

	// Container
	vector<pair<T1, T2> > v;

	// Size
	long long numberOfElement;

	// Creating a instance of Comparator class
	Comparator comp;

	// Max Capacity
	long long capacity = LLONG_MAX;

	// Obtaining the index value from hash map
	long long int getValueIndex(T1 key)
	{
		if (m[key] == 0) {
			cout << "No Such Key Exist";
			return -1;
		}
		return v[m[key] - 1];
	}

	// heapify the container
	void heapify(vector<pair<T1, T2> >& v,
				long long int heap_size,
				long long index)
	{
		long long leftChild = 2 * index + 1,
				rightChild = 2 * index + 2,
				suitableNode = index;

		if (leftChild < heap_size
			&& comp(v[suitableNode].second,
					v[leftChild].second)) {
			suitableNode = leftChild;
		}

		if (rightChild < heap_size
			&& comp(v[suitableNode].second,
					v[rightChild].second)) {
			suitableNode = rightChild;
		}

		if (suitableNode != index) {

			// swap the value
			pair<T1, T2> temp = v[index];
			v[index] = v[suitableNode];
			v[suitableNode] = temp;

			// updating the map
			m[v[index].first] = index + 1;
			m[v[suitableNode].first]
				= suitableNode + 1;

			// heapify other affected nodes
			heapify(v, numberOfElement,
					suitableNode);
		}
	}

public:
	indexed_priority_queue()
	{
		numberOfElement = 0;
		m.clear();
		v.clear();
	}

	void push(T1 key, T2 value)
	{
		if (numberOfElement == capacity) {
			cout << "Overflow";
			return;
		}
		if (m[key] != 0) {
			cout << "Element Already Exists";
			return;
		}

		// Adding element
		v.push_back(make_pair(key, value));
		numberOfElement++;
		m[key] = numberOfElement;

		long long index = numberOfElement - 1;

		// Comparing to parent node
		while (index != 0
			&& comp(v[(index - 1) / 2].second,
					v[index].second)) {

			// swap the value
			pair<T1, T2> temp = v[index];
			v[index] = v[(index - 1) / 2];
			v[(index - 1) / 2] = temp;

			// updating the map
			m[v[index].first] = index + 1;
			m[v[(index - 1) / 2].first]
				= (index - 1) / 2 + 1;

			// updating index in map
			index = (index - 1) / 2;
		}
	}

	void pop()
	{
		if (numberOfElement == 0) {
			cout << "UnderFlow";
			return;
		}

		// Removing element
		v.erase(v.begin());
		numberOfElement--;
		heapify(v, numberOfElement, 0);
	}

	pair<T1, T2> top() { return v[0]; }

	long long int size() { return numberOfElement; }

	bool empty() { return numberOfElement == 0; }

	void changeAtKey(T1 key, T2 value)
	{
		if (m[key] == 0) {
			cout << "No Such Key Exist";
			return;
		}
		long long index = m[key] - 1;
		v[index].second = value;

		// Comparing to child nodes
		heapify(v, numberOfElement, index);

		// Comparing to Parent Node
		while (index != 0
			&& comp(v[(index - 1) / 2].second,
					v[index].second)) {

			// swap the value
			pair<T1, T2> temp = v[index];
			v[index] = v[(index - 1) / 2];
			v[(index - 1) / 2] = temp;

			// updating the map
			m[v[index].first] = index + 1;
			m[v[(index - 1) / 2].first]
				= (index - 1) / 2 + 1;

			// updating index in map
			index = (index - 1) / 2;
		}
	}
};

void display(indexed_priority_queue<int, int> IPQ)
{
	indexed_priority_queue<int, int> temp = IPQ;
	while (!IPQ.empty()) {
		pair<int, int> tmp;
		tmp = IPQ.top();
		IPQ.pop();
		cout << "( " << tmp.first << ", "
			<< tmp.second << " ) ";
	}
	cout << '\n';
}

// Driver Code
int main()
{

	// First parameter is key datatype
	// and it should be hashable
	// Second parameter is value datatype comparator
	// function (by default it implements maxheap)
	indexed_priority_queue<int, int> IPQ;

	// Check if empty
	cout << "Checking if initially the IPQ is empty\n";
	if (IPQ.empty())
		cout << "IPQ is empty\n";
	else
		cout << "IPQ is not empty\n";

	// Insertion
	cout << "Inserting pairs (2, 1), (3, 7), "
		<< " (1, 0) and (4, 5)\n";
	IPQ.push(2, 1);
	IPQ.push(3, 7);
	IPQ.push(1, 0);
	IPQ.push(4, 5);

	// Printing the contents of IPQ
	cout << "IPQ: ";
	display(IPQ);
	cout << '\n';

	// Checking size and top after pushing
	cout << "Size: " << IPQ.size() << endl;
	cout << "Top: " << IPQ.top().first
		<< ", " << IPQ.top().second
		<< "\n\n";

	// Replace operation
	cout << "Changing value associated with"
		<< " key 3 to 2 and 1 to 9\n";
	IPQ.changeAtKey(3, 2);
	IPQ.changeAtKey(1, 9);

	// Checking size and top after replacement
	cout << "Size: " << IPQ.size() << endl;
	cout << "Top: " << IPQ.top().first
		<< ", " << IPQ.top().second
		<< "\n\n";

	// Deleting 2 elements from IPQ
	cout << "Popping an element from IPQ: ";
	IPQ.pop();
	cout << "\nPopping an element from IPQ: ";
	IPQ.pop();
	cout << '\n\n';

	// Printing the contents of IPQ after deletion
	cout << "IPQ: ";
	display(IPQ);
	cout << '\n';

	// Checking size and top after pushing
	cout << "Size: " << IPQ.size() << endl;
	cout << "Top: " << IPQ.top().first
		<< ", " << IPQ.top().second
		<< "\n\n";

	return 0;
}
