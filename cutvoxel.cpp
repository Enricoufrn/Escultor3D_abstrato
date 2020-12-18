#include "cutvoxel.h"
#include <Sculptor.h>

CutVoxel::CutVoxel(int _x,int _y,int _z)
{
    x = _x; y = _y; z = _z;
}

void CutVoxel::draw(Sculptor &screen)
{
    if(screen.verificaCord(x,y,z)){
        screen.cutVoxel(x,y,z);
    }
}
