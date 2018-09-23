#include<graphics.h>
#include<stdlib.h>
int main()
{
    int gd = DETECT , gm ;
    initgraph( &gd , &gm , NULL);

    int x1 = 20, y1 = 20, x2 = 400, y2 = 300 ;
    int dx = x2-x1, dy = y2-y1;
    int p = 2*dy - dx ;
    for(int i=1; i<=dx; i++)
    {
        putpixel(x1 , y1, 6);
        delay(10);
        x1++;
        if(p<0)
        {
            p = p + 2*dy;
        }
        else
        {
            y1++;
            p = p + 2*(dy-dx);
        }
    }
    delay(1000);
    closegraph();
    return 0;
}