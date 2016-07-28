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

class TemplateMatching {

	public:
	int getVal(string s1,string s2)
	{
		for (int i = min(s1.length(),s2.length()); i >= 1; i--) {
	       if(s2.substr(0,i)==s1.substr(s1.length()-i))
	    	   return i;

		}
		return 0;

	}
	string bestMatch(string text, string prefix, string suffix) {
	int a=-1;
	int b=-1;
	string result="";
		FOR(i,0,text.length())
		{
			FOR(j,1,text.length()-i+1)
		{
             string str=text.substr(i,j);
             int a1=getVal(prefix,str);
             int b1=getVal(str,suffix);
             if((a1+b1>a+b)||(a1+b1==a+b && a1>a)||(a1+b1==a+b && a1==a && str<result))
             {
            	a=a1;
            	b=b1;
            	result=str;
             }
		}
		}


		return result;
	}

};
