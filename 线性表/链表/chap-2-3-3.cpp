#include <iostream>
using namespace std;

typedef struct DNode{
    int data;
    struct DNode *prior, *next;
} DNode, *DLinkList;

// 创建双链表
DLinkList List_TailInsert(DLinkList &L){
    DLinkList node, r;
    // DNode *node, *r; //都可以
    int x;
    L = new DNode;
    L -> next = NULL;
    r = L;
    cout << "new element:";
    cin >> x;
    while (x != 9999){
        node = new DNode;
        node->data = x;
        node->prior=r;
        r -> next = node;
        r = node;
        cout << "new element:";
        cin >> x;
    }
    r->next=NULL;
    return L;
}

// 获得第i个结点
// DNode *GetElem()也可
DLinkList GetElem(DLinkList L, int i){
    if (i < 0){
        return NULL; 
    }
    if (i==0){
        return L; // 返回头结点
    }
    DNode *p;
    p = L -> next; // 从头结点的next指针开始(第一个结点)
    int j = 1; // 计数
    while (p && j != i){ // 遍历到最后一个结点或者找到第i个结点为止
        p = p->next;
        j ++;
    }
    return p;
}

// 插入和删除操作都要特别考虑最后一个结点的问题

// 插入结点操作(在第i个位置)
DLinkList List_Insert(DLinkList &L, int i, int e){
    if (i<0){
        return NULL;
    }
    DNode *p = GetElem(L, i-1);
    DNode *node;
    node = new DNode;
    node->data = e;
    node->next = p->next;
    node->prior=p;
    if (p->next != NULL){
        p->next->prior = node;
    }
    p->next=node;
    return L;
}

// 删除结点操作
DLinkList List_Delete(DLinkList &L, int i){
    if (i<0){
        return NULL;
    }
    DNode *p = GetElem(L, i);
    if (p->next != NULL){
        p->next->prior = p->prior;
    }
    p->prior->next = p->next;
    delete p;
    return L;
}

// 打印
void PrintElem(DLinkList L){
    DNode *p = L->next;
    while (p){
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
    return;
}

int main(){
    DLinkList L;
    List_TailInsert(L);
    PrintElem(L);
    cout << "5th element: " << GetElem(L, 5) -> data << endl;
    List_Insert(L, 4, 4);
    List_Insert(L, 7, 999);
    PrintElem(L);
    List_Delete(L, 3);
    List_Delete(L, 6);
    PrintElem(L);
}
