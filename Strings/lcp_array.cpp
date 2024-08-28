// || जय जय जय बजरंग बली ||
#include<bits/stdc++.h>
using namespace std;
#define ll long long

/**

Longest Common Prefix array (LCP) array :: 
        https://www.youtube.com/watch?v=53VIWj8ksyI&list=PLDV1Zeh2NRsCQ_Educ7GCNs3mvzpXhHW5&index=2
        
        The LCP array is an array in which every index tracks how many characters two sorted
        adjacent suffixes have in common.
        Hence lcp[i] = number of common characters in prefix between both the strings.

        
        Example :: 
            string :: "ABABBAB"
        
        suffixArrayVal             lcpArrayVal          suffix
        5                           2                      AB 
        0                           2                      ABABBAB
        2                           0                      ABBAB
        6                           1                      B
        4                           3                      BAB
        1                           1                      BABBAB
        3                           Undefined              BBAB
    
        lcp[0] = 2 because AB and ABABBAB have 2 characters common
        lcp[1] = 2 becuase ABABBAB and ABBAB have 2 charachters common
        lcp[2] = 0 becuse ABBAB and B have 0 characters common.
        ans so on.......
    
    Using kasai algorithm :: 
            Given a suffix array pf string we can construct lcp array in O(n).
            
            Let's look at two adjacent suffixes in the sorted order (order of the suffix array).
            Let their starting positions be  i  and  j and their  lcp  equal to  k > 0 .
            If we remove the first letter of both suffixes - i.e. we take the suffixes  i+1  and  j+1 - then it should be obvious that the  lcp of these two is  k - 1 .
            However we cannot use this value and write it in the lcp  array, because these two suffixes might not be next to each other in the sorted order.
            The suffix  i+1  will of course be smaller than the suffix  j+1 , but there might be some suffixes between them.
            
            However, since we know that the LCP between two suffixes is the minimum value of all transitions, we also know that the LCP between any two pairs in that interval has to be at least  k-1, especially also between  i+1  and the next suffix.
            And possibly it can be bigger.

            Now we already can implement the algorithm.
            We will iterate over the suffixes in order of their length.
            This way we can reuse the last value  k , since going from suffix  i  to the suffix  i+1  is exactly the same as removing the first letter.
            We will need an additional array  rank , which will give us the position of a suffix in the sorted list of suffixes.
            
**/


vector<int> sort_cyclic_shifts(string const& s) {
    int n = s.size();
    const int alphabet = 256;
    
    vector<int> p(n), c(n), cnt(max(alphabet, n), 0);
    for (int i = 0; i < n; i++)
        cnt[s[i]]++;
    for (int i = 1; i < alphabet; i++)
        cnt[i] += cnt[i-1];
    for (int i = 0; i < n; i++)
        p[--cnt[s[i]]] = i;
    c[p[0]] = 0;
    int classes = 1;
    for (int i = 1; i < n; i++) {
        if (s[p[i]] != s[p[i-1]])
            classes++;
        c[p[i]] = classes - 1;
    }
    vector<int> pn(n), cn(n);
    for (int h = 0; (1 << h) < n; ++h) {
        for (int i = 0; i < n; i++) {
            pn[i] = p[i] - (1 << h);
            if (pn[i] < 0)
                pn[i] += n;
        }
        fill(cnt.begin(), cnt.begin() + classes, 0);
        for (int i = 0; i < n; i++)
            cnt[c[pn[i]]]++;
        for (int i = 1; i < classes; i++)
            cnt[i] += cnt[i-1];
        for (int i = n-1; i >= 0; i--)
            p[--cnt[c[pn[i]]]] = pn[i];
        cn[p[0]] = 0;
        classes = 1;
        for (int i = 1; i < n; i++) {
            pair<int, int> cur = {c[p[i]], c[(p[i] + (1 << h)) % n]};
            pair<int, int> prev = {c[p[i-1]], c[(p[i-1] + (1 << h)) % n]};
            if (cur != prev)
                ++classes;
            cn[p[i]] = classes - 1;
        }
        c.swap(cn);
    }
    return p;
}

vector<int> suffix_array_construction(string s) {
    
    // time :: O(nlogn)
    // space :: O(n)
    
    s += "$"; // this character must be less than any of the character in string
    vector<int> sorted_shifts = sort_cyclic_shifts(s);
    
    // if you want to know smallest cyclic shift then 
    //                              return sorted_shifts[0] at this line
    
    
    
    sorted_shifts.erase(sorted_shifts.begin());
    return sorted_shifts;
}


vector<int> lcp_construction(string& s, vector<int> p) {
    
    // kasai algorithm
    // time :: O(n)
    // space :: O(n)
    
    int n = s.size();
    vector<int> rank(n, 0);
    for (int i = 0; i < n; i++)
        rank[p[i]] = i;

    int k = 0;
    vector<int> lcp(n-1, 0);
    for (int i = 0; i < n; i++) {
        if (rank[i] == n - 1) {
            k = 0;
            continue;
        }
        int j = p[rank[i] + 1];
        while (i + k < n && j + k < n && s[i+k] == s[j+k])
            k++;
        lcp[rank[i]] = k;
        if (k)
            k--;
    }
    return lcp;
}

int main() {
    
    string s = "ABABBAB";
    vector<int> suffix_array = suffix_array_construction(s);
    vector<int> lcp_array = lcp_construction(s, suffix_array);
    
    for(auto it:lcp_array) {
        cout << it << " ";
    }
    
    return 0;
    
    
}
