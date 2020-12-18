#ifndef SCULPTOR_H
#define SCULPTOR_H
struct Voxel {
  float r,g,b; // Colors
  float a;
// Transparency
  bool isOn; // Included or not
};
class Sculptor {
protected:
    int nx,ny,nz; // Dimensions
    float r,g,b,a; // Current drawing color
    Voxel ***v;// 3D matrix

public:
  bool verificaCord(int x, int y, int z);
  Sculptor(int _nx, int _ny, int _nz); // OK
  ~Sculptor(); // OK
  void setColor(float _r, float _g, float _b, float alpha); // OK
  void putVoxel(int x, int y, int z); // OK
  void cutVoxel(int x, int y, int z); // OK
  void writeOFF(char* filename); // OK
};

// fuções auxiliares
bool satisfazEqEsfera(int z,int x,int y,int a,int b,int c, int raio);
bool satisfazEqElipse(int z,int x,int y,int xcent, int ycent,int zcent,int a,int b,int c);

#endif // SCULPTOR_H
