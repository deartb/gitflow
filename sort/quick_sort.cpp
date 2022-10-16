//快速排序
void quick_sort(int *num, int left, int right)
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
    quick_sort(num, left, i-1);
    quick_sort(num, i+1, right);
    
}

// 快排+vector
vector<int> quicksort_vec(vector<int> &num)
{
    if(2 > num.size())
        return num;
    quicksort(num, 0, num.size()-1);
    return num;
}
void quicksort(vector<int> &num, int left, int right)
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
    quicksort(num, left, i - 1);
    quicksort(num, i + 1, right);
}