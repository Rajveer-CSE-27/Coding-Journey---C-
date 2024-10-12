#include<iostream>
using namespace std;

int mat[1000][1000];
bool vis[1000][1000];
int n,m;


struct node {
	int x;
	int y;
	int l;
};

node q[1000000];
int front, back;

void push(node temp) {
	q[back] = temp;
	back++;
}
node pop() {
	return q[front++];
}

bool empty() {
	return (front == back);
}

bool valid(int x, int y) {
	if(x >= 0 and y >= 0 and x < n and y < m) {
		return true;
	}
	return false;
}

bool left(int x, int y) {
	if(mat[x][y] == 1 or mat[x][y] == 3 or mat[x][y] == 6 or mat[x][y] == 7) {
		return true;
	}

	return false;
}

bool right(int x,int y){
    return (mat[x][y]==1 || mat[x][y]==3 || mat[x][y]==4 || mat[x][y]==5);
}
bool up(int x,int y){
    return (mat[x][y]==1 || mat[x][y]==2 || mat[x][y]==4 || mat[x][y]==7);
}
bool down(int x,int y){
    return (mat[x][y]==1 || mat[x][y]==2 || mat[x][y]==6 || mat[x][y]==5);
}


void solve() {

	front = 0;
	back = 0;

	cin >> n >> m;
	int x,y,len;
	cin >> x >> y >> len;

	for(int i=0; i<n; i++) {
		for(int j=0; j<m; j++) {
			cin >> mat[i][j];
			vis[i][j] = false;
		}
	}

	if(mat[x][y] == 0) {
		cout << 0;
		return;
	}

	int ans = 0;
	push({x,y,len});
	vis[x][y] = true;

	while(!empty()) {
		node curr = pop();

		int i = curr.x;
		int j = curr.y;
		int l = curr.l;

		if(l == 0) {
			continue;
		}

		ans++;

		if(valid(i,j-1) and left(i,j) and right(i,j-1) and vis[i][j-1] == false) {
			vis[i][j-1] = true;
			push({i,j-1,l-1});
		}

		if(valid(i,j+1) and right(i,j) and left(i,j+1) and vis[i][j+1] == false) {
			vis[i][j+1] = true;
			push({i,j+1,l-1});
		}
		if(valid(i+1,j) and down(i,j) and up(i+1,j) and vis[i+1][j] == false) 
		{
			vis[i+1][j] = true;
			push({i+1,j,l-1});
		}
		if(valid(i-1,j) and up(i,j) and down(i-1,j) and vis[i-1][j] == false) 
		{
			vis[i-1][j] = true;
			push({i-1,j,l-1});
		}
	}

	cout << ans;
}

int main() {

	int tc;
	cin >> tc;

	while(tc--) {
		solve();
		cout << '\n';
	}
}
