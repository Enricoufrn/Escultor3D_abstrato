#include "cutbox.h"
#include <Sculptor.h>
CutBox::CutBox(int _x0, int _xi, int _y0, int _yi, int _z0, int _zi)
{
    x0 = _x0-1; xi = _xi-1; y0 =_y0-1; yi = _yi-1; z0 = _z0-1; zi = _zi-1;
}

void CutBox::draw(Sculptor &screen)
{
    int i,j,w;
    if(xi>=x0&&yi>=y0&&zi>=z0){
        for(i=z0;i<=zi;i++){
            for(j=x0;j<=xi;j++){
                for(w=y0;w<=yi;w++){
                    if(screen.verificaCord(j,w,i)){
                        screen.cutVoxel(j,w,i);
                    }
                }
            }
        }
    }
}
