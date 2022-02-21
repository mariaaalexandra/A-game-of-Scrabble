#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "util/print_board.h"
#include "util/scrabble.h"

void task1(char board[15][15])
{
    char N[10];
    long Y, X, D;
    char line[50];
    char WORD[15];
    char *ptr = NULL, *p;
    long result;

    fgets(N, 10, stdin);
        
    result = strtol(N, &ptr, 10);

    int i;

    /* Despart liniile cu strtok și transform
    variabilele Y, X, D din char in int */
    for (i = 0; i < result; i++) {
        fgets(line, 50, stdin);

        p = strtok(line, " ");
        Y = strtol(p, &ptr, 10);

        p = strtok(NULL, " ");
        X = strtol(p, &ptr, 10);

        p = strtok(NULL, " ");
        D = strtol(p, &ptr, 10);

        p = strtok(NULL, " ");
        strcpy(WORD, p);

        WORD[strlen(WORD) - 1] = '\0';

        /*Variabila contor reține poziția 
        caracterelor din WORD */
        int contor = 0;

        int len = strlen(WORD);

        int j;

        /*Verific daca cuvantul trebuie 
        plasat pe verticala sau pe orizontala 
        si copiez fiecare caracter pe pozitia 
        corespunzatoare din matrice*/

        if (D == 1) {
            for (j = Y; j < Y + len; j++) {
                board[j][X] = WORD[contor];
                contor++;
            }
        }
        else {
            for (j = X; j < X + len; j++) {
                board[Y][j] = WORD[contor];
                contor++;
            }
        }      
    }
}

void task2() 
{
    char N[10];
    long result;
    char line[50];
    char WORD[15];
    int i, j, sum = 0, sum1 = 0, sum2 = 0, len;
    char *p, *ptr = NULL;

    fgets(N, 10, stdin);
    result = strtol(N, &ptr, 10); 
    for (i = 0; i < result; i++) {
        fgets(line, 50, stdin);

        /* aplic functia strtok de 4 ori
        si rezultatul final il copiez in 
        variabila WORD */
        p = strtok(line, " ");
        p = strtok(NULL, " ");
        p = strtok(NULL, " ");
        p = strtok(NULL, " ");

        strcpy(WORD, p);
        len = strlen(WORD);

        //adaug sfarsitul de sir
        WORD[len - 1] = '\0';

        len = strlen(WORD);

        /* parcurg fiecare caracter din WORD, 
        verific ce valoare are fiecare si adaug 
        in sum punctajul corespunzator */ 
        for (j = 0; j < len; j++) {
            if (WORD[j] == 'K') {
                sum = sum + 5;
            }
            else if (WORD[j] == 'D' || WORD[j] == 'G') {
                sum = sum + 2;
            }
            else if (WORD[j] == 'J' || WORD[j] == 'X') {
                sum = sum + 8;
            }
            else if (WORD[j] == 'Q' || WORD[j] == 'Z') {
                sum = sum + 10;
            }
            else if (WORD[j] == 'B' || WORD[j] == 'C' ||
            WORD[j] == 'M' || WORD[j] == 'P') {
                sum = sum + 3;
            }
            else if (WORD[j] == 'F' || WORD[j] == 'H' || 
            WORD[j] == 'V' || WORD[j] == 'W'  || WORD[j] == 'Y') {
                sum = sum + 4;
            }
            else {
                sum = sum + 1;
            }
        }

        // verific la ce jucator ma aflu
        if (i % 2 == 0) {
            sum1 += sum;
        }
        else {
            sum2 += sum;
        }

        sum = 0;
    }

    printf("Player 1: %d Points\n", sum1);
    printf("Player 2: %d Points\n", sum2); 
}

void task3() 
{
    char N[10], str1[10], str2[10];
    long Y, X, D;
    char line[50];
    char WORD[15];
    char *ptr = NULL, *p;
    long result;
    int i, j, sum1 = 0, sum2 = 0, sum = 0;

    //Citesc cele doua stringuri si adaug sfarsitul de sir
    fgets(str1, 10, stdin);
    str1[strlen(str1) - 1] = '\0';

    fgets(str2, 10, stdin);
    str2[strlen(str2) - 1] = '\0';

    fgets(N, 10, stdin);
    result = strtol(N, &ptr, 10);

    for (i = 0; i < result; i++) {
        fgets(line, 50, stdin);

        p = strtok(line, " ");
        Y = strtol(p, &ptr, 10);

        p = strtok(NULL, " ");
        X = strtol(p, &ptr, 10);

        p = strtok(NULL, " ");
        D = strtol(p, &ptr, 10);

        p = strtok(NULL, " ");
        strcpy(WORD, p);

        int len = strlen(WORD);

        WORD[len - 1] = '\0';

        len = strlen(WORD);
        
        int logicx = 0, logicy = 0;

        //verific daca str1 se afla in WORD
        if (strstr(WORD, str1)) {
            logicx++;
        }
        
        //verific daca str2 se afla la finalul lui WORD
        if (strstr(WORD + len - 2, str2)) {
            logicy++;
        }

        //calculez punctajul 
        for (j = 0; j < len; j++) {
            if (WORD[j] == 'K') {
                sum = sum + 5;
            }
            else if (WORD[j] == 'D' || WORD[j] == 'G') {
                sum = sum + 2;
            }
            else if (WORD[j] == 'J' || WORD[j] == 'X') {
                sum = sum + 8;
            }
            else if (WORD[j] == 'Q' || WORD[j] == 'Z') {
                sum = sum + 10;
            }
            else if (WORD[j] == 'B' || WORD[j] == 'C' || 
            WORD[j] == 'M' || WORD[j] == 'P') {
                sum = sum + 3;
            }
            else if (WORD[j] == 'F' || WORD[j] == 'H' ||
            WORD[j] == 'V' || WORD[j] == 'W'  || WORD[j] == 'Y') {
                sum = sum + 4;
            }
            else {
                sum = sum + 1;
            }
        }

        /*Verific daca logicx este diferit de 0
        si daca WORD este plasat pe verticala sau orizontala.
        Daca la coordonatele la care se afla caracterele exista 
        valoarea 1, atunci inmultesc cu 2 sum*/
        if (logicx) {
            if (D == 1) {
                for (j = Y; j < Y + len; j++) {
                    if (bonus_board[j][X] == 1) {
                        sum *= 2;
                    }
                }
            }
            else {
                for (j = X; j < X + len; j++) {
                    if (bonus_board[Y][j] == 1) {
                        sum *= 2;
                    }
                }
            }      
        }

        /*Verific daca logicy este diferit de 0
        si daca WORD este plasat pe verticala sau orizontala.
        Daca la coordonatele la care se afla caracterele exista 
        valoarea 2, atunci inmultesc cu 3 sum*/
        if (logicy) {
            if (D == 1) {
                for (j = Y; j < Y + len; j++) {
                    if (bonus_board[j][X] == 2) {
                        sum *= 3;
                    }
                }
            }
            else {
                for (j = X; j < X + len; j++) {
                    if (bonus_board[Y][j] == 2) {
                        sum *= 3;
                    }
                }
            }      
        }

        if (i % 2 == 0) {
            sum1 += sum;
        }
        else {
            sum2 += sum;
        }
        sum = 0;
    }
    printf("Player 1: %d Points\n", sum1);
    printf("Player 2: %d Points\n", sum2);
}

void task4(char board[15][15])
{
    char N[10], str1[10], str2[10];
    long Y, X, D;
    char line[50];
    char WORD[15];
    char *ptr = NULL, *p;
    long result;
    int apparition[100] = {0}, logic, nr_line, vert, oriz, k;

    fgets(str1, 10, stdin);
    str1[strlen(str1) - 1] = '\0';

    fgets(str2, 10, stdin);
    str2[strlen(str2) - 1] = '\0';

    fgets(N, 10, stdin);
        
    result = strtol(N, &ptr, 10);
    nr_line = 0;

    int i, j;

    for (i = 0; i < result; i++) {
        fgets(line, 50, stdin);

        p = strtok(line, " ");
        Y = strtol(p, &ptr, 10);

        p = strtok(NULL, " ");
        X = strtol(p, &ptr, 10);

        p = strtok(NULL, " ");
        D = strtol(p, &ptr, 10);

        p = strtok(NULL, " ");
        strcpy(WORD, p);

        int len = strlen(WORD);

        WORD[len - 1] = '\0';

        len = strlen(WORD);

        int contor = 0;

        if (D == 1) {
            for (j = Y; j < Y + len; j++) {
                board[j][X] = WORD[contor];
                contor++;
            }
        }
        else {
            for (j = X; j < X + len; j++) {
                board[Y][j] = WORD[contor];
                contor++;
            }
        }   
        
        /* logic păstrează 0 dacă WORD se
        află în vectorul words */
        logic = 0;

        for (j = 0; j < 100; j++) {
            //verific dacă WORD se afla in words
            if (strcmp(WORD, words[j]) == 0) {
                logic = 1;
                break;
            }
        }
    
       // adaug valoarea lui logic in vectorul de aparitii
       apparition[j] = logic;

    }

    // parcurg vectorul words si matricea board
    for (nr_line = 0; nr_line < 100; nr_line++) {
        for (i = 0; i < 15; i++) {
            for (j = 0; j < 15; j++) {
                if (board[i][j] == words[nr_line][0] && 
                apparition[nr_line] == 0) {

                    /*variabilele vert si oriz ma ajuta sa aflu daca plasez pe 
                    verticala sau orizontala cuvantul*/
                    vert = 1;
                    oriz = 1;
                    int lung = strlen(words[nr_line]);

                    /*verific daca am spatiu suficient pentru a adauga cuvantul
                    si daca locurile din matrice sunt libere*/ 
                    for (k = i + 1; k < (i + lung); k++) {
                        if (k == 15) {
                            vert = 0;
                            break;
                        }
                        if (board[k][j] != '.') {
                            vert = 0;
                            break;
                        }
                    }

                    for (k = j + 1; k < (j + lung); k++) {
                        if (k == 15) {
                            oriz = 0;
                            break;
                        }
                        if (board[i][k] != '.') {
                            oriz = 0;
                            break;
                        }
                    }

                    if (oriz == 1) {
                        break;
                    }
                    else if (vert == 1) {
                        break;
                    }
                }
               
            }

            //Aplic break pentru a iesi din fiecare for
            if (oriz == 1) {
                break;
            }
            else if (vert == 1) {
                break;
            }
        }

        if (oriz == 1) {
            break;
        }
        else if (vert == 1) {
            break;
        }
    }

    int el = 1;
    int lung = strlen(words[nr_line]);

    if (oriz == 1) {
        for (k = j + 1; k < j + lung; k++) {
            board[i][k] = words[nr_line][el];
            el++;
        }
    }
    else if (vert == 1) {
        for (k = i + 1; k < i + lung; k++) {
            board[k][j] = words[nr_line][el];
            el++;
        }
    }
    print_board(board);   
    
}

void task5(char board[15][15])
{
    char N[10], str1[10], str2[10];
    long Y, X, D;
    char line[50];
    char WORD[15];
    char *ptr = NULL, *p, *word_max;
    long result;
    int i, j, sum1 = 0, sum2 = 0, sum = 0, logic, nr_line, vert, oriz, k,
    apparition[100] = {0}, logicx, logicy, len, new_sum_o, new_sum_v, 
    x_max, y_max, d_max, el, lung_max;

    fgets(str1, 10, stdin);
    str1[strlen(str1) - 1] = '\0';

    fgets(str2, 10, stdin);
    str2[strlen(str2) - 1] = '\0';

    fgets(N, 10, stdin);
    result = strtol(N, &ptr, 10);

    for (i = 0; i < result; i++) {
        fgets(line, 50, stdin);

        p = strtok(line, " ");
        Y = strtol(p, &ptr, 10);

        p = strtok(NULL, " ");
        X = strtol(p, &ptr, 10);

        p = strtok(NULL, " ");
        D = strtol(p, &ptr, 10);

        p = strtok(NULL, " ");
        strcpy(WORD, p);

        len = strlen(WORD);

        WORD[len - 1] = '\0';
        len = strlen(WORD);

        int contor = 0;

        //plasez fiecare cuvânt din input in matricea board
        if (D == 1) {
            for (j = Y; j < Y + len; j++) {
                board[j][X] = WORD[contor];
                contor++;
            }
        }
        else {
            for (j = X; j < X + len; j++) {
                board[Y][j] = WORD[contor];
                contor++;
            }
        }
        
        int logicx = 0, logicy = 0;

        //verific daca str1 si str2 se afla in cuvantul citit
        if (strstr(WORD, str1)) {
            logicx++;
        }
        
        if (strstr(WORD + len - 2, str2)) {
            logicy++;
        }

        //calculez scorul fara bonusuri
        for (j = 0; j < len; j++) {
            if (WORD[j] == 'K') {
                sum = sum + 5;
            }
            else if (WORD[j] == 'D' || WORD[j] == 'G') {
                sum = sum + 2;
            }
            else if (WORD[j] == 'J' || WORD[j] == 'X') {
                sum = sum + 8;
            }
            else if (WORD[j] == 'Q' || WORD[j] == 'Z') {
                sum = sum + 10;
            }
            else if (WORD[j] == 'B' || WORD[j] == 'C' ||
            WORD[j] == 'M' || WORD[j] == 'P') {
                sum = sum + 3;
            }
            else if (WORD[j] == 'F' || WORD[j] == 'H' || 
            WORD[j] == 'V' || WORD[j] == 'W'  || WORD[j] == 'Y') {
                sum = sum + 4;
            }
            else {
                sum = sum + 1;
            }
        }

        /*verific daca in matricea bonus se afla 1 sau 2 
        la coordonatele la care se gaseste cuvantul*/

        if (logicx) {
            if (D == 1) {
                for (j = Y; j < Y + len; j++) {
                    if (bonus_board[j][X] == 1) {
                        sum *= 2;
                    }
                }
            }
            else {
                for (j = X; j < X + len; j++) {
                    if (bonus_board[Y][j] == 1) {
                        sum *= 2;
                    }
                }
            }      
        }

        if (logicy) {
            if (D == 1) {
                for (j = Y; j < Y + len; j++) {
                    if (bonus_board[j][X] == 2) {
                        sum *= 3;
                    }
                }
            }
            else {
                for (j = X; j < X + len; j++) {
                    if (bonus_board[Y][j] == 2) {
                        sum *= 3;
                    }
                }
            }      
        }

        //verific la ce jucator ma aflu
        if (i % 2 == 0) {
            sum1 += sum;
        }
        else {
            sum2 += sum;
        }
        sum = 0;

        logic = 0;

        //verific daca cuvantul citit se afla in words
        for (j = 0; j < 100; j++) {
            if (strcmp(WORD, words[j]) == 0) {
                logic = 1;
                break;
            }
        }

        apparition[j] = logic;
        
    }

    //in variabila max retin scorul maxim pe care il poate avea jucatorul 2
    int Max = 0;

    //Parcurg lista de cuvinte si matricea board
    for (nr_line = 0; nr_line < 100; nr_line++) {
        logicx = 0;
        logicy = 0;
        for (i = 0; i < 15; i++) {
            for (j = 0; j < 15; j++) {
                if (board[i][j] == words[nr_line][0] && 
                apparition[nr_line] == 0) {
                    /*variabilele vert si oriz ma ajuta sa 
                    verific daca plasez cuvantul pe orizontala sau 
                    pe verticala*/
                    vert = 1;
                    oriz = 1;
                    int lung = strlen(words[nr_line]);
                    
                    /*verific daca cuvantul are loc in matrice atat 
                    pentru verticala, cat si pentru orizontala*/

                    for (k = i + 1; k < (i + lung); k++) {
                        if (k == 15) {
                            vert = 0;
                        }
                        if (board[k][j] != '.') {
                            vert = 0;
                        }
                    }

                    for (k = j + 1; k < (j + lung); k++) {
                        if (k == 15) {
                            oriz = 0;
                        }
                        if (board[i][k] != '.') {
                            oriz = 0;
                        }
                    }
                    
                    /*verific daca cuvantul incape fie pe orizontala, 
                    fie pe verticala si calculez suma pe verticala si
                    suma pe orizontala*/
                    if (oriz == 1 || vert == 1) {
                        new_sum_v = 0;
                        new_sum_o = 0;
                        for (k = 0; k < lung; k++) {
                            if (words[nr_line][k] == 'K') {
                                new_sum_o += 5;
                                new_sum_v += 5;
                            }
                            else if (words[nr_line][k] == 'D' || 
                            words[nr_line][k] == 'G') {
                                new_sum_o += 2;
                                new_sum_v += 2;
                            }
                            else if (words[nr_line][k] == 'J' || 
                            words[nr_line][k] == 'X') {
                                new_sum_o += 8;
                                new_sum_v += 8;
                            }
                            else if (words[nr_line][k] == 'Q' || 
                            words[nr_line][k] == 'Z') {
                                new_sum_o += 10;
                                new_sum_v += 10;
                            }
                            else if (words[nr_line][k] == 'B' ||
                            words[nr_line][k] == 'C' || 
                            words[nr_line][k] == 'M' 
                            || words[nr_line][k] == 'P') {
                                new_sum_o += 3;
                                new_sum_v += 3;
                            }
                            else if (words[nr_line][k] == 'F' || 
                            words[nr_line][k] == 'H' || words[nr_line][k] == 
                            'V' || words[nr_line][k] == 'W'  || 
                            words[nr_line][k] == 'Y') {
                                new_sum_o += 4;
                                new_sum_v += 4;
                            }
                            else {
                                new_sum_o += 1;
                                new_sum_v += 1;
                            }
                        }

                        //verific daca str1 se afla in cuvant                        
                        if (strstr(words[nr_line], str1)) {
                            logicx++;
                        }
                        
                        //verific daca str2 se afla la sfarsitul cuvantului
                        if (strstr(words[nr_line] + lung - 2, str2)) {
                            logicy++;
                        }

                        /*calculez scorul impreuna cu bonusuri, mai intai 
                        pentru primul tip de bonus, iar apoi pentru al doilea*/
                        if (logicx) {
                            if (vert == 1) {
                                for (k = i; k < i + lung; k++) {
                                    if (bonus_board[k][j] == 1) {
                                        new_sum_v *= 2;
                                    }
                                }
                            }
                            if (oriz == 1) {
                                for (k = j; k < j + lung; k++) {
                                    if (bonus_board[i][k] == 1) {
                                        new_sum_o *= 2;
                                    }
                                }
                            }      
                        }   

                        
                        if (logicy) {
                            if (vert == 1) {
                                for (k = i; k < i + lung; k++) {
                                    if (bonus_board[k][j] == 2) {
                                        new_sum_v *= 3;
                                    }
                                }
                            }
                            if (oriz == 1) {
                                for (k = j; k < j + lung; k++) {
                                    if (bonus_board[i][k] == 2) {
                                        new_sum_o *= 3;
                                    }
                                }
                            }      
                        }

                        /*verific daca suma pe orizontala adunata cu 
                        suma 2 depaseste Max si daca cuvantul 
                        incape pe orizonatala.
                        Pastrez coordonatele, directia, lungimea si cuvantul*/
                        if (new_sum_o + sum2 > Max && oriz == 1) {
                            Max = new_sum_o + sum2;
                            x_max = i;
                            y_max = j;
                            d_max = 0;
                            lung_max = strlen(words[nr_line]);
                            word_max = words[nr_line];
                        }
                        /*verific daca suma pe orizontala adunata cu 
                        suma 2 este egala cu Max, daca cuvantul incape pe 
                        orizonatala si daca pasul i nu depaseste coordonata 
                        x max*/
                        else if (new_sum_o + sum2 == Max && oriz == 1
                        && i < x_max) {
                            Max = new_sum_o + sum2;
                            x_max = i;
                            y_max = j;
                            d_max = 0;
                            lung_max = strlen(words[nr_line]);
                            word_max = words[nr_line];
                        }
                        /*verific daca suma pe orizontala adunata cu suma
                        2 este egala cu Max, daca cuvantul incape pe 
                        orizonatala, daca pasul i este egal cu x_max si
                        j nu depasesc y max*/
                        else if (new_sum_o + sum2 == Max && oriz == 1 && 
                        i == x_max && j < y_max) {
                            Max = new_sum_o + sum2;
                            x_max = i;
                            y_max = j;
                            d_max = 0;
                            lung_max = strlen(words[nr_line]);
                            word_max = words[nr_line];
                        }
                        //repet verificarile si pentru verticala
                        if (new_sum_v + sum2 > Max && vert == 1) {
                            Max = new_sum_v + sum2;
                            x_max = i;
                            y_max = j;
                            d_max = 1;
                            lung_max = strlen(words[nr_line]);
                            word_max = words[nr_line];
                        }
                        else if (new_sum_v + sum2 == Max && vert == 1 
                        && i < x_max) {
                            Max = new_sum_v + sum2;
                            x_max = i;
                            y_max = j;
                            d_max = 1;
                            lung_max = strlen(words[nr_line]);
                            word_max = words[nr_line];
                        }
                        else if (new_sum_v + sum2 == Max && vert == 1
                        && i == x_max && j < y_max) {
                            Max = new_sum_v + sum2;
                            x_max = i;
                            y_max = j;
                            d_max = 1;
                            lung_max = strlen(words[nr_line]);
                            word_max = words[nr_line];
                        }
                        
                    } 

                }
            }
        }
    }


    /*daca Max este mai mic decat suma jucatorului 1, 
    atunci afisez mesajul "Fail!"
    altfel adaug cuvantul si afisez tabla*/
   if (Max < sum1) {
        printf("Fail!");
    }
    else {
        el = 1;
        if (d_max == 0) {
            for (k = y_max + 1; k < y_max + lung_max; k++) {
                board[x_max][k] = word_max[el];
                el++;
            }
        }
        else {
            for (k = x_max + 1; k < x_max + lung_max; k++) {
                board[k][y_max] = word_max[el];
                el++;
            }

        }
        
        print_board(board);
    }                      
}


int main()
{
    char board[15][15];
    int i, j;
    char task;

    task = getchar(); getchar();

    //populez matricea cu puncte
    for (i = 0; i < 15; i++) {
        for(j = 0; j < 15; j++) {
            board[i][j] = '.';
        }
    }


    //In functie de task apelez functia corespunzatoare
    if (task == '0') {
        print_board(board);
    }
    else if (task == '1') {
        task1(board);
        print_board(board);  
    }
    else if (task == '2') {
        task2();
    }
    else if (task == '3') {
        task3();
    }
    else if (task == '4') {
        task4(board);
    }
    else {
       task5(board);
    }
    
    
    
    return 0;
}