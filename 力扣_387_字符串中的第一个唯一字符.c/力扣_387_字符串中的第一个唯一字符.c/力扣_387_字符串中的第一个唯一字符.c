#include <stdio.h>

int firstUniqChar(char* s) {
    int letterhash[26] = { 0 };

    int index = 0;

    while (s[index] != '\0')
    {
        letterhash[s[index] - 'a']++;
        index++;
    }


    /*for (int i = 0; i < 26; i++)
    {
        printf ("%d ", letterhash[i]);
    }*/


    index = 0;
    while (s[index] != '\0')
    {
        if (letterhash[s[index] - 'a'] == 1)
        {
            return index;
        }
        //printf ("%d ", s[index]);
        index++;
    }

    return -1;
}



int main()
{
    char ch[9] = { 'l', 'e', 'e', 't', 'c', 'o', 'd', 'e', '\0'};
    firstUniqChar(ch);


	system("pause");
	return 0;
}