#include "putvoxel.h"
#include <Sculptor.h>
PutVoxel::PutVoxel(int _x,int _y,int _z,int _r,int _g,int _b,int _a){
    x = _x; y = _y; z = _z; r = _r; g = _g; b = _b; a = _a;
}
void PutVoxel :: draw(Sculptor &screen){
    screen.setColor(r,g,b,a);
    if(screen.verificaCord(x,y,z)){
        screen.putVoxel(x,y,z);
    }
}
