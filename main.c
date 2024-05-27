#include <stdio.h>
#include "leer.c"

void menu()
{
    int opcion;
    printf("ACTC TC 2024 \n\n");

    printf("\t1-Pole Position Carrera\n");

    printf("\t2-Podio Carrera\n");

    printf("\t3-Salir\n\n");

    printf("\tOpción: ");
    scanf("%d", &opcion);
    while (opcion < 1 || opcion > 3)
    {
        printf("Opción incorrecta, Ingrese una opción válida\n");
        scanf("%d", &opcion);
    }
    switch (opcion)
    {
    case 1:
        // printf("Menú Pole Position");
        printf("\n\nCarrera: ");
        printf("\t1- El Calafate\n");
        printf("\t\t2- Viedma\n");
        printf("\t\t3- Neuquén\n");
        break;
    case 2:
        // printf("Menú Podio");
        printf("\n\nCarrera: ");
        printf("\t1- El Calafate\n");
        printf("\t\t2- Viedma\n");
        printf("\t\t3- Neuquén\n");
        break;
    case 3:
        exit(1);
        break;
    }
}
int main()
{
    setlocale(LC_ALL, "");
    //LeerPilotos();
    LeerTiempos();
    menu();
}