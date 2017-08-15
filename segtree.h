#include <bits/stdc++.h>
#define INF 100000000
using namespace std;
int tree[15];
void initialize(int a[],int start,int end,int node)
{
if(start==end)
{
	tree[node]=a[start];
	}
else
{
	int mid=(start+end)/2;
initialize(a,start,mid,2*node+1);
initialize(a,mid+1,end,2*node+2);
tree[node]=min(tree[2*node+1],tree[2*node+2]);

}
}

int getMinRange(int startIdx,int endIdx,int start,int end,int node)
{

	if(endIdx<start)
		return INF;
	else if(startIdx>=start and endIdx<=end)
		return tree[node];
	else{
		int mid=(start+end)/2;
		return min(getMinRange(startIdx,endIdx,start,mid,2*node+1),getMinRange(startIdx,endIdx,mid+1,end,2*node+2));
	}
}

void update(int idx,int start,int end,int node,int a[],int val)
{

	if(start==end and idx==end)
	{
        a[node]=val;
		tree[node]=val;

	}
	else {
		int mid=(start+end)/2;
		if (idx>=start and idx<=mid)
		{
			update(idx,start,mid,2*node+1,a,val);
		}
		else if(idx>=mid+1 and idx<=end)
		{
			update(idx,mid+1,end,2*node+2,a,val);
		}
	tree[node]=min(tree[2*node+1],tree[2*node+2]);
	}
}


