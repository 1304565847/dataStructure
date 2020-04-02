#include<iostream>
using namespace std;

class MagicMatrix{
private:
    int** data;
    int row, col; // 行数、列数
    int *rows, *cols;   // 用标记交换，而不是真正交换行列
public:
    MagicMatrix(){}
    MagicMatrix(int n, int m){
        // 创建矩阵，大小：n行m列
        data = new int*[n];
        for (int i = 0; i < n; ++i){
            data[i] = new int[m];
        }
        rows = new int[n];
        cols = new int[m];
        for (int i = 0; i < n; ++i){
            rows[i] = i;
        }
        for (int i = 0; i < m; ++i){
            cols[i] = i;
        }
        row = n;
        col = m;
    }

    // 从标准输入流来初始化矩阵
    void init(){
        for (int i = 0; i < row; ++i){
            for (int j = 0; j < col; ++j){
                cin >> data[i][j];
            }
        }
    }

    // 从标准输出流输出矩阵
    void print(){
        int ii, jj;
        for (int i = 0; i < row; ++i){
            for (int j = 0; j < col; ++j){
                ii = rows[i];
                jj = cols[j];
                cout << data[ii][jj];
                if (j != col-1){
                    cout << " ";    // 输出数据之间的空格
                }
            }
            cout << endl;   // 输出行尾换行符
        }
    }

    // 交换列
    void exchangeCol(int y, int z){
        y--;z--;
        int temp;
        temp = cols[y];
        cols[y] = cols[z];
        cols[z] = temp;
    }

    // 交换行
    void exchangeRow(int y, int z){
        y--;z--;
        int temp = rows[y];
        rows[y] = rows[z];
        rows[z] = temp;
    }
};

int main(){
    int n, m, op, x, y, z;
    cin >> n >> m;
    MagicMatrix mm(n, m);
    mm.init();
    // mm.print();
    cin >> op;
    for (int i = 0; i < op; ++i){
        cin >> x >> y >> z;
        switch (x){
            case 0: mm.exchangeRow(y, z); break;
            case 1: mm.exchangeCol(y, z); break;
        }
    }
    mm.print();
    return 0;
}