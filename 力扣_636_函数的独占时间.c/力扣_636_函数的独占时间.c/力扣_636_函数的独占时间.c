#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//�ڵݹ鴦����bug
typedef struct /*fun_exc_time*/
{
    int id;
    int time;
}fe_t;

int cal_other_time(int* arr, fe_t* arr_tmp, int size, int cur_id)
{
    int total_other_time = 0;
    for (int i = 0; i < size; i++)
    {
        if (arr_tmp[i].id > cur_id)
        {
            total_other_time += arr[i];
        }
    }
    return total_other_time;
}

int* exclusiveTime(int n, char** logs, int logsSize, int* returnSize) {
    int* res_arr = (int*)calloc(logsSize, sizeof(int));
    int index_a = 0;
    fe_t* stack = (fe_t*)malloc(sizeof(fe_t) * logsSize);
    fe_t* arr_tmp = (fe_t*)malloc(sizeof(fe_t) * logsSize);

    int i = 0, top = 0;
    int cur_id = 0, cur_time = 0;
    //int prev_pop_time = 0;

    for (i = 0; i < logsSize; i++)
    {
        char* word;
        //ȡ����һ����":"��β���ַ���
        word = strtok(logs[i], ":");
        cur_id = atoi(word);

        //ȡ���ڶ�����":"��β���ַ���
        word = strtok(NULL, ":");
        if ((*word) == 's')  //�ַ���wordΪstart
        {
            //ȡ�������":"��β��ʱ��ڵ�
            word = strtok(NULL, ":");
            cur_time = atoi(word);

            //��ջ
            stack[top].id = cur_id;
            stack[top].time = cur_time;
            top++;
        }
        else  //�ַ���wordΪend
        {
            //��ջ������
            //1.ȡ����ǰԪ�ص�ʱ��
            cur_time = atoi(strtok(NULL, ":"));
            //2.��������������ȥ��ʱ��
            int other_time = cal_other_time(res_arr, arr_tmp, logsSize, cur_id);
            //3.����ʱ����cur_idΪ��������������
            if (other_time == 0 && cur_time != stack[top - 1].time)
            {
                res_arr[cur_id] += cur_time - stack[top - 1].time + 1;
            }
            else if (cur_time == stack[top - 1].time)
            {
                res_arr[cur_id] += 1;
            }
            else
            {
                res_arr[cur_id] += cur_time - stack[top - 1].time + 1 - other_time - res_arr[cur_id];
            }
            arr_tmp[cur_id].id = cur_id;
            arr_tmp[cur_id].time = res_arr[cur_id];
            //4.��ջ
            top--;
        }
    }

    *returnSize = n;
    return res_arr;
}

//���ѽ��
int* exclusiveTime(int n, char** logs, int logsSize, int* returnSize) {

    int* result = (int*)malloc(sizeof(int) * n);
    memset(result, 0, sizeof(int) * n);

    int* stack = (int*)malloc(sizeof(int) * logsSize);
    memset(stack, 0, sizeof(int) * logsSize);

    int top = -1;

    int id;
    int currTime, prevTime;
    char action[6];

    for (int i = 0; i < logsSize; i++) {
        sscanf(logs[i], "%d:%[a-z]:%d", &id, action, &currTime);
        if (action[0] == 's') {
            if (top >= 0) {
                result[stack[top]] += currTime - prevTime;
            }
            top++;
            stack[top] = id;
            prevTime = currTime;
        }
        else {
            result[stack[top]] += currTime - prevTime + 1;
            top--;
            prevTime = currTime + 1;
        }
    }
    free(stack);

    *returnSize = n;
    return result;
}

int main()
{
    char** a = (char**)malloc(sizeof(char*) * 6);
    a[0] = "0:start:0";
    a[1] = "0:start:2";
    a[2] = "0:end:5";
    a[3] = "0:start:6";
    a[4] = "0:end:6";
    a[5] = "0:end:7";
    int b = 0;
    exclusiveTime(1, a, 6, &b);

    return 0;
}