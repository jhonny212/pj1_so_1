#ifndef PLANTA_H
#define PLANTA_H
#include<string>
using namespace std;

class planta
{
    public:
        planta();
        virtual ~planta();
        int ramas;
        int hojas;
        bool init=false;

        void setRamas(int ram);
        void setRamas(int ram,int hoj);
        void construirArbol();

        bool isFile(string ruta);


    protected:

    private:

};

#endif // PLANTA_H
