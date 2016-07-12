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
int dp[30][55][55][55];
class RoughStrings {

	public:
	int count[27];
	int cal(int i,int maxi,int mini,int k)
	{
if(k<0) return 1000000000;
if(dp[i][maxi][mini][k]!=-1) return dp[i][maxi][mini][k];
if(i==26) return dp[i][maxi][mini][k]=maxi-mini;
int ret=1000000000;
FOR(tk,0,count[i]+1)
{
	if(tk==0)
       ret=min(ret,cal(i+1,maxi,mini,k-count[i]+tk));
	else
		ret=min(ret,cal(i+1,max(maxi,tk),min(mini,tk),k-count[i]+tk));
	}
     return dp[i][maxi][mini][k]=ret;
	}
	int minRoughness(string s, int n) {

		memset(count,0,sizeof(count));
		memset(dp,-1,sizeof(dp));
		FOR(i,0,s.size())
		{
++count[s[i]-'a'];
		}
//printf("%d",cal(0,0,50,n));
		return cal(0,0,50,n);
	}

};
