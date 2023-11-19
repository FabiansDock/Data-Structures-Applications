#include<stdio.h>
void display(int [], int);

void bubbleSort(int a[20], int size)
{
    int temp;
    for(int i = 0; i < size-1; ++i)
    {
        for(int j = 0; j < size-i-1; ++j)
        {
            if(a[j] > a[j+1])
            {
                temp = a[j]; a[j] = a[j+1]; a[j+1] = temp;
            }
        }
    }
    display(a, size);
}

void insertionSort(int a[20], int size)
{
    int temp;
    for(int i = 1; i < size; ++i)
    {
        for(int j = i; j >= 1; --j)
        {
            if(a[j] < a[j-1])
            {
                temp = a[j]; a[j] = a[j-1]; a[j-1] = temp;
            }
        }
    }
    display(a, size);
}

void selectionSort(int a[20], int size)
{
    int smallest, temp;
    for(int i = 0; i < size-1; ++i)
    {
        smallest = i;
        for(int j = i+1; j < size; ++j)
        {
            if(a[j] < a[smallest])
            {
                smallest = j;
            }
        }
        if(smallest != i)
        {
            temp = a[smallest]; a[smallest] = a[i]; a[i] = temp;
        }
    }
    display(a, size);
}

int partition(int a[20], int lb, int ub)
{
    int temp, pivot = a[lb];
    int down = lb+1, up = ub;
    while(down < up)
    {
        while((a[down] < pivot) && (down <= up))
        {
            ++down;
        }
        while(a[up] > pivot)
        {
            --up;
        }
        if(down <= up)
        {
            temp = a[down]; a[down] = a[up]; a[up] = temp;
        }
    }
    temp = a[lb]; a[lb] = a[up]; a[up] = temp;
    return up;
}

void quickSort(int a[20], int lb, int ub)
{
    int loc;
    if(lb < ub)
    {
        loc = partition(a, lb, ub);
        quickSort(a, lb, loc-1);
        quickSort(a, loc+1, ub);
    }
}

void merge(int a[20], int start, int mid,int end)
{
    int i = start, j = mid+1, k = start, temp[20];
    while(i <= mid && j <= end)
    {
        if(a[i] <= a[j])
        {
            temp[k] = a[i]; ++k; ++i;
        }else
        {
            temp[k] = a[j]; ++k; ++j;
        }
    }
    while(i <= mid)
    {
        temp[k] = a[i]; ++k; ++i;
    }
    while(j <= end)
    {
        temp[k] = a[j]; ++k; ++j;
    }
    k = start;
    while(k <= end)
    {
        a[k] = temp[k]; ++k;
    }
}

void mergeSort(int a[20], int start, int end)
{
    int mid;
    if(start != end)
    {
        mid = (start+end)/2;
        mergeSort(a, start, mid);
        mergeSort(a, mid+1, end);
        merge(a, start, mid, end);
    }
}


void maxHeapify(int a[20],int size, int i)
{
    int l = 2*i, r = 2*i+1, largest, temp;
    if((l <= size-1) && a[l] > a[i])
    {
        largest = l;
    }else
    {
        largest = i; 
    }
    if((r <= size-1) && a[r] > a[largest])
    {
        largest = r;
    }
    if(largest != i)
    {
        temp = a[largest]; a[largest] = a[i]; a[i] = temp;
        maxHeapify(a, size, largest);
    }
}

void buildMaxHeap(int a[20], int size)
{
    for(int i = (size-1)/2; i >= 1; --i)
    {
        maxHeapify(a, size, i);
    }
}

void heapSort(int a[20], int size)
{
    int temp;
    buildMaxHeap(a, size);
    for(int i = size-1; i >= 2; --i)
    {
        temp = a[i]; a[i] = a[1]; a[1] = temp;
        size = size-1;
        maxHeapify(a, size, 1);
    }
}

void display(int a[20], int size)
{
    printf("Elements after sorting\n");
    for(int i = 0; i < size; ++i)
    {
        printf("%d ", a[i]);
    }
}

void main()
{
    int op, size, a[20];
    printf("Size:");
    scanf("%d", &size);
    while(1)
    {
        printf("\nEnter the elements of the array:\n");
        for(int i = 0; i < size; ++i)
        {
            scanf("%d", &a[i]);
        }
        printf("\n1.Bubble Sort\n2.Insertion Sort\n3.Selection Sort\n4.Quick Sort\n5.Merge Sort\n6.Heap Sort\nEnter option:");
        scanf("%d", &op);
        switch(op)
        {
            case 1: bubbleSort(a, size); break;
            case 2: insertionSort(a, size); break;
            case 3: selectionSort(a, size); break;
            case 4: quickSort(a, 0, size-1); display(a, size); break;
            case 5: mergeSort(a, 0, size-1); display(a, size); break;
            case 6: for(int i = size-1; i >= 0; --i)
                    {  a[i+1] = a[i];   } 
                    heapSort(a, size+1); 
                    for(int i = 0; i < size; ++i)
                    {  a[i] = a[i+1];   }
                    display(a, size); break;
            default: printf("Invalid option"); break; 
        }
    }
}