#include <iostream> 
using namespace std;

// 23. 最大公约数（Greatest Common Divisor，GCD）
int calculate_GCD_with_recursive_funcation(int x, int y)
{
    if (y == 0)
        return x;
    else
        return calculate_GCD_with_recursive_funcation(y, x%y);
}

int calculate_GCD_with_non_recursive_funcation(int x, int y)
{
    if (x < y) // 保证 x > y
        swap(x, y);

    while(y != 0)
    {
        int temp = x % y;
        x = y;
        y = temp;
    }
    return x;
}

// 测试23
void test_GCD()
{
    int x = 18, y = 24;
    cout << "With recursive funcation, GCD(" << x << ", " << y << ") = ";
    cout << calculate_GCD_with_recursive_funcation(x, y);
    cout << endl;

    cout << "With non-recursive funcation, GCD(" << x << ", " << y << ") = ";
    cout << calculate_GCD_with_non_recursive_funcation(x, y);
    cout << endl;
}

int main(){
	test_GCD();
	return 0;
}
