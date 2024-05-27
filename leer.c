#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

    /**
    Para trabajar con archivos en C, es necesaria la declaración de una variable de tipo
FILE. En particular para manipular un archivo se necesita una referencia a una variable
del tipo FILE, para lo cual se utiliza el concepto de puntero.
    **/

void LeerPilotos(){
    setlocale(LC_ALL,"");
    int num_auto, edad;
    char nom[41], ap[41], ciudad[41], marca[41], equipo[41];
    FILE *ArchivoPilotos;

    /**
    Para abrir un archivo se utiliza la función fopen, que recibirá el nombre del archivo
con su ruta y el modo en el cual será abierto:
    ->r para lectura -por read-
    ->w para escritura -por write-
    ->a para agregado -por append-
    ->a+ para lectura y posterior agregado
    **/

    ArchivoPilotos = fopen("pilotos.txt","r");
    if (ArchivoPilotos == NULL) {
        printf("Error: no se pudo abrir el archivo pilotos.txt.-\n");
        exit(1);
    }

    /**
    Para leer y escribir de un archivo que haya sido previamente abierto, se utilizan las
funciones fscanf y fprintf, que funcionan del mismo modo que las funciones entrada
y salida previamente estudiadas, sólo que recibirán además como primer parámetro la
referencia al archivo con el que deseamos trabajar.
    **/

    ///Lectura del primer archivo

    fscanf(ArchivoPilotos,"%d %s %s %d %s %s %s",&num_auto, ap, nom, &edad, ciudad, marca, equipo);       //lee la primera linea del archivo.
    while(!(feof(ArchivoPilotos))){
        //printf("%d\t %s\t %s\t %d\t %s\t %s\t %s\t \n", num_auto, ap, nom, edad, ciudad, marca, equipo);
        fscanf(ArchivoPilotos,"%d %s %s %d %s %s %s",&num_auto, ap, nom, &edad, ciudad, marca, equipo);
    }

    /**
    Finalmente, luego de haber realizado todas las operaciones que se deseen sobre un archivo,
este debe ser cerrado utilizando la función fclose
que recibe una referencia al archivo que se desea cerrar
    **/
    fclose(ArchivoPilotos);


}

void LeerTiempos(){
    setlocale(LC_ALL,"");
    int num_auto, vueltas, minutos, n_carrera;
    float segundos;
    char etapa[41];
    FILE *ArchivoTiempos;
    ArchivoTiempos = fopen("tiempos.txt","r");
    if (ArchivoTiempos == NULL) {
        printf("Error: no se pudo abrir el archivo tiempos.txt.-\n");
        exit(1);
    }
    fscanf(ArchivoTiempos,"%d %d %d %f %d %s",&num_auto, &vueltas, &minutos, &segundos, &n_carrera, etapa);
    while(!(feof(ArchivoTiempos))){
        printf("%d\t %d\t %d\t %.3f\t %d\t %s\t \n", num_auto, vueltas, minutos, segundos, n_carrera, etapa);
        fscanf(ArchivoTiempos,"%d %d %d %f %d %s",&num_auto, &vueltas, &minutos, &segundos, &n_carrera, etapa);
    }
    fclose(ArchivoTiempos);
}

//CM_wsw
