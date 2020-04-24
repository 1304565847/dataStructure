#include<iostream>
#include<string>
#include<vector>
#include<queue>

using namespace std;

struct treeNode{
    char data;
    treeNode *leftChild, *rightChild;
};

treeNode* createBT(vector<string>);

void printBT(treeNode*);

int main(){
    vector<string> inputs;
    string cmd;
    treeNode *root;
    cin >> cmd;
    while (cmd[1] != '^'){
        inputs.push_back(cmd);
        cin >> cmd;
    }
    if (inputs.size()){
        root = createBT(inputs);
    }
    else{
        root = NULL;
    }
    printBT(root);
    return 0;
}


treeNode* createBT(vector<string>inputs){
    queue<treeNode*> BT;
    treeNode *root, *cr, *temp;
    root = new treeNode();
    root->data = inputs[0][1];
    cr = root;
    BT.push(cr);
    for (string cmd : inputs){
        // 跳过根节点
        if (cmd[0] == '^'){
            continue;
        }
        // 匹配当前节点
        while (cr->data != cmd[0] && !BT.empty()){
            // 从队列中去下一个
            cr = BT.front(); BT.pop();
        }
        temp = new treeNode();
        temp->data = cmd[1];
        BT.push(temp);
        // 匹配左右节点
        if (cmd[2] == 'L'){
            cr->leftChild = temp;
        }
        else{
            cr->rightChild = temp;
        }
    }
    return root;
}

void printBT(treeNode* root){
    if (root != NULL){
        cout << root->data;
        // 存在左子数或者右子树
        if (root->leftChild || root->rightChild){
            cout << "(";
            // 输出左子树
            if (root->leftChild){
                printBT(root->leftChild);
            }
            // 输出右子树
            if (root->rightChild){
                cout << ",";
                printBT(root->rightChild);
            }
            cout << ")";
        }
    }
}