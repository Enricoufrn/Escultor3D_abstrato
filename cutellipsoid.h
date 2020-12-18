#ifndef CUTELLIPSOID_H
#define CUTELLIPSOID_H
#include <FiguraGeometrica.h>
#include <Sculptor.h>
class CutEllipsoid : public FiguraGeometrica
{
protected:
    int xcenter, ycenter, zcenter, rx, ry, rz,dimx,dimy,dimz;
public:
    CutEllipsoid(int _xcenter, int _ycenter, int _zcenter, int _rx, int _ry,int _rz,int _dimx,int _dimy,int _dimz);
    void draw(Sculptor &screen);
};

#endif // CUTELLIPSOID_H
