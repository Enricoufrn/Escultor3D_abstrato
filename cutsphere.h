#ifndef CUTSPHERE_H
#define CUTSPHERE_H
#include <FiguraGeometrica.h>
#include <Sculptor.h>
class CutSphere : public FiguraGeometrica
{
protected:
    int xcenter,ycenter,zcenter,radius,dimx,dimy,dimz;
public:
    CutSphere(int _xcenter, int _ycenter, int _zcenter, int _radius,int _dimx,int _dimy,int _dimz);
    void draw(Sculptor &screen);
};

#endif // CUTSPHERE_H
