#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#include "utn.h"



int main()
{
    ArrayList* listPelicula;
    listPelicula = al_newArrayList();
    char seguir='s';
    int opcion=0;
    EMovie* auxMovie;
    funciones_cargarDeArchivo(listPelicula);
    while(seguir=='s')
    {
        printf("1- Agregar pelicula\n");
        printf("2- Borrar pelicula\n");
        printf("3- Generar pagina web\n");
        printf("4- Salir\n");

        scanf("%d",&opcion);
        int i;
        int size;
        switch(opcion)
        {
        case 1:
            funciones_cargarPelicula(auxMovie,listPelicula);
            break;
        case 2:
            funciones_borrarPelicula(listPelicula);
            break;
        case 3:
            funciones_crearHTML(listPelicula);
            break;
        case 4:
            seguir = 'n';
            break;
        }
    }

    return 0;
}
