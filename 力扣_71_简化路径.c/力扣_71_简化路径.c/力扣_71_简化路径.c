#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int jump_root_dir(char* path, int i)
{
    while (path[i] == '/') { i++; }

    return i;
}

int last_word(char* path, int i)
{
    while (path[i] != '/') { i--; }

    return i;
}

char* simplifyPath(char* path) {
    int i = 0;
    int index_res = 0;
    int path_len = strlen(path);
    //i = jump_root_dir(path);

    char* res = malloc(sizeof(char) * strlen(path));
    if (!res) { return NULL; }
    //res[index_res++] = '/';

    while (i < path_len - 1)
    {
        i = jump_root_dir(path, i);

        res[index_res++] = '/';

        if (path[i] == '.' && path[i + 1] == '/') { i += 2; index_res--; continue; }
        else if (path[i] == '.' && path[i + 1] == '.' && path[i + 2] == '/')
        {
            if (i != 1)
                index_res = last_word(path, index_res - 2);
            i += 3;
            continue;
        }

        while (path[i] != '/') { res[index_res++] = path[i++]; }
    }

    res[index_res] = '\0';

    return res;
}


char* simplifyPath(char* path) {
    char* stack[100];
    int size = 0;
    for (char* s = strtok(path, "/"); s; s = strtok(NULL, "/")) {
        if (strcmp(s, ".") == 0) {
            //do nothing
        }
        else if (strcmp(s, "..") == 0) {
            //back 
            size = fmax(0, size - 1);
        }
        else {
            stack[size++] = s;
        }
    }
    if (size == 0) return "/";
    char* res = calloc(1000, sizeof(char));
    for (int i = 0; i < size; ++i) {
        strcat(res, "/");
        strcat(res, stack[i]);
    }
    return res;
}


int main()
{

    char* a = "/../";
    simplifyPath(a);

	return 0;
}