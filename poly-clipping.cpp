#include<graphics.h>
#include<stdlib.h>
#include<iostream>
#define x1 50
#define x2 300
#define y1 80
#define y2 350
using namespace std;
//LRBT
int getCode(int x, int y)
{
    int ans = 0;
    if(x<x1) ans+=8;
    else if (x>x2) ans+=4;
    if(y<y1) ans+=2;
    else if (y>y2) ans+=1;
    return ans;
}

void lineClip(int x, int y, int xx, int yy)
{
        int c1 = getCode(x,y);
        int c2 = getCode(xx,yy);

        //fully accepted
        if( (c1 | c2) == 0 )
            line(x,y,xx,yy);

        //fully rejected
        else if( (c1 & c2) != 0 )  return;

        //partially accepted
        else
        {
            int inpoint = (c1==0)?c1:c2;
            //swapping endpoints if (xx,yy) are inside
            if(inpoint == c2)
            {
                x^=xx;
                xx^=x;
                x^=xx;

                y^=yy;
                yy^=y;
                y^=yy;
            }
            //now inside point is x,y and outside is xx,yy
            int outCode = getCode(xx,yy);
            double m = 1.0*(yy-y)/(xx-x);
            //outcode 1- top, 2-bottom, 4-right, 8-left
             if(outCode == 2)
                line( x , y , x-((y-y1)/m) , y1 );
             else if(outCode == 1)
                line( x , y , x-((y-y2)/m) , y2 );
             else if(outCode == 4)
                line( x , y , x2 , y-m*(x-x2) );
             else if(outCode == 8)
                line( x , y , x1 , y-m*(x-x1) );

        }
}

int main()
{
    int gd = DETECT , gm ;
    initgraph( &gd , &gm , NULL);

    rectangle(x1,y1,x2,y2);
   // lineClip(20,30,200,300);
    cout<<"Enter the num of vertices"<<endl;
    int n;
    cin>>n;
    int arr[n][2];
    for(int i=0; i<n;i++)
        cin>>arr[i][0]>>arr[i][1];

//polygon drawing
    for(int i=0;i<n-1;i++)
    {
        line( arr[i][0] , arr[i][1] , arr[i+1][0] , arr[i+1][1] );
        delay(500);
    }
    line( arr[0][0] , arr[0][1] , arr[n-1][0] , arr[n-1][1] );
    delay(500);

    delay(2000);
    cleardevice();

    //clipping
    rectangle(x1,y1,x2,y2);
    for(int i=0;i<n-1;i++)
    {
        lineClip( arr[i][0] , arr[i][1] , arr[i+1][0] , arr[i+1][1] );
        delay(500);
    }
    lineClip( arr[0][0] , arr[0][1] , arr[n-1][0] , arr[n-1][1] );
    delay(2000);
    closegraph();
    return 0;
}
