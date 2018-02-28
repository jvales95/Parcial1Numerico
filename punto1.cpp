#include <stdio.h>
#include <chrono>
#include <iostream>

#define MAX 5
 
void leer_matriz (unsigned v[][MAX], unsigned t);
void triangulo_superior (unsigned v[][MAX], unsigned t);
void tiempo();

 
unsigned long long fib(unsigned long long n) {
    return (0==n || 1==n) ? 1 : fib(n-1) + fib(n-2);
}
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
