#ifndef PUTBOX_H
#define PUTBOX_H
#include <FiguraGeometrica.h>
#include <Sculptor.h>
class PutBox : public FiguraGeometrica
{
protected:
    int x0,xi,y0,yi,z0,zi;
public:
    PutBox(int _x0, int _xi, int _y0, int _yi, int _z0, int _zi,int _r,int _g,int _b,int _a);
    void draw(Sculptor &screen);
};

#endif // PUTBOX_H
