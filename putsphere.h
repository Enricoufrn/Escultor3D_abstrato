#ifndef PUTSPHERE_H
#define PUTSPHERE_H
#include <FiguraGeometrica.h>
#include <Sculptor.h>
class PutSphere : public FiguraGeometrica
{
protected:
    int xcenter,ycenter,zcenter,radius,dimx,dimy,dimz;
public:
    PutSphere(int _xcenter, int _ycenter, int _zcenter, int _radius,int _dimx,int _dimy,int _dimz,int _r,int _g,int _b,int _a);
    void draw(Sculptor &screen);
};

#endif // PUTSPHERE_H
