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

    rectangle(10,10,120,140);
    for(int i=11 ; i<120 ; i++)
        for(int j=11;j<140;j++)
        {
            if(i<50) putpixel(i , j, 9);
            else if (i<90) putpixel( i , j , 10);
            else if (i<120) putpixel(i , j , 12);
            if (j>40 && j<70) putpixel(i , j , 14);
        }
    floodfill( 50,50, 14,4);

    delay(1000);
    closegraph();
    return 0;
}