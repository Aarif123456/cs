#include <iostream>
#include <regex>
#include <string>
#include <vector>
#include <numeric>
#include <cmath> 
using namespace std;
typedef vector<int> vi; 
typedef vector<vi> vvi; 
  
/* For loop excluding end*/
#define FOR(i, b, c) for (int(i) = (b); (i) < (c); (i)++) 
/* For loop going till end*/
#define FORL(i, b, c) for (int(i) = (b); (i) <= (c); (i)++) 
/* For loop backward */
#define FORR(i, b, c) for (int(i) = (b); (i) >= (c); --(i)) 
/* Traverse collection */
#define TRAV(a, b) for (auto&(a) : (b)) 
/* Quick for loop */
#define REP(i, n) FOR(i, 0, n) 
/* general shortcut */
#define ALL(v) v.begin(), v.end() 
#define SIZE(v) static_cast<int>(v.size()) 
#define SORT(v) sort(ALL(v)) 
#define REVERSE(v) reverse(ALL(v)) 

int solution(const vector<int> &A)
{
  /*Problem is special version of knapsack problem where our weight is half the sum */
  auto sum = accumulate(A.begin(), A.end(), 0);
  int target = ceil(double(sum)/2.0);
  int n = SIZE(A);
  vi dp(target+1, 0);
  FORL(i, 1, n){
      FORR(c, target, A[i-1]){
         dp[c] = max(dp[c], A[i-1] + dp[c-A[i-1]]);
      }
  }
  auto otherNum = floor(double(sum)/2.0)+(target- dp[target]);
  return abs(dp[target]- otherNum) ;
  // Put your solution here
  return 0; 
}

vector<int> toIntVector(string str)
{
  std::vector<int> out;
  std::string i;
  std::istringstream tokenStream(str);
  while (std::getline(tokenStream, i, ','))
  {
    out.push_back(atoi(i.c_str()));
  }
  return out;
}

int main()
{
  // Read in from stdin, solve the problem, and write answer to stdout.
  string AS;
  cin >> AS;
  cout << solution(toIntVector(AS));
}