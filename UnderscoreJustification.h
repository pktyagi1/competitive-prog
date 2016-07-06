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

class UnderscoreJustification {

	public: string justifyLine(vector<string> words, int width) {
		int strlt=0;
		int n=words.size();
		FOR(i,0,words.size())
		{
			strlt+=words[i].length();
		}
		int diff=width-strlt;
        int spacmin=diff/(n-1);
        int spacmax=diff%(n-1);
        int spaceminval=n-1-spacmax;
        string strres=words[0];
       FOR(i,1,n)
        {
            if((words[i][0]<'_' && spaceminval>0)||(spacmax==0))
            {
            	FOR(j,0,spacmin)
		{
            		strres+='_';
		}

            spaceminval--;
            }
            else{

            	FOR(j,0,spacmin+1)
            			strres+='_';
            	spacmax--;
            }
            strres+=words[i];

        }

		return strres;
	}

};
