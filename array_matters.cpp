#include<iostream>

using namespace std;

/*
delete:
        first;
        last;
        at some index;
        some value;
        delete all value;
bubble sort;
*/

int travarseAndInitialize(int *arr, int size)
{
    //travarsal
    for(int i=0;i<size;i++)
    {
        arr[i]=-1;
    }
    //initialize
    for(int i=0;i<10;i++)
    {
        arr[i]=i*5;
    }
    int filledTo=9;
    return filledTo;
}

void printArray(int *arr, int size, int filledTo)
{
    cout << "Printing" <<endl;
    for(int i=0;i<=filledTo;i++)
    {
        cout << arr[i] <<"\t";
    }
    cout <<endl << "Size " << size << " Filled To " <<filledTo <<endl;
}

bool isArrayFull(int size,int filledTo)
{
    if(filledTo==size-1) return true;
    else return false;
}

bool boundaryCheckIndex(int size, int filledTo, int index)
{
    if(isArrayFull(size,filledTo)||index<0||index>filledTo+1) return true;
    else return false;
}

int search(int *arr,int filledTo, int beforeValue)
{
    for(int i=0;i<=filledTo;i++)
    {
        if(arr[i]==beforeValue) return i;
    }
    return -1;
}

void makeSpaceAT(int *arr,int index, int &filledTo)
{
    for(int i=filledTo+1;i>index;i--)
    {
        arr[i]=arr[i-1];
    }
    filledTo++;
    arr[index]=-1;
}

bool insertAtTheEnd(int *arr, int size, int &filledTo, int itemTobeInserted)
{
    if(isArrayFull(size,filledTo)) return false;
    filledTo++;
    arr[filledTo]= itemTobeInserted;
    return true;
}

bool insertAtTheBeginning(int *arr, int size, int &filledTo, int itemTobeInserted)
{
    if(isArrayFull(size,filledTo)) return false;
    makeSpaceAT(arr,0,filledTo);
    arr[0]=itemTobeInserted;
    return true;
}

bool insertAtIndexPosition(int *arr, int size, int &filledTo, int itemTobeInserted, int index)
{
    if(boundaryCheckIndex(size, filledTo, index)) return false;
    if(index<=filledTo)
    {
        makeSpaceAT(arr,index,filledTo);
    }
    else {
        filledTo++;
    }
    arr[index] =itemTobeInserted;
    return true;
}

bool insertBeforeValue(int *arr, int size, int &filledTo, int itemTobeInserted, int beforeValue)
{
    if(isArrayFull(size,filledTo)) return false;
    int index=search(arr, filledTo, beforeValue);
    if(index==-1) {
        cout << beforeValue << " Not Found" << endl;
        return false;
    }
    makeSpaceAT(arr,index,filledTo);
    arr[index]=itemTobeInserted;
    return true;
}

bool insertAfterValue(int *arr, int size, int &filledTo, int itemTobeInserted, int afterValue)
{
    if(isArrayFull(size,filledTo)) return false;
    int index=search(arr, filledTo, afterValue);
    if(index==-1) {
        cout << afterValue << " Not Found" << endl;
        return false;
    }
    makeSpaceAT(arr,index+1,filledTo);
    arr[index+1]=itemTobeInserted;
    return true;
}


int main()
{
    int size=100;
    int arr[100];
    int filledTo=0;
    filledTo =travarseAndInitialize(arr,size);
    return 0;
}
