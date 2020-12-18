#include "cutellipsoid.h"
#include <Sculptor.h>

CutEllipsoid::CutEllipsoid(int _xcenter, int _ycenter, int _zcenter, int _rx, int _ry,int _rz,int _dimx,int _dimy,int _dimz)
{
    xcenter = _xcenter; ycenter = _ycenter; zcenter = _zcenter; rx = _rx; ry = _ry; rz = _rz;
    dimx = _dimx; dimy = _dimy; dimz = _dimz;
}

void CutEllipsoid::draw(Sculptor &screen)
{
    if(screen.verificaCord(xcenter,ycenter,zcenter)){
        int i,j,w;
        for(i=0;i<dimz;i++)
        {
            for(j=0;j<dimx;j++)
            {
                for(w=0;w<dimy;w++)
                {
                    if(satisfazEqElipse(i,j,w,xcenter,ycenter,zcenter,rx,ry,rz)){ // verifica se o pixel satisfaz a equação da esfera com os parametros informados
                        screen.cutVoxel(j,w,i);
                    }
                }
            }
        }
    }
}
