#ifndef CUTBOX_H
#define CUTBOX_H
#include <FiguraGeometrica.h>
#include <Sculptor.h>
class CutBox : public FiguraGeometrica
{
protected:
    int x0,xi,y0,yi,z0,zi;
public:
    CutBox(int _x0, int _xi, int _y0, int _yi, int _z0, int _zi);
    void draw(Sculptor &screen);

};

#endif // CUTBOX_H
