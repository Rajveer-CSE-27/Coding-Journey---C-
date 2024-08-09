// || जय जय जय बजरंग बली ||
#include<bits/stdc++.h>
using namespace std;
#define ll long long

/**
https://www.youtube.com/watch?v=pSqmAO-m7Lk&list=PLDV1Zeh2NRsDGO4--qE8yH72HFL1Km93P&index=18

Eager's Dijkstra ::
	In lazy dijkstra we stored duplicate keys because it's more efficient to insert a new key-value pair in 0(log(n)) than it is to update an existing key's value in 0(n).
	This approach is inefficient for dense graphs because we end up with several stale outdated key-value pairs in our PQ.
	
	The eager version of Dijkstra's avoids duplicate key-value pairs and supports efficient value updates in 0(log(n))
	by using an Indexed Priority Queue (IPQ).
	
	Here we have used Min IPQ.
	For more see https://github.com/Rajveer-CSE-27/Coding-Journey-CPP/blob/main/Graph/William%20Fiset%20Graph%20Theory/18_3_indexed_priority_queue.cpp 
	
	Hence our algorithm gets more efficient as our IPQ size will be atmost n anytime.
	
Time Complexity :: O(Elog(V))

**/
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



vector<vector<pair<int,int>>> graph;

void dijkstra(int source, int n) {
	
	MinIndexedPQ mpq(n); // it will contain atmost n elements.
	vector<int> parent(n);
	vector<int> dist(n, INT_MAX);
	
	mpq.insert(source,0);
	for(int i=0; i<n; i++) {
		if(i != source) {
			mpq.insert(i,INT_MAX);
		}
	}
	parent[source] = -1;
	
	while(!mpq.isEmpty()) {
		int node = mpq.minIndex(), curr_dist = mpq.minKey();
		mpq.deleteMin();
		
		int dist_from_source = (parent[node] == -1) ? 0 : dist[parent[node]];
		
		if(dist[node] < dist_from_source + curr_dist) {
			continue;
		}
		
		dist[node] = dist_from_source + curr_dist;
		
		for(pair<int,int> adj:graph[node]) {
			if(mpq.keyOf(adj.first) > adj.second) {
				mpq.decreaseKey(adj.first, adj.second);
				parent[adj.first] = node;
			}
		}
		
	}
	
	cout << "Source Node : " << source << '\n';
	for(int i=0; i<n; i++) {
		cout << "Current node : " << i << " ";
		cout << "Shortest distance from source : " << dist[i] << '\n';
		cout << "Path : ";
		int curr = i;
		vector<int> path;
		while(curr != -1) {
			path.push_back(curr);
			curr = parent[curr];
		}
		for(int j=path.size()-1; j>=0; j--) {
			cout << path[j] << " "; 
		}
		cout << '\n';
	}
	
}

int main(){
	
	int n,m;
	cin >> n >> m;
	graph.resize(n); // 0 based indexing
	for(int i=0; i<m; i++) {
		int n1,n2,w;
		cin >> n1 >> n2 >> w;
		graph[n1].push_back({n2,w});
	}
	
	dijkstra(0, n); // that is we want shortest path from source node 0.
	
    return 0;
}
