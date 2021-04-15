#include <stdio.h>

void moveZeroes(int* nums, int numsSize) {
    int tofront = 0;
    int totail = 0;

    //totailָ���һ��0
    //tofrontָ���һ������
    while (tofront < numsSize && nums[tofront] == 0) { tofront++; }
    while (totail < numsSize && nums[totail] != 0) { totail++; }

    while (tofront < numsSize && totail < numsSize)
    {
        //���ñ��
        int flag = 0;
        if (nums[tofront] != 0 && nums[totail] == 0 && tofront > totail)
        {
            flag = 1;
            int tmp = nums[totail];
            nums[totail] = nums[tofront];
            nums[tofront] = tmp;
        }

        //���е�����ʱ��flag=0˵��û���뽻��
        //ԭ�����Ϊtofront<=totail,��ʹtofrontָ���һ��(totail���ɼ�һ,�����©��0)
        if (flag == 0)
        {
            tofront++;
            //totail++;      
        }

        //totailָ����һ��0
        //tofrontָ����һ������
        while (tofront < numsSize && nums[tofront] == 0) { tofront++; }
        while (totail < numsSize && nums[totail] != 0) { totail++; }
    }
}

int main()
{

	system("pause");
	return 0;
}