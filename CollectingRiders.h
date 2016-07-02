#include <algorithm>
#include <iostream>
#include <queue>
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

class CollectingRiders {

	public:
int vis[11][11], dis[11][11][11][11];


int minimalMoves(vector<string> board) {
	int dx[]={1,1,-1,-1,2,2,-2,-2};
	int dy[]={2,-2,2,-2,1,-1,1,-1};
FOR(i,0,11)
{
FOR(j,0,11)
		{

	FOR(k,0,11)
	{
		FOR(l,0,11)
			{
			dis[i][j][k][l]=100000000;
			}
	}
	dis[i][j][i][j]=0;
		}
}
int n=board.size();
int m=board[0].size();
FOR(i,0,n)
{
	FOR(j,0,m)
		{
          FOR(k,0,8)
		{
        	  if(i+dx[k]<n && i+dx[k]>=0 && j+dy[k]<m && j+dy[k]>=0)
        	  {dis[i][j][i+dx[k]][j+dy[k]]=1;
        	  }
		}
		}
	}

FOR(k,0,n)
{
FOR(k1,0,m)
		{
	FOR(i,0,n)
		{
		FOR(i1,0,m)
		{
			FOR(j,0,n)
		{
				FOR(j1,0,m)
		{
dis[i][i1][j][j1]=min(dis[i][i1][j][j1],dis[i][i1][k][k1]+dis[k][k1][j][j1]);
		}
		}
		}
		}
		}
}
int ttime=100000000;
FOR(i,0,n)
{
FOR(j,0,m)
		{
	int curtime=0;
	FOR(k,0,n)
		{
		FOR(l,0,m)
		{
  if(board[k][l]!='.')
  {
	  curtime+=ceil(((dis[i][j][k][l]*1.0)/(board[k][l]-'0')));
  }


		}
		}
	ttime=min(ttime,curtime);

		}
}

if(ttime>=10000000)
	return -1;

		return ttime;
	}

};
