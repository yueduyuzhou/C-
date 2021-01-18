
#include <stdio.h>    //缺少插件，无法运行画图程序
#include <graphics.h>
#include <conio.h>

    int main()
    {
        int i = 0, j = 0;
        initgraph(280, 280);
        setbkcolor(YELLOW);
        cleardevice();

        for (i = 50; i <= 230; i += 20)
        {
            for (j = 50; j <= 230; j += 3)
            {
                putpixel(i, j, BLACK);
            }
        }
        for (i = 50; i <= 230; i += 20)
        {
            for (j = 50; j <= 230; j += 3)
            {
                putpixel(j, i, BLACK);
            }
        }

        return 0;
    }

