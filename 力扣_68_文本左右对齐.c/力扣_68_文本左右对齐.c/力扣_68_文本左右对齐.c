#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int space_num;
    int word_num;
}node;

char** fullJustify(char** words, int wordsSize, int maxWidth, int* returnSize) {
    node** arr = (node**)malloc(sizeof(node*) * wordsSize);
    if (arr == NULL) { return NULL; }

    int index_words = 0;
    int index_arr = 0;
    int total_len = 0;
    while (index_words < wordsSize)
    {
        int tmp_arr = 0;
        if (total_len + strlen(words[index_words] + 1) <= maxWidth)
        {
            total_len += strlen(words[index_words]) + 1;
            tmp_arr++;
        }
        else
        {
            arr[index_arr]->space_num = maxWidth - total_len;
            arr[index_arr++]->word_num = tmp_arr;
        }

        index_words++;
    }

    char** res = (char**)malloc(sizeof(char*) * index_arr);
    if (res == NULL) { return NULL; }
    int i = 0;
    while (i < index_arr)
    {
        res[i] = (char*)malloc(sizeof(char) * maxWidth);
        if (res[i] == NULL) { return NULL; }
    }

    index_words = 0;
    while (index_words < wordsSize)
    {
        i = 0;
        int j = 0;
        while (i < index_arr)
        {
            if (arr[i]->space_num < arr[i]->word_num)
            {
                int j = 0;
            }
        }

    }

    *returnSize = index_arr;
    return res;
}

/***************************************************************************************************************************************/

char* GetLastLine(char** words, int wordsSize, int start, int end, int maxWidth)
{
    char* res = (char*)malloc(sizeof(char) * (maxWidth + 1));
    memset(res, 0, sizeof(char) * (maxWidth + 1));
    if (start == end) {
        // 说明只有一个元素，左对齐，其余补空格
        memcpy(res, words[start], strlen(words[start]));
        memset(res + strlen(words[start]), ' ', maxWidth - strlen(words[start]));
        return res;
    }
    // 也是左对齐，一个单词后面空一格，其余的补空格
    int i = 0;
    for (int j = start; j <= end; j++) {
        memcpy(res + i, words[j], strlen(words[j]));
        if (i + strlen(words[j]) < maxWidth) {
            res[i + strlen(words[j])] = ' ';
        }
        i += strlen(words[j]) + 1;
    }
    for (int j = i; j < maxWidth; j++) {
        res[j] = ' ';
    }
    return res;
}
// 处理普通行数据
char* GetLine(char** words, int wordsSize, int start, int end, int maxWidth, int curLen)
{
    char* res = (char*)malloc(sizeof(char) * (maxWidth + 1));
    memset(res, 0, sizeof(char) * (maxWidth + 1));
    // 说明只有一个元素，左对齐，其余补空格
    if (start == end) {
        memcpy(res, words[start], strlen(words[start]));
        memset(res + strlen(words[start]), ' ', maxWidth - strlen(words[start]));
        return res;
    }
    // space存每个单词之间的空格数
    int space[end - start];
    // space初始化全为1
    for (int i = 0; i < end - start; i++) {
        space[i] = 1;
    }
    int k = 0;
    int num = maxWidth - curLen;
    // 轮流加1，平均的更新space
    while (num != 0) {
        space[k]++;
        k++;
        k = k % (end - start);
        num--;
    }
    int pos = 0;
    // pos为相对位置,先贴上word再贴上对应数量的空格，循环做
    for (int i = start; i < end; i++) {
        memcpy(res + pos, words[i], strlen(words[i]));
        pos += strlen(words[i]);
        memset(res + pos, ' ', space[i - start]);
        pos += space[i - start];
    }
    // 最后，复制上最后一个，因为最后一个后面不加空格
    memcpy(res + pos, words[end], strlen(words[end]));
    return res;
}

char** fullJustify(char** words, int wordsSize, int maxWidth, int* returnSize) {
    char** res = (char**)malloc(sizeof(char*) * wordsSize);
    *returnSize = 0;

    int start = 0; // 每一轮单词的起始位置
    int end = -1; // 每一轮单词的最后一个的位置
    while (start < wordsSize) {
        int curLen = 0; // 加上空格后当前字符串长度
        int wordIndex = end + 1; // 该处理的单词index
        // 每一行开始逐一加单词
        while (curLen <= maxWidth && wordIndex < wordsSize) {
            curLen += strlen(words[wordIndex]);
            // 加超了，退一个单词，并把多加的空格也退掉
            if (curLen > maxWidth) {
                end = wordIndex - 1;
                curLen--;
                curLen -= strlen(words[wordIndex]);
                break;
            }
            // 正好用完所有单词
            else if (curLen == maxWidth) {
                end = wordIndex;
                break;
            }
            curLen++;
            wordIndex++;
            end = wordIndex - 1;
        }
        // 所有单词都用完了，也就是最后一行
        if (wordIndex >= wordsSize) {
            res[(*returnSize)++] = GetLastLine(words, wordsSize, start, end, maxWidth);
            break;
        }
        // 有单词没用，不是最后一行
        res[(*returnSize)++] = GetLine(words, wordsSize, start, end, maxWidth, curLen);
        start = end + 1;
    }
    // 防止最后一行正好用完所有单词，多加了一行的情况
    if (res[(*returnSize) - 1][0] == ' ') {
        (*returnSize)--;
    }
    return res;
}

/***************************************************************************************************************************************/
//方法一：
//1,先决定一行放多少个单词
//2,确定放多少个单词之后决定一行中空格如何分配

//函数一：填写单词，左右对齐，合理分配空格
void fillWords(char** words, int iNum, char* pRet, int iLen, int maxWidth) {
    int     i = 0;
    int     iSpaceNum = 0;    //空格总数
    int     iAveNum = 0;    //平均空格数
    int     iresNum = 0;    //剩余空格数
    int     ipos = 0;

    //1,计算空格平均数及剩余空格数
    iSpaceNum = maxWidth - iLen;
    if (iNum > 1)
    {
        iAveNum = iSpaceNum / (iNum - 1);
        iresNum = iSpaceNum % (iNum - 1);
    }

    //2,将结果先全部填上空格
    for (i = 0; i < maxWidth; i++)
    {
        pRet[i] = ' ';
    }

    //3,将单词插入相应的位置
    for (i = 0; i < iNum; i++)
    {
        memcpy(&pRet[ipos], words[i], strlen(words[i]));
        ipos += strlen(words[i]) + iAveNum;
        if (iresNum > 0)
        {
            //如果有剩余空格数，则从左边起，一个单词多填一个空格
            ipos += 1;
            iresNum -= 1;
        }
    }

    return;
}

//函数二：最后一行处理，左对齐
void fillWordsLastRow(char** words, int iNum, char* pRet, int maxWidth) {
    int     i = 0;
    int     ipos = 0;

    //1,将结果先全部填上空格
    for (i = 0; i < maxWidth; i++)
    {
        pRet[i] = ' ';
    }

    //2,将单词插入相应的位置
    for (i = 0; i < iNum; i++)
    {
        memcpy(&pRet[ipos], words[i], strlen(words[i]));
        ipos += strlen(words[i]) + 1;
    }

    return;
}

char** fullJustify(char** words, int wordsSize, int maxWidth, int* returnSize) {
    int         i = 0;
    int         iTmpLen = 0;
    int         iTmpNum = 0;
    int         iPos = 0;
    int         iRetSize = 0;
    char** pRet = NULL;

    if ((NULL == words) || (0 == wordsSize)) return NULL;

    //1,初始化
    pRet = (char**)malloc(sizeof(char*) * wordsSize);
    memset(pRet, 0x00, sizeof(char*) * wordsSize);

    //2,循环处理单词
    for (i = 0; i < wordsSize; i++)
    {
        if (iTmpLen + strlen(words[i]) + iTmpNum > maxWidth)
        {
            //            printf("[1][i=%d][num=%d][len1=%d][len2=%d][%s]\n", i, iTmpNum, iTmpLen, strlen(words[i]), words[i]);
                        //3，将未超过最大长度的单词填写到结果中
            pRet[iRetSize] = (char*)malloc(sizeof(char) * (maxWidth + 1));
            memset(pRet[iRetSize], 0x00, sizeof(char) * (maxWidth + 1));

            fillWords(&words[iPos], iTmpNum, pRet[iRetSize], iTmpLen, maxWidth);

            iPos = i;
            iTmpNum = 0;
            iTmpLen = 0;
            iRetSize += 1;
        }

        iTmpNum += 1;
        iTmpLen += strlen(words[i]);
    }

    //    printf("[2][ipos=%d][num=%d][size=%d][%s]\n", iPos, iTmpNum, iRetSize, words[iPos]);
        //4,最后一行处理
    if (iPos <= wordsSize - 1)
    {
        pRet[iRetSize] = (char*)malloc(sizeof(char) * (maxWidth + 1));
        memset(pRet[iRetSize], 0x00, sizeof(char) * (maxWidth + 1));

        fillWordsLastRow(&words[iPos], iTmpNum, pRet[iRetSize], maxWidth);
        iRetSize += 1;
    }

    //    printf("[3][size=%d]\n", iRetSize);
        //5,返回
    *returnSize = iRetSize;
    return pRet;
}

int main()
{

    system("pause");

    exit(0);
}