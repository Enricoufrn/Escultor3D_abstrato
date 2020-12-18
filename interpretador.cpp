#include "interpretador.h"
#include <FiguraGeometrica.h>
#include <Sculptor.h>
#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <putvoxel.h>
#include <cutvoxel.h>
#include <putbox.h>
#include <cutbox.h>
#include <putellipsoid.h>
#include <cutellipsoid.h>
#include <putsphere.h>
#include <cutsphere.h>
using namespace std;
Interpretador::Interpretador()
{

}

vector<FiguraGeometrica *> Interpretador::Recover(string filename)
{
    vector<FiguraGeometrica*> figs;
    string s,token;
    stringstream ss;
    ifstream fin;
    fin.open(filename.c_str());
    if(!fin.is_open())
    {
        exit(1);
    }
    while (fin.good()) {
        getline(fin,s);
        if(fin.good()){
            ss.clear();
            ss.str(s);
            ss >> token;
            if(token.compare("dim") ==0){
                ss >> dimx >> dimy >> dimz;
            }else if (token.compare("putvoxel")==0){
                int x,y,z;
                ss >> x >> y >> z >> r >> g >> b >> a;
                figs.push_back(new PutVoxel(x,y,z,r,g,b,a));
            }else if(token.compare("putbox")==0){
                int x0,xi,y0,yi,z0,zi;
                ss >> x0 >> xi >> y0 >> yi >> z0 >> zi >> r >> g >> b >> a;
                figs.push_back(new PutBox(x0,xi,y0,yi,z0,zi,r,g,b,a));
            }else if(token.compare("cutvoxel")==0){
                int x,y,z;
                ss >> x >> y >> z;
                figs.push_back(new CutVoxel(x,y,z));
            }else if(token.compare("cutbox") == 0){
                int x0,xi,y0,yi,z0,zi;
                ss >> x0 >> xi >> y0 >> yi >> z0 >> zi;
                figs.push_back(new CutBox(x0,xi,y0,yi,z0,zi));
            }else if(token.compare("putellipsoid") == 0){
                int xc,yc,zc,rx,ry,rz;
                ss >> xc >> yc >> zc >> rx >> ry >> rz;
                figs.push_back(new PutEllipsoid(xc,yc,zc,rx,ry,rz,dimx,dimy,dimz,r,g,b,a));
            }else if(token.compare("putellipsoid") == 0){
                int xc,yc,zc,rx,ry,rz;
                ss >> xc >> yc >> zc >> rx >> ry >> rz;
                figs.push_back(new CutEllipsoid(xc,yc,zc,rx,ry,rz,dimx,dimy,dimz));
            }else if(token.compare("putsphere") == 0){
                int xc,yc,zc,r;
                ss >> xc >> yc >> zc >> r;
                figs.push_back(new PutSphere(xc,yc,zc,r,dimx,dimy,dimz,r,g,b,a));
            }else if(token.compare("cutsphere") == 0){
                int xc,yc,zc,r;
                ss >> xc >> yc >> zc >> r;
                figs.push_back(new CutSphere(xc,yc,zc,r,dimx,dimy,dimz));
            }
        }
    }
    return figs;
}
int Interpretador::getDimx()
{
    return dimx;
}
int Interpretador::getDimy()
{
    return dimy;
}
int Interpretador::getDimz()
{
    return dimz;
}
