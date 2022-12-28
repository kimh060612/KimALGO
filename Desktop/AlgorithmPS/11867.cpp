#include <iostream>

using namespace std;

int main() {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false); 

  int N, M;
  cin >> N >> M;


  if(N % 2 == 0 || M % 2 == 0) {
    cout << "A" << endl;
  }
  else {
    cout << "B" << endl;
  }
} 