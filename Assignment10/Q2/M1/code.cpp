#include<bits/stdc++.h>
using namespace std;
struct record
{
	int a;
	int b;
};
int main()
{
/*	cout << "Enter the number of Rows:";
	cin >> R;
	cout << "Enter the number of columns:";
	for(i = 0; i < R; i++)
	{
		cin >> C;
	}*/
	stack<record> st;
	int mat[4][5] = {{1,1,1,1,0},{1,1,0,1,0},{1,1,0,0,0},{0,0,0,0,1}}, c = 0;
	int visited[4][5] = {{0},{0}}, i, j;
	struct record r;
	r.a = 0;
	r.b = 0;
	st.push(r);
	visited[0][0] = 1; visited[0][4] = 1; visited[1][4] = 1; visited[2][2] = 1;visited[2][3] = 1; visited[2][4] = 1;
	visited[3][0] = 1; visited[3][1] = 1; visited[3][2] = 1;visited[3][3] = 1;
	while(1)
	{
		while(!st.empty())
		{
			r = st.top();
			st.pop();
			i = r.a;
			j = r.b;
			if(i > 0)
			{
				if(visited[i-1][j] == 0 && mat[i-1][j] == 1)
				{
					visited[i-1][j] = 1;
					r.a = i-1;
					r.b = j;
					st.push(r);
				}
			}
			if(i < 3)
			{
				if(visited[i+1][j] == 0 && mat[i+1][j] == 1)
				{
					visited[i+1][j] = 1;
					r.a = i+1;
					r.b = j;
					st.push(r);
				}
			}
			if(j > 0)
			{
				if(visited[i][j-1] == 0 && mat[i][j-1] == 1)
				{
					visited[i][j-1] = 1;
					r.a = i;
					r.b = j-1;
					st.push(r);
				}
			}
			if(j < 4)
			{
				if(visited[i][j+1] == 0 && mat[i][j+1] == 1)
				{
					visited[i][j+1] = 1;
					r.a = i;
					r.b = j+1;
					st.push(r);
				}
			}
		}
		c++;
		for(i = 0; i < 4; i++)
		{
			for(j = 0; j < 5; j++)
			{
				if(visited[i][j] == 0)
				{
					r.a = i;
					r.b = j;
					st.push(r);
					visited[i][j] = 1;
					break;
				}
			}
		}
		if(st.empty())
		{
			cout << c;
			return 0;	
		}
		//cout << "Hi";
	}

}
