#include<graphics.h>
#include<stdlib.h>
void fill( int x , int y , int bc , int newc )
{
    int cc = getpixel(x, y);
    if( cc == newc || cc == bc )
        return;
    putpixel( x , y , newc);
    fill( x +1 , y , bc , newc);
    fill( x , y +1 , bc , newc);
    fill( x-1 , y , bc , newc);
    fill( x , y-1 , bc , newc);
}
int main()
{
    int gd = DETECT , gm ;
    initgraph( &gd , &gm , NULL);

    rectangle(10,10,200,100);
    fill( 100 , 50 , 15 , 9 );
    
    circle( 300 , 200 , 100 );
    fill( 300 , 200 , 15 , 10);
    delay(500);
    closegraph();
    return 0;
}