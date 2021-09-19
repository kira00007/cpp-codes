#include<bits/stdc++.h>
#define ll long long

using namespace std;

struct Tree{
	int val;
	Tree* left=0;
	Tree* right=0;
};

Tree* root=0;

stack<Tree *> st;

void in(Tree* &u, int v){
	if(u){
		if(v<=u->val)
			in(u->left, v);
		else
			in(u->right, v);
	}
	else{
		Tree* node = new Tree;
		node->val=v;
		u=node;
	}
}

int srch(Tree* u, int v){
	if(u){
		if(u->val==v) return 1;
		else if(v<u->val) srch(u->left, v);
		else srch(u->right, v);
	}
	else
		return 0;
}

void mx_term(Tree* u){
	if(u){
		while(u->right)
			u=u->right;
		cout<<u->val<<endl;
		return;
	}
	cout<<"Tree is empty!\n";
}

void mn_term(Tree* u){
	if(u){
		while(u->left)
			u=u->left;
		cout<<u->val<<endl;
		return;
	}
	cout<<"Tree is empty!\n";
}

int ans=0;

void sumDepths(Tree* u, int dep){
	if(u){
		ans+=dep;

		if(u->left)
			sumDepths(u->left, dep+1);
		if(u->right)
			sumDepths(u->right, dep+1);
	}
}

int hi(Tree* u){
	if(u)
		return max(hi(u->left)+1, hi(u->right)+1);

	return -1;
}

void bfs(Tree* u){
	if(u){
		queue<Tree*> q;
		q.push(u);
		while(!(q.empty())){
			Tree *curr = q.front();
			cout<<curr->val<<" ";
			if(curr->left)
				q.push(curr->left);
			if(curr->right)
				q.push(curr->right);
			q.pop();
		}
	}
}

void ino(Tree *u){
	if(u){
		if(u->left)
			ino(u->left);

		cout<<u->val<<" ";

		if(u->right)
			ino(u->right);
	}
}

void pre(Tree *u){
	if(u){

		cout<<u->val<<" ";

		if(u->left)
			pre(u->left);
		if(u->right)
			pre(u->right);
	}
}

void post(Tree* u){
	if(u){
		if(u->left)
			post(u->left);
		if(u->right)
			post(u->right);
		cout<<u->val<<" ";
	}
}

bool isBinarySearchTree(Tree *u){
	if(u){
		if(u->left&&u->right){
			return (u->val>=u->left->val && u->val<=u->right->val && isBinarySearchTree(u->left)&&isBinarySearchTree(u->right));
		}
		else if(u->left&&!(u->right))
			return (u->val>=u->left->val && isBinarySearchTree(u->left));
		else if(!(u->left)&&u->right)
			return (u->val<=u->right->val && isBinarySearchTree(u->right));
		else
			return true;
	}
	else return true;
}

Tree* delElement(Tree* u, int value){
	if(u){
		if(value<u->val) u->left = delElement(u->left, value);
		else if(value>u->val) u->right = delElement(u->right, value);
		else{
			if(!(u->left)&&!(u->right)){
				delete u;
				return 0;
			}
			else if(!(u->left)){
				Tree* temp = u->right;
				delete u;
				return temp;
			}
			else if(!(u->right)){
				Tree* temp = u->left;
				delete u;
				return temp;
			}
			else{
				Tree* temp = u->right;
				while(temp->left){
					temp = temp->left;
				}
				u->val = temp->val;
				u->right = delElement(u->right, u->val);
			}
		}
	}
	else
		cout<<"element not found!\n";
}

void inorderSuccessor(Tree* u, int data){
	if(u){
		if(u->val==data){
			if(u->right){
				Tree* temp = u->right;
				while(temp->left)
					temp = temp->left;
				cout<<temp->val<<"\n";
			}
			else{
				if(st.empty()) cout<<"NULL"<<"\n";
				else{
					Tree* temp = st.top();
					cout<<temp->val<<"\n";
				}
			}
		}
		else if(data > u->val)
			inorderSuccessor(u->right, data);
		else{
			st.push(u);
			inorderSuccessor(u->left, data);
		}
	}
}

void clearStack(stack<Tree *> stk){
	while(!stk.empty()) stk.pop();
}

int main(){
	//ios::sync_with_stdio(0);
	//cin.tie(0);
	in(root, 50);
	in(root, 25);
	in(root, 15);
	in(root, 35);
	in(root, 75);
	in(root, 85);
	in(root, 65);

	while(1){
		cout<<"1. Insert\n2. Search\n3. Max Term\n"
			<<"4. Min Term\n5. height\n6. SumOfDepths\n7. BFS\n"
			<<"8. Inorder Traversal\n9. Preorder Traversal\n"
			<<"10. Postorder Traversal\n11. isBinarySearchTree?\n12. Delete Element\n13. Inorder Successor\n";
		int choice;
		cin>>choice;
		switch(choice){
			case 1:
				int v;
				cout<<"enter value: ";
				cin>>v;
				in(root, v);
				break;
			case 2:
				int q;
				cout<<"enter value: ";
				cin>>q;
				cout<<srch(root, q)<<endl;
				break;
			case 3:
				mx_term(root);
				break;
			case 4:
				mn_term(root);
				break;
			case 5:
				cout<<hi(root)<<endl;
				break;
			case 6:
				sumDepths(root, 0);
				cout<<"sum of depths: "<<ans<<endl;
				break;
			case 7:
				bfs(root);
				cout<<"\n";
				break;
			case 8:
				ino(root);
				cout<<"\n";
				break;
			case 9:
				pre(root);
				cout<<"\n";
				break;
			case 10:
				post(root);
				cout<<"\n";
				break;
			case 11:
				cout<<isBinarySearchTree(root)<<"\n";
				break;
			case 12:
				int b;
				cout<<"enter value: ";
				cin>>b;
				delElement(root, b);
				break;
			case 13:
				int data;
				cout<<"enter value: ";
				cin>>data;
				inorderSuccessor(root, data);
				clearStack(st);
				break;
			default:
				return 0;
		}
	}
	return 0;
}
