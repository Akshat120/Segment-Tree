#include<bits/stdc++.h>
using namespace std;
// maxSize of Segment
int N = 1e5 + 5;
// Segemnt Vector
vector<int> S( 4 * N - 1 ,-1);
// Build Segment Tree
void segmentTree(int arr[],int v,int L,int R)
{
	if(L>R) return;
	S[v] = accumulate(arr+L,arr+R+1,0);
	if(L==R) return;
	int M = L + (R-L)/2;
	segmentTree(arr,2*v+1,L,M);
	segmentTree(arr,2*v+2,M+1,R);
}
// query processor
int getSum(int ql,int qr,int l,int r,int v)
{
	if(ql>r || qr<l) return 0;
	if(ql<=l&&qr>=r) return S[v];
	int m = l + (r-l)/2;
	int ans = getSum(ql,qr,l,m,2*v+1) + getSum(ql,qr,m+1,r,2*v+2);
	return ans;
}
// update processor
void update(int v,int l,int r,int id,int val)
{
	if(id<l || id>r) return;
	if(id==l&&id==r) {
	 S[v]=val;	
	 return;
	}
	int m = l + (r-l)/2;
	update(2*v+1,l,m,id,val);
	update(2*v+2,m+1,r,id,val);
	S[v] = S[2*v+1]+S[2*v+2];
}
int main()
{
	int arr[]={5,3,8,2,9,1};          // Change if u like 
	
	int n=sizeof(arr)/sizeof(int);	  // do not change
	
	segmentTree(arr,0,0,n-1);  // Segment builder
	
	while(true)
	{
		cout<<"1.getSum\n";
		cout<<"2.update\n";
		cout<<"Enter 1 or 2 : ";
		int c;
		cin>>c;
		switch(c)
		{
			case 1: cout<<"Enter l,r : ";
					int l,r;
					cin>>l>>r;
					cout<<getSum(l,r,0,n-1,0)<<endl;
				break;
			case 2: cout<<"Enter id,val : ";
					int id,val;
					cin>>id>>val;
					update(0,0,n-1,id,val);
					cout<<"Segment Updated...\n";
				break;
		}
	}
	
}














