#include <stdio.h>

int main()
{
    int n = 0, i = 0;
    int arr[31] = { 0 }; 
    scanf("%d", &n);
    arr[0] = 0;
    arr[1] = 1;
    for (i = 2; i <= n; i++)    
    {
        arr[i] = arr[i - 1] + arr[i - 2];    //从第三项开始算斐波那契数    
    }
    printf("%d", arr[n]);
    main();

    return 0;
}