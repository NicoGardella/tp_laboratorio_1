#ifndef PERSONA_H_INCLUDED
#define PERSONA_H_INCLUDED
typedef struct
{
    char nombre[50];
    int edad;
    int dni;
    //------------

    int isEmpty;
}Persona;


int persona_init(Persona* array,int limite);
int persona_mostrar(Persona* array,int limite);
int persona_mostrarDebug(Persona* array,int limite);
int persona_alta(Persona* array,int limite);
int persona_baja(Persona* array,int limite, int id);
int persona_altaForzada(Persona* array,int limite, char nombre[50], int dni, int edad);
int persona_ordenar(Persona* array,int limite, int orden);
int persona_graficoEdades(Persona* array,int limite);



#endif // PERSONA_H_INCLUDED
