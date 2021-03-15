#include <iostream>
using namespace std;

typedef long long ll;
ll A,B;
ll sum(ll x){
    ++x;
	ll save=x,target=1,ret=0;
	while(save){
		if(x&target) ret+=x%target+(x-x%(target*2))/2;
		else ret+=(x-x%target)/2;
		target<<=1;
		save>>=1;
	}
	return ret;
}
int main(){
	cin>>A>>B;
	cout<<sum(B)-sum(A-1)<<'\n';
}