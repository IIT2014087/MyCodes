#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t,n,i,j,k,kp,b,u;
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
		scanf("%d",&kp);
		//kp=kp;
		queue<vector<vector<int> > >a;
		while(!a.empty())a.pop();
		stack<vector<vector<int> > >s;
		while(!s.empty())s.pop();
		map<vector<vector<int> >,vector<vector<int> > >par;par.clear();
		map<vector<vector<int> >,bool>visit;visit.clear();
		a.push(x);
		vector<vector<int> >tull(n,vector<int>(n));tull.clear();
		par[x]=tull;
		visit[x]=true;
		while(!a.empty())
		{
			temp=a.front();
			a.pop();
			//int sum=0;
			//for(int df=0;df<n;df++)
			//	sum=sum+temp[0][df];
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
				temp2=temp;
				int flag=0;
				for(j=0;j<n;j++)
				{
					if(temp2[i][j]==kp)
					{
						flag=1;
						break;
					}
				}
				if(flag==0){
				for(b=1;b<=n;b++)
				{
					temp2=temp;
					rotate(temp2[i].begin(),temp2[i].end()-b,temp2[i].end());
					if(visit.find(temp2)==visit.end())
					{
						par[temp2]=temp;
						a.push(temp2);
						visit[temp2]=true;
					}
				}}
				else
				{
					temp2=temp;
					rotate(temp2[i].begin(),temp2[i].end()-1,temp2[i].end());
					if(visit.find(temp2)==visit.end())
					{
						par[temp2]=temp;
						a.push(temp2);
						visit[temp2]=true;
					}
					temp2=temp;
					rotate(temp2[i].begin(),temp2[i].end()-n+1,temp2[i].end());
					if(visit.find(temp2)==visit.end())
					{
						par[temp2]=temp;
						a.push(temp2);
						visit[temp2]=true;
					}
				}
			}
			for(i=0;i<n;i++)
			{
				vector<vector<int> >temp2(n,vector<int>(n));
				vector<int>arr(n);
				int flag=0;
				temp2=temp;
				for(j=0;j<n;j++)
				{
					if(temp2[j][i]==kp)
					{
						flag=1;
						break;
					}
				}
				if(flag==0){
				for(b=1;b<=n;b++)
				{
					temp2=temp;
					for(j=0;j<n;j++)
						arr[j]=temp2[j][i];
					rotate(arr.begin(),arr.end()-b,arr.end());
					for(j=0;j<n;j++)
						temp2[j][i]=arr[j];
					if(visit.find(temp2)==visit.end())
					{
						par[temp2]=temp;
						a.push(temp2);
						visit[temp2]=true;
					}
				}
				}
				else
				{
					temp2=temp;
					for(j=0;j<n;j++)
						arr[j]=temp2[j][i];
					rotate(arr.begin(),arr.end()-1,arr.end());
					for(j=0;j<n;j++)
						temp2[j][i]=arr[j];
					if(visit.find(temp2)==visit.end())
					{
						par[temp2]=temp;
						a.push(temp2);
						visit[temp2]=true;
					}
					temp2=temp;
					for(j=0;j<n;j++)
						arr[j]=temp2[j][i];
					rotate(arr.begin(),arr.end()-n+1,arr.end());
					for(j=0;j<n;j++)
						temp2[j][i]=arr[j];
					if(visit.find(temp2)==visit.end())
					{
						par[temp2]=temp;
						a.push(temp2);
						visit[temp2]=true;
					}
				}
			}
		}
	}
	return 0;
}
