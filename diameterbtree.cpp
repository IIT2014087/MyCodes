#include <bits/stdc++.h>
using namespace std;

typedef struct node{
	int data;
	struct node* left;
	struct node* right;
}node;

node * createnode(int data){
	node * p;
	p=new node;
	p->data=data;
	p->left=NULL;
	p->right=NULL;
	return p;
}

int depth(node * root){
	if(root==NULL)
		return 0;
	int ld=depth(root->left);
	int rd=depth(root->right);
	return max(ld+1,rd+1);
}

int main(){
	if(fopen("input.txt","r")){
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	}
	string str;
	int n;
	cin>>n;
	int rdata,j;
	cin>>rdata;
	node* root=new node;
	root->data=rdata;
	root->left=NULL;
	root->right=NULL;
	node * head=root;
	for (int i = 0; i < n; ++i)
	{
		root=head;
		cin>>str;
		cin>>rdata;
		for ( j = 0; j < str.size(); ++j)
		{
			if(str[j]=='L'){
				if(root->left==NULL)
					root->left=createnode(0);
				root=root->left;
			}
			else{
				if(root->right==NULL)
					root->right=createnode(0);
				root=root->right;
			}
		}
		root->data=rdata;
	}
	cout<<depth(head->left)+depth(head->right)+1<<endl;
	return 0;

}