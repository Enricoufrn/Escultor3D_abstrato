#ifndef PUTELLIPSOID_H
#define PUTELLIPSOID_H
#include <FiguraGeometrica.h>
#include <Sculptor.h>
class PutEllipsoid : public FiguraGeometrica
{
protected:
    int xcenter, ycenter, zcenter, rx, ry, rz,dimx,dimy,dimz;
public:
    PutEllipsoid(int _xcenter, int _ycenter, int _zcenter, int _rx, int _ry,int _rz,int _dimx,int _dimy,int _dimz,int _r,int _g,int _b,int _a);
    void draw(Sculptor &screen);
};

#endif // PUTELLIPSOID_H
