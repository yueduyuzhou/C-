#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

//����һ��ʶ��汾��
//1,ʶ�������İ汾��
//2,���չ���Ƚϰ汾�ŵĴ�С

#define     MIN(a, b)       ((a) < (b) ? (a) : (b))
#define     MAX(a, b)       ((a) > (b) ? (a) : (b))

struct VersionInfo {
    int     iNum;
    int* pLevel;
};

//����һ���汾�Žṹ��ʼ��
bool VersionInfoInit(struct VersionInfo** pstrVer, int iLen) {

    (*pstrVer) = (struct VersionInfo*)malloc(sizeof(struct VersionInfo));
    if (NULL == (*pstrVer)) return false;

    (*pstrVer)->iNum = (iLen / 2) + 1;
    (*pstrVer)->pLevel = (int*)malloc(sizeof(int) * (*pstrVer)->iNum);
    if (NULL == (*pstrVer)->pLevel) return false;

    memset((*pstrVer)->pLevel, 0x00, sizeof(int) * (*pstrVer)->iNum);
    return true;
}

//���������汾�Žṹ�ͷ�
void VersionInfoFree(struct VersionInfo* pstrVer) {

    if (NULL == pstrVer) return;

    if (NULL != pstrVer->pLevel)
    {
        free(pstrVer->pLevel);
        pstrVer->pLevel = NULL;
    }

    free(pstrVer);
    return;
}

//���������ַ���ת��������
int Atoi(const char* pVer, int iLen) {
    int     iRet = 0;
    char* pTmp = NULL;

    if (NULL == pVer) return -1;

    pTmp = (char*)malloc(sizeof(char) * (iLen + 1));
    if (NULL == pTmp) return -1;
    memset(pTmp, 0x00, sizeof(char) * (iLen + 1));

    memcpy(pTmp, pVer, sizeof(char) * iLen);
    iRet = atoi(pTmp);

    free(pTmp);
    pTmp = NULL;
    return iRet;
}

//�����ģ��汾���ַ�����������
bool AnalysisVer(char* pVer, struct VersionInfo* pstrVer) {
    int     i = 0;
    int     iIndex = 0;
    int     iLen = 0;
    char* pHead = pVer;
    char* pTail = pVer;

    if ((NULL == pVer) || (NULL == pstrVer)) return false;

    while (pVer[i] != '\0') {
        if (pVer[i] == '.')
        {
            if (iLen == 0) return false;
            if (iIndex >= pstrVer->iNum) return false;

            pstrVer->pLevel[iIndex] = Atoi(pHead, iLen);
            if (pstrVer->pLevel[iIndex] < 0) return false;

            pTail += 1;
            pHead = pTail;
            iIndex += 1;
            iLen = 0;
        }
        else
        {
            pTail += 1;
            iLen += 1;
        }

        i += 1;
    }

    if (iLen > 0)
    {
        if (iIndex >= pstrVer->iNum) return false;
        pstrVer->pLevel[iIndex] = Atoi(pHead, iLen);
        if (pstrVer->pLevel[iIndex] < 0) return false;
    }

    return true;
}

//�����壺�汾�űȽϺ���
int compareVer(struct VersionInfo* pstrVerI, struct VersionInfo* pstrVerII) {
    int     i = 0;

    if ((NULL == pstrVerI) || (NULL == pstrVerII)) return 0;

    for (i = 0; i < pstrVerI->iNum; i++)
    {
        if (pstrVerI->pLevel[i] > pstrVerII->pLevel[i])
        {
            return 1;
        }

        if (pstrVerI->pLevel[i] < pstrVerII->pLevel[i])
        {
            return -1;
        }
    }

    return 0;
}

//������
int compareVersion(char* version1, char* version2) {
    int     iRet = 0;
    int     iLen1 = strlen(version1);
    int     iLen2 = strlen(version2);

    struct VersionInfo* pstrVerI = NULL;
    struct VersionInfo* pstrVerII = NULL;

    if ((NULL == version1) || (NULL == version2)) return 0;

    if (false == VersionInfoInit(&pstrVerI, MAX(iLen1, iLen2))) return 0;
    if (false == VersionInfoInit(&pstrVerII, MAX(iLen1, iLen2))) return 0;

    if (false == AnalysisVer(version1, pstrVerI)) return 0;
    if (false == AnalysisVer(version2, pstrVerII)) return 0;

    iRet = compareVer(pstrVerI, pstrVerII);

    VersionInfoFree(pstrVerI);
    pstrVerI = NULL;
    VersionInfoFree(pstrVerII);
    pstrVerII = NULL;
    return iRet;
}

/***************************************************************************************************************************************/



int main()
{
    char* a = "1.01";
    char* b = "1.001";
    compareVersion(a, b);

    system("pause");

    return 0;
}