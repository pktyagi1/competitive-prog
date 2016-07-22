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
vector<int> vec[56];
class AddElectricalWires {

	public:
	int vis[56],n,deg[56],deg1[56],edge[56];
	vector<string> Wires;
	void dfs(int i,int v)
	{
		if(vis[v])
			return;

			vis[v]=1;
            vec[i].push_back(v);
            FOR(j,0,n)
            {
            if(Wires[v][j]=='1'&& vis[j]==0)
            	dfs(i,j);
            }
		return;

	}
	int maxNewWires(vector<string> wires, vector<int> gridConnections) {
		memset(vis,0,sizeof(vis));
		memset(deg,0,sizeof(deg));
		memset(deg1,0,sizeof(deg1));
		memset(deg1,0,sizeof(edge));
		  FOR(i,0,56)
		        vec[i].clear();
		Wires=wires;
        int m=(int)gridConnections.size();
         n=wires.size();
        FOR(i,0,n)
        {
        	FOR(j,0,n)
		{
        		deg[i]+=(wires[i][j]-'0');
		}
        }

      FOR(i,0,m)
      {

    	  dfs(i,gridConnections[i]);
      }
      int nonvis=0;
      FOR(i,0,n)
      {
    	 if(!vis[i])
    		 nonvis++;

      }

      FOR(i,0,m)
      {
            FOR(j,0,vec[i].size())
            		deg1[i]+=deg[vec[i][j]];
      }
      FOR(i,0,m)
         deg1[i]/=2;
      int maxi=0;

      FOR(i,0,m)
      {
    	  int totedge=((vec[i].size()+nonvis)*(vec[i].size()+nonvis-1))/2;
    	  edge[i]=(totedge-deg1[i]);
      }
     FOR(i,1,m)
       if(edge[i]>edge[maxi])
    	   maxi=i;
int res=edge[maxi];
     FOR(i,0,m)
     {
  if(maxi!=i){
   	  int totedge=((vec[i].size())*(vec[i].size()-1))/2;
   	  res+=(totedge-deg1[i]);
  }
     }
     printf("%d\n",res);
		return res;
	}

};
