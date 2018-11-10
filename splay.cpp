#include<bits/stdc++.h>
using namespace std;
struct Node{
	Node *l;
	Node *r;
	Node *p;
	int v;
};
Node *root=NULL;
void rightRotate(Node *P)
{
	Node *T=P->l;
	Node *B=T->r;
	Node *D=P->p;
	if(D)
	{
		if(D->r==P) D->r=T;
		else D->l=T;
	}
	if(B)
		B->p=P;
	T->p=D;
	T->r=P;
	
	P->p=T;
	P->l=B;
}
void leftRotate(Node *P)
{
	Node *T=P->r;
	Node *B=T->l;
	Node *D=P->p;
	if(D)
	{
		if(D->r==P) D->r=T;
		else D->l=T;
	}
	if(B)
		B->p=P;
	T->p=D;
	T->l=P;
	
	P->p=T;
	P->r=B;
}

void Splay(Node *T)
{
	while(true)
	{
		Node *p=T->p;
		if(!p) break;
		Node *pp=p->p;
		if(!pp)//Zig
		{
			if(p->l==T)
				rightRotate(p);
			else
				leftRotate(p);
			break;
		}
		if(pp->l==p)
		{
			if(p->l==T)
			{//ZigZig
				rightRotate(pp);
				rightRotate(p);
			}
			else
			{//ZigZag
				leftRotate(p);
				rightRotate(pp);
			}
		}
		else
		{
			if(p->l==T)
			{//ZigZag
				rightRotate(p);
				leftRotate(pp);
			}
			else
			{//ZigZig
				leftRotate(pp);
				leftRotate(p);
			}
		}
	}
	root=T;
}
void Insert(int v)
{
	if(!root)
	{
		root=(Node *)malloc(sizeof(Node));
		root->l=NULL;
		root->r=NULL;
		root->p=NULL;
		root->v=v;
		return;
	}
	Node *P=root;
	while(true)
	{
		if(v < (P->v) )
		{
			if(P->l) 
				P=P->l;
			else
			{
				P->l=(Node *)malloc(sizeof(Node));
				P->l->p=P;
				P->l->r=NULL;
				P->l->l=NULL;
				P->l->v=v;
				P=P->l;
				break;
			}
		}
		else
		{
			if(P->r) 
				P=P->r;
			else
			{
				P->r=(Node *)malloc(sizeof(Node));
				P->r->p=P;
				P->r->r=NULL;
				P->r->l=NULL;
				P->r->v=v;
				P=P->r;
				break;
			}
		}
	}
	Splay(P);
}
void Inorder(Node *R)
{
	if(!R) return;
	Inorder(R->l);
	printf("%d ",R->v);
	if(R->l) printf("l: %d ",R->l->v);
	if(R->r) printf("r: %d ",R->r->v);
	Inorder(R->r);
}
Node* Find(int v)
{
	if(!root) return NULL;
	Node *P=root;
	while(P)
	{
		if(P->v==v)
			break;
		if(v<(P->v))
		{
			if(P->l)
				P=P->l;
			else
				break;
		}
		else
		{
			if(P->r)
				P=P->r;
			else
				break;
		}
	}
	Splay(P);
	if(P->v==v) return P;
	else return NULL;
}
bool Erase(int v)
{
	Node *N=Find(v);
	if(!N) return false;
	 Splay(N);
	
	 Node *P=N->l;
	
	if(!P)
	{
		root=N->r;
		root->p=NULL;
		free(N);
		return true;
	}
	while(P->r) P=P->r;
	if(N->r)
	{
		P->r=N->r;
		N->r->p=P;
	}
	root=N->l;
	root->p=NULL;
	free(N);
	return true;
}
int main()
{
	//vector<int> v;
	//for(int i=1;i<=100000;i++)
	//	v.push_back(i);
	//random_shuffle(v.begin(),v.end());
	// clock_t a=clock();
	// for(auto rr=v.begin();rr!=v.end();rr++)
	//  Insert(*rr);
	// clock_t b=clock();
	// cout<<"------------"<<1000*(double)(b-a)/CLOCKS_PER_SEC<<"-----------";
	while(1)
	{
		cout<<"1.insert"<<endl;
		cout<<"2.search"<<endl;
		cout<<"3.delete"<<endl;
		cout<<"4.display"<<endl;
		cout<<"5.exit"<<endl;
		int choice;
		cin>>choice;
		if(choice==1)
		{
			int val;
			cout<<"enter value to be inserted:";
			cin>>val;
			
				Insert(val);
			cout<<"value inserted into the tree"<<endl;
		}
		else if(choice==2)
		{
			int val;
			cout<<"enter value to be searched:";
			cin>>val;
			if(!Find(val))
				cout<<"value is not present in the tree"<<endl;
			else
			cout<<"value is found in the tree"<<endl;
		}
			else if(choice==3)
		{
			int val;
			cout<<"enter value to be deleted:";
			cin>>val;
			if(Erase(val))
				cout<<"value deleted"<<endl;
			else
			cout<<"value is not in the tree"<<endl;
		}
		else if(choice==4)
		{
			if(root) 
			printf("root: %d\n",root->v);
	 	Inorder(root);
	 	cout<<endl;
		}
		else if(choice==5)
			break;
		else
			cout<<"enter valid input"<<endl;
	}

	}
