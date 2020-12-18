#ifndef PUTVOXEL_H
#define PUTVOXEL_H
#include <FiguraGeometrica.h>

class PutVoxel : public FiguraGeometrica
{
protected:
    int x,y,z; // Coordenadas no espaço tridimensional do voxel
public:
    PutVoxel(int _x,int _y,int _z,int _r,int _g,int _b,int _a);
    virtual void draw(Sculptor &screen);
};

#endif // PUTVOXEL_H
