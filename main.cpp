#include <iostream>
#include <stdio.h>
#include <unistd.h>
#include <string>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <planta.h>
#include <fstream>
using namespace std;
vector<string> split(string str, char pattern, bool enter);
vector<vector<string>> results;
vector<planta> plantas;
void abrir();
void create();
FILE * archivo;
  long medida;
  char * texto;

int main()
{


    create();
    for (int i=0;i<results.size();i++){
        vector<string>tmp=results[i];

        int cod_ = stoi(tmp[1]);
        switch(tmp.size()){
        case 2:

            if(tmp[0]=="P"){
                //Creation of planta
                for(int j=0;j<cod_;j++){
                    planta pl=planta();
                    plantas.push_back(pl);

                }
            }else if(tmp[0]=="M"){
                //Show planta
                plantas[cod_].construirArbol();

            }else if(tmp[0]=="I"){
                //Print planta
            }
            break;
        case 4:
            int cantidadRamas=stoi(tmp[2]);
            int cantidadHojas=stoi(tmp[3]);
            plantas[cod_].setRamas(cantidadRamas,cantidadHojas);

            break;

        }
    }

    while(true){
        sleep(2);
    }

    return 0;
}

void create(){
    abrir();
    vector<string> res=split(texto,')',true);
    res.pop_back();
    for(int i=0; i<res.size(); i++){
        results.push_back(split(res[i],',',true));
    }
}

void abrir(){
    //char ruta[400];
    //cout<<"Escriba la ruta del archivo"<<endl;
    //cin>>ruta;
    archivo = fopen ("documento.txt", "r");
    fseek (archivo , 0 , SEEK_END);
    medida = ftell (archivo);
    rewind (archivo);
    texto = (char*) malloc (sizeof(char)*medida);
    fread(texto, medida+1, 1, archivo);
    fclose(archivo);



}
vector<string> split(string str, char pattern,bool enter) {

    int posInit = 0;
    int posFound = 0;
    string splitted;
    vector<string> resultados;
    char chars[]="(\n\t";
    while(posFound >= 0){
        posFound = str.find(pattern, posInit);
        splitted = str.substr(posInit, posFound - posInit);
        posInit = posFound + 1;

        if(enter){
            for (unsigned int i = 0; i < 2; ++i) {
            splitted.erase (std::remove(splitted.begin(), splitted.end(), chars[i]), splitted.end());
            }
        }


        resultados.push_back(splitted);

    }

    return resultados;
}






