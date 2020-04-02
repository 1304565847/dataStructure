#include<iostream>
#include<cstring>
using namespace std;

template <class T>
class stack{
private: 
    int size = 0;
    T data[30];
public:
    bool empty(){
        return not size;
    }
    T pop(){
        if (size){
            size--;
        }
        return data[size];
    }
    void push(T d){
        if (size < 30){
            data[size] = d;
            size++;
        }
    }
};

void delLast(char*);
char* reverse(char*);

int main(){
    char str[30];
    cin >> str;
    delLast(str);
    char *res = new char[strlen(str)];
    res = reverse(str);
    if (strcmp(str, res)){
        cout << "false";
    }    
    else{
        cout << "true";
    }
    return 0;
}

void delLast(char *str){
    str[strlen(str) - 1] = '\0';
}

char* reverse(char *str){
    stack<char> s;
    char *res = new char[strlen(str)];
    strcpy(res, str);
    for (int i = 0; str[i] != '\0'; ++i){
        s.push(str[i]);
    }
    int i = 0;
    while(not s.empty()){
        res[i] = s.pop();
        i++;
    }
    return res;
}