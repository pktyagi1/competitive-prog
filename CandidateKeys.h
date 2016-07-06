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

class CandidateKeys {

	public: vector<int> getKeys(vector<string> table) {
		int n=table.size();

		int m=table[0].size();
		int N=1<<m;
		int maxlen=-1;
		int minlen=100000;
		vector<bool> valid(N,true);
		FOR(i,1,N)
		{
		if(valid[i]){
			vector<string> entries(n);
			FOR(j,0,m)
			{
                     if((1<<j)&i)
                     {
                        FOR(k,0,n)
		{
                        entries[k].push_back(table[k][j]);
		}
                     }
			}
		set<string> keys;
		FOR(j,0,n)
		{
			keys.insert(entries[i]);
		}
		if(keys.size()!=entries.size())
			continue;
        maxlen=max(maxlen,(int)entries[0].size());
        minlen=min(minlen,(int)entries[0].size());
        FOR(j,i+1,N)
        {
        	if((i&j)==i)
        		valid[j]==false;
        }
		}
		}
     vector<int> ckeys;
     if(minlen>maxlen)
    	 return ckeys;
     ckeys.push_back(minlen);
     ckeys.push_back(maxlen);
		return ckeys;
	}

};
