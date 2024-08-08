#include <stdio.h>
#include <stdlib.h>

void main()
{
    int a[6] = {25, 20, 96, 88, 70, 85};
    int hash[10] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1};

    int coll = 0;
    for (int i = 0; i < 6; i++)
    {
        int mod = a[i] % 10;
        while (1)
        {
            if (hash[mod] == -1)
            {
                hash[mod] = a[i];
                break;
            }
            else
            {
                mod++;
                coll++;
            }
        }
    }

    for (int i = 0; i < 10; i++)
    {
        printf("%d ", hash[i]);
    }

    printf("\nNumber of collisions = %d",coll);
}