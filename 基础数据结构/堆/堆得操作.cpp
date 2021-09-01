#include<bits/stdc++.h>
using namespace std;
void push(int A[], int i, int& n) {  // i 为插入的值, n 为插入之前堆的大小
    n++; // 调整大小
    A[n] = i; // 放进堆的最后
    int p = n;
    while (p > 1 && A[p / 2] > A[p]) { // 调整，如果不满足堆的性质，交换父节点和当前节点
        swap(A[p / 2], A[p]);
        p /= 2;
    }
}//插入元素
int pop(int A[], int& n) {
    int res = A[1]; // 记录堆顶元素
    A[1] = A[n]; // 把堆顶元素换到最后
    n--; // 调整大小，此时原来的最后一位虽然有值但不会再用了
    int p = 1, t;
    while (p * 2 <= n) { // 调整
        if (p * 2 + 1 > n || A[p * 2] <= A[p * 2 + 1]) { // 找到左右两个孩子中的较小者
            t = p * 2;
        } else {
            t = p * 2 + 1;
        }
        if (A[p] > A[t]) { // 如果不满足堆的性质就交换
            swap(A[p], A[t]);
            p = t;
        } else { // 否则就调整完成了
            break;
        }
    }
    return res;
}
int main(){

  return 0;
}
