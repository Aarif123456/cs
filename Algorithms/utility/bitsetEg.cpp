// you can use includes, for example:
// #include <algorithm>
#include <bitset>
#define MAX_NUMBER 100001

int solution(int X, vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    int num=0;
    bitset<MAX_NUMBER> bits;
    for(int i=0;i<X;i++){
        bits[i] = 1;
    }
    int count=0;
    for(auto a: A){
        if(!bits.any()) return count;
        count++;
    }
    return -1;
}
