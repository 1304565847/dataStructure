#include<iostream>
#include<string>
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

bool isPre(char op1, char op2){
    if ((op1 == '*' or op1 == '/') and (op2 == '+' or op2 == '-')){
        return true;
    }
    return false;
}

int main(){
    string str;
    stack<char> BL, back;
    string res = "";
    double a, b, temp;
    cin >> str;
    for (char i : str){
        if (i == '*' or i == '/' or i == '+' or i == '-'){
            if (BL.empty() or isPre(i, BL.top())){
                BL.push(i);
            }
            else{
                while (!BL.empty() and !isPre(i, BL.top())){
                    res += BL.top();
                    BL.pop();
                }
                BL.push(i);
            }
        }
        else{
            res += i;
        }
    }
    while (!BL.empty()){
        res += BL.top();
        BL.pop();
    }
    for (char i : res){
        if (i == '*' or i == '/' or i == '+' or i == '-'){
            b = back.top(); back.pop();
            a = back.top(); back.pop();
            switch (i){
                case '*': back.push(a * b); break;
                case '/': back.push(a / b); break;
                case '+': back.push(a + b); break;
                case '-': back.push(a - b); break;
            }
        }
        else{
            back.push(i - '0');
        }
    }
    temp = back.top();
    cout << temp << endl;
    return 0;
}