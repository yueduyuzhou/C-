/*bool canJump(int* nums, int numsSize){
    //last��¼�ܵ������Ԫ�ص���ǰλ��
    int last = numsSize - 1;
    //�ӵ����ڶ�����ǰ��������������Ԫ���ܵ���last��ǵ�λ��ʱ������last
    for (int i = numsSize - 2; i >= 0; i--)
    {
        if (i + nums[i] >= last) {last = i;}
    }
    //��last==0���ʾ�ܵ���0
    return last == 0;
}*/


int Max(int a, int b) { return a > b ? a : b; }

bool canJump(int* nums, int numsSize) {
    //reach��¼�ܵ������Զ����
    int reach = 0;
    //������������
    for (int i = 0; i < numsSize; i++)
    {
        //i>reach��ʾi������reach�ﲻ����λ�ã����ؼ�
        if (i > reach) { return false; }
        reach = Max(i + nums[i], reach);
    }
    //��ѭ����ʾ��iһֱ<=reach
    return true;
}