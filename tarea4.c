#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define filas 500
#define columnas 744
#define pi 3.1415
int main(void) {
  int map[filas][columnas];
  int xtot[filas*columnas];
  int ytot[filas*columnas];
  int xnow = 265; 
  int ynow = 70; 
  int rx; 
  int ry; 
  int posx; 
  int posy; 
  double rr;
  FILE *datos;
  datos=fopen("map_data.txt","r");
  int tierra=0;
  int i = 0;
  int j = 0;
  int k = 0;
  if (datos){
    const size_t size=10000;
    char *linea= malloc(size);
    while (fgets(linea, size, datos) != NULL){
      if(j<k){
        k=j;
      }
      j=0;
      char *first=strtok(linea," ");
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


  return 0;
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
