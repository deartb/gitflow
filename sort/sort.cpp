#include<iostream>
#include<stdlib.h>
#include<vector>
using namespace std;

// void quicksort(vector<int> &num, int left, int right);
void quick_sort(vector<int>& num, int left, int right);
int partition(vector<int>& num,int left,int right);

//元素交换
void swap(int &a, int &b)
{
    int tmp = a;
    a = b;
    b = tmp;
}
void swap_a(int &a, int &b)
{
    a = a + b;
    b = a - b;
    a = a - b;
}
void swap_b(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

// 选择排序
void select_sort(int a[], int size)
{
    int i,j,min;
    for(i=0; i<size-1; i++)
    {
        min = i;
        for(j=i+1; j<size; j++)
        {
            if(a[j]<a[min]){
                min = j;
            }
        }
        if(min!=i){
            a[min] = a[min] + a[i];
            a[i] = a[min] - a[i];
            a[min] = a[min] - a[i];
        }       
    }
}

//冒泡排序
void popsort(int num[], int size)
{
    int i,j;
    for(i=0; i<size-1; i++)
        for(j=i+1; j<size; j++){
            if(num[i]>num[j]){
                int tmp = num[i];
                num[i] = num[j];
                num[j] = tmp;
            }
        }
}

//快速排序
// void quick_sort(int *num, int left, int right)
// {
//     // int size = sizeof(num)/sizeof(*num);
//     if(left > right)
//         return ;
//     // if(left < 0 || right > size-1)
//     //     return ;
//     int i = left;
//     int j = right;
//     int pivot = num[i];
    
//     while(i < j)
//     {
//         while(num[j] >= pivot && i < j)
//         {
//             j--;
//         }
//         num[i] = num[j];
//         while(num[i] <= pivot && i < j)
//         {
//             i++;
//         }
//         num[j] = num[i];
//     }
//     num[i] = pivot;
//     quick_sort(num, left, i-1);
//     quick_sort(num, i+1, right);
    
// }

// 快排+vector
// vector<int> quicksort_vec(vector<int> &num)
// {
//     if(2 > num.size())
//         return num;
//     quicksort(num, 0, num.size()-1);
//     return num;
// }
// void quicksort(vector<int> &num, int left, int right)
// {
//     if(left > right)
//         return ;
//     int i = left;
//     int j = right;
//     int pivot = num[i];
//     while (i < j)
//     {
//         while(num[j] >= pivot && i < j){
//             j--;
//         } 
//         num[i] = num[j];
//         while(num[i] < pivot && i < j){
//             i++;
//         }
//         num[j] = num[i];
//     }
//     num[i] = pivot;
//     quicksort(num, left, i - 1);
//     quicksort(num, i + 1, right);
// }

//快排+vector+分层
vector<int> quick_sort_vec(vector<int>& num)
{
    int size = num.size();
    if(2 > size){
        return num;
    }
    quick_sort(num, 0, size -1);
    return num;
}

void quick_sort(vector<int>& num, int left, int right)
{
    if (left > right)
    {
        return ;
    }
    int pivot_idx = partition(num, left, right);
    quick_sort(num, left, pivot_idx - 1);
    quick_sort(num, pivot_idx + 1, right);
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
    int a[] = {5,3,1,2,4,7,6,8,9,10};
    // int b[3] = {5,3,1};
    // select_sort(a,10);
    // popsort(b,3);
    // int length = sizeof(a)/sizeof(*a);
    // // int length = sizeof(b)/sizeof(*b);
    // quick_sort(a, 0, length-1);
    // print(a,length);
    vector<int> v = {5,3,1,2,4,7,6,8,9,10};
    vector<int> v2 = quick_sort_vec(v);
    print_vec(v2);
    
    return 0;
}