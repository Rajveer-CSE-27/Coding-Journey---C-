// || जय जय जय बजरंग बली ||
#include<bits/stdc++.h>
using namespace std;
#define ll long long

/**
https://www.youtube.com/watch?v=ZakhE_eaonY&list=PLb3g_Z8nEv1isaHPaXL1j-pSo60812JtY&index=6
https://cses.fi/problemset/task/1648

Square root decomposition :: 
    
    Used when some queries are update queries.
    Let you have array :: {a1,a2,a3,.....,an}
    And Q queries of 2 types :: 
        -> [l,r] give something from range l to r
        -> [i,v] point update {a[i] = v}
        
    
    Let array A be of length n.
    Break the array A into x smaller arrays :: B1, B2, ..., Bx each having y elements each.
    So x*y = n.

    Let we calculate the required value of type 1 for each smaller array. 
    i.e :: let [1,y] = S1 that is answer for query 1 with range = all values of B1
           [y+1,2*y] = S2 that is answer for query 2 with range = all values of B2.
           
           and so on.
           
    If we have point update query [i,v]
        
        Let element i lies in Bk
        Update that element to v. And recalculate Sk
        updating Sk can be done in atmost :: O(y). Becuase there are y elements in Bk.
    
    If we have query :: [l,r]
        
        Let l lies in Bi and r lies in Bj.
        let there be this scenario :: Bi, Bi+1, Bi+2, ...., Bj-1, Bj
        So our answer will surely have Si+1, Si+2, .... Sj-1
        We can access all these values in O(x) because there are atmost x smaller arrays.
        Also in Bi we need to calculate answer from l to end element of  Bi.
        In Bj we need to calculate answer from start element of Bj to r.
        These both operation will take O(y).
        
        Hence query :: [l,r] can be answered in O(x+y)
    
    Best x and y = sqrt(n).
    
    Hence time complexity for any query :: O(sqrt(n)).
    

That is why this is called sqrt decomposition. Becuase we decompose array into sqrt(n) arrays each having sqrt(n) elements.
And we can answer any query in sqrt(n) time.

Q. If n is not a perfect square ?
        Imagine N the size of array is not a perfect square.
        There are two things you can do:
            1. Add some extra elements to the array (equal to identity element, 0 incase of sum queries, 1 in case of multiplication ) to make the size a perfect square.
            2. Make ceil(root(N)) chunks with each chunk having exactly ceil(root(N)) elements except for the last chunk which will have fewer elements and it's okay.
    

**/

struct Chunk {
    vector<int> elementsInChunk;
    int aggregatedValueForChunk; // Si for chunk Bi
};

class SquareRootDecomposition {
    int block_size;
    vector<Chunk> chunks;
    
    pair<int,int> getChunkForIndex(int index) {
        int chunk_number = index/block_size;
        int index_inside_chunk = index - (chunk_number * block_size);
        return {chunk_number, index_inside_chunk};
    }
    
    int calculateAggregatedValue(Chunk& chunk, int index_from, int index_till){
        int aggregatedValue = 0;
        
        // we are doing sum queries here. Change if you want to perform other type of queries.
        while(index_from <= index_till) {
            aggregatedValue += chunk.elementsInChunk[index_from];
            index_from++;
        }
        
        return aggregatedValue;
    }
    
    void fillChunks(vector<int>& dataVector){
        int curr_chunk = 0;
        for(int i = 0; i < dataVector.size(); i++){
            if(i != 0 and ((i % block_size) == 0)){
                curr_chunk++;
            }
            chunks[curr_chunk].elementsInChunk.push_back(dataVector[i]);
        }
 
        for(Chunk &chunk: chunks){
            chunk.aggregatedValueForChunk = calculateAggregatedValue(chunk, 0, (int)chunk.elementsInChunk.size() - 1);
        }
    }
    
    int internalChunks(int l, int r){
        if(l > r) return 0;
        int aggregatedValue = 0;
        while(l <= r)
            aggregatedValue += chunks[l++].aggregatedValueForChunk;
        return aggregatedValue;
    }
    
public:
    
    SquareRootDecomposition(vector<int>& dataVector){
        
        block_size = sqrt((int)dataVector.size());       
        chunks = vector<Chunk>(block_size + 1);
        fillChunks(dataVector);          
    }
    
    int query(int L, int R){
        
        pair<int,int> leftChunk = getChunkForIndex(L);
        pair<int,int> rightChunk = getChunkForIndex(R);
        
        if(leftChunk.first == rightChunk.first)
            return calculateAggregatedValue(chunks[leftChunk.first], leftChunk.second, rightChunk.second);
        else {
           return calculateAggregatedValue(chunks[leftChunk.first], leftChunk.second, (int)chunks[leftChunk.first].elementsInChunk.size() - 1) 
                      + calculateAggregatedValue(chunks[rightChunk.first], 0, rightChunk.second)
                      + internalChunks(leftChunk.first + 1, rightChunk.first - 1);
        }
    }
    
    void update(int index, int value){
        pair<int,int> indexInChunk = getChunkForIndex(index);
        chunks[indexInChunk.first].elementsInChunk[indexInChunk.second] = value;
        chunks[indexInChunk.first].aggregatedValueForChunk = calculateAggregatedValue(chunks[indexInChunk.first], 0, chunks[indexInChunk.first].elementsInChunk.size());
    }
    
    
    
};

int main() {
    
    vector<int> vc = {1,2,3,4,5,6,7,8,9,10};
    
    SquareRootDecomposition s(vc);
    
    cout << s.query(0,5) << '\n' ;// print :: 1+2+3+4+5+6
    s.update(2,0);
    
    cout << s.query(0,5) << '\n'; // print :: 1+2+0+4+5+6 
    
    return 0;
}
