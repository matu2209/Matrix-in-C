#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void chargeMatrix(int rows, int columns, int matrix[rows][columns]);
void printMatrix(int rows, int columns, int matrix[rows][columns]);
void chargeAutoMatrix(int rows, int columns, int matrix[rows][columns]);
void printMatrixWords(int rowsChar, int columns, char matrix[rowsChar][columns]);
void orderedMatrixWords(int rowsChar,int columns, char matrix[rowsChar][columns]);
void printVotes(int rowsValidate, int columns, int columnsChar, int matrixVote[rowsValidate][columns], char matrixCharVote[rowsValidate][columnsChar]);
void calculateVotesByCandidates(int rowsValidate, int columns, int columnsChar, int matrixVote[rowsValidate][columns], char matrixCharVote[rowsValidate][columns]);

int chargeVote(int rows, int columns, int columnsChar, int matrixVote[rows][columns], char matrixCharVote[rows][columnsChar]);
int summationMatrix(int rows, int columns, int matrix[rows][columns]);
int chargeMatrixWithWords(int rows, int columns, char matrix[rows][columns]);
int searchInMatrix(int rows, int columns, int matrix[rows][columns], int dato);
int searchWordInMatrix(int rowsChar,int columns, char matrix[rowsChar][columns], char word[], int dimensionWord);
int searchWordInMatrixOrdered(int rowsChar, int columns, char matrix[rowsChar][columns], char word[]);

float averageMatrix(int rows, int columns, int matrix[rows][columns]);

int main()
{
    srand(time(NULL));
    int rowsManual = 3, columnsManual = 3, district = 5, rowsPhrase = 10, matrixManual[rowsManual][columnsManual],matrixAuto[rowsManual][columnsManual],
        matrixVote[district][rowsPhrase], columnsChar = 20, summation, number,
        validateArrayChar, validatePhrase, rowsArrayChar = 20, columnsArrayChar = 40, dimensionWord = 40; 
    
    char phrase[rowsPhrase][columnsArrayChar],arrayChar[rowsArrayChar][columnsArrayChar], word[dimensionWord], option;
    float average;
    
    system("cls");
    
    do
    {
        printf("Trabajo con matrices.\n",25);
        printf("1 - Cargar una matriz por completo (3x3).\n");
        printf("2 - Muestra una matriz cargada manualmente.\n");
        printf("3 - Cargar una matriz con numeros aleatorios y mostrar por pantalla(3x3)\n");
        printf("4 - Sumar una matriz ya cargada (tener en cuenta haber realizado opcion 2).\n");
        printf("5 - Calcular el promedio de una matriz (tener en cuenta haber realizado opcion 2)\n");
        printf("6 - Buscar un numero en la matriz (tener en cuenta haber realizado opcion 2).\n");
        printf("7 - Cargar palabras en un arreglo.\n");
        printf("8 - Muestra arreglo de palabras (tener en cuenta de haber realizado opcion 7).\n");
        printf("9 - Buscar una palabra en el arreglo de palabras (tener en cuenta haber realizado la opcion 7)\n");
        printf("0 - Ordenar el arreglo de palabras (tener en cuenta haber realizado opcion 7)\n");
        printf("q - Realizar el subprograma que calcula votos de elecciones\n");
        printf("w - Busqueda binaria (tener en cuenta haber realizado la opcion 7).\n");
        
        option = getch();
        
        system("cls");
        
        switch (option)
        {
        case '1':
            chargeMatrix(rowsManual, columnsManual, matrixManual);
            system("pause");
            break;
        
        case '2':
            printMatrix(rowsManual,columnsManual, matrixManual);
            system("pause");
            break;
        
        case '3':
            chargeAutoMatrix(rowsManual, columnsManual, matrixAuto);
            printMatrix(rowsManual, columnsManual, matrixAuto);
            printf("\nMatriz cargada con numeros aleatorio con exito\n");
            system("pause");
            break;
        
        case '4':
            summation = summationMatrix(rowsManual, columnsManual, matrixManual);
            printf("\nLa suma de la matriz es %d\n", summation);
            system("pause");
            break;
        case '5':
            average = averageMatrix(rowsManual, columnsManual, matrixManual);
            printMatrix(rowsManual, columnsManual, matrixManual);
            printf("\nEl promedio de la matriz es %.2f\n", average);
            system("pause");
            break;
        
        case '6':
            printf("Ingrese un numero a buscar en la matriz: ");
            scanf("%d", &number);
            printMatrix(rowsManual, columnsManual, matrixManual);
            if(searchInMatrix(rowsManual, columnsManual, matrixManual,number))
                printf("\nEl valor %d se encuentra en la matriz\n", number);
            else
                printf("\nEl valor %d no se encuentra en la matriz\n", number);
                system("pause"); 
            break;
        
        case '7':
            validateArrayChar = chargeMatrixWithWords(rowsArrayChar, columnsArrayChar, arrayChar);
            break;
        
        case '8':
            printMatrixWords(validateArrayChar, columnsArrayChar, arrayChar);
            printf("\n");
            system("pause");
            break;
        
        case '9':
            printf("Ingrese una palabra para ser buscada: ");
            scanf(" %s", word);
            printMatrixWords(validateArrayChar, columnsArrayChar, arrayChar);
            if (searchWordInMatrix(validateArrayChar, columnsArrayChar, arrayChar, word, dimensionWord) != -1)
                printf("\nLa palabra se encuentra en el arreglo de palabras\n");
            else    
                printf("\nLa palabra no se encuentra en el arreglo de palabras\n");
            system("pause");
            break;
        
        case '0':
            printf("El arreglo de palabras\n");
            printMatrixWords(validateArrayChar, columnsArrayChar, arrayChar);
            orderedMatrixWords(validateArrayChar, columnsArrayChar, arrayChar);
            printf("El arreglo de palabras luego de ser ordenado por seleccion\n");
            printMatrixWords(validateArrayChar, columnsArrayChar, arrayChar);
            system("pause");
            break;
        
        case 113:
            validatePhrase = chargeVote(rowsPhrase, district, columnsChar, matrixVote, phrase);
            printVotes(validatePhrase, district, columnsChar, matrixVote, phrase);
            calculateVotesByCandidates(validatePhrase, district, columnsChar,matrixVote, phrase);
            system("pause");
            break;
        
        case 119:
            printf("Ingrese una palabra para ser buscada: ");
            scanf(" %s", word);
            orderedMatrixWords(validateArrayChar, columnsArrayChar, arrayChar);
            printMatrixWords(validateArrayChar, columnsArrayChar, arrayChar);
            if (searchWordInMatrixOrdered(validateArrayChar, columnsArrayChar, arrayChar, word) != -1)
                printf("\nLa palabra se encuentra en el arreglo de palabras\n");
            else
                printf("\nLa palabra no se encuentra en el arreglo de palabras\n");
            system("pause");
            break;
        
        default:
            break;
        }
        
        system("cls");
    
    } while (option != 27);
    
    return 0;
}

/*Hacer una función que reciba como parámetro una matriz de números enteros y permita que
el usuario ingrese valores al mismo por teclado. La función debe cargar la matriz por
completo.*/

void chargeMatrix(int rows,int columns,int matrix[rows][columns]){

    int i=0, j=0;
    
    for (i = 0; i < rows; i++)//se carga la matriz por completo!! usando todos los lugares
    {
        for  (j = 0; j < columns; j++)
        {
            printf("\nIngrese elementos de la matriz: ");
            scanf("%d", &matrix[i][j]);
        }
    }
}

/*Hacer una función que reciba como parámetro una matriz de números enteros y la muestre
por pantalla (en formato matricial).*/
void printMatrix(int rows, int columns, int matrix[rows][columns]){

    int i,j;

    for (i = 0; i < rows; i++)
    {
        for (j = 0; j < columns; j++)
        {
            printf("| %d", matrix[i][j]);//se muestra por pantalla los datos la matriz
        }
        printf("\n");//separador para mostrar en formato matriz
    }
    
}

/*Hacer una función que reciba como parámetro una matriz de números enteros y que cargue
la misma con números aleatorios (sin intervención del usuario). La función debe cargar la
matriz por completo.*/
void chargeAutoMatrix(int rows, int columns, int matrix[rows][columns]){

    int i=0, j=0;

    for (i = 0; i < rows; i++)
    {
        for (j = 0; j < columns; j++)
        {
            matrix[i][j] = rand()%10;//se cargan valores randon entre 0-10
        }
    }
}

/*Hacer una función tipo int que sume el contenido total de una matriz de números enteros.*/
int summationMatrix(int rows, int columns, int matrix[rows][columns]){

    int i, j, summation = 0;

    for (i = 0; i < rows; i++)
    {
        for (j = 0; j < columns; j++)
        {
            summation += matrix[i][j];//hace la sumatoria de la matriz
        }
        
    }
    return summation;
}

/*Hacer una función tipo float que calcule el promedio de una matriz de números enteros.*/
float averageMatrix(int rows, int columns, int matrix[rows][columns]){
    int summation; float average;

    summation = summationMatrix(rows,columns,matrix);//invocamos a la funcion que hace la sumatoria de la matriz

    return (average = (float) summation / (rows * columns));//retornamos el promedio    
}

/*Hacer una función que determine si un elemento se encuentra dentro de una matriz de
números enteros. La función recibe la matriz y el dato a buscar.*/
int searchInMatrix(int rows, int columns, int matrix[rows][columns], int dato){

    int i=0, j=0, flag=0;

    for (i=0; i < rows && flag == 0; i++){
        for(j=0; j < columns && flag ==0; j++)
        {
            if (matrix[i][j] == dato)
                flag = 1;
        }
        
    }
    return flag;
}

/*Hacer una función que cargue un arreglo de palabras (strings). La función debe retornar
cuantas palabras se cargaron. (puede ser a través del parámetro como puntero)*/

int chargeMatrixWithWords(int rows, int columns, char matrix[rows][columns]){

    int i=0, j=0; char option;
    
    printf("\nIngrese palabras, para salir presione escape.");
    do
    {
        printf("\nIngrese la palabra Nro %d: ",i+1);
        scanf(" %s",&matrix[i]);//dejar espacio antes del % para limpiar el buffer
        puts("Desea continuar? esc=salir");
        option = getch();
        i++;
    }while(option != 27 && i<rows);//siempre controlamos que no se pase de la dimension
    return i;
}

/*Hacer una función que muestre un arreglo de palabras.*/
void printMatrixWords(int rowsChar, int columns, char matrix[rowsChar][columns]){

    int i=0;

    for (i; i < rowsChar; i++)
    {
        printf("\nPalabra %d es :%s\n", i+1, matrix[i]);//como el %s muestra el string que contiene en esa posicion, no hace falta anidar ciclo
    }
}

/*Hacer una función que determine si un string se encuentra dentro de un arreglo de strings.
La función recibe el arreglo, la cantidad de palabras que contiene y la palabra a buscar.
///devuelve el índice de la fila en que se encuentra, de lo contrario -1*/
int searchWordInMatrix(int rowsChar, int columns, char matrix[rowsChar][columns], char word[], int dimensionWord){

    int i=0, flag=-1, match=0,j=0;//match va a ser la clave de que funcione la logica
    while(i<rowsChar && flag == -1){//controlamos que no tenga iteraciones de mas, encuentra la palabra y corta el ciclo
        
        match=0;//por cada vuelta inicializamos en 0 match
        for (j=0; j<strlen(matrix[i]) && j<dimensionWord; j++){
            if (matrix[i][j] == word[j])//comparamos caracter a caracter y cuenta los matchs
                match++;
        }
    if (match == strlen(matrix[i]))//pregunta si los matchs es igual a la cantidad de letras de la palabra,salva bug que si busca hello y hay un helloo = -1!
        flag = i;//toma el valor de la posicion
    i++;
    }
    return flag;
}

/*Hacer una función que determine si un string se encuentra dentro de un arreglo de strings
ordenado alfabéticamente. La función recibe el arreglo, la cantidad de palabras que contiene
y el string a buscar. ///devuelve el índice de la fila en que se encuentra, de lo contrario -1*/
int searchWordInMatrixOrdered(int rowsChar, int columns, char matrix[rowsChar][columns], char word[]){

    int mid=0, flag =-1, min=0, max=rowsChar-1, count = 1;

    mid = (min + max) / 2;//dividir el arreglo en dos(por medio de los indices)

    while (min < max && strcmp(matrix[mid], word) != 0){
        if (strcmp(word, matrix[mid]) == -1)
            max = mid -1;//si es mas chico toma el valor del medio
        else
            min = mid + 1;//si es mas grande el minimo se corre al medio
        mid = (min + max) / 2;//vuelve a partir en dos la parte en la cayo
    }

    if (strcmp(matrix[mid], word) == 0)//pregunta si es igual y cambia el flag
        flag = 1;

    return flag;
}

/*Hacer una función (o varias) que ordene un arreglo de palabras por orden alfabético. (Por
selección o inserción, el que más te guste).*/
void orderedMatrixWords(int rowsChar,int columns, char matrix[rowsChar][columns]){
    int i, j; char auxWord[20];

    for (i=0; i < rowsChar; i++)
    {
        j = i-1;
        
        strcpy(auxWord,matrix[i]);//copiamos la palabra para ordenar

        while (j >= 0 && strcmp(matrix[j],auxWord)==1){//funcion que devuelve si la cadena es mayor o menor
            strcpy(matrix[j+1],matrix[j]);//si es mayor la vamos corriendo para encontrar el hueco
            j--;
        }
        strcpy(matrix[j+1],auxWord);//insertamos la cadena en el lugar que corresponde
    }
}

/*cargar los candidatos y los votos por distrito*/
int chargeVote(int rows, int columns,int columnsChar, int matrixVote[rows][columns], char matrixCharVote[rows][columnsChar]){

    int i=0, j=0; char option;

    puts("Cargue los candidatos");
    do
    {   
        scanf(" %s", matrixCharVote[i]);
            for (j = 0; j < columns; j++)
            {
                //printf("\nIngrese los votos de %s distrito %d:", matrixCharVote[i],j+1);
                //scanf("%d", &matrixVote[j][i]);//carga manual
                matrixVote[j][i] = rand()%100;//carga random
            }
        i++;
        puts("Desea seguir cargando esc = salir");
        option = getch();
    }while (i<rows && option != 27);
    return i;
}

/*imprimir los votos con las candidatos*/
void printVotes(int rowsValidate, int columns, int columnsChar, int matrixVote[rowsValidate][columns], char matrixCharVote[rowsValidate][columnsChar]){

    int i,j;
    printf("Distrito   |");
    for (i = 0; i < rowsValidate; i++)
    {
        printf("%*s|", 10, matrixCharVote[i]);
    }
    printf("\n");
    for (i = 0; i < columns; i++)
    {
        printf("%*d",10 , i+1);
        for (j = 0; j < rowsValidate; j++)
        {
            printf("%*d", 10 , matrixVote[i][j]);
        }
        printf("\n");
        
    }
    
}

/*calcular la cantidad de votos por candidato*/
void calculateVotesByCandidates(int rowsValidate, int columns, int columnsChar, int matrixVote[rowsValidate][columns], char matrixCharVote[rowsValidate][columnsChar]){
    int totalVotesCandidate[10]={0}, i, j, maxCandidate=0, maxCandidate2=0, totalVotes=0, winner=-1, candidateForBallotage=0, otherCandidateForBallotage=1; 
    float averageCandidate[10], max=0, min=0;
    

    for (i = 0; i < columns; i++)
    {
        for (j = 0; j < rowsValidate; j++)
        {
            totalVotesCandidate[j] += matrixVote[i][j];
            totalVotes += matrixVote[i][j];
        }
    }

    for (i = 0; i < rowsValidate; i++)
    {
        averageCandidate[i] = (float) totalVotesCandidate[i]*100 / totalVotes;

        if (averageCandidate[i] > 50)
            winner = i;
        else if (averageCandidate[i] > max){
            maxCandidate = i;
            max=averageCandidate[i];
        }
        else if ((int)averageCandidate[i] < max && (int)averageCandidate[i] > min){
            maxCandidate2 = i;
            min=averageCandidate[i];
        }
        printf("\nCandidato %s con %.2f%% de los votos y el total de sus votos es %d", matrixCharVote[i], averageCandidate[i], totalVotesCandidate[i]);
    }
    printf("\n%d maxCan y %d maxCandi2", maxCandidate, maxCandidate2);
    if (winner!=-1)
        printf("\nEl candidato ganador por superar el 50%% de los votos es: %s", matrixCharVote[winner]);
    else {
        printf("\nLos candidatos que iran a ballotage son %s con %.2f%% de los votos y  y %s con %.2f%% de los votos", matrixCharVote[maxCandidate], averageCandidate[maxCandidate] ,matrixCharVote[maxCandidate2],  averageCandidate[maxCandidate2]);
    }
}