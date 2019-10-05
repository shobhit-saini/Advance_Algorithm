#include<iostream>
#include<string.h>
using namespace std;
int main()
{
	string s1, s2;
	int i = 0, j = 0;
	
	////////////////////////////INPUT/////////////////////////////////////////////////////////////
	cout << "Enter the first string:";
	cin >> s1;
	cout << "Enter the second string:";
	cin >> s2;
	
	while(s1[i] != '\0' && s2[j] != '\0')
	{
		if(s1[i] == s2[j])
		{
			i++; 
		}
		j++;
	}

	if(i == strlen(s1.c_str()))
	  cout << "TRUE";
	 	else
	  		cout << "FALSE";
}
