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

class EquilibriumPoints {

	public:
	double force(double mass,double dis)
	{
		return (mass)/(dis*dis);
	}
	vector<double> getPoints(vector<int> x, vector<int> m) {
  int n=x.size();
  vector<double> dVector;
  FOR(i,0,n-1)
  {

	  double st=x[i];
	  double end=x[i+1];
	  double mid,f;
FOR(k,0,500){
	 mid=(st+end)/2;
	 f=0;
	  FOR(j,i+1,n){
		  f+=force(m[j],x[j]-mid);
	  }
	  FOR(j,0,i+1)
	  {
		  f-=force(m[j],mid-x[j]);
	  }
     if(f>0)
    	 end=mid;
     else
    	 st=mid;
}

dVector.push_back((st+end)/2);
  }

		return dVector;
	}

};
