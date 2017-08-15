#include<bits/stdc++.h>
using namespace std;
void heapify(int a[],int i,int n)
{
	int left=i,right=i;
	if(i>=n)
	{
		return;
	}
	else{
		if(2*i+1<n)
{
			left=2*i+1;
			heapify(a,left,n);
}
		if(2*i+2<n)
{
	right=2*i+2;
			heapify(a,right,n);}

	if(a[left]>a[i])
		swap(a[left],a[i]);
	if(a[right]>a[i])
		swap(a[right],a[i]);

return;

	}

	}
