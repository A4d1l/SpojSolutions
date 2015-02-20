
#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,N) for(int i=a;i<N;++i)
typedef long long ll;
#define SIZE 11

struct Node{
	bool isEnd;
	Node *childs[SIZE];
}*Root;

Node* GetNode(){
	Node* node=new Node;
	node->isEnd=false;
	rep(i,0,SIZE)
		node->childs[i]=NULL;
	return node;
};

void Init(){
	Root=GetNode();
}

bool Insert( string str){
	Node *node=Root;
	bool flag=false;
	rep(i,0,str.size()) {
		if(!(node->childs[str[i]-'0'])){
			flag=true;
			node->childs[str[i]-'0']=GetNode();
		}
		node=node->childs[str[i]-'0'];
		if(!flag && node->isEnd)//reached on a leaf node without creating any new node
			return false;
		
	}
	node->isEnd=true;
	if(!flag)//did not create any new node
		return false;
	return true;
}

void Free(Node* node){
	if(!node)
		return;
	rep(i,0,SIZE)
		if(!node->childs[i])
			Free(node->childs[i]);
	free(node);
}
int main(){
	int T,N;
	vector<string> str;
	bool myflag;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&N);
		str.resize(N);
		myflag=true;
		Free(Root);
		Init();
		rep(i,0,N)
			cin>>str[i];
		rep(i,0,N)
				myflag = myflag && Insert(str[i]);
			
		if(myflag)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}