#include <stdio.h>

/*int numRescueBoats(int* people, int peopleSize, int limit){
    if (peopleSize == 1)
        return 1;

    int prev = 0;
    int rear = 1;
    int respeople = peopleSize;
    int shipnum = 0;

    while (respeople)
    {
        int flag = 0;
        while (rear < peopleSize)
        {
            if (people[prev] + people[rear] <= limit && people[prev] != 0 && people[rear] != 0 && prev != rear)
            {
                shipnum++;
                people[prev] = people[rear] = 0;
                respeople -= 2;
                flag = 1;
                break;
            }
            else //if (people[prev] + people[rear] > limit && people[prev] != 0 && people[rear] != 0)
            {
                rear++;
            }
        }
        if (flag == 0)
        {
            shipnum++;
            people[prev] = 0;
            respeople--;
        }
        while (people[prev] == 0 && prev < peopleSize - 1){
            prev++;
        }
        if (prev < peopleSize - 1){
            rear = prev + 1;
        }
    }

    return shipnum;
}*/
/*int numRescueBoats(int* people, int peopleSize, int limit){
    if (peopleSize < 2)
        return 1;

    //排序people数组
    int prev, rear, flag;
    for (prev = peopleSize; prev > 0; prev--)
    {
        flag = 0;
        for (rear = 0; rear < prev - 1; rear++)
        {
            if (people[rear] > people[rear + 1])
            {
                int tmp = people[rear];
                people[rear] = people[rear + 1];
                people[rear + 1] = tmp;
                flag = 1;
            }
        }
        if (flag == 0)
            break;
    }*/
    /*for (int i = 0; i < peopleSize; i++)
    {
        printf("%d ", people[i]);
    }*/
    /*prev = 0,rear = peopleSize - 1;
    int respeople = peopleSize;
    int shipnum = 0;
    while (respeople)
    {
        flag = 0;
        while (rear > prev)
        {
            if (people[prev] + people[rear] <= limit && people[rear] != 0)
            {
                flag = 1;
                people[prev] = people[rear] = 0;
                respeople -= 2;
                shipnum++;
                break;
            }
            else
            {
                while (people[rear] == 0 || people[prev] + people[rear] > limit)
                {
                    rear--;
                }
            }
        }
        if (flag == 0)
        {
            people[prev] = 0;
            respeople--;
            shipnum++;
        }
        if (respeople < 2)
        {
            if (respeople == 1)
                shipnum++;
            break;
        }
        //调整prev和rear的位置
        while (people[prev] == 0)
            prev++;
        rear = peopleSize - 1;
        while (people[rear] == 0)
            rear--;
    }
    return shipnum;
}*/
int cmp(const void* a, const void* b) {
    return *(int*)a - *(int*)b;
}

int numRescueBoats(int* people, int peopleSize, int limit) {
    int l = 0, r = peopleSize - 1, res = 0;

    qsort(people, peopleSize, sizeof(int), cmp);

    while (l <= r) {
        if (people[r] + people[l] <= limit) {
            l++;
        }

        r--;
        res++;
    }

    return res;
}