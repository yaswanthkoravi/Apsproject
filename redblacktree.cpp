#include<bits/stdc++.h>
using namespace std;

typedef struct tree{
	struct tree* left;
	struct tree* right;
	struct tree* parent;
	int info;
	char color;
}node;

void left_rotate(node* &root , node* x , node* &neel){
	node* y=x->right;
	x->right = y->left;
	
	if(y->left!=neel)
		y->left->parent = x;
	y->parent=x->parent;    
	
	if(x->parent==neel)
	   root = y;
	else if(x==x->parent->left)
		x->parent->left = y;
	else
		x->parent->right = y;	
			
	y->left = x;
	x->parent = y;
}

void right_rotate(node* &root , node* y , node* &neel){	
	node* x = y->left;  
	y->left = x->right;
	
	if(x->right!=neel)
	   x->right->parent = y; 
	x->parent = y->parent;
	
	if(y->parent==neel)
		root = x;
	else if(y==y->parent->left)
		y->parent->left = x;
	else
	    y->parent->right = x;	
	    
	x->right = y;
	y->parent = x; 	   
}

void insert_fixup(node* &root , node* z , node* &neel){
	while(z->parent->color=='r'){
		
		if(z->parent==z->parent->parent->left){
			node* y=z->parent->parent->right;
			if(y->color=='r'){
				z->parent->color='b';
				y->color='b';
				z->parent->parent->color='r';
				z=z->parent->parent;
			}
			else if(z==z->parent->right){
				z=z->parent;
				left_rotate(root,z,neel);
			
			    z->parent->color='b';
			    z->parent->parent->color='r';
			    right_rotate(root,z->parent->parent,neel);
	        }
	       else{
	       	    z->parent->color='b';
			    z->parent->parent->color='r';
			    right_rotate(root,z->parent->parent,neel);
		     }
		}
		else{                                   
			node* y=z->parent->parent->left;
			if(y->color=='r'){
				z->parent->color='b';
				y->color='b';
				z->parent->parent->color='r';
				z=z->parent->parent;
			 }
			else if(z==z->parent->left){
				z=z->parent;
				right_rotate(root,z,neel);
			
		    	z->parent->color='b';
			    z->parent->parent->color='r';
			    left_rotate(root,z->parent->parent,neel);
	         }
		   else{
		   	   	z->parent->color='b';
			    z->parent->parent->color='r';
			    left_rotate(root,z->parent->parent,neel);
		     }   
		}
	}
	root->color='b';
}

void insert(node* &root , node* &z , node* &neel){
	node* y=neel;
	node* x=root;
	while(x!=neel){
		y=x;
		if(z->info < x->info)
		   x=x->left;
		else
		   x=x->right;   
	}
	z->parent=y;
	
	if(y==neel)
	  root=z;
	else if(z->info < y->info)
		y->left=z;
	else
		y->right=z;
		
	z->left=neel;
	z->right=neel;
	z->color='r';
	insert_fixup(root,z,neel);  		    
}

void transplant(node* &root , node* &u , node* &v , node* neel){
	if(u->parent==neel)
	   root=v;
	else if(u==u->parent->left)
	   u->parent->left=v;
	else
	   u->parent->right=v;
	v->parent=u->parent;         
}

void del_fixup(node* &root , node* x , node* &neel){
	while(x!=root && x->color=='b'){
		
		if(x==x->parent->left){
			node* w=x->parent->right;
			
			if(w->color=='r'){
				w->color='b';
				x->parent->color='r';
				left_rotate(root,x->parent,neel);
				w=x->parent->right;
			}
			if(w->left->color=='b' && w->right->color=='b'){
				w->color='r';
				x=x->parent;
			}
			else if(w->right->color=='b'){
				w->left->color='b';
				w->color='r';
				right_rotate(root,w,neel);
				w=x->parent->right;
				
			    w->color=x->parent->color;
			    x->parent->color='b';
			    w->right->color='b';
			    left_rotate(root,x->parent,neel);
			    x=root;
			}
			else{
				w->color=x->parent->color;
			    x->parent->color='b';
			    w->right->color='b';
			    left_rotate(root,x->parent,neel);
			    x=root;
			}
		}
		
		else{
			node* w=x->parent->left;
			
			if(w->color=='r'){
				w->color='b';
				x->parent->color='r';
				right_rotate(root,x->parent,neel);
				w=x->parent->left;
			}
			if(w->right->color=='b' && w->left->color=='b'){
				w->color='r';
				x=x->parent;
			}
			else if(w->left->color=='b'){
				w->right->color='b';
				w->color='r';
				left_rotate(root,w,neel);
				w=x->parent->left;
				
				w->color=x->parent->color;
				x->parent->color='b';
				w->left->color='b';
				right_rotate(root,x->parent,neel);
				x=root;
			}
			else{
				w->color=x->parent->color;
				x->parent->color='b';
				w->left->color='b';
				right_rotate(root,x->parent,neel);
				x=root;
			}
		}
	}
	x->color='b';
}

node* find_min(node* &root , node* neel){
   node* temp=root;
   	if(temp->left==neel)
   		return temp;
	else
		return find_min(temp->left,neel); 
}

void del(node* &root , node* &z , node* &neel){
	node* y=z;
	node* x;
	char y_original_color=y->color;
	
	if(z->left==neel){
		x=z->right;
		transplant(root,z,z->right,neel);
	}
	else if(z->right==neel){
		x=z->left;
		transplant(root,z,z->left,neel);
	}
	else{
		y=find_min(z->right,neel);
		y_original_color=y->color;
		x=y->right;
		
		if(y->parent==z){
			x->parent=y;
		}
		else{
			transplant(root,y,y->right,neel);
			y->right=z->right;
			y->right->parent=y;
		}
		
		transplant(root,z,y,neel);
		y->left=z->left;
		y->left->parent=y;
		y->color=z->color;
	}
	
	if(y_original_color=='b')
	    del_fixup(root,x,neel);
}

node* search(node* &root , int x , node* neel){
	node* temp=root;
	while(temp!=neel){
		if(temp->info == x)
			return temp;         
		else if(x < temp->info)
			temp=temp->left;
		else if(x > temp->info)
			temp=temp->right;
	}
		return NULL;
}

void inorder(node* &p , node* &neel){
   if(p!=neel){
      inorder(p->left,neel);
	  cout<<p->info<<","<<p->color<<"  ";
	  inorder(p->right,neel);
   }
}
   			
int main(){
    node* neel = new node;  
	neel->color='b';
	node* root = neel;
	// vector<int> v;
	// for(long long i=1;i<=100000;i++)
	// 	v.push_back(i);
	// random_shuffle(v.begin(),v.end());
	 while(1)
	{
	 	cout<<"\n1.insert\n2.delete\n3.search\n4.display\n5.exit"<<endl;
		int ch;
		cin>>ch;
		if(ch==1){
					int val;
					cout<<"enter value to be inserted:";
					cin>>val;
					if(search(root,val,neel))
					cout<<"value already found in the tree"<<endl;
					else
				{
					node* z=new node;	
       				z->left=neel;
       				z->right=neel;
       				z->parent=neel;
       				z->color='r';
       				z->info=val;
       				insert(root,z,neel);
       			}}
     				//clock_t b=clock();
	//cout<<"------------"<<1000*(double)(b-a)/CLOCKS_PER_SEC<<"-----------";
			else if(ch==2)
				{
					int val;
					cout<<"enter value to be deleted";
   				cin>>val;
    			node* temp=search(root,val,neel);
				del(root,temp,neel);
				}
			else if(ch==3)
			{
				int val;
				cout<<"enter value to be searched:";
				cin>>val;
				if(search(root,val,neel))
					cout<<"value found in the tree"<<endl;
					else
						cout<<"value not found in the tree"<<endl;
					
			}
			else if(ch==4)
			{
				inorder(root,neel);
			}
			else if(ch==5)
				break;
			else
				cout<<"enter valid input"<<endl;
		}

  return 0;
}