#include<bits/stdc++.h>
using namespace std;

int main(){
	if(fopen("input.txt","r")){
		freopen("input.txt","r",stdin);
	}
	int n,start,d=1,ans;
	cin>>n>>start;
	vector<int> crime(n);
	for(int i=0;i<n;i++)
		cin>>crime[i];
	ans=crime[start-1];
	while(start+d-1<n || start-d-1>=0){
		int a=start-d-1;
		int b=start+d-1;
		if(a>=0 && b<n){
			if(crime[a]>0 && crime[b]>0)
				ans+=crime[a]+crime[b];
		}
		else if(a<0 && b<n){
			if(crime[b]>0)
				ans+=crime[b];	
		}
		else if(a>=0 && b>=n){
			if(crime[a]>0)
				ans+=crime[a];
		}
		d++;
	}
	cout<<ans;
	return 0;
}
