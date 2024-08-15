// || जय जय जय बजरंग बली ||
#include<bits/stdc++.h>
using namespace std;
#define ll long long


/**
https://www.youtube.com/watch?v=xq3ABa-px_g&list=PLDV1Zeh2NRsDGO4--qE8yH72HFL1Km93P&index=31

Eager prim's algorithms :: 
	Instead of priority queue, here we will use indexed priority queue.
	Hence at anytime our priority queue will store atmost V elements.
	
	Time complexity :: O(Elog(v))
	
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
vector<bool> visited;

void dfs(int node) {
	visited[node] = true;
	for(pair<int,int> adj:graph[node]) {
		if(visited[adj.second] == false) {
			dfs(adj.second);
		}
	}
}

bool isConnected() {
	int n = graph.size();
	int components = 0;
	
	
	for(int i=0; i<n; i++) {
		if(visited[i] == false) {
			components++;
			dfs(i);
		}
	}
	
	return (components == 1);
	
	
}

void prims() {
	
	// check whether graph is connected;
	if(isConnected() == false) {
		cout << "Graph is disconnected\n";
		return;
	}
	int n = graph.size();
	visited.clear();
	visited.resize(n,false);
	
	
	MinIndexedPQ mpq(n);
	// it will contain atmost n elements
	
	mpq.insert(0,0);
	// {cost, nextNode}
	
	for(int i=1; i<n; i++) {
		mpq.insert(i,INT_MAX);
	}
		
	int cost = 0;
	vector<pair<int,int>> mst;
	vector<int> parent(n,-1);
	
	while(!mpq.isEmpty()) {
		
		int node = mpq.minIndex(), edge_cost = mpq.minKey();
		mpq.deleteMin();
		
		visited[node] = true;
		cost += edge_cost;
		
		for(pair<int,int> adj:graph[node]) {
			if(visited[adj.second] == false) {
				if(mpq.keyOf(adj.second) > adj.first) {
					mpq.decreaseKey(adj.second, adj.first);
					parent[adj.second] = adj.first;
				}
			}
		}
	}
	
	cout << cost << '\n';
	
	for(int i=1; i<n; i++) {
		cout << parent[i] << " " << i << '\n';
	}
	
	
}

int main() {
	
	// undirected
	int n,m;
	cin >> n >> m;
	
	graph.resize(n);
	visited.resize(n,false);
	
	for(int i=0; i<m; i++) {
		int n1,n2,w;
		cin >> n1 >> n2 >> w;
		graph[n1].push_back({w,n2});
		graph[n2].push_back({w,n1});
	}
	
	prims();
	
	return 0;
}
