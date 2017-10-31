#include <bits/stdc++.h>
using namespace std;
#define  ll long long
#define pb push_back
#define fs first
#define sc second
#define P pair<int,int>
#define ppp pair<pp,pp>
#define mod 1000000009
#define fast_io ios::sync_with_stdio(false);cin.tie(NULL)
int main()
{
	/*fast_io;
	if(fopen("input.txt", "r"))
	{
		freopen("input.txt", "r", stdin);
		freopen("output.txt","w",stdout);
	}*/
	int t;
	cin>>t;
	int sz = t; 
	while(t--){
		int n , m , x1,y1 , len , i , j ,ans  ;
		int a[100][100] , vis[100][100]; 
		memset(vis,0,sizeof(vis) ) ;  
		map< int , string > mp , mp1; 
		cin>>n>>m;
		cin>>x1>>y1>>len ; 
		mp[1]="udlr";
		mp[2] = "ud";
		mp[3] = "lr" ;
		mp[4] = "ru" ;
		mp[5] = "rd" ;
		mp[6] = "ld" ;
		mp[7] = "ul" ;
		mp1 = mp ; 
		mp1[4] ="ur";
		mp1[5] = "dr";
		mp1[6] = "ld";
		mp1[7] = "lu";
		for(i = 0 ; i < n ; i++){
			for(j = 0 ; j< m ;j++){
				cin>>a[i][j] ; 
			}
		}

		queue< pair< P ,int > > q ; 
		q.push({{x1,y1}, len}) ;
		vis[x1][y1] = 1; 
		ans = 1; 
		while(!q.empty()){
			P  p  = q.front().fs ; 
			// int y = q.front().fs.sc ; 
			int dis = q.front().sc ;
			q.pop() ;
			int x,y ; 
			if(a[p.fs][p.sc] == 0 || dis == 0 ) continue; 
			string s = mp[a[p.fs][p.sc]] ;
			
			for(i = 0 ; i< s.size() ; i++){
				if(s[i] == 'u'){
					x = p.fs -1 ; 
					y = p.sc ;  

				}
				else if(s[i] == 'd'){
					x = p.fs + 1 ; 
					y = p.sc ; 
				}
				else if(s[i] =='l'){
					x = p.fs ; 
					y = p.sc - 1 ; 
				}
				else if(s[i] == 'r'){
					x = p.fs ; 
					y = p.sc + 1 ; 
				}
				else if(s[i] == 'w'){
					x = p.fs - 1 ; 
					y = p.sc + 1 ; 
				}
				else if(s[i] == 'x'){
					x = p.fs + 1;
					y = p.sc + 1 ;
				}
				else if(s[i] == 'y'){
					x = p.fs + 1 ;
					y = p.sc  - 1 ; 
				}
				else{
					x = p.fs - 1 ;
					y = p.sc - 1 ; 
				}
				if( x >= 0 && y >=0 && x <n && y <m && a[x][y] != 0 &&  vis[x][y] == 0 && dis > 1 ){

					string s1 = mp1[a[x][y]] ;
					int x1 ,y1 ; 
					int flag = 0 ; 
					P p1 = make_pair(x,y) ;  
					for(int i  = 0 ; i < s1.size();i++){
							if(s1[i] == 'u'){
								x1 = p1.fs -1 ; 
								y1 = p1.sc ;  

							}
							else if(s1[i] == 'd'){
								x1 = p1.fs + 1 ; 
								y1 = p1.sc ; 
							}
							else if(s1[i] =='l'){
								x1 = p1.fs ; 
								y1 = p1.sc - 1 ; 
							}
							else if(s1[i] == 'r'){
								x1 = p1.fs ; 
								y1 = p1.sc + 1 ; 
							}
							if(x1 == p.fs && y1 == p.sc ){
								flag = 1; 
								break ; 
							}
					}
					if(flag == 0  ) continue ; 
					vis[x][y] = 1 ; 
					ans++ ; 
					q.push({{x,y},dis-1}) ; 
				}
			} 


		}
		cout<<"#"<<sz-t<<" "<<ans<<"\n" ; 

	}
	return 0;
}
