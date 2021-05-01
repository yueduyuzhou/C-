#include <stdio.h>
#include <stdbool.h>

bool isAnagram(char* s, char* t) {
    int s_hash[26] = { 0 };
    int t_hash[26] = { 0 };
    int i = 0;

    while (s[i] != '\0' && t[i] != '\0')
    {
        s_hash[s[i] - 'a']++;
        t_hash[t[i] - 'a']++;
        i++;
    }

    if (s[i] != '\0' || t[i] != '\0') { return false; }

    int s_sum = 0;
    int t_sum = 0;
    for (i = 0; i < 26; i++)
    {
        if (s_hash[i] != t_hash[i])
        {
            return false;
        }
    }

    return true;
}

int main()
{

	system("pause");

	return 0;
}