#include "putbox.h"

PutBox::PutBox(int _x0, int _xi, int _y0, int _yi, int _z0, int _zi,int _r,int _g,int _b,int _a)
{
    x0 = _x0-1; xi = _xi-1; y0 =_y0-1; yi = _yi-1; z0 = _z0-1; zi = _zi-1;
    r = _r; g = _g; b = _b; a = _a;
}

void PutBox::draw(Sculptor &screen)
{
    int i,j,w;
    screen.setColor(r,g,b,a);
    if(xi>=x0&&yi>=y0&&zi>=z0){
        for(i=z0;i<=zi;i++){
            for(j=x0;j<=xi;j++){
                for(w=y0;w<=yi;w++){
                    if(screen.verificaCord(j,w,i)){
                        screen.putVoxel(j,w,i);
                    }
                }
            }
        }
    }
}

