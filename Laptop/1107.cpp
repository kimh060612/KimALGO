#include <iostream>

using namespace std;

int _min(int a, int b) { return a < b ? a : b; }  

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    bool broken[10]={false,};
    int n,m,min;
    
    cin>>n>>m;
    
    while(m--)
    {
        int tmp;
        cin>>tmp;
        broken[tmp]=true;
    }
    
    min=abs(n-100);
    
    if(!broken[0] && min>n+1)
    {
        min=n+1;
    }
    
    for(int i=1;i<=2*n;i++)
    {
        int tmp=i,len=0;
        while(true)
        {
            if(tmp)
            {
                if(broken[tmp%10]) break;
                tmp/=10;
                len++;
            }
            else
            {
                min = _min(abs(i-n)+len, min);
                break;
            }
        }
    }
    
    cout<<min;
    return 0;
}