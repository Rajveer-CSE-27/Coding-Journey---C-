#include <bits/stdc++.h>
using namespace std;

/**

Recurrence Relation :: It defines a sequence such that you can get the next values based upon previous and current values
Ex : Fibonnaci series has a recurrence relation :: F(n) = F(n-1) + F(n-2)

To get the nth term of the series you can calculate it using recurrence relation for n times.
But you can also calculate it in O(logn) time

Every recurrence relation has a special matrix defined which helps to find the next values.
Let for fibonnaci series :: 
	[F1 F2]*[A B] = [F2 F3]  because our recurrence relation is based upon previous 2 values hence matrix of size 2*2.
 		[C D]				If it was dependent on previous k values then matrix of size k*k
 			
 	
 	We see that :
 	[F2 F3]*[A B] = [F3 F4]  
 		[C D]
 			
 	[F3 F4]*[A B] = [F4 F5]  
 		[C D]
 			
 	if we observe then : [F1 F2] * [A B] * [A B] = [F3 F4]  
 					[C D]   [C D]
 				
 				also :  [F1 F2] * [A B] * [A B] * [A B]= [F4 F5]  
 						  [C D]   [C D]	  [C D]
 	
 	Hence to find the nth term that is FN we need : to multiply the matrix [A B] to the power(n-1) with [F1 F2]. 
 																		   [C D]
 	
 	This boils down to same problem as matrix exponentition.
 	The overall time complexity would be :: O(dim^3 * (logn)) here dim = 2 that is constant therefore T : O(logn)
 	Hence we can find the nth value of reccurence relation in logn time.
 	
 	
 	The question is how to find the matrix for a recurrence relation.
 	We can do it by observing;
 	for fibonnaci :: 
 		[F1 F2] * [A B] = [F2 F3]
 			  [C D]
 				  
 		F1*A + F2*C = F2
 		F1*B + F2*D = F3
 		
 		hence A = 0, C = 1
 		and we know for any fibbonaci term : FN = F(N-1) + F(N-2)
 		hence B = 1 D = 1
 		
 		hence matrix : [0 1]
 				       [1 1]
 				       
 	For ex : reccurence relation :: F(n) = 2*F(n-1) + 3*F(n-2) + 4*F(n-3) :: F(1) = 0, F(2) = 1, F(3) = 2
 				matrix will be 3*3 as any term depends on last 2 terms.
 				[F1 F2 F3] * [A B C] = [F2 F3 F4]
 					     [D E F]
 					     [G H I]
 				A = 0, D = 1, G = 0
 				B = 0, E = 0, H = 1
 				C = 4, F = 3, I = 2
 					
**/		


// Main code example of above explaination.

vector<vector<int>> identity;

vector<vector<int>> mul(vector<vector<int>> A , vector<vector<int>> B, int dim) {
	vector<vector<int>> res(dim, vector<int>(dim, 0));
	
	for(int i=0; i<dim; i++) {
		for(int j=0; j<dim; j++) {
			for(int k=0; k<dim; k++) {
				res[i][j] += A[i][k]*B[k][j];
			}
		}
	}
	return res;
}

void solve(vector<int>& initial, vector<vector<int>>& matrix, int n, int dim) {
	identity.resize(2, vector<int>(2));
	identity[0][0] = identity[1][1] = 1;
	identity[0][1] = identity[1][0] = 1;
	
	n--; // beause to get nth term we need to multiply n-1 times;
	
	while(n > 0) {
		if(n&1) {
			identity = mul(identity, matrix, dim);
			n--;
		} else {
			matrix = mul(matrix, matrix, dim);
			n /= 2;
		}
	}
	
	int res = 0;
	
	for(int i=0; i<dim; i++) {
		res += initial[i]*identity[i][dim-1];
	}
	
	cout << res << '\n';
	
}

int main() {
	
	int n;
	cin >> n;
	
	///for fibonnaci
	vector<vector<int>> matrix(2, vector<int>(2,1));
	matrix[0][0] = 0;
	
	vector<int> initial(1, 1); // taking f1 = 1, f2 = 1
	solve(initial,matrix,n,2);
	
	return 0;
}
