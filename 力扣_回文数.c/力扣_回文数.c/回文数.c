#include <stdio.h>
#include <stdbool.h>

bool isPalindrome(int x)
{
    if (x < 0)
    {
        return false;
    }
    int left = 0, right = 0;
    int arr[10] = { 0 };
    while (x != 0)
    {
        arr[right] = x % 10;
        x = x / 10;
        right++;
    }
    while (left < right)
    {
        if (arr[left] != arr[right - 1])
        {
            return false;
        }
        left++;
        right--;
    }
    return true;
}

int main()
{
    int x = 0;
    scanf("%d", &x);
    if (isPalindrome(x))
    {
        printf("%d是回文数\n",x);
    }
    else
    {
        printf("%d不是回文数\n", x);
    }

    return 0;
}










