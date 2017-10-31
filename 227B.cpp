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
	long long int n;
	cin>>n;
	vector<pair<long long int,long long int> > a(n);
	for(long long int i=0;i<n;i++){
		long long int z;
		cin>>z;
		a[i]=make_pair(z,i);
	}
	sort(a.begin(), a.end());
	long long int m;
	cin>>m;
	long long int petya=0,vasya=0;
	while(m--){
		long long int x;
		cin>>x;
		vasya+=1+a[x-1].second;
		petya+=n-a[x-1].second;
	}
	cout<<vasya<<" "<<petya;
	return 0;
}
