int longestPrefixSuffix(string str) { // KMP algorithm
	
    vector<int> A(str.size(), 0); 
    int j = 0, i = 1; 
          
    while(i < str.size()) { 
        if(str[i] == str[j]) { 
            A[i] = j+1; 
            j++; 
            i++; 
        } else { 
            if(j==0) {
                i++; 
            }
            else {
                j = A[j-1]; 
            }
                  
        } 
    } 
  
    return A.back(); 
} 
