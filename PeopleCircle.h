#include <algorithm>
#include <iostream>
#include <map>
#include <numeric>
#include <set>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

#define FOR(i,s,e) for (int i = int(s); i != int(e); i++)
#define FORIT(i,c) for (typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)
#define ISEQ(c) (c).begin(), (c).end()

class PeopleCircle {

	public: string order(int numMales, int numFemales, int K) {
         string result(numMales+numFemales,'M');
int pos=result.length()-1;
int size=result.length();
         FOR(i,0,numFemales)
         {

             for (int  j= 0;  j< K;) {


            	 pos=(pos+1)%size;
if(result[pos]=='M')
	  j++;
		}
result[pos]='F';
         }

		return result;
	}

};
