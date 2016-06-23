#include <algorithm>
#include <iostream>
#include <map>
#include <numeric>
#include <set>
#include <sstream>
#include <string>
#include <vector>
#include <stdio.h>
using namespace std;

#define FOR(i,s,e) for (int i = int(s); i != int(e); i++)
#define FORIT(i,c) for (typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)
#define ISEQ(c) (c).begin(), (c).end()

class BigBurger {

	public: int maxWait(vector<int> arrival, vector<int> service) {
		int maxt=0;
		int n=arrival.size();
        vector<int> wait(n,0);
		FOR(i,0,arrival.size())
		{
			if(maxt<arrival[i])
			{
maxt=arrival[i];
maxt+=service[i];
wait[i]=0;
			}
			else
			{
				wait[i]=maxt-arrival[i];
				maxt+=service[i];

			}
printf("%d ",wait[i]);

		}
int maxtime=*max_element(wait.begin(),wait.end());
printf("\n");
//cout << maxtime <<endl;
		return maxtime;
	}

};
