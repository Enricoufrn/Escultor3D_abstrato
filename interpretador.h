#ifndef INTERPRETADOR_H
#define INTERPRETADOR_H
#include <FiguraGeometrica.h>
#include <Sculptor.h>
#include <vector>
#include <string>
using namespace std;
class Interpretador
{
    int dimx,dimy,dimz;
    float r,g,b,a;
public:
    Interpretador();
    vector<FiguraGeometrica*> Recover(string filename);
    int getDimx();
    int getDimy();
    int getDimz();
};

#endif // INTERPRETADOR_H
