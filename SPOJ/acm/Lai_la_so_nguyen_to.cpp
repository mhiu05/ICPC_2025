#include <iostream>
#include <math.h>
using namespace std;
// chep code tu 2023 quen nguon =))
int ktnt(int a)
{
	if (a<2) return 0;
	else for (int i=2; i<=sqrt(a); i++) if (a%i==0) return 0;
	return 1;
}
 
int main ()
{
	int t;
	cin>>t;
	int n;
	for (int i=1; i<=t; i++)
	{
		cin>>n;
		int d=0;
		if (ktnt(n)==1) d++;
		int tg=0;
		for (int i=2; i<=n/2; i++)
		{
			tg=0;
			if (ktnt (i)==1)
			{
				for (int j=i; j<=n; j++)
				{
					if (ktnt(j)==1)
					{
						tg+=j;
						if (tg==n) d++;
						if (tg>n) break;
					}
				}
			}
		}
		cout<<d<<endl;
	}
	return 0;
}