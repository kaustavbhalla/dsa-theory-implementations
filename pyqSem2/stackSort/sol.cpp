#include <bits/stdc++.h>
using namespace std;

stack<int> sortStack(stack<int> &s) {
  stack<int> ts;

  while (!s.empty()) {
    int temp = s.top();
    s.pop();

    while (!ts.empty() && ts.top() > temp) {
      int temp2 = ts.top();
      ts.pop();
      s.push(temp2);
    }

    ts.push(temp);
  }

  return ts;
}
