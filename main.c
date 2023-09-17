#include <stdio.h>
#include <stdlib.h>

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

int Compare ( const void* a, const void* b ) {
    int* start = * ( int** ) a;
    int* end = * ( int** ) b;
        
    return start[0] - end[0];
}

int** Merge ( int** intervals, int intervalsSize, int* intervalsColSize, int* returnSize, int** returnColumnSizes ) {
    if ( intervalsSize == 0 ) {
        *returnSize = 0;
        return NULL;
    }
    qsort( intervals, intervalsSize, sizeof( int* ), Compare );

    int** res = ( int** )malloc( sizeof(int*) * intervalsSize );
     
    for ( int i = 0; i < intervalsSize; i++ ) {
        res[i] = ( int* )malloc( sizeof(int) * 2 );
    }

    int c = 0;
    int start = intervals[0][0];
    int end = intervals[0][1];

    for ( int i = 1; i < intervalsSize; i++ ) {
        int temp_Start = intervals[i][0];
        int temp_End = intervals[i][1];

        if ( end >= temp_Start ) {
            end = ( temp_End > end ) ? temp_End : end;
        } else {
            res[c][0] = start;
            res[c][1] = end;
            c++;
            start = temp_Start;
            end = temp_End;
        }
    }
    res[c][0] = start;
    res[c][1] = end;
    c++;
    *returnSize = c;
    *returnColumnSizes = ( int* )malloc( sizeof(int) * c );
    for ( int i = 0; i < c; i++ ) {
        ( *returnColumnSizes )[i] = 2;
    }



    return res;
}

int main ( int argc, char const *argv[] ){
    // Complexidade do código se manteve em: 
    //Ordenação - (n log n) - complexidade final/total
    //Mesclar - O(n)
    //levando em conta que o código não será levado para o pior caso do qsort
    int n;
    printf ( "Quantidade de intervalos " );
    scanf ( "%d", &n );

    int** intervals = ( int** )malloc( n * sizeof(int*) );
    int intervalsColSize = 2;

    for ( int i = 0; i < n; i++ ) {
        intervals[i] = ( int* )malloc( intervalsColSize * sizeof(int) );
        printf ( "Informe os valores do intervalo[%d]:\n ", i + 1 );
        scanf ( "%d %d", &intervals[i][0], &intervals[i][1] );
    }

    int returnSize;
    int* returnColumnSizes;
    int** res = Merge ( intervals, n, &intervalsColSize, &returnSize, &returnColumnSizes );

    printf ("Resultado:\n");
    for ( int i = 0; i < returnSize; i++ ) {
        printf ("[%d, %d] ", res[i][0], res[i][1]);
    }
    printf ("\n");
    for ( int i = 0; i < n; i++ ) {
        free ( intervals[i] );
    }
    free ( intervals );

    for ( int i = 0; i < returnSize; i++ ) {
        free ( res[i] );
    }
    free ( res );
    free ( returnColumnSizes );

    return 0;
}