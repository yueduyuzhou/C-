#include <stdio.h>
#include <stdbool.h>


    bool canConstruct(char* ransomNote, char* magazine) {
        int ransomhash[26] = { 0 };
        int magazinehash[26] = { 0 };
        int index = 0;

        while (ransomNote[index] != '\0')
        {
            ransomhash[ransomNote[index] - 'a']++;
            index++;
        }

        index = 0;
        while (magazine[index] != '\0')
        {
            magazinehash[magazine[index] - 'a']++;
            index++;
        }

        /*for (int i = 0; i < 26; i++)
        {
            printf ("%d%d  ", ransomhash[i], magazinehash[i]);
        }*/

        for (int i = 0; i < 26; i++)
        {
            if (ransomhash[i] > magazinehash[i])
            {
                return false;
            }
        }

        return true;
    }

int main()
{
    char a[3] = { 'a', 'a', '\0' };
    char b[4] = { 'a', 'a', 'b', '\0' };

    canConstruct(a, b);


	system("pause");
	return 0;
}