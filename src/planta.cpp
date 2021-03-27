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

    char buffer_[100];
    char buffer2_[50];

    int num;

    if(!this->init){
        this->init=true;
    }

   if(this->init){



       for(int i=0; i<this->ramas;i++){



        int pid1=fork();

        if(pid1==0){

            //Caso hijo
            int pidRama=getpid();

            for (int j=0; j<this->hojas; j++){

                int pid2=fork();
                int pr1[2],pr2[2];
                pipe(pr1);
                pipe(pr2);

                if(pid2==0){

                    /*
                    num=read(fd[0],buffer_,sizeof(buffer_));
                    cout<<buffer_<<"->HIJO "<<getpid()<<endl;
                    */

                    //  FILE * fileHoja=fopen ("documento.txt", "w");
                    /*string codigoName=to_string(getpid());
                    char fileName[codigoName.length()+10]="archivosFork/";


                    char extension[]=".txt";
                    strcat(fileName,codigoName.c_str());
                    strcat(fileName,extension);

                    ofstream file;
                    file.open(fileName,ios::out);
                    file.close();*/

                    /*
                    close(pr1[1]);
                    close(pr2[1]);
                    int x;

                    read(pr2[0],&x,sizeof(x));

                    cout<<"HIJO msj DAD "<<x<<" SON: "<<getpid()<<endl;*/





                    break;
                }else if(pid1==-1){
                    //Error
                }else{

                    /*char txt[100]="Rama";
                    string codPid=to_string(getpid());
                    char txt2[codPid.length()+1];
                    strcpy(txt2,codPid.c_str());
                    strcat(txt, txt2);
                    write(fd[1],txt,sizeof(txt));*/
                    //break;

                    //close(pr1[0]);
                    //close(pr2[0]);



                    //int x;
                    //x*=getpid();
                    //write(pr1[1],&x,sizeof(x));



                }
            }
             //close(fd[1]);
             //close(fd[0]);

          /*int pr4[2];
          pipe(pr4);
          char rama[100];
          close(pr4[1]);
          read(pr4[0],rama,sizeof(rama));
          cout<<"DAD "<<rama<<" SON "<<getpid()<<endl;
          close(pr4[0]);*/
          cout<<"HOLA"<<endl;

          break;
        }else if(pid1==-1){
            //Error de crear hijo
        }else{
            //Caso padre



        }
    }

   }else{   }



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




