#include <iostream>
using namespace std;

#define MaxSize 100
typedef struct{
    int data[MaxSize];
    int length;
}SqList;

// 按序输出
void PrintElem(SqList L){
    for (int i=0; i<L.length; i++)
        cout << L.data[i] << ' ';
    cout << endl;
}

// 综合题8：已知在一个一维数组A[m+n]中依次存放两个线性表(a1,...a_m)和(b1,...,bn)，编写一个函数使两个顺序表位置互换
int Exchange(SqList &L1, SqList &L2, int m, int n){
    if ((m+n) != L1.length | L1.length < 1 | L2.length != L1.length)
        return 0;
    for (int i = 1; i <= n; i++){
        L2.data[i-1] = L1.data[m+i-1];
    }
    for (int j = 1; j <= m; j++){
        L2.data[n+j-1] = L1.data[j-1];
    }
    return 1;
}

// 综合题8 v2：这是一个空间复杂度为O（1）的求解方法
int Reverse(SqList &L, int Left, int Right){
    if (Left >= Right | Right >= L.length | L.length < 1)
        return 0;
    int mid = (Left + Right) / 2;
    int temp;
    for (int i=0; i<=mid-Left;i++){
        temp = L.data[Left+i];
        L.data[Left+i] = L.data[Right-i];
        L.data[Right-i] = temp;
    }
    return 1;
}

int Exchange2(SqList &L, int m, int n){
    if (L.length < 1)
        return 0;
    Reverse(L, 0, m+n-1);
    // PrintElem(L);
    Reverse(L, 0, n-1);
    // PrintElem(L);
    Reverse(L, n, m+n-1);
    // PrintElem(L);
    return 1;
}

// 综合题9：线性表(a1,...,an)中的元素递增有序且顺序存储。要求设计一算法，完成用最少时间在表中查找数值为x的元素，若找到则将其与后继元素位置相交换。若找不到则将其插入表中并使元素依然顺序递增。
int ChangeOrInsert(SqList &L, int x){
    if (L.length < 1)
        return 0;
    int left = 0;
    int right = L.length-1;
    int mid;
    while (left <= right){
        mid = (left+right) / 2;
        if (L.data[mid] == x)
            {
                if (mid != L.length-1){
                    int temp = L.data[mid];
                    L.data[mid] = L.data[mid+1];
                    L.data[mid+1] = temp;                    
                }
                return 1;
            }
        else
        {
            if (L.data[mid] > x)
               {
                   right = mid-1;
               }
            else
            {
                left = mid+1;
            }
            
        } 
    }
    for (int i=L.length-1; i>right; i--){
        L.data[i+1] = L.data[i];
    }
    L.data[right+1] = x;
    L.length ++;
    return 1;
}

// 综合题10：将n(n>1)个整数存放到一维数组R中，设计一个尽可能高效的方法，将R中保存的序列循环左移p (0<p<n)个位置，即将R中的数据由(X0,X1,...,Xn-1)变换成(Xp,Xp+1,...,Xn-1,X0,...,Xp-1)
int MoveP(SqList &L, int p){
    if (L.length < 1 | p>=L.length)
        return 0;
    Reverse(L, 0, L.length-1);
    Reverse(L, 0, L.length-p-1);
    Reverse(L, L.length-p, L.length-1);
    return 1;
}
// 时间复杂度为O(n) 空间复杂度为O(1)

int main(){
    SqList L;
    // 初始化
    for (int i=0; i<10; i++){
        L.data[i] = i+1;
    }
    L.length = 10;
    for (int j=0; j<5; j++){
        L.data[L.length] = 10-j;
        L.length ++;
    }
    cout << "sequential list:" << endl;
    PrintElem(L);
    cout << "length:" << L.length << endl;
    cout << "problem 8:" << endl;
    int m = 10;
    int n = 5;
    SqList L2;
    L2.length = m+n;
    Exchange(L, L2, m, n);
    PrintElem(L2);
    Exchange2(L, m, n);
    PrintElem(L);
    cout << "problem 9:" << endl;
    SqList L9;
    // 初始化
    for (int i=0; i<11; i++){
        if (i<8)
            L9.data[i] = i+1;
        else
        {
            L9.data[i] = i+2;
        }
        
    }
    L9.length = 10;
    PrintElem(L9);
    SqList L9_v2=L9;
    ChangeOrInsert(L9, 5);
    PrintElem(L9);
    ChangeOrInsert(L9_v2, 9);
    PrintElem(L9_v2);
    cout << "problem 10:" << endl;
    int p=5;
    PrintElem(L);
    MoveP(L, p);
    PrintElem(L);
    return 1;
}