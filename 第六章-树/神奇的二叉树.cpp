#include<iostream>
#include<string>

using namespace std;

struct treeNode{
	char data;
	treeNode *leftChild, *rightChild;
};


treeNode* reConBT(string pre, string in){

	if (pre.length() <= 0 || in.length() <= 0){
		return NULL;
	}

	treeNode* node = new treeNode();
	node->data = pre[0];			// 先序遍历序列中的第一个是根节点

	for (int i = 0; i < in.length(); ++i){
		if (in[i] == pre[0]){
			// 重构左子树
			node->leftChild = reConBT(pre.substr(1, i), in.substr(0,i));
			// 重构右子树
			node->rightChild = reConBT(pre.substr(i+1, pre.length()), in.substr(i+1, in.length()));
		}
	}
	return node;
}

// 后续遍历二叉树
void lastVis(treeNode* bt){
	if (bt != NULL){
		lastVis(bt->leftChild);
		lastVis(bt->rightChild);
		cout << bt->data;
	}
}

// 交换左右节点
void exchange(treeNode* bt){
	if (bt != NULL){
		treeNode *temp = bt->leftChild;
		bt->leftChild = bt->rightChild;
		bt->rightChild = temp;
		exchange(bt->leftChild);
		exchange(bt->rightChild);
	}
}

int main(){
	string pre;
	string in;
	cin >> pre >> in;
	treeNode* root = reConBT(pre, in);
	lastVis(root);
	cout << endl;
	exchange(root);
	lastVis(root);
	return 0;
}