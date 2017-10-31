#include<bits/stdc++.h>
using namespace std;

bool win(vector<vector<char> > a){
	int X[]={-1,-1,0,1,1,1,0,-1};
	int Y[]={0,1,1,1,0,-1,-1,-1};
	for(int i=0;i<4;i++){
		for(int j=0;j<4;j++){
			for(int k=0;k<8;k++){
				int a1=i+X[k];int x=i-X[k];
				int b=j+Y[k];int y=j-Y[k];
				if(a1>=0 && b>=0 && a1<4 && b<4 && x>=0 && y>=0 && x<4 && y<4){
					if(a[a1][b]+a[i][j]+a[x][y]==286)
						return true;
				}
			}
		}
	}
	return false;
}

int main(){
	vector<vector<char> > a(4,vector<char>(4));
	for(int i=0;i<4;i++){
		for(int j=0;j<4;j++)
			cin>>a[i][j];
	}
	if(win(a))
		cout<<"YES";
	else
		cout<<"NO";
}
