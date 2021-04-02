/*bool canJump(int* nums, int numsSize){
    //last记录能到达最后元素的最前位置
    int last = numsSize - 1;
    //从倒数第二个往前遍历，遍历到的元素能到达last标记的位置时，更新last
    for (int i = numsSize - 2; i >= 0; i--)
    {
        if (i + nums[i] >= last) {last = i;}
    }
    //当last==0则表示能到达0
    return last == 0;
}*/


int Max(int a, int b) { return a > b ? a : b; }

bool canJump(int* nums, int numsSize) {
    //reach记录能到达的最远距离
    int reach = 0;
    //遍历整个数组
    for (int i = 0; i < numsSize; i++)
    {
        //i>reach表示i到达了reach达不到的位置，返回假
        if (i > reach) { return false; }
        reach = Max(i + nums[i], reach);
    }
    //出循环表示，i一直<=reach
    return true;
}