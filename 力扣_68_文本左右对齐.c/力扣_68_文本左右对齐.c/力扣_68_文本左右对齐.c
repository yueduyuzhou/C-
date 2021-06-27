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
        // ˵��ֻ��һ��Ԫ�أ�����룬���ಹ�ո�
        memcpy(res, words[start], strlen(words[start]));
        memset(res + strlen(words[start]), ' ', maxWidth - strlen(words[start]));
        return res;
    }
    // Ҳ������룬һ�����ʺ����һ������Ĳ��ո�
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
// ������ͨ������
char* GetLine(char** words, int wordsSize, int start, int end, int maxWidth, int curLen)
{
    char* res = (char*)malloc(sizeof(char) * (maxWidth + 1));
    memset(res, 0, sizeof(char) * (maxWidth + 1));
    // ˵��ֻ��һ��Ԫ�أ�����룬���ಹ�ո�
    if (start == end) {
        memcpy(res, words[start], strlen(words[start]));
        memset(res + strlen(words[start]), ' ', maxWidth - strlen(words[start]));
        return res;
    }
    // space��ÿ������֮��Ŀո���
    int space[end - start];
    // space��ʼ��ȫΪ1
    for (int i = 0; i < end - start; i++) {
        space[i] = 1;
    }
    int k = 0;
    int num = maxWidth - curLen;
    // ������1��ƽ���ĸ���space
    while (num != 0) {
        space[k]++;
        k++;
        k = k % (end - start);
        num--;
    }
    int pos = 0;
    // posΪ���λ��,������word�����϶�Ӧ�����Ŀո�ѭ����
    for (int i = start; i < end; i++) {
        memcpy(res + pos, words[i], strlen(words[i]));
        pos += strlen(words[i]);
        memset(res + pos, ' ', space[i - start]);
        pos += space[i - start];
    }
    // ��󣬸��������һ������Ϊ���һ�����治�ӿո�
    memcpy(res + pos, words[end], strlen(words[end]));
    return res;
}

char** fullJustify(char** words, int wordsSize, int maxWidth, int* returnSize) {
    char** res = (char**)malloc(sizeof(char*) * wordsSize);
    *returnSize = 0;

    int start = 0; // ÿһ�ֵ��ʵ���ʼλ��
    int end = -1; // ÿһ�ֵ��ʵ����һ����λ��
    while (start < wordsSize) {
        int curLen = 0; // ���Ͽո��ǰ�ַ�������
        int wordIndex = end + 1; // �ô���ĵ���index
        // ÿһ�п�ʼ��һ�ӵ���
        while (curLen <= maxWidth && wordIndex < wordsSize) {
            curLen += strlen(words[wordIndex]);
            // �ӳ��ˣ���һ�����ʣ����Ѷ�ӵĿո�Ҳ�˵�
            if (curLen > maxWidth) {
                end = wordIndex - 1;
                curLen--;
                curLen -= strlen(words[wordIndex]);
                break;
            }
            // �����������е���
            else if (curLen == maxWidth) {
                end = wordIndex;
                break;
            }
            curLen++;
            wordIndex++;
            end = wordIndex - 1;
        }
        // ���е��ʶ������ˣ�Ҳ�������һ��
        if (wordIndex >= wordsSize) {
            res[(*returnSize)++] = GetLastLine(words, wordsSize, start, end, maxWidth);
            break;
        }
        // �е���û�ã��������һ��
        res[(*returnSize)++] = GetLine(words, wordsSize, start, end, maxWidth, curLen);
        start = end + 1;
    }
    // ��ֹ���һ�������������е��ʣ������һ�е����
    if (res[(*returnSize) - 1][0] == ' ') {
        (*returnSize)--;
    }
    return res;
}

/***************************************************************************************************************************************/
//����һ��
//1,�Ⱦ���һ�зŶ��ٸ�����
//2,ȷ���Ŷ��ٸ�����֮�����һ���пո���η���

//����һ����д���ʣ����Ҷ��룬�������ո�
void fillWords(char** words, int iNum, char* pRet, int iLen, int maxWidth) {
    int     i = 0;
    int     iSpaceNum = 0;    //�ո�����
    int     iAveNum = 0;    //ƽ���ո���
    int     iresNum = 0;    //ʣ��ո���
    int     ipos = 0;

    //1,����ո�ƽ������ʣ��ո���
    iSpaceNum = maxWidth - iLen;
    if (iNum > 1)
    {
        iAveNum = iSpaceNum / (iNum - 1);
        iresNum = iSpaceNum % (iNum - 1);
    }

    //2,�������ȫ�����Ͽո�
    for (i = 0; i < maxWidth; i++)
    {
        pRet[i] = ' ';
    }

    //3,�����ʲ�����Ӧ��λ��
    for (i = 0; i < iNum; i++)
    {
        memcpy(&pRet[ipos], words[i], strlen(words[i]));
        ipos += strlen(words[i]) + iAveNum;
        if (iresNum > 0)
        {
            //�����ʣ��ո�������������һ�����ʶ���һ���ո�
            ipos += 1;
            iresNum -= 1;
        }
    }

    return;
}

//�����������һ�д��������
void fillWordsLastRow(char** words, int iNum, char* pRet, int maxWidth) {
    int     i = 0;
    int     ipos = 0;

    //1,�������ȫ�����Ͽո�
    for (i = 0; i < maxWidth; i++)
    {
        pRet[i] = ' ';
    }

    //2,�����ʲ�����Ӧ��λ��
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

    //1,��ʼ��
    pRet = (char**)malloc(sizeof(char*) * wordsSize);
    memset(pRet, 0x00, sizeof(char*) * wordsSize);

    //2,ѭ��������
    for (i = 0; i < wordsSize; i++)
    {
        if (iTmpLen + strlen(words[i]) + iTmpNum > maxWidth)
        {
            //            printf("[1][i=%d][num=%d][len1=%d][len2=%d][%s]\n", i, iTmpNum, iTmpLen, strlen(words[i]), words[i]);
                        //3����δ������󳤶ȵĵ�����д�������
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
        //4,���һ�д���
    if (iPos <= wordsSize - 1)
    {
        pRet[iRetSize] = (char*)malloc(sizeof(char) * (maxWidth + 1));
        memset(pRet[iRetSize], 0x00, sizeof(char) * (maxWidth + 1));

        fillWordsLastRow(&words[iPos], iTmpNum, pRet[iRetSize], maxWidth);
        iRetSize += 1;
    }

    //    printf("[3][size=%d]\n", iRetSize);
        //5,����
    *returnSize = iRetSize;
    return pRet;
}

int main()
{

    system("pause");

    exit(0);
}