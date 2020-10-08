#include <iostream>
#include <iomanip>
#include <cstring>
using namespace std;

// 顺序表定义 - 静态分配
#define MaxSize 100
typedef struct{
    int data[MaxSize];
    int length;
}SqList;

// 顺序表定义 - 动态分配
#define InitSize 50
typedef struct{
    int *data;
    int MaxSizeDyna, length;
}SeqList;

// SeqList L
// L.data=new ElemType[InitSize]

// 插入操作: 在第i个位置前插入e
bool ListInsert(SqList &L, int i, int e){
    if (i<1 || i>L.length+1)
        return false;
    if (L.length >= MaxSize)
        return false;
    for (int j=L.length; j>=i; j--)
        L.data[j] = L.data[j-1];
    L.data[i-1] = e;
    L.length ++ ;
    return true;
}

// 删除操作：删除第i个元素并把元素值用引用变量e返回
bool ListDelete(SqList &L, int i, int &e){
    if (i<1 || i>L.length)
        return false;
    e = L.data[i-1];
    for (int j=i-1; j<L.length-1; j++)
        L.data[j] = L.data[j+1];
    L.length--;
    return true;
}

//按值查找
int LocateElem(SqList L, int e){
    for (int i=0; i<L.length; i++){
        if (L.data[i]==e)
            return i+1;
    }
    return 0;
}

// 按序输出
void PrintElem(SqList L){
    for (int i=0; i<L.length; i++)
        cout << L.data[i] << ' ';
    cout << endl;
}

// 综合题1：从顺序表中删除具有最小值的元素（假设唯一）并由函数返回被删除的元素。空出的位置由最后一个元素填补。若顺序表为空则提示出错。
int DeleteMin(SqList &L){
    if (L.length==0)
        return false;
    int MinElem = L.data[0];
    int MinIndex = 0;
    for (int i=1; i<L.length; i++){
        if (L.data[i] < MinElem){
            MinElem = L.data[i];
            MinIndex = i;            
        }
    }
    L.data[MinIndex] = L.data[L.length-1];
    L.length--;
    return MinElem;
}
//可以用函数返回值（如上面所写），也可以用参数返回（即，引用传参）

// 综合题2： 设计一个高效算法，将顺序表L的所有元素逆置，要求算法的空间复杂度为0（1）
int ListReverse(SqList &L){
    if (L.length > 1){
        int temp;
        for (int i=0; i<L.length/2; i++){
            temp = L.data[i];
            L.data[i] = L.data[L.length-i-1];
            L.data[L.length-i-1] = temp;
        }  
    }
    return 0;
}

// 综合题3： 对长度为n个顺序表L，编写一个时间复杂度为O(n)，空间复杂度为O（1）的算法，该算法删除线性表中所有值为x的数据元素。
// v1是我想到的会改变顺序表元素顺序的方法
int ListDeleteValue_v1(SqList &L, int x){
    if (L.length < 1)
        return 0;
    int k = 0;
    for (int i=0; i<L.length; i++){
         if (L.data[i]==x){
            k += 1;
            L.data[i] = L.data[L.length - k];             
         }
    }
    L.length -= k;
    return 1;
}

// v2不会改变元素顺序：如果元素为非x，则放进第k个位置（k为非x的元素个数），k+1
int ListDeleteValue_v2(SqList &L, int x){
    if (L.length < 1)
        return 0;
    int k = 0;
    for (int i=0; i<L.length; i++){
        if (L.data[i]!=x)
            L.data[k] = L.data[i];
            k += 1;
        }
    L.length = k;
    return 1;
}

// 综合题4：从[有序]顺序表中删除其值在给定的s和t之间的所有元素，如果s/t不合理或顺序表为空，则显示错误信息
int ListDeleteRange(SqList &L, int s, int t){
    if (L.length<1 | s>=t)
        return 0;
    int k = 0; //统计s和t之间的元素个数
    for (int i=0; i<L.length; i++){
        if (L.data[i]>s & L.data[i]<t){
            k += 1;
        }
        if (L.data[i]>=t){
            L.data[i-k] = L.data[i];
        }
    }
    L.length -= k;
    return 1;
}

// 综合题5：从顺序表中删除在给定值s和t之间（包含s和t）的所有元素，如果s和t不合理或顺序表为空，则显示出错信息
int ListDeleteRange_p5(SqList &L, int s, int t){
    if (L.length<1 | s>t)
        return 0;
    int k = 0;
    for (int i=0; i<L.length; i++){
        if (L.data[i]<s | L.data[i]>t){
            L.data[k] = L.data[i];
            k += 1;
        }
    }
    L.length = k;
    return 1;
}

// 综合题6：从有序顺序表中删除所有其值重复的元素，使表中所有元素的值均不同
int SortedListDuplicated(SqList &L){
    if (L.length<1)
        return 0;
    int k = 1;
    for (int i=1; i<L.length; i++){
        if (L.data[i]!=L.data[i-1]){
            L.data[k] = L.data[i];
            k += 1;
        }
    }
    L.length = k;
    return 1;
}

// 综合题7：将两个有序列表合并成一个新的有序列表，并由函数返回结果顺序表
SqList SortedListCombine(SqList L1, SqList L2){
    SqList L3;
    L3.length = L1.length + L2.length;
    int k = 0;
    int i = 0;
    int j = 0;
    while (i<L1.length){
        while (j<L2.length){
            if (L1.data[i]<L2.data[j]){
                L3.data[k] = L1.data[i];
                i += 1;
                k += 1;
            }
            else{
                L3.data[k] = L2.data[j];
                j += 1;
                k += 1;
            }
        }
    }
    // 只剩一个没比完
    for (; i<L1.length; i++){
        L3.data[k] = L1.data[i];
        k += 1;
    }
    for (; j<L2.length; j++){
        L3.data[k] = L2.data[j];
        k += 1;
    }
    return L3;
}

int main(){
    SqList L;
    // 初始化 （上面没有定义初始化函数，不能用ListInsert
    for (int i=0; i<10; i++){
        L.data[i] = i+1;
    }
    L.length = 10;
    cout << "sequential list:" << endl;
    PrintElem(L);
    // 在第10个元素前插入100
    bool a = ListInsert(L, 10, 100);
    cout << "success? (0/1):" << a << endl;
    cout << "sequential list after insertion:" << endl;
    PrintElem(L);
    // 删除第10个元素
    int e;
    int b = ListDelete(L, 10, e);
    cout << "success? (0/1):" << b << ' ' << "deleted value: " << e << endl;
    cout << "sequential list after deletion:" << endl;
    PrintElem(L);
    // 按值查找
    cout << "searching:" << endl;
    cout << LocateElem(L, 9) << endl;
    cout << LocateElem(L, 90) << endl;
    // 综合题1 test
    cout << "problem 1:" << endl;
    DeleteMin(L);
    PrintElem(L);
    // 综合题2 test
    cout << "problem 2:" << endl;    
    ListReverse(L);
    PrintElem(L);
    // 综合题3 v1 test
    ListInsert(L, 8, 8);
    ListInsert(L, 5, 8);
    cout << "problem 3 v1:" << endl;
    PrintElem(L);
    ListDeleteValue_v1(L, 8);
    PrintElem(L);
    // 综合题3 v2 test  
    ListInsert(L, 8, 8);
    ListInsert(L, 5, 8);
    cout << "problem 3 v2:" << endl;
    PrintElem(L);
    ListDeleteValue_v1(L, 8);
    PrintElem(L);
    // 综合题4 test
    SqList L4; 
    for (int i=0; i<10; i++){
        L4.data[i] = i+1;
    }
    L4.length = 10;
    cout << "problem 4:" << endl;
    PrintElem(L4);
    ListDeleteRange(L4, 0, 5);
    PrintElem(L4);
    cout << "problem 5:" << endl;
    PrintElem(L);
    ListDeleteRange_p5(L, 5, 7);
    PrintElem(L);
    cout << "problem 6:" << endl;
    ListInsert(L4, 2, 6);
    ListInsert(L4, 2, 6);
    ListInsert(L4, 6, 8);
    PrintElem(L4);
    SortedListDuplicated(L4);
    PrintElem(L4);
    cout << "problem 7:" << endl;
    SqList L7;
    SqList Lc;
    for (int i=0; i<5; i++){
        L7.data[i] = i+3;
    }
    L7.length = 5;
    PrintElem(L4);
    PrintElem(L7);
    Lc = SortedListCombine(L7, L4);
    PrintElem(Lc);
    return 0;
}
