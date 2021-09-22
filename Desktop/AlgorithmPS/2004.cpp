#include <cstdio> 
#include <algorithm> 

using namespace std;

long long M, N;
long long divide5(long long number);
long long divide2(long long number);

int main()
{
	scanf("%lld %lld", &N, &M); 
	printf("%lld", min(divide5(N) - (divide5(M) + divide5(N - M)), divide2(N) - (divide2(M) + divide2(N - M))));
}

long long divide5(long long number) { 
	long long appendix = 0; 
	for (long long i = 5; i <= number; i = i * 5) appendix += number / i; 
	return appendix; 
} 

long long divide2(long long number) { 
	long long appendix = 0; 
	for (long long i = 2; i <= number; i = i * 2) appendix += number / i; 
	return appendix; 
}