#include <iostream>
using namespace std;

typedef struct LNode{
    int data;
    struct LNode *next;
}LNode, *LinkList;

// 采用头插法建立单链表
LinkList List_HeadInsert(LinkList &L){
    LNode *node;
    int x; // 元素值
    L = new LNode; // 头结点，将内存的起始地址分配给L                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                 
    L -> next = NULL; // 空链表
    cout << "new element:"; 
    cin >> x; // 输入第一个值
    while (x != 9999){ // 输入9999标志结束
        node = new LNode; // 新结点，内存起始地址分配给node
        node -> data = x;
        node -> next = L -> next; // 指向头结点的next指针
        L -> next = node; // 头结点的next指针指向node，完成node的插入
        cout << "new element:";
        cin >> x;
    }
    return L;
}

// 采用尾插法建立单链表（定义一个指针指向尾结点）
LinkList List_TailInsert(LinkList &L){
    LNode *r, *node;
    int x;
    L = new LNode; // 头结点，将内存的起始地址分配给L                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                 
    L -> next = NULL; // 空链表
    r = L; // 指向尾结点
    cout << "new element:";
    cin >> x;
    while (x != 9999){
        node = new LNode;
        node -> data = x;
        r -> next = node;
        r = node;
        cout << "new element:";
        cin >> x;
    }
    r -> next = NULL; 
    return L;4
}

// 按序号查找结点
LNode *GetElem(LinkList L, int i){
    if (i < 0){
        return NULL; 
    }
    if (i==0){
        return L; // 返回头结点
    }
    LNode *p;
    p = L -> next; // 从头结点的next指针开始(第一个结点)
    int j = 1; // 计数
    while (p && j != i){ // 遍历到最后一个结点或者找到第i个结点为止
        p = p->next;
        j ++;
    }
    return p;
}

// 按值查找结点
LNode *LocateElem(LinkList L, int e){
    LNode *p;
    p = L -> next;
    while (p && p->data!=e){
        p = p->next;
    }
    return p;
}

// 插入结点操作(在第i个位置)
LinkList List_Insert(LinkList &L, int i, int e){
    LNode *p, *s;
    p = GetElem(L, i-1); //指针p指向前一个元素
    s -> data = e; //定义新结点
    s -> next = p -> next;
    p -> next = s;
    return L;
}

// 删除结点操作
LinkList List_Delete(LinkList &L, int i){
    LNode *p, *q;
    p = GetElem(L, i-1); //指针p指向前一个元素
    q = p->next;
    p -> next = q->next;
    delete q; // 释放存储空间
    return L;
}

// 求表长操作
int List_Len(LinkList L){
    int len = 0;
    LNode *p = L->next;
    while (p){
        p = p->next;
        len ++;
    }
    return len;
}

// 打印
void PrintElem(LinkList L){
    LNode *p = L->next;
    while (p){
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
    return;
}

int main(){
    LinkList L;
    List_HeadInsert(L);
    PrintElem(L);
    cout << "5th element: " << GetElem(L, 5) -> data << endl;
    cout << "5? "<< LocateElem(L, 5) ->data << endl;
    List_Delete(L, 5);
    PrintElem(L);
    cout << "len: " << List_Len(L) << endl;

    LinkList L2;
    List_TailInsert(L2);
    PrintElem(L2);
    cout << "5th element: " << GetElem(L2, 5) -> data << endl;
    cout << "5? "<< LocateElem(L2, 5) ->data << endl;
    List_Delete(L2, 5);
    PrintElem(L2);
    cout << "len: " << List_Len(L2) << endl;
    return 1;
}
