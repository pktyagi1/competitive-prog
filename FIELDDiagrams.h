#include <algorithm>
#include <iostream>
#include <map>
#include <numeric>
#include <set>
#include <sstream>
#include <string>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

#define FOR(i,s,e) for (int i = int(s); i != int(e); i++)
#define FORIT(i,c) for (typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)
#define ISEQ(c) (c).begin(), (c).end()
typedef long long ll;
class FIELDDiagrams {

	public:
	ll dp[55][55];
	int n;
	ll cal(int i,int k)
	{

   if(i==n)
	   return 1;
   else
   {
ll sum=0;
FOR(j,0,min(k,n-i)+1)
		{
	sum+=cal(i+1,j);
		}
return sum;
   }
	}
	long long countDiagrams(int fieldOrder) {
		n=fieldOrder;
		memset(dp,-1,sizeof(dp));
		cal(0,fieldOrder);
		return cal(0,fieldOrder)-1;
	}

};
