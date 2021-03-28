#include "planta.h"
#include <iostream>
#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <string>
#include<sys/wait.h>
#include<filesystem>
#include<dirent.h>
#include<fstream>


using namespace std;

planta::planta()
{
    //ctor
}

planta::~planta()
{

}



void construirArbol(){

}

void planta::setRamas(int ram){
    this->ramas=ram;
}
void planta::setRamas(int ram,int hoj){
    this->ramas=ram;
    this->hojas=hoj;
    int num;
    bool direccion=true;

     for(int i=0; i<this->ramas;i++){

        int pid1=fork();
        if(pid1==0){
            //Caso hijo
            int pidRama=getpid();
            for (int j=0; j<this->hojas; j++){
                int pid2=fork();
                if(pid2==0){
                    while(true){
                        sleep(1);
                    }
                    break;
                }else if(pid1==-1){
                    //Error
                }else{
                    //caso padre
                }
            }
            while(true){
                        sleep(1);
                    }
            break;
        }else if(pid1==-1){
            //Error de crear hijo
        }else{
            //Caso padre



        }
    }

}

void planta::imprimir(string namecod){
string name="pstree -c | grep proyectoSO > "+namecod;
system(name.c_str());
}

void planta::construirArbol(){


}

bool planta::isFile(string ruta){
    FILE *file;
    if(file=fopen(ruta.c_str(),"r")){
        fclose(file);
        return true;
    }
    return false;
}




