#include <algorithm>
#include <iostream>
#include <map>
#include <stdio.h>
#include <numeric>
#include <set>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

#define FOR(i,s,e) for (int i = int(s); i != int(e); i++)
#define FORIT(i,c) for (typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)
#define ISEQ(c) (c).begin(), (c).end()

class CeyKaps {

	public: string decipher(string typed, vector<string> switches) {
		string result="";

		FOR(i,0,typed.length())
		{
			char c=typed[i];

			FOR(j,0,switches.size())
		{
          if(c==switches[j][0])
        	  {	printf("%c switches to %c\n",c,switches[j][2]);
        	  c=switches[j][2];}
          else if (c==switches[j][2]) {
        	  printf("%c switches to %c\n",c,switches[j][0]);
			c=switches[j][0];
		}
		}
			printf("Next character start\n");
         result+=c;
		}

		return result;
	}

};
