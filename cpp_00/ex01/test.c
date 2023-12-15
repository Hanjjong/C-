#include <stdio.h>

int sort_check(int *arr)
{
    int size;
    int i;
    int max;

    max = 0;
    size = 5;
    i = 0;
    size = (size + 1) / 2;
    //정렬 확인
    while (size--)
    {
        if (arr[i] > max)
            max = arr[i];
        else
            return (0);
        if (arr[4 - i] > max)
            max = arr[4 - i];
        else
            return (0);
        i++;
    }
    return (1);
}
int search_min(int *arr, int start, int end)
{
    int min_index;
    int min;

    min_index = start;
    min = arr[start];
    while (start <= end)
    {
        if (arr[start] < min)
        {
            min_index = start;
            min = arr[start];
        }
        start++;
    }
    return (min_index);
}

void print(int *arr)
{
    for (int i=0; i < 5; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main()
{
    int arr[5] = {3, 1 ,2 ,5 ,4};
    int min;
    int start;
    int end;
    int tmp;

    tmp = 0;
    start = 0;
    end = 4;
    min = 0;
    
    printf("정렬전 : ");
    print(arr);
    int cnt = 5;
    while (!sort_check(arr) && start < end)
    {
        // 앞 친구 정렬
        if (arr[start])
        {
            min = search_min(arr, start , end);
            tmp = arr[start];
            arr[start] = arr[min];
            arr[min] = tmp;
            start++;
        }
        //뒤 친구 정렬
        if (arr[end])
        {
            min = search_min(arr, start, end);
            tmp = arr[end];
            arr[end] = arr[min];
            arr[min] = tmp;
            end--;
        }
    }
    printf("정렬후 : ");
    print(arr);
}
