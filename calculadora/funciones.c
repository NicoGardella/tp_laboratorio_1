
/** \brief
 *
 * \param operaciones cantidad de operaciones realizadas.
 * \param numeroUno int primer numero a operar
 * \param numeroDos int segundo numero a operar
 * \return void
 *
 */
void imprimirMenu(int operaciones, int numeroUno, int numeroDos)
{

    printf("||||||||||||||||||||||%d||||||||||||||||||||||\n",operaciones);
    if(!operaciones)
    {
        printf("\t1. Ingresar 1er operando (A=x)\n");
        printf("\t2. Ingresar 2do operando (B=y)\n");
    }else
    {
        printf("\t1. Ingresar 1er operando (A=%d)\n",numeroUno);
        printf("\t2. Ingresar 2do operando (B=%d)\n",numeroDos);
    }
        printf("\t3. Calcular la suma (A+B)\n");
        printf("\t4. Calcular la resta (A-B)\n");
        printf("\t5. Calcular la division(A/B)\n");
        printf("\t6. Calcular la multiplicacion(A*B)\n");
        printf("\t7. Calcular el factorial(A!)\n");
        printf("\t8. Calcular todas las operaciones\n");
        printf("\t9. Salir\n");
        printf("||||||||||||||||||||||%d||||||||||||||||||||||\n\n",operaciones);
}

/** \brief
 *
 * \param numeroUno int primer numero a operar
 * \param numeroDos int segundo numero a operar
 * \param resultado float* resultado de la suma
 * \return int
 *
 */
int suma(int numeroUno,int numeroDos, float* resultado)
{
    *resultado=(numeroUno+numeroDos);
    return *resultado;
}
/** \brief
 *
 * \param numeroUno primer numero a operar
 * \param numeroDos segundo numero a operar
 * \param resultado float* resultado de la resta
 * \return int
 *
 */
int resta(int numeroUno,int numeroDos, float* resultado)
{
   *resultado=(numeroUno-numeroDos);
    return 0;
}
/** \brief
 *
 * \param numeroUno int primer numero a operar
 * \param numeroDos int segundo numero a operar
 * \param resultado float* resultado de la multiplicacion
 * \return int
 *
 */
int multiplicar(int numeroUno,int numeroDos, float* resultado)
{
    *resultado =  (numeroUno*numeroDos);
    return 0;
}
/** \brief
 *
 * \param numeroUno int primer numero a operar
 * \param numeroDos int segundo numero a operar
 * \param resultado float* resultado de la divicion
 * \return int [1]Error - ingreso 0 en el numero dos [0] ok
 *
 */
int dividir(int numeroUno,int numeroDos, float* resultado)
{
    if(!numeroDos){
        return 1;
    }
    *resultado = ((float)numeroUno/(float)numeroDos);
    return 0;
}
/** \brief
 *
 * \param numeroUno int numero a operar
 * \param resultado float* resultado del factorial
 * \return int[1]Error - ingreso menor a 0 en el numero uno [0] ok
 *
 */
int factorial(int numeroUno, float* resultado)
{
    if(numeroUno<0){
        return 1;
    }
    *resultado=1;
    while(numeroUno>0){
        *resultado = *resultado * (long)numeroUno;
        numeroUno--;
    }

    return 0;
}
/** \brief
 *
 * \param numeroUno int* primer numero a operar
 * \param numeroDos int* segundo numero a operar
 * \param opcionSeleccionada int* opcion del menu seleccionada
 * \return void
 *
 */
void ProcesarRespuestaUsuario(int* numeroUno, int* numeroDos, int* opcionSeleccionada)
{
    float resultado;
    scanf("%d",opcionSeleccionada);

    switch(*opcionSeleccionada)
    {
        case 1: printf("Ingrese el primer numero:\n");
                scanf("%d",numeroUno);
                break;
        case 2: printf("Ingrese el numero dos\n");
                scanf("%d",numeroDos);
                break;
        case 3: suma(*numeroUno,*numeroDos,&resultado);
                printf("El resultado de la suma de %d y %d es %.0f\n",*numeroUno,*numeroDos,resultado);
                break;
        case 4: resta(*numeroUno,*numeroDos,&resultado);
                printf("El resultado de la resta de %d y %d es %.0f\n",*numeroUno,*numeroDos,resultado);
                break;
        case 5: if(dividir(*numeroUno,*numeroDos,&resultado))
                {
                    printf("No es posible dividir por 0\n");
                }else
                {
                    printf("El resultado de la divicion de %d y %d es %.2f\n",*numeroUno,*numeroDos,resultado);
                }

                break;
        case 6: multiplicar(*numeroUno,*numeroDos,&resultado);
                printf("El resultado de la multiplicacion de %d y %d es %.0f\n",*numeroUno,*numeroDos,resultado);
                break;
        case 7:

                if(factorial(*numeroUno,&resultado))
                {
                    printf("No es posible realizar factorial de un numero menor a 0.(Valor ingresado: %d)\n",*numeroUno);
                }else
                {
                    printf("El resultado del factorial de %d es %.0f\n",*numeroUno,resultado);
                }
                break;
        case 8: suma(*numeroUno,*numeroDos,&resultado);
                printf("El resultado de la suma de %d y %d es %.0f\n",*numeroUno,*numeroDos,resultado);
                resta(*numeroUno,*numeroDos,&resultado);
                printf("El resultado de la resta de %d y %d es %.0f\n",*numeroUno,*numeroDos,resultado);
                if(dividir(*numeroUno,*numeroDos,&resultado))
                {
                    printf("No es posible dividir por 0\n");
                }else
                {
                    printf("El resultado de la divicion de %d y %d es %.2f\n",*numeroUno,*numeroDos,resultado);
                }
                multiplicar(*numeroUno,*numeroDos,&resultado);
                printf("El resultado de la multiplicacion de %d y %d es %.0f\n",*numeroUno,*numeroDos,resultado);
                factorial(*numeroUno,&resultado);
                printf("El resultado del factorial de %d es %.0f\n",*numeroUno,resultado);
                break;
        case 9: printf("FIN PROGRAMA.\n");break;
        default: printf("ERROR. Ingrese la opcion nuevamente.\n");
                 ProcesarRespuestaUsuario(&numeroUno,&numeroDos,&opcionSeleccionada);
                 break;
    }
}
