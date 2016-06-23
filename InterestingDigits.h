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

class InterestingDigits {

	public:
	vector<int> digits(int base) {
		vector<int> result;
		FOR(i,2,base)
		{
			int flag=1;
			for (int j = i; j < 1000; j+=i)


		{
				if(sumdig(j,base)%i!=0)
					{flag=0;
					break;
					}
		}
			if(flag==1)
				result.push_back(i);

		}
//sumdig(34,base);
		return result;
	}


int sumdig(int num,int b)
{
	int s=0;
while(num>0)
{
int dig=num%b;
num=num/b;
//printf("%d ",dig);
s+=dig;
	}
//printf("\n");
return s;
}

};
