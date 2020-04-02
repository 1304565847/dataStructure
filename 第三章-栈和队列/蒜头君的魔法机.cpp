#include<iostream>
using namespace std;

template <class T>
class stack{
private: 
    int size = 0;
    T data[100];
public:
    bool empty(){
        return not size;
    }
    T top(){
        return data[size-1];
    }
    void pop(){
        if (size){
            size--;
        }
    }
    void push(T d){
        if (size < 99){
            data[size] = d;
            size++;
        }
    }
};

int main(){
    stack<int> magic;
    int temp[100] = {0};
    int n, t, it = 0;
    cin >> n;
    for (int i = 0; i < n; ++i){
        cin >> temp[i];
    }
    for (int i = 1; i <= n; ++i){
        magic.push(i);
        while(!magic.empty() && magic.top() == temp[it]){
            magic.pop();
            it += 1;
        }
    }
    if (magic.empty()){
        cout << "YES" << endl;
    }
    else{
        cout << "NO" << endl;
    }

}