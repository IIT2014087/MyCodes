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
	string n;
	int sum=0,count=0;
	cin>>n;
	while(n.size()!=1){
		for(int i=0;i<n.size();i++){
			sum+=n[i]-'0';
		}
		n=to_string(sum);
		sum=0;
		count++;
	}
	cout<<count;
	return 0;
}
