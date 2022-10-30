#include<iostream>
using namespace std;
#include <stdio.h>
int array[100], n;

void display()
{
    int i;
    if (n == 0)
    {
        printf("Heap is empty \n");
        return;
    }
    for (i = 0; i < n; i++)
        printf("%d ", array[i]);
    printf("\n");
}

void insert(int num, int location)
{
    int parentnode;
    while (location > 0)
    {
        parentnode =(location - 1)/2;
        if (num <= array[parentnode])
        {
            array[location] = num;
            return;
        }
        array[location] = array[parentnode];
        location = parentnode;
    }
    array[0] = num;
}
void del(int num)
{
    int left, right, i, temp, parentnode;

    for (i = 0; i < num; i++) {
        if (num == array[i])
            break;
    }
    if (num != array[i])
    {
        printf("%d not found in heap list\n", num);
        return;
    }
    array[i] = array[n - 1];
    n = n - 1;
    parentnode =(i - 1) / 2;
    if (array[i] > array[parentnode])
    {
        insert(array[i], i);
        return;
    }
    left = 2 * i + 1;
    right = 2 * i + 2;
    while (right < n)
    {
        if (array[i] >= array[left] && array[i] >= array[right])
            return;
        if (array[right] <= array[left])
        {
            temp = array[i];
            array[i] = array[left];
            array[left] = temp;
            i = left;
        }
        else
        {
            temp = array[i];
            array[i] = array[right];
            array[right] = temp;
            i = right;
        }
        left = 2 * i + 1;
        right = 2 * i + 2;
    }
    if (left == n - 1 && array[i])    {
        temp = array[i];
        array[i] = array[left];
        array[left] = temp;
    }
}
int main()
{
    int choice, num;
    n = 0;
    cout<<"\tHEAP\n";
    while(1)
    {
        cout<<"1.Insert the element \n";
        cout<<"2.Delete the element \n";
        cout<<"3.Display all elements \n";
        cout<<"4.Quit \n";
        cout<<"Enter your choice : ";
        cin>>choice;
        switch(choice)
        {
        case 1:
            cout<<"Enter the element to be inserted to the list : ";
            cin>>num;
            insert(num, n);
            n = n + 1;
            break;
        case 2:
            cout<<"Enter the elements to be deleted from the list: ";
            cin>>num;
            del(num);
            break;
        case 3:
            display();
            break;
        case 4:
            exit(0);
        default:
            cout<<"Invalid choice \n";
            break;
    }
}
return 0;
}
