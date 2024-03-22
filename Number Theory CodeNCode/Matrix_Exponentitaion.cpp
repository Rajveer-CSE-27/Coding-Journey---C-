#include <bits/stdc++.h>
using namespace std;
#define N 101

int matrix[N][N], identity[N][N];
//Time Complexity approach 1: O((dim^3)*power)
int matrix2[N][N], identity2[N][N];
//Time Complexity approach 2: O((dim^3)*log(power))


void mul(int A[][N], int I[][N], int dim) {
	
	int res[dim][dim];
	
	for(int i=0; i<dim; i++) {
		for(int j=0; j<dim; j++) {
			res[i][j] = 0;
			for(int k=0; k<dim; k++) {
				res[i][j] += A[i][k]*I[k][j];
			}
		}
	}
	for(int i=0; i<dim; i++) {
		for(int j=0; j<dim; j++) {
			I[i][j] = res[i][j];
		}
	}
}

void approach1(int A[][N], int dim, int n) {
	
	// forming the identity matrix
	for(int i=0; i<dim; i++) {
		for(int j=0; j<dim; j++) {
			if(i==j) {
				identity[i][j] = 1;
			} else {
				identity[i][j] = 0;
			}
		}
	}
	
	for(int i=0; i<n; i++) {
		mul(A,identity,dim);
	}
	
	for(int i=0; i<dim; i++) {
		for(int j=0; j<dim; j++) {
			cout << identity[i][j] << " ";
		}
		cout << '\n';
	}
}

void approach2(int A[][N], int dim, int n) {
	// forming the identity matrix
	for(int i=0; i<dim; i++) {
		for(int j=0; j<dim; j++) {
			if(i==j) {
				identity2[i][j] = 1;
			} else {
				identity2[i][j] = 0;
			}
		}
	}
	
	// similar to binary exponentition
	
	while(n > 0) {
		if(n&1) {
			mul(A,identity2,dim);
			n--;
		} else {
			mul(A,A,dim);
			n /= 2;
		}
	}
	
	for(int i=0; i<dim; i++) {
		for(int j=0; j<dim; j++) {
			cout << identity2[i][j] << " ";
		}
		cout << '\n';
	}
}


int main() {
	
	int dim;
	cin >> dim;
	int n;
	cin >> n;
	
	for(int i=0; i<dim; i++) {
		for(int j=0; j<dim; j++) {
			cin >> matrix[i][j];
			matrix2[i][j] = matrix[i][j];
		}
	}
	
	approach1(matrix, dim, n);
	cout << '\n';
	approach2(matrix2,dim,n);
	
	
	return 0;
}
