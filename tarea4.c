#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define filas 500
#define columnas 744
double latitud(int x);
double longitud(int y);
void calcula_todo();
void coor();
void guarda();
double distancia(int xi, int yi);
int z = 0;
int i=0;
int tierra=0;
double memoria = 0;
int map[filas][columnas];
int xtot[filas*columnas];
int ytot[filas*columnas];
int xnow = 350;
int ynow = 100;
int rx;
int ry;
int posx;
int posy;
double rr;
int main(void) {

  FILE *datos;
  datos=fopen("map_data.txt","r");

  int i = 0;
  int j = 0;
  int z = 0;
  if (datos){
    const size_t size=10000;
    char* linea= malloc(size);
    while (fgets(linea, size, datos) != NULL){
      if(j<z){
        z=j;
      }
      j=0;
      char *first = strtok(linea," ");
      while(first!=NULL){
        double step=strtod(first,NULL);
        map[i][j]=step;
        if (map[i][j]==1){
          ytot[tierra]=j;
          xtot[tierra]=i;
          tierra+=1;
        }
        first = strtok(NULL," ");
        j+=1;
      }
      i+=1;
    }
    free(linea);
fclose(datos);

  }
    calcula_todo();

    guarda();


  return 0;
}
void calcula_todo(){
double memoria = 0;
int recorrido = 2000;
i = 0;

double despues = 0;
double antes = 0;
while(i<recorrido){


             coor();
      despues = distancia(posx,posy);
      antes = distancia(xnow,ynow);
        double c = exp(despues - antes);


               if(despues>rr){
                        rx = posx;
                        ry = posy;
                        rr = despues;
                                  }
               if(c > 1){
                        c = 1;
                        }
               memoria = (double) rand()/RAND_MAX;
               if(c>memoria){
                             xnow = posx;
                             ynow = posy;

                             }


i = i+1;
      }
}
void guarda(){
  FILE *apy =fopen("datos_obtenidos.txt","w+");
  fprintf(apy,"%d %d %.2f",rx, ry, rr);


  printf("Las coordenadas del punto mas alehado son: %.3f %.3f\n", longitud(ynow), latitud(xnow));


}
double latitud(int x){
       double x1 = (double) x;
       double res = (-90.0/250)*x1 + 90.0;
       return res;
}
double longitud(int y){
       double y1 = (double) y;
       double res = (360.0/744.0)*y1 - 180.0;
       return res;
}
void coor(){
double x2= ((double)rand()/RAND_MAX);
double y2= ((double)rand()/RAND_MAX);
posx = xnow;
posy = ynow;
if(x2 > 0.5){ //Decide si cambiar x o y
  if(y2 > 0.5){
    posx += 1;
                      }
  else{
    posx -= 1;
    }

}
else{
  if(y2 > 0.5){
    posy += 1;
                }
  else{
    posy -= 1;
          }

        }

     }
double distancia(int xi, int yi){
  double respuesta = (double) RAND_MAX;
  for(z = 0;z<tierra;z++){
     memoria = sqrt( pow(((double) xi- (double) xtot[z]),2) + pow(((double) yi-(double) ytot[z]),2));

    if(memoria<respuesta){
       respuesta = memoria;
            }

        }
       return respuesta;
  }
