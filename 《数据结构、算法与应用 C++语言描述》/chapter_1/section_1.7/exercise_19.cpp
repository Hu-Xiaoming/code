#include <iostream> 
using namespace std;

// 19. �ǵݹ���n��
long long calculate_factorial_of_n_with_non_recursive_program(int n)
{
    // 0 �Ľ׳��� 1
    if (n == 0)
        return 1;
    // ����û�н׳�
    else if (n < 0)
    {
        throw "Negative numbers have no factorials!";
        return -1;
    }
    else
    {
        long long factorial_result = 1;
        // n! = n x (n-1) x (n-2) x ... x 1
        while(n > 1)
        {
            factorial_result *= n;
            n -= 1;
        }
        return factorial_result;
    }
}

long long calculate_factorial_of_n_with_recursive_program(int n)
{
// f(n) = { 1, if n = 1
//            n * f(n-1), else
//          }
    // 0 �Ľ׳��� 1
    if (n == 0)
        return 1;
    // ��������
    else if (n == 1)
        return 1;
    // ����û�н׳�
    else if (n < 0)
    {
        throw "Negative numbers have no factorials!";
        return -1;
    }
    // �ݹ鲿��
    // n! = n x (n-1) x (n-2) x ... x 1
    else
        return n * calculate_factorial_of_n_with_recursive_program(n-1);
}

// ����19
void test_calculate_factorial()
{
	int n;
	cout << "input n:";
    cin >> n;
    try
    {
        long long result = calculate_factorial_of_n_with_non_recursive_program(n);
        cout << "With non-recursive program, factorial of n = ";
        cout << result;
    }
    // ���� n Ϊ�������쳣
    catch(const char* e)
    {
        cout << e;
    }
    cout << endl;

    try
    {
        long long result = calculate_factorial_of_n_with_recursive_program(n);
        cout << "With recursive program, factorial of n = ";
        cout << result;
    }
    catch(const char* e)
    {
        cout << e;
    }
    cout << endl;
}

int main()
{
	test_calculate_factorial(); 
	return 0;
}

