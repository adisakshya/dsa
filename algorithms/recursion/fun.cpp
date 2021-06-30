#include<bits/stdc++.h>
using namespace std;

void fun(int num) {
    if(num < 1) {
        return;
    }
    cout << num << " ";
    fun(num - 1);
    cout << num << " ";
}

int main() {
    int num = 3;
    cout << "Doing fun" << endl;
    fun(num);
    return 0;
}