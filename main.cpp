#include <iostream>
#include <FiguraGeometrica.h>
#include <Sculptor.h>
#include <vector>
#include <interpretador.h>
#include <putvoxel.h>
#include <cutvoxel.h>
#include <putbox.h>
#include <cutbox.h>
using namespace std;
char* TesteEscultor = "saida_teste1.OFF";
int main()
{
    Sculptor *escultura;
    Interpretador interpretador;
    vector<FiguraGeometrica*> fig = interpretador.Recover("C:/Users/enric/Desktop/Nova pasta/teste1.txt");
    escultura = new Sculptor(interpretador.getDimx(),interpretador.getDimy(),interpretador.getDimz());
    for(double i = 0; i < fig.size();i++){
        fig[i]->draw(*escultura);
    }
    escultura->writeOFF(TesteEscultor);
    for(double i = 0; i < fig.size();i++){
        delete fig[i];
    }
    delete escultura;
    return 0;
}
