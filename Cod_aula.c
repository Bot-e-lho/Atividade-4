/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** merge(int** intervals, int intervalsSize, int* intervalsColSize, int* returnSize, int** returnColumnSizes){
    int* temp = (int*)malloc(sizeof(int) * 2);
    temp[2] = 0;
    int* temp2 = (int*)malloc(sizeof(int) * 2);
    temp2[2] = 0, 10000;
    int** res = (int*)malloc(sizeof(int) * intervalsColSize);
        for ( int i = 0; i < intervalsSize; i++) {
            *res[i] = (int*)malloc(sizeof(int) * intervalsSize); 
        }

    for ( int i = 0; i < intervalsColSize; i++ ) {// teria que fazer algumas logicas antes, mas procurei acessar a matriz pra iniciar a temporaria com a primeira dupla de intervalos 
        for ( int j = 0; j < 2; j++ ){//cada dupla é uma coluna aqui percorre ela com a ideia de ser uma dupla
            if ( temp[j] >= *(&intervals[i][j]) ){
                temp[j] = *(&intervals[i][j]);
                }
            if ( temp2[0] <= temp[0] && temp[1] < temp2[1] ) {// procura saber se está contido no intervalo.
                temp2[0] = temp[0];
                temp2[1] = temp[1];

            }
        }


    }

//pegaria o primeiro vetor constituido com um intervalo, e compararia com o restante, se houvesse algum que se cruzassem, armazenava em uma variavel temporaria, mesmo que o primeiro contenha um ponto ele checaria o restante dos array's para indicaria cruzamentos maiores.
//tentativa banal, mas esta fazendo sentido na hora, provalvemente se continuar daria(arrumando a lógica dos ponteiros que está uma bagunça entre outros)
// criei um vetor para fazer os testes, poderia ter feito direto com uma matriz, a criação de uma matriz res, a qual guardaria o resultado da função e retornaria.
//o codigo está bem incompleto mas acho que consigo prosseguir com essa lógica para a conclusão.