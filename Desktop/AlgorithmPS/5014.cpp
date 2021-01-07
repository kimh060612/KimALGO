#include<iostream>
#include<queue>

using namespace std;

const int MAX = 1000000 + 1;
int F,S,G,U,D,map[MAX],chk[MAX]={0, };

int main()
{
  
  queue<int> q;
  cin>>F>>S>>G>>U>>D;
  for(int i = 0 ; i<=F ;i++) map[i] = 9999999;
  q.push(S);
  map[S] = 0;
  while(!q.empty()){
    int t = q.front();
    q.pop();
    if(t+U<=F){
      if(map[t+U] > map[t] + 1){
        map[t+U] = map[t] + 1;
        q.push(t+U);
      }
    }
    if(t-D>=1){
      if(map[t-D] > map[t] + 1){
        map[t-D] = map[t] + 1;
        q.push(t-D);
      }
    }
  }
  if(map[G]==9999999) cout<<"use the stairs";
  else cout<<map[G];
  return 0;
}