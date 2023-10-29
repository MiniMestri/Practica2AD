#include <stdio.h>
#include <string.h>


int main(int argc, char *argv[]){
    
    FILE *archivo;
    
    char cadena[20];
    char linea[1000];
    int incremento =1;
    char texto[100];
    char nombre[30];
    char apellido[30];
    char edad[2];
    

    printf("Desea 'insertar' o 'leer' el archivo: \n");
    scanf("%s", cadena);
    
    if(strcmp(cadena,"insertar")==0){ 
        
        archivo = fopen("bbdd.txt","a");
        printf("Introduce el nombre: \n");
        scanf("%s",nombre);
        printf("Introduce el apellido: \n");
        scanf("%s",apellido);
        printf("Introduce la edad, \n");
        scanf("%s",edad);
        
        strcpy(texto,nombre);
        strcat(texto,"\t");
        strcat(texto,apellido);
        strcat(texto,"\t");
        strcat(texto,edad);
        
        fputs(strcat(texto,"\n"),archivo);
        
        printf("registro insertado correctamente \n");
        
    }else if(strcmp(cadena,"leer")==0){
        
        archivo =fopen("bbdd.txt","r");
        
        while(fgets(linea,sizeof(linea),archivo)!=NULL){
            printf("       NOMBRE  APELLIDO    \n");
            printf("Linea %i: %s ",incremento,linea);
            incremento++;
        }
    }else{
        printf("ERROR");
    }     

    fclose(archivo);
    
    return 0;
}