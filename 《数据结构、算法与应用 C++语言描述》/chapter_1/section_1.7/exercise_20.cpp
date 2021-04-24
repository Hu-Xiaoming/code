#include <iostream> 
using namespace std;

// 20. ì³²¨ÄÇÆõÊýÁÐ£¨Fibonacci sequence£©
int calculate_Fibonacci_with_recursive_funcation(int n)
{
    if (n == 0)
        return 0;
    else if (n == 1)
        return 1;
    else
        return calculate_Fibonacci_with_recursive_funcation(n-1) + calculate_Fibonacci_with_recursive_funcation(n-2);
}

int calculate_Fibonacci_with_non_recursive_funcation(int n)
{
    int* a = new int[n+1];
    a[0] = 0; a[1] = 1;
    for (int i = 2; i <= n; i ++)
        a[i] = a[i-1] + a[i-2];
    return a[n];
}

// ²âÊÔ20
void test_calculate_Fibonacci()
{
    int n;
	cout << "input n:";
    cin >> n;
    cout << "With recursive funcation, Fibonacci sequence F(" << n << ") = ";
    cout << calculate_Fibonacci_with_recursive_funcation(n);
    cout << endl;

    cout << "With non-recursive funcation, Fibonacci sequence F(" << n << ") = ";
    cout << calculate_Fibonacci_with_non_recursive_funcation(n);
    cout << endl;
}

int main(){
	test_calculate_Fibonacci();
	return 0;
}
