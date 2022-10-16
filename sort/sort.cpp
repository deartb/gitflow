# 快速排序

#include<iostream>
#include<vector>
using namespace std;

void quick_sort_1(vector<int> &num, int left, int right);
void quick_sort_2(vector<int>& num, int left, int right);
int partition(vector<int>& num,int left,int right);

//快速排序
void quick_sort_int(int *num, int left, int right)
{
    if(left > right)
        return ;
    int i = left;
    int j = right;
    int pivot = num[i];
    
    while(i < j)
    {
        while(num[j] >= pivot && i < j)
        {
            j--;
        }
        num[i] = num[j];
        while(num[i] <= pivot && i < j)
        {
            i++;
        }
        num[j] = num[i];
    }
    num[i] = pivot;
    quick_sort_int(num, left, i-1);
    quick_sort_int(num, i+1, right);
}

// 快排+vector
vector<int> quick_sort_vec_basic(vector<int> &num)
{
    if(2 > num.size())
        return num;
    quick_sort_1(num, 0, num.size()-1);
    return num;
}
void quick_sort_1(vector<int> &num, int left, int right)
{
    if(left > right)
        return ;
    int i = left;
    int j = right;
    int pivot = num[i];
    while (i < j)
    {
        while(num[j] >= pivot && i < j){
            j--;
        } 
        num[i] = num[j];
        while(num[i] < pivot && i < j){
            i++;
        }
        num[j] = num[i];
    }
    num[i] = pivot;
    quick_sort_1(num, left, i - 1);
    quick_sort_1(num, i + 1, right);
}

//快排+vector+模块化
vector<int> quick_sort_vec_full(vector<int>& num)
{
    int size = num.size();
    if(2 > size){
        return num;
    }
    quick_sort_2(num, 0, size -1);
    return num;
}

void quick_sort_2(vector<int>& num, int left, int right)
{
    if (left > right)
    {
        return ;
    }
    int pivot_idx = partition(num, left, right);
    quick_sort_2(num, left, pivot_idx - 1);
    quick_sort_2(num, pivot_idx + 1, right);
}

int partition(vector<int>& num,int left,int right)
{
    int pivot = num[left];
    while (left < right)
    {
        while(num[right] >= pivot && left < right)
        {
            right--;
        }
        num[left] = num[right];
        while (num[left] <= pivot && left < right)
        {
            left++;
        }
        num[right] = num[left];
    }
    num[left] = pivot;
    return left;
}

//输出函数
void print(const int a[], int size)
{
    for(int i = 0; i < size; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
}

//输出函数
void print_vec(const vector<int> &vec)
{
    for(auto v:vec)
    {
        cout << v << " ";
    }
    cout << endl;
}

int main()
{
    int v1[] = {5,3,1,2,4,7,6,8,9,10};
    vector<int> v2 = {3,1,2,4,7,6,8,9};
    vector<int> v3 = {1,2,4,7,6,8};
    
    quick_sort_int(v1, 0, 9);
    print(v1, 10);
    print_vec(quick_sort_vec_basic(v2));
    print_vec(quick_sort_vec_full(v3));

    return 0;
}