#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define size 10

int arr[size] = {345, 274, 153, 874, 923, 452, 657, 109, 387, 888};

int biggestNum()
{
    int num = -1;
    for (int i = 0; i < size; i++)
    {
        if (arr[i] > num)
        {
            num = arr[i];
        }
    }
    return num;
}

int noOfDigs(int a)
{
    int num = 0;
    for (int i = a; i > 0; i = i / 10)
    {
        num++;
    }
    return num;
}

int power(int a)
{
    int num = 1;
    for (int i = 0; i < a; i++)
    {
        num = num * 10;
    }
    return num;
}

int redixArr[10][size];

void redixSort()
{
    int numOfDigs = noOfDigs(biggestNum());
    for (int i = 0; i < 10; i++)
    {
        redixArr[0][i] = i;
    }

    for (int i = 0; i < numOfDigs; i++)
    {
        int zero = 1, one = 1, two = 1, three = 1, four = 1, five = 1, six = 1, seven = 1, eight = 1, nine = 1;
        for (int j = 0; j < size; j++)
        {
            int remainder = (arr[j] / power(i)) % 10;
            if (remainder == 0)
            {

                redixArr[zero++][remainder] = arr[j];
            }
            else if (remainder == 1)
            {

                redixArr[one++][remainder] = arr[j];
            }
            else if (remainder == 2)
            {

                redixArr[two++][remainder] = arr[j];
            }
            else if (remainder == 3)
            {

                redixArr[three++][remainder] = arr[j];
            }
            else if (remainder == 4)
            {

                redixArr[four++][remainder] = arr[j];
            }
            else if (remainder == 5)
            {

                redixArr[five++][remainder] = arr[j];
            }
            else if (remainder == 6)
            {

                redixArr[six++][remainder] = arr[j];
            }
            else if (remainder == 7)
            {

                redixArr[seven++][remainder] = arr[j];
            }
            else if (remainder == 8)
            {

                redixArr[eight++][remainder] = arr[j];
            }
            else
            {

                redixArr[nine++][remainder] = arr[j];
            }
        }
        int count = 0;
        for (int i = 0; i < size; i++)
        {
            int j = 1;
            while (redixArr[j][i] != 0)
            {
                arr[count++] = redixArr[j][i];
                j++;
            }
        }
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
            {
                redixArr[i][j] = 0;
            }
        }
    }
}

void main()
{
    redixSort();

    for (int i = 0; i < size; i++)
    {
        printf(" %d ", arr[i]);
    }
}
