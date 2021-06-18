#include <stdio.h>

char* intToRoman(int num) {
    int roman[13] = { 1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1 };
    char* res = (char*)malloc(sizeof(char) * 55);
    int i = 0;
    while (num != 0)
    {
        int j = 0;
        while (j < 13)
        {
            if (num >= roman[j])
            {
                if (j == 1)
                {
                    sprintf(res + i, "%c", 'C');
                    i++;
                    sprintf(res + i, "%c", 'M');
                }
                else if (j == 3)
                {
                    sprintf(res + i, "%c", 'C');
                    i++;
                    sprintf(res + i, "%c", 'D');
                }
                else if (j == 5)
                {
                    sprintf(res + i, "%c", 'X');
                    i++;
                    sprintf(res + i, "%c", 'C');
                }
                else if (j == 7)
                {
                    sprintf(res + i, "%c", 'X');
                    i++;
                    sprintf(res + i, "%c", 'L');
                }
                else if (j == 9)
                {
                    sprintf(res + i, "%c", 'I');
                    i++;
                    sprintf(res + i, "%c", 'X');
                }
                else if (j == 11)
                {
                    sprintf(res + i, "%c", 'I');
                    i++;
                    sprintf(res + i, "%c", 'V');
                }
                else if (j == 0) { sprintf(res + i, "%c", 'M'); }
                else if (j == 2) { sprintf(res + i, "%c", 'D'); }
                else if (j == 4) { sprintf(res + i, "%c", 'C'); }
                else if (j == 6) { sprintf(res + i, "%c", 'L'); }
                else if (j == 8) { sprintf(res + i, "%c", 'X'); }
                else if (j == 10) { sprintf(res + i, "%c", 'V'); }
                else if (j == 12) { sprintf(res + i, "%c", 'I'); }
                //printf ("%d ", roman[j]);
                num -= roman[j];
                i++;
                break;
                //printf ("%d ", num);
                //break;
            }
            j++;
        }
    }

    sprintf(res + i, "%c", '\0');
    return res;
}

/***************************************************************************************************************/

const int values[] = { 1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1 };
const char* symbols[] = { "M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I" };

char* intToRoman(int num) {
    char* roman = malloc(sizeof(char) * 16);
    roman[0] = '\0';
    for (int i = 0; i < 13; i++) {
        while (num >= values[i]) {
            num -= values[i];
            strcpy(roman + strlen(roman), symbols[i]);
        }
        if (num == 0) {
            break;
        }
    }
    return roman;
}

/***************************************************************************************************************/
const char* thousands[] = { "", "M", "MM", "MMM" };
const char* hundreds[] = { "", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM" };
const char* tens[] = { "", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC" };
const char* ones[] = { "", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX" };

char* intToRoman(int num) {
    char* roman = malloc(sizeof(char) * 16);
    roman[0] = '\0';
    strcpy(roman + strlen(roman), thousands[num / 1000]);
    strcpy(roman + strlen(roman), hundreds[num % 1000 / 100]);
    strcpy(roman + strlen(roman), tens[num % 100 / 10]);
    strcpy(roman + strlen(roman), ones[num % 10]);
    return roman;
}

int main()
{
    intToRoman(3);

	system("pause");
	return 0;
}