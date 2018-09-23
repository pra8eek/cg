#include<graphics.h>
#include<stdlib.h>

void floodfill(int x, int y, int oldc, int newc)
{
    int cc = getpixel(x,y);
    if ( cc == newc || cc != oldc ) return;
    putpixel(x,y,newc);
    floodfill( x+1 , y , oldc , newc );
    floodfill( x , y+1 , oldc , newc );
    floodfill( x-1 , y , oldc , newc );
    floodfill( x , y-1 , oldc , newc );
}

int main()
{
    int gd = DETECT , gm ;
    initgraph( &gd , &gm , NULL);

    int r = 150;
    int x = 0 , y = r ;
    int p = 3 - 2*r;
    while(y>=x)
    {
        putpixel(300 + x, 300 + y , 2 );
        putpixel(300 - x, 300 + y , 2 );
        putpixel(300 + x, 300 - y , 3 );
        putpixel(300 - x, 300 - y , 3 );
        putpixel(300 + y, 300 + x , 5 );
        putpixel(300 - y, 300 + x , 5 );
        putpixel(300 + y, 300 - x , 7 );
        putpixel(300 - y, 300 - x , 7 );
        delay(20);
        x++;
        if (p<0)
        {
            p = p + 4*x + 6;
        }
        else
        {
            y--;
            p = p + 4*(x-y) +10;
        }
    }
    floodfill(300,200,0,10);

    delay(1000);
    closegraph();
    return 0;
}