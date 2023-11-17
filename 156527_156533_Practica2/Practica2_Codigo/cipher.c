#include <stdio.h>
#include <string.h>
#include "cipher.h"
#define MAXC 90
#define MINC 65
#define MAXc 122
#define MINc 97
#define MINN 48
#define MAXN 57

/*
 * student 1 = Tomás
 * student 2 = Sergio
 * work = Práctica 2
 * date of creation = 06/11/2023
 *
 * aim of the document = implement the functions of the cipher.h document. These four functions lets cipher and
 * decipher the input text in Caesar or Vigenere techniques. It makes this program very useful.
 */


//Creation of my own Strlen function
int strlenC(const char array[])
{
    int lenght = 0;

    for(int i = 0; i < 50; i++)
    {
        if(array[i] != '\0' && array[i] != '\r' && array[i] != '\n')
        {
            lenght++;
        }else
        {
            break;
        }
    }
    return lenght;

}

int cipher_vigenere( char PlainToCipher[],  char key[])
{

    //Declare the variables
    int size = strlenC(PlainToCipher);
    int ksize = strlenC(key);

    printf("Ciphering: [");


    //Show the original phrase array
    for(int h = 0; h < size; h++)
    {
        if(h == size - 1)
        {
            printf("%c", PlainToCipher[h]);
            printf("]\n\nciphered: ");
        }else if( h < size - 1){
            printf("%c, ", PlainToCipher[h]);
        }
    }



    //loop to check the array[i] and make the calculations
    for(int i = 0; i < size ; i++)
    {
        //check if it has spaces, if it ends (\0 or \n) or if it is a number.
        if(PlainToCipher[i] != ' ' && PlainToCipher[i] != '\0' && PlainToCipher[i] != '\n' && PlainToCipher[i] != '\r' && (MINN >= PlainToCipher[i] || MAXN <PlainToCipher[i]))
        {

            //When the phrase[i] is in capital letter and the key[i] is too
            if((MINC <= PlainToCipher[i] && PlainToCipher[i] <= MAXC) && (MINC <= key[i % (ksize)] && key[i % (ksize)] <= MAXC))
            {

                PlainToCipher[i] = PlainToCipher[i] + (key[i % (ksize)]) - MINC;

                if((int)PlainToCipher[i] > MAXC)
                {
                    PlainToCipher[i] = MINC + (int)PlainToCipher[i] - MAXC - 1;
                }

            //When the phrase[i] is in capital letter and the key[i] is not
            }else if((MINC <= PlainToCipher[i] && PlainToCipher[i] <= MAXC) && (MINc <= key[i % (ksize)] && key[i % (ksize)] <= MAXc))
            {

                PlainToCipher[i] = PlainToCipher[i] + (key[i % ksize]) - MINc;


                if((int)PlainToCipher[i] > MAXC)
                {
                    PlainToCipher[i] = MINC + (int)PlainToCipher[i] - MAXC - 1;
                }

            //When the key[i] is in capital letter and the phrase[i] is not
            }else if((MINc <= PlainToCipher[i] && PlainToCipher[i] <= MAXc) && (MINC <= key[i % (ksize)] && key[i % (ksize)] <= MAXC))
            {

                PlainToCipher[i] = PlainToCipher[i] + (key[i % (ksize)]) - MINC;

                if((int)PlainToCipher[i] > MAXc)
                {
                    PlainToCipher[i] = MINc + (int)PlainToCipher[i] - MAXc - 1;
                }

            //When the key[i] is not in capital letter and the key[i] isn't either
            }else if((MINc <= PlainToCipher[i] && PlainToCipher[i] <= MAXc) && (MINc <= key[i % (ksize)] && key[i % (ksize)] <= MAXc))
            {

                PlainToCipher[i] = PlainToCipher[i] + (key[i % ksize]) - MINc;


                if((int)PlainToCipher[i] > MAXc)
                {

                        PlainToCipher[i] = MINc  + (int)PlainToCipher[i] - MAXc - 1;

                }

            //When the phrase[i] is not a valid character
            }else{
                return -1;
            }

            //manual correction of an unusual error
            if(-128 <= (int)PlainToCipher[i] && (int)PlainToCipher[i] <= -109)
            {
                PlainToCipher[i] = 102 + (128 + PlainToCipher[i]);
            }


        }

        //Print the result one at a time to build the phrase
        printf("%c", PlainToCipher[i]);


    }



    /*


    for(int i = 0; i < size ; i++)
    {
        if(offset[i % ksize] != '\n')
        {
            printf("%c", offset[i % ksize]);
        }

    }
     */

    return 0;

}

int decipher_vigenere( char PlainToCipher[],  char key[])
{

    //Declare the variables
    int size = strlenC(PlainToCipher); //usage of our own Strlen function
    int ksize = strlenC(key); //usage of our own Strlen function

    printf("Ciphering: [");


    //Show the original cipher phrase array
    for(int h = 0; h <= size; h++)
    {
        if(h == size - 1)
        {
            printf("%c", PlainToCipher[h]);
            printf("]\n\ndeciphered: ");
        }else if( h < size - 1){
            printf("%c, ", PlainToCipher[h]);
        }
    }

    //loop to check the array[i] and make the calculations
    for(int i = 0; i < size ; i++)
    {
        //check if it has spaces, if it ends (\0 or \n) or if it is a number.
        if(PlainToCipher[i] != ' ' && PlainToCipher[i] != '\0' && PlainToCipher[i] != '\n' && PlainToCipher[i] != '\r' && (MINN >= PlainToCipher[i] || MAXN <PlainToCipher[i]))
        {

            //When the phrase[i] is in capital letter and the key[i] is too
            if((MINC <= PlainToCipher[i] && PlainToCipher[i] <= MAXC) && (MINC <= key[i % (ksize)] && key[i % (ksize)] <= MAXC))
            {

                PlainToCipher[i] = PlainToCipher[i] - ((key[i % (ksize)]) - MINC);

                if((int)PlainToCipher[i] < MINC)
                {
                    PlainToCipher[i] = (MAXC) - (MINC - 1 - (int)PlainToCipher[i]);
                }

            //When the phrase[i] is in capital letter and the key[i] is not
            }else if((MINC <= PlainToCipher[i] && PlainToCipher[i] <= MAXC) && (MINc <= key[i % (ksize)] && key[i % (ksize)] <= MAXc))
            {

                PlainToCipher[i] = PlainToCipher[i] - ((key[i % (ksize)]) - MINc);


                if((int)PlainToCipher[i] < MINC)
                {
                    PlainToCipher[i] = (MAXC) - (MINC - 1 - (int)PlainToCipher[i]);
                }

            //When the phrase[i] is not a capital letter and the key[i] is
            }else if((MINc <= PlainToCipher[i] && PlainToCipher[i] <= MAXc) && (MINC <= key[i % (ksize)] && key[i % (ksize)] <= MAXC))
            {

                PlainToCipher[i] = PlainToCipher[i] - ((key[i % (ksize)]) - MINC);

                if((int)PlainToCipher[i] < MINc)
                {
                    PlainToCipher[i] = MAXc - (MINc - 1 - (int)PlainToCipher[i]);
                }

            //When the phrase[i] is not a capital letter and the key[i] is not either
            }else if((MINc <= PlainToCipher[i] && PlainToCipher[i] <= MAXc) && (MINc <= key[i % (ksize)] && key[i % (ksize)] <= MAXc))
            {

                PlainToCipher[i] = PlainToCipher[i] - ((key[i % ksize]) - MINc);


                if((int)PlainToCipher[i] < MINc)
                {
                    PlainToCipher[i] = MAXc - (MINc - 1 - (int)PlainToCipher[i]);
                }

            //When the phrase[i] is not a valid character
            }else{
                return -1;
            }

            //manual correction of an unusual error
            if(-128 <= (int)PlainToCipher[i] && (int)PlainToCipher[i] <= -109)
            {
                PlainToCipher[i] = 102 + (128 + PlainToCipher[i]);
            }


        }

        //Print the result one at a time to build the phrase
        printf("%c", PlainToCipher[i]);


    }



    /*


    for(int i = 0; i < size ; i++)
    {
        if(offset[i % ksize] != '\n')
        {
            printf("%c", offset[i % ksize]);
        }

    }
     */

    return 0;

}

//-----------------------------------------------------------------------------------------------------
//-----------------------------------CAESAR------------CIPHER------------------------------------------
//-----------------------------------------------------------------------------------------------------

int cipher_caesar(char PlainToCipher[], int offset) {//Declare varables;
    int i = 0;



    while (PlainToCipher[i] != '\0') { //while the phrase[i] is not null, the program can execute
        if ((PlainToCipher[i] >= 'a' && PlainToCipher[i] <= 'z') ||
            (PlainToCipher[i] >= 'A' && PlainToCipher[i] <= 'Z') ||
            (PlainToCipher[i] >= '0' && PlainToCipher[i] <= '9') || PlainToCipher[i] == ' ')
        { // checks if the phrase[i] is a capital letter, a number or a non-capital letter

            if ((PlainToCipher[i] >= 'a' && PlainToCipher[i] <= 'z') ||
                (PlainToCipher[i] >= 'A' && PlainToCipher[i] <= 'Z'))
            { // checks if phrase[i] is a letter

                if (PlainToCipher[i] >= 'a' && PlainToCipher[i] <= 'z') // if it is a letter it makes the necessary calculations
                {
                    PlainToCipher[i] = ((((PlainToCipher[i] - 'a' + offset) % 26) + 26) % 26) + 'a';
                } else {
                    PlainToCipher[i] = ((((PlainToCipher[i] - 'A' + offset) % 26) + 26) % 26) + 'A';
                }
            }

            //if something goes wrong, the program returns -1
        } else {

            return -1;
        }
        i++;
    } //Shows the text correctly ciphered.
    printf ("\n");
    printf("Ciphered: %s", PlainToCipher);
    printf("\n");




    return 0;
}


int decipher_caesar(char PlainToCipher[], int offset) {//Declare variables
    int i = 0;

    offset = offset * -1;

    //Spanish for long explanation
    /*Se han utilizado condicionales anidadas. Primero el programa pone de condicional que el texto sea de letras o números
     *Posteriormente, se reduce a sólo letras. Por último, se reduce a sólo letras minúsculas. Así, si la letra es minúscula
     * se llega hasta el último if, que define lo que el programa debe hacer en caso de encontrar una letra minúscula.
     * Si es una letra mayúscula, el programa ejecuta el segundo "if". En caso de no ser una letra, el programa ejecuta sólo el primer "if".
     * Los espacios se respetan al no aplicar rotaciones cuando se encuentra uno.
     *
     * Los módulos %26 y %10 se han utilizado para permitir que en caso de letra cada 26 rotaciones (hay 26 letras) vuelva a empezar y así
     * no se salga de los valores ASCII para las letras "a" - "z" y "A" - "Z". En
     * caso de que las rotaciones sean números altos, habría que aplicar a ese resultado nuevamente otro módulo más para seguir reduciendo
     * su tamaño hasta que de tantas vueltas como sean necesarias para que las rotaciones que queden sean menores de 26. */


    while (PlainToCipher[i] != '\0') { //while the phrase[i] is not null, the program can execute
        if ((PlainToCipher[i] >= 'a' && PlainToCipher[i] <= 'z') ||
            (PlainToCipher[i] >= 'A' && PlainToCipher[i] <= 'Z') ||
            (PlainToCipher[i] >= '0' && PlainToCipher[i] <= '9') || PlainToCipher[i] == ' ')
        {
            if ((PlainToCipher[i] >= 'a' && PlainToCipher[i] <= 'z') ||
                (PlainToCipher[i] >= 'A' && PlainToCipher[i] <= 'Z'))
            {
                if (PlainToCipher[i] >= 'a' && PlainToCipher[i] <= 'z')
                {
                    PlainToCipher[i] = ((((PlainToCipher[i] - 'a' + offset) % 26) + 26) % 26) + 'a';
                } else {
                    PlainToCipher[i] = ((((PlainToCipher[i] - 'A' + offset) % 26) + 26) % 26) + 'A';
                }
            }


        } else {

            return -1;
        }
        i++;
    } //Show the text correctly deciphered.
    printf("\n");
    printf("Deciphered: %s", PlainToCipher);



    return 0;
}


