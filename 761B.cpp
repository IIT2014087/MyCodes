#include<bits/stdc++.h>
#include <cstdio>//fill(a,a+n,0) copy(a,a+n,b) for array only
#include <algorithm>
using namespace std;
#define ll long long 
#define pr pair<ll,ll>
#define mp make_pair
#define vi vector<ll>
#define vvi vector<vector<ll> >
#define vp vector<pr >
#define X first
#define Y second

int main(){
	if(fopen("input.txt","r")){
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	}
	int n,L;
	cin>>n>>L;
	vector<int> a(n),b(n),c(n);
	for(int i=0;i<n;i++)
		cin>>a[i];
	for(int i=0;i<n;i++)
		cin>>b[i];
	int flag=0,cur;
	for(int i=0;i<n;i++){
		c[i]=abs(a[(i+1)%n]-a[i]);
		if(i==n-1)
			c[i]=abs(L-a[n-1]+a[0]);
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cur = (b[j] + c[(i+j)%n])%L;
			if(cur==b[(j+1)%n]){
				if(j==n-1){
					flag=1;
					break;
				}
			}
			else{
				flag=0;
				break;
			}
		}
		if(flag==1)
			break;
	}

	if(flag==1)
		cout<<"YES";
	else
		cout<<"NO";
	return 0;
}
