#include <bits/stdc++.h>
using namespace std;
#define ll long long

/**
Problem link :: https://codeforces.com/edu/course/2/lesson/6/4/practice/contest/285069/problem/A

Approach :: Maximum Average using binary search

    -> Problem meaning :: We need to find a segment [l,r) of length at least d such that :: 
                          (a[l] + a[l+1] + .... + a[r-2] + a[r-1])/(r - l) is maximum.
                          That is find the maximal average sum of a segment with size >= d
   
    -> Let us take a variable x which represents a value such that the maximal average sum of any segment [l,r). with length >= d in an array will be >= x
    -> Now the variable x follows a good-bad sequence :: 11111111100000000000.....
    -> We need to find maximum x that satisfies this. Hence can apply Binary search on the value of x.
    
    -> For a given x :: Checking whether it is good or not ?
        (a[l] + a[l+1] + .... + a[r-2] + a[r-1])/(r - l) >= x with (r - l) >= d
        (a[l] + a[l+1] + .... + a[r-2] + a[r-1]) >= x * (r - l)
        
        ((a[l] - x) + (a[l+1] - x) + .... + (a[r-2] - x) + (a[r-1] - x)) >= 0
        
        Hence if we subtract all elements in [l,r) with x and then calculate the sum of it must be >= 0 for x to be GOOd.
        
        Let a array Prefix P : such that P[i] = sum(j=0 to j=i-1 :: (a[j] - x))
        
        Now after finding P ::
            If there exist :: l and r such that ::
                    -> r - l >= d 
                    -> P[r] - P[l] >= 0
            Then x is good.
            
        To find for valid (l,r) :: 
            -> Iterate through all possible values of r.
            
            Now for a given r we have P[r].
            Now we need to find a valid l which lies from [0,r-d] and P[r] - P[l] >= 0 that is :: P[r] >= P[l]
            
            This indicates that if we take minimum value of P[i] from [0, r-d]  = mn and if P[r] >= mn then x is good.
            
            Create an array : M with the creation of P array such that ::
                    M[i] = min(P[0], P[1], P[2],......., P[i])
            
            Hence now for each r you can check M[r-d] and if P[r] >= M[r-d] then x is good.
        
    -> Because this includes average i.e floating point number hence use Binary search on real numbers.
    

**/

int n,d;
vector<double> vc;
int l,r;

bool is_good(double x) {
    
    vector<double> pref(n);    
    vector<pair<double,int>> mnPref(n);
    
    mnPref[0].first = vc[0] - x;
    mnPref[0].second = 0;
    pref[0] = vc[0] - x;
    
    double sm = pref[0];
    
    for(int i=1; i<n; i++) {
        sm += (vc[i] - x);
        pref[i] = sm;
        
        if(pref[i] <= mnPref[i-1].first) {
            mnPref[i].first = sm;
            mnPref[i].second = i;
        } else {
            mnPref[i] = mnPref[i-1];
        }
    }
    
    for(int i=n-1; i+1-d >= 0; i--) {
        if(i+1-d >= 0 and pref[i] >= 0) {
            l = 0;
            r = i;
            return true;
        }
        
        if(i-d >= 0 and  mnPref[i-d].first <= pref[i]) {
            l = mnPref[i-d].second + 1;
            r = i;
            return true;
        }
    }
    return false;
}

int main() {
    
    cin >> n >> d;
    vc.resize(n);
    
    for(int i=0; i<n; i++) {
        cin >> vc[i];
    }
       
    double low = 0; // this is definitely a good value as we can always  have a segment of any size whose avergae is >= 0 because all values : a[i] >= 0
    double high = 1e8; // acc to constraints the greatest sum possible is 1e7 hence greatest average must be less then this. Hence 1e8 is definitely a bad value.
    
    
    for(int i=0; i<80; i++) {
        double mid = (low + high)/2;
        if(is_good(mid) == true) {
            low = mid;
        } else {
            high = mid;
        }
    }
    
    
    cout << l+1 << " " << r+1;
    
    return 0;    
    
}
