#include <stdio.h>
 
#define MAX 5
 
void leer_matriz (unsigned v[][MAX], unsigned t);
void triangulo_superior (unsigned v[][MAX], unsigned t);
 
int main()
{
    unsigned t, v[MAX][MAX];
 
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
        for (j = 0; j < t; j++)
            printf ( "%u\t", v[i][j] );
 
        printf ( "\n" );
    }
}
 
void triangulo_superior (unsigned v[][MAX], unsigned t)
{
    unsigned i, j;
    int x = 0;
 
    for (i = 0; i < t; i++)
        for (j = 0; j < t; j++)
            if (j > i)
                x += v[i][j];
 
    printf ( "La suma es: %d", x );
}