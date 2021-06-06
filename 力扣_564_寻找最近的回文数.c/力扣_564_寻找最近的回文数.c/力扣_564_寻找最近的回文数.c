#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE    18
#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define ABS(a)  ((a) >= 0 ? (a) : -(a))
typedef long long int64;

static int64 CalcHighHalfVal(char* n)
{
    char high_half[MAX_SIZE / 2 + 2];
    int  inputlen, halflen;

    inputlen = strlen(n);
    halflen = (inputlen + 1) / 2;
    strncpy(high_half, n, halflen);
    high_half[halflen] = '\0';

    return atoll(high_half);
}

/* �����������ֵĸ߰벿��hhalf������߰벿�ֵĻ������֡�lowhalflen��ʾ��Ҫ����ĵͰ벿�ֳ��� */
static int64 PalindByHighHalf(int64 hhalfval, int lowhalflen)
{
    int halflen, i;
    char buff[MAX_SIZE + 2];

    if (hhalfval == 0) {
        /* 10~19֮������֣���1��Ļ������̶ֹ�Ϊ9 */
        return 9;
    }

    snprintf(buff, sizeof(buff), "%lld", hhalfval);
    halflen = strlen(buff);

    if (lowhalflen <= halflen) {
        for (i = 0; i < lowhalflen; i++) {
            buff[halflen + lowhalflen - 1 - i] = buff[i];
        }
    }
    else {
        /* ����������Ϊ1000��ǰ�벿��Ϊ10���������1ʱ���9����ʱlowhalflenΪ2��halflenΪ1�����ֵͰ벿�ֳ��ȴ��ڸ߰벿�ֵ����
            ��ʱ����Ҫ�ԵͰ벿��ȫ�����9 */
        for (i = 0; i < lowhalflen; i++) {
            buff[halflen + i] = '9';
        }
    }
    buff[halflen + lowhalflen] = '\0';

    return atoll(buff);
}


static char strbuff[MAX_SIZE + 2];
char* nearestPalindromic(char* n)
{
    int64 inputval, outval, outval0, outval1;
    int64 halfval;
    int  inputlen, halflen;

    inputval = atoll(n);
    if (inputval <= 10) {
        outval = inputval - 1;
        snprintf(strbuff, sizeof(strbuff), "%lld", outval);
        return strbuff;
    }

    inputlen = strlen(n);
    halflen = (inputlen + 1) / 2;
    halfval = CalcHighHalfVal(n);

    outval1 = PalindByHighHalf(halfval, inputlen - halflen);
    if (outval1 > inputval) {
        outval0 = PalindByHighHalf(halfval - 1, inputlen - halflen);
    }
    else if (outval1 < inputval) {
        outval0 = PalindByHighHalf(halfval + 1, inputlen - halflen);
    }
    else {
        outval0 = PalindByHighHalf(halfval - 1, inputlen - halflen);
        outval1 = PalindByHighHalf(halfval + 1, inputlen - halflen);
    }

    outval = ABS(inputval - outval0) < ABS(inputval - outval1) ? outval0 : outval1;
    outval = ABS(inputval - outval0) == ABS(inputval - outval1) ? MIN(outval0, outval1) : outval;

    snprintf(strbuff, sizeof(strbuff), "%lld", outval);
    return strbuff;
}

