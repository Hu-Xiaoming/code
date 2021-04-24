#include <iostream> 
using namespace std;

// 21.
int calculate_f_n_with_recursive_funcation(int n)
{
    if(n % 2 == 0)// ż��
        return n / 2;
    else
        return calculate_f_n_with_recursive_funcation(3*n+1);
}

int  calculate_f_n_with_non_recursive_funcation(int n)
{
    if (n % 2 == 0)// ż��
        return n / 2;
    else// �������� 3n+1 ��Ϊż��
        return  (3 * n + 1) / 2;
}

// ����21
void test_f_n()
{
    int n;
	cout << "input n:";
    cin >> n;
    cout << "With recursive funcation, f(" << n << ") = ";
    cout << calculate_f_n_with_recursive_funcation(n);
    cout << endl;

    cout << "With non-recursive funcation, f(" << n << ") = ";
    cout << calculate_f_n_with_non_recursive_funcation(n);
    cout << endl;
}

int main(){
	test_f_n();
	return 0;
}
