#include <bits/stdc++.h>
using namespace std;
#define int long long

/**
Problem link :: https://codeforces.com/edu/course/2/lesson/6/5/practice/contest/285084/problem/A

Approach :: Binary search for finding K-th ascending element in some set.

    ->Suppose we have several segments of numbers.
        [1,2,3,4]
        [3,4,5]
        [4,5,6,7,8]
        [6,7]
        Thus, each segment is specified by two numbers — its left boundary li and right boundary ri.
        We want to put all of them into one large multiset and find the k-th ascending element in it. 
        In this case, if we merge all the segments, we will get [1,2,3,3,4,4,4,5,5,6,6,7,7,8].
    
    -> Note that the elements in each segment are continues and increase by 1.
    -> Let there be a variable x. And we implement a function on x which tells the number of values less than x.
    -> This function follows a good-bad sequence for boundary K.
    
    -> i.e Let's make a check function cnt(x) that returns the number of elements in the set that less than x.
            Then what is the k-th element? 
            This is the maximum element x such that cnt(x) <= k. This task can be solved by binary search, if we know how to calculate the function cnt.
            
    -> How to define the cnt function? 
    Let's go through all segments and count how many elements less than x are on this segment. 
    The sum of all such values ​​will be the answer. 
    Since each segment contains consecutive numbers, then if x <= l, then the answer is 0, otherwise the answer is min(r,x) - l.
    This is a general algorithm and can be used for many tasks. 
    If a given set consists of numbers, then usually everything is simple. But with this algorithm, you can also build more complex objects such as bit vectors or permutations.

    
**/

int n,k;
vector<pair<int,int>> vc;

bool is_good(int x) {
    int cnt = 0;
    
    for(int i=0; i<n; i++) {
        
        if(vc[i].first > x) {
            cnt += 0;
        } else if(vc[i].second < x) {
            cnt += (vc[i].second - vc[i].first + 1);
        } else {
            cnt += (x - vc[i].first);
        }
    }
    
    return (cnt <= k);
}

signed main() {
    
    cin >> n >> k;
    vc.resize(n);
    for(int i=0; i<n; i++) {
        cin >> vc[i].first >> vc[i].second;
    }
    
    int low = INT_MIN; // definitely a good value
    int high = INT_MAX; // from constraints
    
    for(int i=0; i<60; i++) { // here in 30-40 value answer will be computed
        int mid = (low + high)/2;
        
        if(is_good(mid) == true) {
            low = mid;
        } else {
            high = mid;
        }
    }
    
    cout << low;
    
    
    return 0;
}

