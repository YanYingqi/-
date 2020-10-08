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

// problem 11: 长度为L（L>=1）的的升序序列S，处在第L/2（大于它的最小整数）的数称为S的中位数。两个序列的中位数是含它们所有元素的升序序列的中位数。设计一个时间、空间都尽可能高效的算法，得到等长升序序列A和B的中位数。
int GetMedian(SqList A, SqList B){
    if (A.length != B.length | A.length < 1)
        return 0;
    int median;
    int pos = A.length;
    int i = 0;
    int j = 0;
    int flag = 0;
    while ((i+j)<pos){
        if (A.data[i]<B.data[j])
        {
            i++;
            flag = 1;
        }
        else
        {
            j++;
            flag = 2;
        }
    }
    if (flag == 2){
        median = B.data[j-1];
    }
    else{
        median = A.data[i-1];
    }
    return median;
}
// 空间复杂度O（1），时间复杂度O（n）

int GetMedian_v2(SqList A, SqList B){
    if (A.length != B.length | A.length < 1)
        return 0;
    int n=A.length;
    int s1=0,d1=n-1,s2=0,d2=n-1;
    int m1, m2;
    while(d1!=s1){
        m1=A.data[(s1+d1)/2];
        m2=B.data[(s2+d2)/2];
        if (m1==m2){
            return m1;
        }
        else{
            if (m1<m2){
                if ((s1+d1)%2==0){
                    s1=(s1+d1)/2;
                    d2=(s2+d2)/2;
                }
                else{
                    s1=(s1+d1)/2+1;
                    d2=(s2+d2)/2;                    
                }
            }
            else{
                if ((s1+d1)%2==0){
                    d1=(s1+d1)/2;
                    s2=(s2+d2)/2;
                }
                else{
                    d1=(s1+d1)/2;
                    s2=(s2+d2)/2+1;                    
                }
            }
        }
    }
    return A.data[s1]<B.data[s2]?A.data[s1]:B.data[s2];    
}
// 空间复杂度O（1），时间复杂度O（n）

// problem 12: 整数序列A，其中0<=a_i<n。若存在... （题太长了，看书）
int PrincipleElem(SqList L){
    int n = L.length;
    int min_m = n/2+1;
    int T[n] = {-1};
    for (int i=0; i<n; i++){
        T[L.data[i]] ++;
    }
    int max_num = 0;
    int pos = -1;
    for (int i=0; i<n; i++){
        if (T[i]>max_num){
            max_num = T[i];
            pos = i;
        }
    }
    if (max_num>=min_m){
        return pos;
    }
    else{
        return -1;
    }
}
// 空间复杂度O(n)；时间复杂度O(n)

int PrincipleElem_v2(SqList L){
    int n = L.length;
    int min_m = n/2+1;
    int count = 1;
    int c=L.data[0];
    for (int i=1; i<n; i++){
        if (L.data[i]==c){
            count ++;
        }
        else{
            if (count > 0){
                count --;
            }
            else{
                count = 1;
                c = L.data[i];
            }
        }
    }
    count = 0;
    for (int i=0; i<n; i++){
        if (L.data[i]==c){
            count ++;
        }
    }
    return count>=min_m?c:-1;
}
// 空间复杂度O(1)；时间复杂度O(n)

// problem 13: 给定一个含n（大于1）个整数的数组，设计一个时间上尽可能高效的算法，找出数组中未出现的最小正整数。
int MinInt(SqList L ){
    if (L.length<1){
        return -1;
    }
    int B[L.length]={0};
    for (int i=0; i<L.length; i++){
        if (L.data[i]>0 & L.data[i]<=L.length){
            B[L.data[i]-1] ++;
        }
    }
    for (int i=0; i<L.length; i++){
        if (B[i]==0){
            return i+1;
        }
    }
    return L.length+1;
}
// 空间复杂度O(n)；时间复杂度O(n)

int main(){
    SqList L, L2;
    // 初始化
    for (int i=0; i<5; i++){
        L.data[i] = 2*i+11;
    }
    L.length = 5;
    for (int j=0; j<5; j++){
        L2.data[j] = 2*(j+1);
    }
    L2.data[4] = 20;
    L2.length = 5;
    cout << "sequential list:" << endl;
    PrintElem(L);
    PrintElem(L2);
    int median = GetMedian(L, L2);
    int median2 = GetMedian_v2(L, L2);
    cout << "problem 11: " << "median: " << median <<", "<< median2 << endl;
    SqList A = {{0,5,5,3,5,7,5,5}, 8}, B = {{0,5,5,3,5,1,5,7}, 8};
    int PrincipleElem1 = PrincipleElem(A);
    int PrincipleElem2 = PrincipleElem(B);
    int PrincipleElem3 = PrincipleElem_v2(A);
    int PrincipleElem4 = PrincipleElem_v2(B);
    cout << "problem 12:" << PrincipleElem1 << ", " <<PrincipleElem2 << endl;
    cout << "problem 12 v2:" << PrincipleElem3 << ", " <<PrincipleElem4 << endl;
    SqList A2 = {{-5,3,2,3}, 4}, B2 = {{1,2,3}, 3};
    int min_int1 = MinInt(A2);
    int min_int2 = MinInt(B2);
    cout << "problem 13:" << min_int1 << ", " << min_int2 << endl;
    return 1;
}
