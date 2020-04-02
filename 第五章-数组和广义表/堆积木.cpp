#include<iostream>
#include<vector>
using namespace std;

class Block{
private:
    vector<int>* data;
    int size;
public:
    Block(){}
    // 初始化
    Block(int n){
        data = new vector<int>[n];
        size = n;
        for (int i = 0; i < n; ++i){
            data[i].push_back(i+1);
        }
    }
    // 移动
    void move(int a, int b){
        a--;b--;
        for (int i : data[b]){
            data[a].push_back(i);
        }
        vector<int>().swap(data[b]);

    }
    void print(){
        for (int i = 0; i < size; ++i){
            if(data[i].size()){
                for (int j : data[i]){
                    cout << j << " ";
                }
            }
            cout << endl;
        }
    }
};

int main(){
    int m, n, a, b;
    cin >> n >> m;
    Block bl(n);
    for (int i = 0; i < m; ++i){
        cin >> a >> b;
        if (a != b){
            bl.move(a, b);
        }
    }
    bl.print();
    return 0;
}
