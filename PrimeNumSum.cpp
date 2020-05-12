#include <iostream>
using namespace std;

int isPrime(int n);
int main()
{
    int n, i;
    cout << "Enter the number: ";
    cin >> n;
    int flag = 0;
    for(i = 2; i <= n/2;i++){
        if (isPrime(i) == 1 && isPrime(n-i) == 1){
            cout << n << " can be expressed as " << i << " + " << n-i <<".\n";
            flag = 1;
        }
    }

    if (flag == 0)
        cout << n << " cannot be expressed as the sum of two prime numbers.\n";
    return 0;
}
int isPrime(int n)
{
    int i, flag = 1;
    for(i = 2; i <= n/2; i++){
        if(n % i == 0){
            flag = 0;
            break;
        }
    }
    return flag;
}
