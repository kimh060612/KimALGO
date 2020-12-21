#include <iostream>
#include <fstream>
#include <map>

using namespace std;

ifstream fin;
ofstream fout;

long long N,P,Q;
map <long long, long long> DP;

long long Inf_Series(long long n)
{

    if(n == 0)return 1;
    long long &ret = DP[n];
    if (ret != 0)return ret;

    ret = Inf_Series(n / P) + Inf_Series(n / Q);

    return ret;
}

int main()
{
    fin.open("input.txt");
    fout.open("output.txt");

    cin >> N >> P >> Q;
    
    cout << Inf_Series(N) << endl;

    fin.close();
    fout.close();
}