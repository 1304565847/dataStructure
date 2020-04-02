#include<iostream>
#include<string>
using namespace std;

// 链表节点
template <class T>
struct linkNode{
    T data;
    linkNode* next;
};

template <class T>
class Queue{
private:
    int size = 0;
    linkNode<T>* dataHead;
    linkNode<T>* datafoot;
public:
    bool push(T); //往队列中插入元素
    T pop();      //弹出元素
    int getSize(){return size;}
    void fillTo10With0();
};



int main(){
    Queue<string> t0, t1, t2;
    int type;
    string num;
    for (int i = 0; i < 10; ++i){
        cin >> type >> num;
        switch (type){
            case 0: t0.push(num);break;
            case 1: t1.push(num);break;
            case 2: t2.push(num);break;
        }
    }
    t0.fillTo10With0();
    t1.fillTo10With0();
    t2.fillTo10With0();
    for (int i = 0; i < 10; ++i){
        cout << t0.pop() << " " << t1.pop() << " " << t2.pop() << endl;
    }
    return 0;
}

// 插入函数定义
template <class T>
bool Queue<T>::push(T data){
    // 队列最大长度设置为20
    if (size >= 20){
        return false;
    }
    else{
        linkNode<T>* node = new linkNode<T>();
        node->data = data;
        // 队列为空时的创建
        if (!size){
            dataHead = datafoot = node;
        }
        // 队列不为空时的创建
        else{
            datafoot->next = node;
            datafoot = node;
        }
        datafoot->next = NULL;
        size++;
        return true;
    }
}

template<class T>
T Queue<T>::pop(){
    linkNode<T> *temp = dataHead;
    // 队列为空时抛出错误
    if (size == 0){
        throw "queue is empty";
    }
    dataHead = dataHead->next;
    size--;
    // 置空
    if (!size){
        datafoot = NULL;
    }
    return temp->data;
}

template<class T>
void Queue<T>::fillTo10With0(){
    while(size < 10){
        push("0");
    }
}