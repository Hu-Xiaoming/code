#include <iostream>
#include <cmath> // pow(double base, double exp)
#include <ctime>
using namespace std;

// 25. 子集生成方法
int sequence[10000][10000];
int subset_generation(int n)
{
    if (n == 0)
    {// 空集的子集只有空集
        cout << 0 << endl;
        return 1;
    }
    else if (n == 1)
    {
        for (int i = 0; i <= 1; i ++)
            sequence[i][1] = i;
        return 2;
    }
    else
    {
        int row_length = subset_generation(n-1);
        int cur_row_length = 2 * row_length;
        // 拷贝两遍 n-1 个元素的信息
        for (int row = row_length; row < cur_row_length; row ++)
            for (int col = 1; col <= n-1; col ++)
                    sequence[row][col] = sequence[row-row_length][col];
        // 添加第 n 个元素
        for (int row = 0; row < cur_row_length; row ++)
            sequence[row][n] = row < row_length? 0 : 1;
        return cur_row_length;
    }
}


void subset_generation_with_non_recursive_funcation(const int n)
{// 转二进制
    int subset[n] = {0};
    // n 位二进制转其能表示的最大十进制
    int number = 1;
    for (int i = n-1; i > 0; i --)
        number += pow(2.0, i);

    for (int i = 0; i <= number; i ++)
    {
        int temp_n = n;
        int temp_i = i;
        while(temp_i > 0)
        {
            subset[temp_n-1] = temp_i % 2;
            temp_i /= 2;
            temp_n --;
        }
        for(int j = 0; j < n; j ++)
            cout << subset[j];
        cout << endl;
    }

}

// 测试25
void test_subset_generation()
{
    // n must lower than seven
    // int n = 10;
    int n = 3;
    time_t start_time = time(0);
    // cout << start_time << endl;
    cout << "all subsets are:" << endl;
    int length = subset_generation(n);
    if (length <= 1)
        return;
    for (int i = 0; i < length; i ++)
    {
        for (int j = 1; j <= n; j ++)
            cout << sequence[i][j];
        cout << endl;
    }
    time_t end_time = time(0);
    cout << end_time - start_time << endl;
    start_time = time(0);
    cout << "with non-recursive_way, all subsets are:" << endl;
    subset_generation_with_non_recursive_funcation(n);
    end_time = time(0);
    cout << end_time - start_time << endl;
    // 经测试，递归快一点

}

int main(){
	test_subset_generation();
	return 0;
}
