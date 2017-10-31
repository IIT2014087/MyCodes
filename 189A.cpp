#include<bits/stdc++.h>
#include <cstdio>//fill copy
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
	int n,b[3];
	vi a(3);
	cin>>n>>a[0]>>a[1]>>a[2];
	sort(a.begin(), a.end());
	vi m(n+1,INT_MIN);
	m[0]=0;
	// m[a[0]]=m[a[1]]=m[a[2]]=1;
	int ans=0;
	for(int i=1;i<=n;i++){
		for(int j=0;j<3;j++){
			if(i<a[j])
				break;
			m[i]=max(m[i-a[j]]+1,m[i]);
		}
	}
	cout<<m[n];
	return 0;
}
