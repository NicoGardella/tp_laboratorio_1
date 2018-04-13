#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"


int main()
{

    int operaciones;
    int numeroUno,numeroDos;
    int opcionSeleccionada;
    operaciones=0;
    numeroUno=4;
    numeroDos=12;
    opcionSeleccionada=1;
    while(opcionSeleccionada!=9)
    {
    imprimirMenu(operaciones, numeroUno, numeroDos);
    if(!operaciones)
    {
        printf("Ingrese el primer numero:\n");
        scanf("%d",&numeroUno);
        printf("Ingrese el segundo numero:\n");
        scanf("%d",&numeroDos);
        printf("Ingrese operacion a realizar:\n");
    }

    ProcesarRespuestaUsuario(&numeroUno,&numeroDos,&opcionSeleccionada);
    operaciones++;
    }

    return 0;
}


