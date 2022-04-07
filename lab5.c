
#include <stdio.h>
  
void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}
  
int selectionSort(int arr[], int n)
{
    int i, j, min_idx;
    int count = 0;
    // One by one move boundary of unsorted subarray
    for (i = 0; i < n-1; i++)
    {
        count++;
        // Find the minimum element in unsorted array
        min_idx = i;
        for (j = i+1; j < n; j++)
        {   count++;
            if (arr[j] < arr[min_idx])
            {
                count++;
                min_idx = j;
            }
        }
        
        // Swap the found minimum element with the first element
        if( min_idx!= i)
        {
            count++;
            swap(&arr[min_idx], &arr[i]);
            count++;
        }
        
    }
    
    return count;
}

int insertionSort(int arr[], int n)
{
    
    int i, key, j,count=0;
    for (i = 1; i < n; i++) 
    {   count++;
        key = arr[i];
        j = i - 1;

        /* Move elements of arr[0..i-1], that are
        greater than key, to one position ahead
        of their current position */
        while (j >= 0 && arr[j] > key) {
            count++;
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
    
    return count;
}
  
void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int findMax(int *myArray,int size)
{
    int i;
    int max = myArray[0];
    for(i=1;i<size;i++)
    {
        if(myArray[i]>max)
        {
            
            max =  myArray[i];
            //printf("%d\n",max);
        }
    }
    return max;
}
int countingSort(int *myArray,int size,int range)
{
    int i,j,k,steps=0;
    int count[range+1];
    int sortedArr[size];
    for(i=0;i<range+1;i++)
    {   
        steps++;
        count[i] =0;
    }
    //printf("counting array\n");
    for(i=0;i<size;i++)
    {
        steps++;
        ++count[myArray[i]];
    }
    // for(i=0;i<range+1;i++)
    // {
    //     printf("%d\n",count[i]);
    // }
    //printf("updating counting array\n");
    for(j=1;j<range+1;j++)
    {   
        steps;
        count[j] = count[j]+count[j-1];
    }
    // for(i=0;i<range+1;i++)
    // {
    //     printf("%d\n",count[i]);
    // }

   for(k=size-1;k>=0;k--)
   {
       steps++;
       sortedArr[--count[myArray[k]]] = myArray[k];   
   }
   for(i =0;i<size;i++)
   {
       steps++;
       myArray[i] = sortedArr[i];
   }
  return steps;
}  

int main()
{
    int arr1[9] = {64, 25, 12, 22, 11,14,8,25,69};
    int arr2[9] = {64, 25, 12, 22, 11,14,8,25,69};  
    int arr3[9] = {64, 25, 12, 22, 11,14,8,25,69};   
    int count1 = selectionSort(arr1, 9);
    printf("Sorted array using selection sort: \n");
    printArray(arr1, 9);
    printf("the count is %d\n",count1);
    int count2 = insertionSort(arr2,9);
    printf("\n\n");
    printf("Sorted array using insertion sort: \n");
    printArray(arr2, 9);
    printf("the count is %d\n",count2);
    int range = findMax(arr3,9);
    int count3 = countingSort(arr3,9,range);
    printf("\n\n");
    printf("Sorted array using counting sort: \n");
    printArray(arr3, 9);
    printf("the count is %d\n",count3);
    
    return 0;
}
