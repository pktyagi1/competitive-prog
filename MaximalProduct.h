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
ll dp[110][25];
class MaximalProduct {

	public:

	long long getMax(int s,int k)
	{
		if(s==0 && k==0)
			return 1LL;
		else if(s!=0 && k==0)
			return 0LL;
		else if(s==0 && k>0)
			return 0LL;
		else if(dp[s][k]!=-1)
			return dp[s][k];
		else
		{
		long long maxi=-1;
			FOR(i,1,101)
		{
			if(s>=i)
				maxi=max(maxi,i*getMax(s-i,k-1));
		}
			dp[s][k]=maxi;
			return maxi;
		}


	}
	long long maximalProduct(int s, int k) {

		memset(dp,-1,sizeof(dp));
		printf("%lld",getMax(s,k));
		return getMax(s,k);
	}

};
