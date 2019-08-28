#include<iostream>
using namespace std;
int main()
{
	int a[] = {1, 2, 5, 10};
	int br[4] = {0};
	int sum = 0, i = 0, temp = 0, res = 0;
	cin>> sum;
		if(sum/10 > 0)
		{
			temp = sum/10;
			sum -= 10*temp;
			br[3] += temp;
		}
		if(sum/5 > 0)
		{
			temp = sum/5;
			sum -= 5*temp;
			br[2] += temp;
		}
		if(sum/2 > 0)
		{
			temp = sum/2;
			sum -= 2*temp;
			br[1] += temp;
		}
		else
		{
			br[0] += sum;
		}

	 
	 for(i = 0; i < 4; i++)
	 {
	 	res += br[i];
	 }
	 
	 cout<< res;
return 0;
}
