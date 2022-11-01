#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int cmp (const void *x,const void* y )
{
    return *(const int * )x - *(const int *)y;
}

int linear_searching(int arr[],int l,int n) //time complexity O(n)
{
    //start from index 0 to search the equivalent value and return the index if not found it will return -1
    for(int i=0;i<l;i++)
        if(arr[i]==n)
            return i;
    return -1;
}

int BinarySearch(int arr[],int l,int n)
{
    //the array must be sorted
    /*in this fun the main idea is start from the middle the if the n > middle index the we
     will neglect the first half of the array and continue as the second half is a new array and check the middle index
     if n<middle index we will neglect the second half of the array and so on
    */
    int start =0; int end=l-1;
    int m;
    //printf("%d\\\\",l);
    while(start<=end)
    {
        m=((start+end)+1)/2;
        //printf("%d,,",m);
        if(arr[m]<n)    start = m+1;
        else if (arr[m]>n)  end = m-1;
        else return m;
        //printf("%d",m)
    }
    //if the element not found it will return -1
    return -1;
}

int jumpSearch(int arr[],int l,int n)
{
    //separate a sorted arrays to a group of blocks search for in in the last element in each block
    //if not found we will start the liner search from the first of the block if not found it will break the while loop then return -1

    int jump = sqrt(l)-1;
    int i = 0;
    char bre_fla=1;
    while(i<l && i>=0&& bre_fla)
    {
        if(arr[i]<n)
            i+=jump;
        else if(arr[i]>n)
            for(i-=jump+1;i<i+jump;i++)
                if(arr[i]== n)  return i;
                else bre_fla=0;
        else return i;
    }
    //if the element not found it will return -1
    return -1;
}

int main()
{
    int x[]={7,58,8,9,7,56,5,6,8,86,48,5,9,87,9,87,52,54,65,654,564,80};
    printf("%d\n",linear_searching(x,sizeof(x)/sizeof(int),56));
    qsort(x,sizeof(x)/sizeof(int),sizeof(int),cmp);
    for(int i=0;i<sizeof(x)/sizeof(int);i++)
        printf("%d,,",x[i]);
    printf("\n");
    printf("%d\n",BinarySearch(x,sizeof(x)/sizeof(int),9));
    printf("\n");
    printf("%d\n",jumpSearch(x,sizeof(x)/sizeof(int),54));
    return 0;
}

