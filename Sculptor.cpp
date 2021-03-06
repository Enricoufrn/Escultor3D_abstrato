#include <iostream>
#include <fstream>
#include <Sculptor.h>
using namespace std;
Voxel*** alocaEspaco(int nc,int na, int nl)
{
    /*
     * A função "alocaEspaco" tem esse nome devido a sua função do escultor,
     * ela é responsável por alocar o espaço tridimensional onde ser feito a escultura 3D
     * Basicamente é feita uma alocação de uma matriz, onde cada elemento dessa matriz recebe
     * um vetor que corresponde a altura desse espaço.
    */
    int i,j;
    Voxel ***aux;
    aux = new Voxel**[nl]; // alocação referente as linhas da matriz
    if(aux != 0) // verifica se a alocação da memória foi feita da forma correta
    {
        /*
         * alocação das colunas de forma onde o primeiro endereço de "aux" contenha o primeiro endereço referente ao
         * vetor de colunas da minha matriz.
         * A iteração que vem logo em seguida serve para ajustar os endereços de memoria de forma que fiquem sequenciais
        */
        aux[0] = new Voxel*[nl*nc];
        if(aux[0]!=0)
        {
            for(i = 1;i < nl; i++) // Iteração para ajuste das posições do eixo X na memória
            {
               aux[i] = aux[i-1] + nc;
            }
        }
        else{
            aux=0;
            return aux;
        }
    }
    else{
        aux = 0;
        return aux;
    }
    for(i=0;i<nl;i++){
        for(j=0;j<nc;j++){
            aux[i][j] = new Voxel[na];
            if(aux[i][j]==0){
                j--;
            }
            else{
            }
        }
    }
    return aux;
}
bool Sculptor::verificaCord(int _x, int _y, int _z){
    if(_x>=0 && _x<=nx){
        if(_y>=0 && _y<= ny){
            if(_z>=0 && _z<=nz){
                return true;
            }
            else{
                return false;
            }
        }
        else
        {
            return false;
        }
    }else{
        return false;
    }
}
Sculptor :: Sculptor(int _nx,int _ny,int _nz)
{
    v = 0; // faço V apontar para zero para ter um parametro que a alocação da memória ocorreu de forma correta
    nx = _nx; ny = _ny; nz = _nz; // seta os valores das dimensões do espaço 3D
    do {
        v = alocaEspaco(nx,ny,nz); // chamada da função para alocação da memória necesária
    } while (v==0);
    for(int i=0;i<nz;i++){
        for(int j=0;j<nx;j++){
            for(int w=0;w<ny;w++){
                v[i][j][w].isOn = false;
            }
        }
    }
}
Sculptor :: ~Sculptor()
{
    delete v[0][0];
    delete v[0];
    delete v; // Libera o espaço da memória antes usado para guardar o espaço de 3D do objeto
    v = 0; // dessa forma posso reutilizar o ponteiro
}
void Sculptor :: setColor(float _r, float _g, float _b, float alpha)
{
    r = _r; g = _g; b = _b; a = alpha; // seta os valores da cores a serem usadas
    cout<<"Cor selecionada!" << endl;
}
void Sculptor ::putVoxel(int x, int y, int z)
{
    v[z][x][y].a = a;
    v[z][x][y].r = r;
    v[z][x][y].g = g;
    v[z][x][y].b = b;
    v[z][x][y].isOn = true;
    cout << "Voxel criado!"<<endl;
}
void Sculptor :: cutVoxel(int x, int y, int z)
{
    v[z][x][y].isOn = false;
    cout << "Voxel deletado!"<<endl;
}
void Sculptor :: writeOFF(char *filename)
{
    int i,j,w; int ind=0; int n_elementos = 0;int cont = 0;
    ofstream fout;
    // cria o arquivo .OFF
    fout.open(filename); // testar
    if(!fout.is_open()){
        cout<<"Falha ao criar o arquivo!"<<endl;
        exit(1);
    }
    else
    {
        cout << "Arquivo criado!" << endl;
    }
    // escreve a primeira linha do arquivo .OFF
    fout << "OFF" << endl;
    for(i=0;i<nz;i++)
    {
        for(j=0;j<nx;j++)
        {
            for(w=0;w<ny;w++)
            {
                if(v[i][j][w].isOn)
                {
                    n_elementos++;
                }
            }
        }
    }
    fout << n_elementos*8 << " " << n_elementos*6 << " " << 0 <<endl;
    for(i=0;i<nz;i++)
    {
        for(j=0;j<nx;j++)
        {
            for(w=0;w<ny;w++)
            {
                if(v[i][j][w].isOn)
                {
                    fout << j - 0.5 << " " << w + 0.5 << " " << i - 0.5 <<endl; // P0
                    fout << j - 0.5 << " " << w - 0.5 << " " << i - 0.5 <<endl; // P1
                    fout << j + 0.5 << " " << w - 0.5 << " " << i - 0.5 <<endl; // P2
                    fout << j + 0.5 << " " << w + 0.5 << " " << i - 0.5 <<endl; // P3
                    fout << j - 0.5 << " " << w + 0.5 << " " << i + 0.5 <<endl; // P4
                    fout << j - 0.5 << " " << w - 0.5 << " " << i + 0.5 <<endl; // P5
                    fout << j + 0.5 << " " << w - 0.5 << " " << i + 0.5 <<endl; // P6
                    fout << j + 0.5 << " " << w + 0.5 << " " << i + 0.5 <<endl; // P7
                }
            }
        }
    }
    fout.precision(2);
    for(i=0;i<nz;i++){
        for(j=0;j<nx;j++){
            for(w=0;w<ny;w++){
                if(v[i][j][w].isOn){
                    ind=cont*8;
                    fout << 4 << " " << ind+0 << " " << ind+3 << " " << ind+2 << " " << ind+1 << " " << fixed << v[i][j][w].r << " " << fixed << v[i][j][w].g << " " << fixed << v[i][j][w].b << " " << fixed << v[i][j][w].a << endl; // face 1
                    fout << 4 << " " << ind+4 << " " << ind+7 << " " << ind+3 << " " << ind+0 << " " << fixed << v[i][j][w].r << " " << fixed << v[i][j][w].g << " " << fixed << v[i][j][w].b << " " << fixed << v[i][j][w].a << endl; // face 2
                    fout << 4 << " " << ind+5 << " " << ind+6 << " " << ind+7 << " " << ind+4 << " " << fixed << v[i][j][w].r << " " << fixed << v[i][j][w].g << " " << fixed << v[i][j][w].b << " " << fixed << v[i][j][w].a << endl; // face 3
                    fout << 4 << " " << ind+6 << " " << ind+2 << " " << ind+3 << " " << ind+7 << " " << fixed << v[i][j][w].r << " " << fixed << v[i][j][w].g << " " << fixed << v[i][j][w].b << " " << fixed << v[i][j][w].a << endl; // face 4
                    fout << 4 << " " << ind+5 << " " << ind+1 << " " << ind+2 << " " << ind+6 << " " << fixed << v[i][j][w].r << " " << fixed << v[i][j][w].g << " " << fixed << v[i][j][w].b << " " << fixed << v[i][j][w].a << endl; // face 5
                    fout << 4 << " " << ind+5 << " " << ind+4 << " " << ind+0 << " " << ind+1 << " " << fixed << v[i][j][w].r << " " << fixed << v[i][j][w].g << " " << fixed << v[i][j][w].b << " " << fixed << v[i][j][w].a << endl; // face 6
                    cont++;
                }
            }
        }
    }
    cout<<"Escultura escrita!"<<endl;
    fout.close();
}

// funções auxiliares

bool satisfazEqEsfera(int z,int x,int y,int a,int b,int c, int raio)
{
    int rQrd = raio*raio;
    int aux = (x-a)*(x-a) + (y-b)*(y-b) + (z-c)*(z-c);
    if(aux <= rQrd){
        return true;
    }
    else{
        return false;
    }
}
bool satisfazEqElipse(int z,int x,int y,int xcent, int ycent,int zcent,int a,int b,int c)
{
    int aux = (float)(x-xcent)*(x-xcent)/(a*a) + float(y-ycent)*(y-ycent)/(b*b) + float(z-zcent)*(z-zcent)/(c*c);
    if(aux <= 1)
        return true;
    else
        return false;
}
