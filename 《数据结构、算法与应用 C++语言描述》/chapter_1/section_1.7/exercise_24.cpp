#include <iostream> 
using namespace std;

// 24.
template<class T>
int search_for_x_in_array_a(const T a[], const T x, int start, int end)
{
    if (start > end)
        return -1;
    else
    {
        int middle = int((start + end) / 2);
        if(a[middle] == x)
            return middle;
        // cout << middle << endl;
        else
        {
            int index = search_for_x_in_array_a(a, x, start, middle-1);
            // cout << endl << middle << endl;
            if (index == -1) // �ؼ�
                search_for_x_in_array_a(a, x, middle+1, end);
        }
    }
}

// ����24
void test_search_x()
{
    int a[] = {5, 2, 45, 7, 8, 3};
    int a_x = 2;
    //int a_x = 10;

    char b[] = {'a', 'c', 'w', 'p', 'r', 'o'};
    char b_x = 'w';
    //char b_x = 'e';
    cout << a_x << "������a�е��±�Ϊ��";
    cout << search_for_x_in_array_a(a, a_x, 0, 6-1);
    cout << endl;
    cout << b_x << "������b�е��±�Ϊ��";
    cout << search_for_x_in_array_a(b, b_x, 0, 6-1);
    cout << endl;
}

int main(){
	test_search_x();
	return 0;
}
