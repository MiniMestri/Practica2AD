#include <stdio.h>
#include <string.h>


int main(int argc, char *argv[]){
    
    
    
    char cadena[20];
    char linea[1000];
    int incremento =1;
    char texto[100];
    char nombre[30];
    char apellido[30];
    int opcion;
    
    FILE *archivo;
    
    do{
    printf("Desea 'insertar' o 'leer' el archivo: \n");
    scanf("%s", cadena);
    
    if(strcmp(cadena,"insertar")==0){ 
        
        archivo = fopen("bbdd.txt","a");
        printf("Introduce el nombre: \n");
        scanf("%s",nombre);
        printf("Introduce el apellido: \n");
        scanf("%s",apellido);

        
        strcpy(texto,nombre);
        strcat(texto,"\t");
        strcat(texto,apellido);
        
        fputs(strcat(texto,"\n"),archivo);
        
        printf("registro insertado correctamente \n");
        
    }else if(strcmp(cadena,"leer")==0){
        
        archivo =fopen("bbdd.txt","r");
        
        while(fgets(linea,sizeof(linea),archivo)!=NULL){
            printf("Linea %i: %s ",incremento,linea);
            incremento++;
        }
    }else{
        printf("Esa opcion no existe \n");
    }

        fclose(archivo);
        
        printf("Desea salir?(0-SI ||1-NO) \n");
        scanf("%i",&opcion);
    }while(opcion==1);
    
    printf("GRACIAS POR PROBAR EL PROGRAMA DE MINIMESTRI :)");
    
    return 0;
}