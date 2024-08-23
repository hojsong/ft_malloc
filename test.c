#include <stdio.h>

int main()
{
    int x, y, z, i;

    // i = 1;
    // while (1)
    // {
    //     x = i * 4096;
    //     x -= 32;
    //     x /= 17;
    //     x *= 16;
    //     y = x / 1024;
    //     if (y >= 200)
    //     {
    //         printf("%d\n", i);
    //         break;
    //     }
    //     i++;
    // }
    i = 54;
    while(1)
    {
        x = i * 4096;
        x -= 32;
        z = x / 1088;
        y = 1024 / z;
        if (1024 % z)
            y++;
        printf("%d : %d %d %d\n", i, i * y, y, z);
        if (i * y <= 273 || i >= 275)
        {
            printf("%d\n",i);
            break;
        }
        i++;
    }
}

452 - 191 261
514 - 245 269