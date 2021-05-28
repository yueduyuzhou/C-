/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

int** matrixReshape(int** nums, int numsSize, int* numsColSize, int r, int c, int* returnSize, int** returnColumnSizes) {
    if (r * c != numsSize * (*numsColSize))
    {
        *returnColumnSizes = numsColSize;
        *returnSize = numsSize;
        return nums;
    }

    int** res = (int**)malloc(sizeof(int*) * r);
    assert(res);
    (*returnColumnSizes) = (int*)malloc(sizeof(int) * r);
    assert(*returnColumnSizes);
    for (int i = 0; i < r; i++)
    {
        res[i] = (int*)malloc(sizeof(int) * c);
        assert(res[i]);
        (*returnColumnSizes)[i] = c;
    }

    int i2 = 0;
    int j2 = 0;
    for (int i = 0; i < numsSize; i++)
    {
        for (int j = 0; j < *numsColSize; j++)
        {
            res[i2][j2++] = nums[i][j];

            //if (i2 == r) {i2++;}
            if (j2 == c)
            {
                j2 = 0;
                i2++;
            }
        }
    }

    *returnSize = r;
    return res;
}