#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED
void imprimirMenu(int operaciones, int numeroUno, int numeroDos);
void ProcesarRespuestaUsuario(int* numeroUno, int* numeroDos, int* opcionSeleccionada);
int suma(int numeroUno,int numeroDos, float* resultado);
int dividir(int numeroUno,int numeroDos, float* resultado);
int factorial(int numeroUno, float* resultado);

#endif // FUNCIONES_H_INCLUDED
