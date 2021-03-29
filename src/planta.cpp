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
#include <exception>

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
    ifstream reader;
    string stReader;
    reader.open("logPlanta.txt");
    while(!reader.eof()){
        getline(reader,stReader);
    }
    reader.close();

     for(int i=0; i<this->ramas;i++){
        int pid1=fork();
        if(pid1==0){
            //Caso hijo
            int pidRama=getpid();
            string RamaName="mkdir -p archivosFork/"+stReader+"/"+to_string(pidRama);
            system(RamaName.c_str());

            for (int j=0; j<this->hojas; j++){
                int pid2=fork();


                if(pid2==0){
                    //string hojaName="mkdir -p archivosFork/"
                    /*close(pr1[1]);
                    close(pr2[1]);
                    char recept[100];
                    read(pr2[0],recept,sizeof(recept));
                    cout<<recept<<endl;
                    close(pr1[0]);
                    close(pr2[0]);*/

                    while(false){
                        sleep(1);
                    }
                    break;
                }else if(pid1==-1){
                    //Error
                }else{
                    //caso padre
                    /*char txt[100];
                    string codPid=to_string(getpid());
                    char txt2[codPid.length()+1];
                    strcpy(txt2,codPid.c_str());
                    strcat(txt, txt2);
                    write(pr1[1],txt,sizeof(txt));*/
                }
            }

            while(false){
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




