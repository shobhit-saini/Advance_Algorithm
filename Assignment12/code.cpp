#include<bits/stdc++.h>
using namespace std;
struct rec
{
	int i, j, k;
};
int main()
{
	int X, Y, Z, x, y, z;
	rec r;
	cout << "Enter the initial state:";
	cin >> r.i >> r.j >> r.k;
	cout << "Enter the final state:";
	cin >>  x >> y >> z;
	queue<rec> q;
	q.push(r);
	
}
