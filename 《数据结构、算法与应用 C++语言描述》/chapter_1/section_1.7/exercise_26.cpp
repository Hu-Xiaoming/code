#include <iostream> 
using namespace std;

// 26.�����루Gray Code��
void print_Gray_code_of_n(int n)
{
    if (n == 1)
        cout << 1 << ' ';
    else
    {
        print_Gray_code_of_n(n-1);
        cout << n << ' ';
        print_Gray_code_of_n(n-1);
    }
}

// ����26
void test_gray_code()
{
    int n = 3;
    cout << "Gray Code is��";
    print_Gray_code_of_n(n);
}

int main(){
	test_gray_code();
	return 0;
}

