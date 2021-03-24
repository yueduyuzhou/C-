#include <stdio.h>

//自己的递归
//void reverseString(char* s, int sSize) {
//    if (sSize == 0 || s == NULL)
//    {
//        return;
//    }
//
//    int left = 0;
//    int right = sSize - 1;
//
//    if (left < right)
//    {
//        reverseString(s + 1, sSize - 2);
//    }
//
//    char tmp = s[left];
//    s[left] = s[right];
//    s[right] = tmp;
//}

//网课的递归
void recarsion(char* s, int left, int right)
{
    if (left >= right)
    {
        return;
    }
    recarsion(s, left + 1, right - 1);

    char tmp = s[left];
    s[left] = s[right];
    s[right] = tmp;
}


void reverseString(char* s, int sSize) {
    if (s == NULL || sSize == 0)
    {
        return;
    }

    int left = 0;
    int right = sSize - 1;
    recarsion(s, left, right);
}

int main()
{
	return 0;
}