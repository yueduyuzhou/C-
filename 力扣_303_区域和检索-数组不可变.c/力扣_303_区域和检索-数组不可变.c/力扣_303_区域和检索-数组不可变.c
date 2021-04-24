/***********************************************************************************************************************/
typedef struct {
    int* nums;
} NumArray;


NumArray* numArrayCreate(int* nums, int numsSize) {
    NumArray* resnums;    //->nums = (int*)malloc(sizeof(int) * numsSize);
    //memset(resnums, 0, sizeof(resnums));    
    resnums = malloc(sizeof(NumArray*));
    assert(resnums);
    resnums->nums = malloc(sizeof(int) * numsSize);
    assert(resnums->nums);

    for (int i = 0; i < numsSize; i++)
    {
        resnums->nums[i] = nums[i];
    }

    return resnums;
}

int numArraySumRange(NumArray* obj, int left, int right) {
    int sum = 0;

    for (; left <= right; left++)
    {
        sum += obj->nums[left];
    }

    return sum;
}

void numArrayFree(NumArray* obj) {
    free(obj->nums);
    obj->nums = NULL;
}
/***********************************************************************************************************************/
typedef struct {
    int* nums;
} NumArray;


NumArray* numArrayCreate(int* nums, int numsSize) {
    NumArray* resnums;    //->nums = (int*)malloc(sizeof(int) * numsSize);
    //memset(resnums, 0, sizeof(resnums));    
    resnums = malloc(sizeof(NumArray*));
    assert(resnums);
    resnums->nums = malloc(sizeof(int) * (numsSize + 1));
    assert(resnums->nums);

    for (int i = 0; i < numsSize; i++)
    {
        resnums->nums[i + 1] = nums[i] + resnums->nums[i];
    }

    return resnums;
}

int numArraySumRange(NumArray* obj, int left, int right) {
    return obj->nums[right + 1] - obj->nums[left];
}

void numArrayFree(NumArray* obj) {
    free(obj->nums);
    obj->nums = NULL;
}