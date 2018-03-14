# Parcial1Numerico

## Punto 1a

El algoritmo usado para sumar el triangulo superior de una matriz es el siguiente:

void triangulo_superior (unsigned v[][MAX], unsigned t)
{
    unsigned i, j;
    int x = 0;
    
    for (i = 0; i < t; i++)
        for (j = 0; j < t; j++)
            if (j > i){
                x += v[i][j];
            }
 
    printf ( "La suma es: %d", x );
}

Este retorna la suma luego de haber contado la suma en la matriz

##

## Punto 1b

Para determinar el tiempo y el numero de operaciones se agrego una funcion nueva
y ademas se agrego una nueva variable de tipo contador, como se puede evidenciar
acontinuacion: 

void triangulo_superior (unsigned v[][MAX], unsigned t)
{
    unsigned i, j;
    int x = 0, contador = 0;
    
    for (i = 0; i < t; i++)
        for (j = 0; j < t; j++)
            if (j > i){
                x += v[i][j];
                contador++;
                
            }
    tiempo();
    printf ( "La suma es: %d", x );
}

Con esta variable cada vez que una suma es realizada un contador contara el numero
de operaciones.

El tiempo se obtuvo con la siguiente funcion la cual actua al acabar las operaciones

void tiempo()
{
 unsigned long long n = 0;
    while (true) {
        auto start = std::chrono::high_resolution_clock::now();
        fib(++n);
        auto finish = std::chrono::high_resolution_clock::now();

        auto microseconds = std::chrono::duration_cast<std::chrono::microseconds>(finish-start);
        printf << microseconds.count() << "µs\n";
        if (microseconds > std::chrono::seconds(1)){
            break;
        }
    }
 
} 

##

## Punto 1C

Debido a que las unicas operaciones realizadas en el algoritmo son sumas
inmediamente sabemos que la complejidad puede estar entre las mas comunes tales 
como son o(n), o(n^2), o(n^3), etc...

Dada la forma del desarrollo del algoritmo tenemos que la funcion que representa
dicho algoritmo es o((n+1)n)/2

Si remplazamos los valores de n por 1 debido a que solo son utilizados for en el
algoritmo tenemos que nuestra complejidad es o(n*n)

##

## Correcion punto 1C

Para poder obtener la complejidad del punto 1C es necesario observar nuevamente cada "funcion"
utilizada en este punto del parcial, y de esta manera ir haciendo las sumas necesarias para
poder obtener la complejidad del algoritmo en si.

Al hacer eso obtenemos un codigo donde cada "funcion" nos brinda las siguientes complejidades

/**
 Pasos para obtener la complejidad de una funcionn, siempre para el peor de los casos:
 
 1. [TE]. Determinar el tamano de la entrada.
 2. [OB]. Determinar la operaciÃ³n bÃ¡sica.
 
 **/
 
void leer_matriz (unsigned v[][MAX], unsigned t);
void triangulo_superior (unsigned v[][MAX], unsigned t);
void tiempo();


/**
 
 COMPLEJIDAD FIB
 
 1. TE: El valor de n
 2. OB: Suma
 
 Al haber recursion: n veces en el peor caso
 Al haber un caso inicial: 1
 fib(n) = 1 + O(n)
        = O(n)
 
 **/
 
unsigned long long fib(unsigned long long n) {
    return (0==n || 1==n) ? 1 : fib(n-1) + fib(n-2);
}


/**
 
 COMPLEJIDAD MAIN
 
 Complejidad en base a suma de ordenes de complejidad de las funciones utilizadas
 
 Al haber while: O(n)
 Al haber un llamado a leer leer_matriz: O(n^2)
 Al haber un llamado a leer triangulo_superior: O(n^2)
 
 main() = O(n) + O(n^2) + O(n^2)
        = O(n) + 2O(n^2)
        = 2O(n^2)
        = O(n^2)
 
 COMPLEJIDAD FINAL DE TODO EL PROGRAMA: O(n^2)
 
 
 **/
 
int main()
{
    unsigned t, v[MAX][MAX];
    int= tiempo;
    do
    {
        printf( "cantidad de elementos matriz?: " );
        scanf ( "%u", &t );
    } while (t < 0 || t > MAX);
 
    leer_matriz (v, t);
    triangulo_superior (v, t);
 
    setbuf (stdin, NULL);
    getchar ();
    return 0;
}


/**
 
 COMPLEJIDAD LEER_MATRIZ
 
 1. TE: El valor de v[][MAX]
 2. OB: ComparaciÃ³n
 
 Al haber un for: O(n)
 Al haber un for dentro de otro for: O(n^2)
 Al haber dos veces dos for's anidados entonces:
    leer_matriz(n) = O(n^2) + O(n^2)
                   = 2O(n^2)
                   = O(n^2)
 
 **/
void leer_matriz (unsigned v[][MAX], unsigned t)
{
    unsigned i, j;
 
    for (i = 0; i < t; i++)
    {
        for (j = 0; j < t; j++)
        {
            printf ( "Dame el elemento M[%u][%u]: ", (i + 1), (j + 1) );
            scanf ( "%u", &v[i][j] );
        }
    }
 
    for (i = 0; i < t; i++)
    {
        for (j = 0; j < t; j++){
            printf ( "%u\t", v[i][j] );
        }
 
        printf ( "\n" );
    }
}

/**
 
COMPLEJIDAD TIEMPO
 
1. TE: 0
2. OB: fib()
 
Al haber un while: O(n)
Al llamar a fib(), se incluye su orden de complejidad: O(n)
tiempo(n) = O(n)
          = O(n)
 
 **/
void tiempo()
{
 unsigned long long n = 0;
    while (true) {
        auto start = std::chrono::high_resolution_clock::now();
        fib(++n);
        auto finish = std::chrono::high_resolution_clock::now();

        auto microseconds = std::chrono::duration_cast<std::chrono::microseconds>(finish-start);
        printf << microseconds.count() << "Âµs\n";
        if (microseconds > std::chrono::seconds(1)){
            break;
        }
    }
 
}

/**
 
 COMPLEJIDAD TRIANGULO_SUPERIOR
 
 1. TE: El valor de v[][MAX]
 2. OB: Comparacion
 
 Al haber un for: O(n)
 Al haber un for dentro de otro for: O(n^2)
 Al haber un if: O(1)
 Al haber dos veces dos for's anidados con un if dentro de ellos:
 triangulo_superior(n) = O(n^2 + n^2)
                       = O(2n^2)
                       = O(n^2)
 
 **/
void triangulo_superior (unsigned v[][MAX], unsigned t)
{
    unsigned i, j;
    int x = 0, contador = 0;
    for (i = 0; i < t; i++)
        for (j = 0; j < t; j++)
            if (j > i){
                x += v[i][j];
                contador++;
                 }
    tiempo();
    printf ( "La suma es: %d", x );
}


Luego de sacar la complejidad para cada parte del algoritmo tenemos que la 
complejidad mayor otenida es de O(n^2) por ende al ser esta la mayor dentro
del algoritmo se puede decir que el algoritmo utilizado para este punto del 
parcial posee una complejidad de O(n^2)


##

## Correcion parte escrita punto 3a

Usando (0,3) en los datos de x0 y x1 de la secante notamos los siguientes datos

                            X= 1.56784 	 E= 8.021358 
                            X= 0.3497213 	 E= 0.8768413 
                            X= -1.006534 	 E= 0.5524558 
                            X= -0.4427458 	 E= 0.009381919 
                            X= -0.4521865 	 E= 5.82919e-05 
                            X= -0.4521283 	 E= 3.250416e-09 

Con estos datos notamos como despues de 6 iteraciones la funcion converge y se
mantiene en un punto cercano a -0.45, ademas
de esto notamos como converge con 9 cifras significativas. 

## 

## Punto 3b

Debido que al utilizar el valor de x0=1 el punto no converge o opta por ser una 
cantidad muy alta de numeros, se cambio el numero de prueba de x0 y ahora se 
utilizo x0=-1.5, con este numero se hicieron las pruebas que dieron lo siguiente:

                            X= -1.563474 	 E= 1e-04 
                            X= -1.584418 	 E= 1e-04 
                            X= -1.596806 	 E= 1e-04 
                            X= -1.605104 	 E= 1e-04 
                            X= -1.611018 	 E= 1e-04 
                            X= -1.615396 	 E= 1e-04 
                            X= -1.618717 	 E= 1e-04 
                            X= -1.621282 	 E= 1e-04 
                            X= -1.623287 	 E= 1e-04 
                            X= -1.624872 	 E= 1e-04 
                            X= -1.626132 	 E= 1e-04 
                            X= -1.62714 	 E= 1e-04 
                            X= -1.62795 	 E= 1e-04 
                            X= -1.628603 	 E= 1e-04 
                            X= -1.629131 	 E= 1e-04 
                            X= -1.62956 	 E= 1e-04 
                            X= -1.629907 	 E= 1e-04 
                            X= -1.63019 	 E= 1e-04 
                            X= -1.63042 	 E= 1e-04 
                            X= -1.630608 	 E= 1e-04 
                            X= -1.630761 	 E= 1e-04 
                            X= -1.630885 	 E= 1e-04 
                            X= -1.630987 	 E= 1e-04 
                            X= -1.63107 	 E= 1e-04 
                            X= -1.631138 	 E= 1e-04 
                            X= -1.631194 	 E= 1e-04 
                            X= -1.631239 	 E= 1e-04 
                            X= -1.631277 	 E= 1e-04 
                            X= -1.631307 	 E= 1e-04 
                            X= -1.631332 	 E= 1e-04 
                            X= -1.631352 	 E= 1e-04 
                            X= -1.631369 	 E= 1e-04 
                            X= -1.631382 	 E= 1e-04 
                            X= -1.631394 	 E= 1e-04 
                            X= -1.631403 	 E= 1e-04 
                            X= -1.63141 	 E= 1e-04
                            
 Con este valor notamos que la funcion que el punto de interseccion se encuentra 
 terminando en x=-1.63141 aproximadamente.
