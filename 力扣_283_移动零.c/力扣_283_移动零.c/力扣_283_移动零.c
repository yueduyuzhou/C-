#include <stdio.h>

void moveZeroes(int* nums, int numsSize) {
    int tofront = 0;
    int totail = 0;

    //totail指向第一个0
    //tofront指向第一个非零
    while (tofront < numsSize && nums[tofront] == 0) { tofront++; }
    while (totail < numsSize && nums[totail] != 0) { totail++; }

    while (tofront < numsSize && totail < numsSize)
    {
        //设置标记
        int flag = 0;
        if (nums[tofront] != 0 && nums[totail] == 0 && tofront > totail)
        {
            flag = 1;
            int tmp = nums[totail];
            nums[totail] = nums[tofront];
            nums[tofront] = tmp;
        }

        //运行到这里时，flag=0说明没进入交换
        //原因可能为tofront<=totail,则使tofront指向后一个(totail不可加一,否则会漏掉0)
        if (flag == 0)
        {
            tofront++;
            //totail++;      
        }

        //totail指向下一个0
        //tofront指向下一个非零
        while (tofront < numsSize && nums[tofront] == 0) { tofront++; }
        while (totail < numsSize && nums[totail] != 0) { totail++; }
    }
}

int main()
{

	system("pause");
	return 0;
}