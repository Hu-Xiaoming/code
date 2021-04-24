#include <iostream> 
#include <cmath> // pow(double base, double exp)
using namespace std;


// 22. °¢¿ËÂüº¯Êý
int calculate_Ackermann_funcation(int i, int j)
{
    if (i < 1 || j < 1)
        return -1;
    if (i == 1 && j >= 1)
        return pow(2.0, j);
    else if (i >= 2 && j == 1)
        return calculate_Ackermann_funcation(i-1, 2);
    else
        return calculate_Ackermann_funcation(i-1, calculate_Ackermann_funcation(i, j-1));
}

// ²âÊÔ22
void test_Ackermann_funcation()
{
    int i = 2, j = 2;
    cout << "Ackermann`s funcation("  << i << ", " << j << ") = ";
    cout << calculate_Ackermann_funcation(i, j);
    cout << endl;
}

int main(){
	test_Ackermann_funcation();
	return 0;
}
