#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t,n,i,j,k,b,u;
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		vector<vector<int> >x;
		vector<vector<int> >y;
		vector<vector<int> >temp;
		x.clear();y.clear();temp.clear();
		for(i=0;i<n;i++)
		{
			vector<int>gh;gh.clear();
			for(j=0;j<n;j++)
			{
				scanf("%d",&u);
				gh.push_back(u);
			}
			x.push_back(gh);
		}
		for(i=0;i<n;i++)
		{
			vector<int>gh;gh.clear();
			for(j=0;j<n;j++)
			{
				scanf("%d",&u);
				gh.push_back(u);
			}
			y.push_back(gh);
		}
		queue<vector<vector<int> > >a;
		while(!a.empty())a.pop();
		stack<vector<vector<int> > >s;
		while(!s.empty())s.pop();
		map<vector<vector<int> >,vector<vector<int> > >par;
		map<vector<vector<int> >,bool>visit;
		map<vector<vector<int> >,int>mark;
		a.push(x);
		vector<vector<int> >tull(n,vector<int>(n));tull.clear();
		par[x]=tull;
		visit[x]=true;
		//int c=1;
		mark[x]=0;
		while(!a.empty())
		{
			temp=a.front();
			a.pop();
			if(temp==y)
			{
				while(temp != tull)
				{
					s.push(temp);
					temp=par[temp];
				}
				while(!s.empty())
				{
					vector<vector<int> >temp1(n,vector<int>(n));
					temp1=s.top();
					s.pop();
					for(i=0;i<n;i++)
						for(j=0;j<n;j++)
							printf("%d ",temp1[i][j]);
					printf("\n");
				}
				break;
			}
			for(i=0;i<n;i++)
			{
				vector<vector<int> >temp2(n,vector<int>(n));
				for(b=1;b<=n-1;b++)
				{
					temp2=temp;
					rotate(temp2[i].begin(),temp2[i].end()-b,temp2[i].end());
					if(mark[temp]%2==1)
						temp2[0][0]=0;
					if(visit.find(temp2)==visit.end())
					{
						par[temp2]=temp;
						mark[temp2]=mark[temp]+1;
						a.push(temp2);
						visit[temp2]=true;
					}
				}
			}
			for(i=0;i<n;i++)
			{
				vector<vector<int> >temp2(n,vector<int>(n));
				vector<int>arr(n);
				for(b=1;b<=n-1;b++)
				{
					temp2=temp;
					for(j=0;j<n;j++)
						arr[j]=temp2[j][i];
					rotate(arr.begin(),arr.end()-b,arr.end());
					for(j=0;j<n;j++)
						temp2[j][i]=arr[j];
					if(mark[temp]%2==1)
						temp2[0][0]=0;
					if(visit.find(temp2)==visit.end())
					{
						par[temp2]=temp;
						mark[temp2]=mark[temp]+1;
						a.push(temp2);
						visit[temp2]=true;
					}
				}
			}
			//c++;
		}
	}
	return 0;
}
