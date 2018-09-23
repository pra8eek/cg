#include<graphics.h>
#include<stdlib.h>
int main()
{
    int gd = DETECT , gm ;
    initgraph( &gd , &gm , NULL);
    
    float x1 = 10, x2 = 50 , y1 = 100 , y2 = 200;
    float dx = x2 - x1 ;
    float dy = y2 - y1 ;
    float l = (dx > dy)? dx : dy;
    dx = 1.0 * dx/l;
    dy = 1.0 * dy/l ;
    for (int i=0 ; i< l ;i++)
    {
        putpixel(x1 , y1, 6);
        delay(10);
        x1+=dx;
        y1+=dy;
    }
    delay(1000);
    closegraph();
    return 0;
}