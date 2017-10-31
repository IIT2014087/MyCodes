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

void form(string s,string& mx,string &mn,int m){
	if(s.size()==1){
		if(m-mx.size()==1){
			mx.push_back(s[0]);
			mn.push_back(s[0]);
			return;
		}
		mn.push_back(s[0]-1);
		int n=mn.size();
		for(int i=0;i<m-n-1;i++){
			mn.push_back('0');	
		}
		mn.push_back('1');
		mx.push_back(s[0]);
		for(int i=0;i<m-n;i++){
			mx.push_back('0');	
		}
		return;
	}
	int N=stoi(s)/9;
	if(stoi(s)%9==0)
		N--;
	for(int i=1;i<=N;i++){
		mx.push_back('9');
		mn.push_back('9');
	}
}

int main(){
	if(fopen("input.txt","r")){
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	}
	int m;string s,s1;
	cin>>m>>s;
	s1=s;
	string mn,mx;
	int total=stoi(s);
	if((m>1 && s=="0") || total>m*9){
		cout<<"-1 -1";
		return 0;
	}
	while(mx.size()!=m){
		form(s,mx,mn,m);
		int sum=stoi(s)%9;
		if(sum==0)
			sum=9;
		s=to_string(sum);
	}
	for(int i=m-1;i>=0;i--){
		cout<<mn[i];
	}
	cout<<" "<<mx;
	return 0;
}
