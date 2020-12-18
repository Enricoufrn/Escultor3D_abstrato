#include "cutsphere.h"
#include <Sculptor.h>

CutSphere::CutSphere(int _xcenter, int _ycenter, int _zcenter, int _radius,int _dimx,int _dimy,int _dimz)
{
    xcenter = _xcenter; ycenter = _ycenter; zcenter = _zcenter; radius = _radius;
    dimx = _dimx; dimy = _dimy; dimz = _dimz;
}

void CutSphere::draw(Sculptor &screen)
{
    if(screen.verificaCord(xcenter,ycenter,zcenter)){
        int i,j,w;
        for(i=0;i<dimz;i++)
        {
            for(j=0;j<dimx;j++)
            {
                for(w=0;w<dimy;w++)
                {
                    if(satisfazEqEsfera(i,j,w,xcenter,ycenter,zcenter,radius)){ // verifica se o pixel satisfaz a equação da esfera com os parametros informados
                        screen.cutVoxel(j,w,i);
                    }
                }
            }
        }
    }
}

