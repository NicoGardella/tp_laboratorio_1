#include <stdio.h>
#include <stdlib.h>
#include "persona.h"
#define QTP 20

int main()
{
    char seguir='s';
    int opcion=0;
    Persona arrayP[QTP];
    persona_init(arrayP,QTP);
    persona_altaForzada(arrayP,QTP,"Nicolas A","36740006",25);
    persona_altaForzada(arrayP,QTP,"Leandro B","16740006",12);
    persona_altaForzada(arrayP,QTP,"Santiago C","26740006",40);
    persona_altaForzada(arrayP,QTP,"Romina D","46740006",30);
    persona_altaForzada(arrayP,QTP,"Christian E","56740006",50);
    persona_altaForzada(arrayP,QTP,"Marcelo F","66740006",30);
    persona_altaForzada(arrayP,QTP,"Lucas G","76740006",17);
    while(seguir=='s')
    {
        printf("1- Agregar persona\n");
        printf("2- Borrar persona\n");
        printf("3- Imprimir lista ordenada por  nombre\n");
        printf("4- Imprimir grafico de edades\n\n");
        printf("5- Salir\n");

        scanf("%d",&opcion);

        switch(opcion)
        {
            case 1:
                persona_alta(arrayP,QTP);
                break;
            case 2:
                persona_mostrar(arrayP,QTP);
                persona_baja(arrayP,QTP,-1);
                break;
            case 3:
                persona_ordenar(arrayP,QTP,1);
                persona_mostrar(arrayP,QTP);
                break;
            case 4:
                persona_graficoEdades(arrayP,QTP);
                break;
            case 5:
                seguir = 'n';
                break;
        }
    }

    return 0;
}
