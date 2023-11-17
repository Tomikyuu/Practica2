#include <stdio.h>
#include <string.h>
#include "cipher.c"
#include "cipher.h"

// create library <cipher.h> --> We need to create the script cipher.c

//previa --> diagramas flujo, pseudo, crear .c y funciones vacias

// Tomás --> ID num = 156527
// Sergio --> ID num = 156533


//FOUR FUNCTIONS --> cipher_vigenere, decipher_vigenere, cipher_Caesar y decipher_Caesar

int main() {

    //declare the variables
    char key[10];
    int off;
    char phrase[50];
    int mode = 0;

    //Select the mode
    while(mode == 0)
    {
        mode = 0;
        int result = 0;
        printf("Select a mode: \nVig%cnere cipher(1)\nVig%cnere decipher(2)\nCaesar cipher(3)\nCaesar decipher(4)\nExit(5)\n\n", 138, 138);

        scanf("%d", &mode);

        switch(mode){

            //Mode 1: vigenere-Cipher
            case 1:

                fflush(stdin);

                //asks for phrase and key
                printf("write the phrase you want to cipher\n");
                fgets(phrase, 50, stdin);

                printf("write the key word to cipher it\n");
                gets(key);

                //call the function and store the return value
                result = cipher_vigenere(phrase, key);

                if (result == 0)
                {
                    //if return is 0, it says that the program was successful asks if you want to continue using the program
                    char rep = 0;
                    printf("\ncipher completed\n\n");
                    printf("continue?: yes(y) no(n)\n");
                    scanf("%c", &rep);
                    if (rep == 'y')
                    {
                        printf("\n\n");

                    }else if(rep == 'n'){
                        return 0;
                    }else{

                        while(rep != 'y' && rep != 'n'){
                            fflush(stdin);
                            printf("try again: yes(y) no (n)\n");
                            scanf("%c", &rep);
                        }
                        printf("\n\n");
                    }

                    //if it returns -1, it tells you that the cipher has failed
                }else{
                    printf("\nsomething went wrong, check your inputs (no special characters allowed)\n\n");
                }


                break;

            //Mode 2: vigenere-Decipher
            case 2:

                //asks for phrase and key
                fflush(stdin);
                printf("write the phrase you want to decipher\n");
                fgets(phrase, 50, stdin);

                printf("write the key word used to cipher it\n");
                gets(key);

                //call the function and store the return value
                result = decipher_vigenere(phrase, key);

                if (result == 0)
                {

                    //if return is 0, it says that the program was successful asks if you want to continue using the program
                    char rep = 0;
                    printf("\ndecipher completed\n\n");
                    printf("continue?: yes(y) no(n)\n");
                    scanf("%c", &rep);
                    if (rep == 'y')
                    {
                        printf("\n\n");

                    }else if(rep == 'n'){
                        return 0;
                    }else{

                        while(rep != 'y' && rep != 'n'){
                            fflush(stdin);
                            printf("try again: yes(y) no (n)\n");
                            scanf("%c", &rep);
                        }
                        printf("\n\n");
                    }
                    //if it returns -1, it tells you that the cipher has failed
                }else{
                    printf("\nsomething went wrong, check your inputs\n\n");
                }


                break;

            //Mode 3: Caesar-Cipher
            case 3:

                fflush(stdin);

                //asks for phrase and key
                printf("Write the text you want to cipher: \n");
                scanf("%[^\n]s", phrase);


                printf("write the number of rotations: \n");
                scanf("%d", &off);

                //call the function and store the return value
                result = cipher_caesar(phrase, off);

                if (result == 0)
                {
                    //if return is 0, it says that the program was successful asks if you want to continue using the program
                    char rep = 0;
                    printf("\ncipher completed\n\n");
                    printf("continue?: yes(y) no(n)\n");
                    fflush(stdin);
                    scanf("%c", &rep);
                    if (rep == 'y')
                    {
                        printf("\n\n");

                    }else if(rep == 'n'){
                        return 0;
                    }else{

                        while(rep != 'y' && rep != 'n'){
                            fflush(stdin);
                            printf("try again: yes(y) no (n)\n");
                            scanf("%c", &rep);
                        }
                        printf("\n\n");
                    }
                    //if it returns -1, it tells you that the cipher has failed
                }else{
                    printf("\nsomething went wrong, check your inputs\n\n");
                }

                break;

            //Mode 4: Caesar-Decipher
            case 4:

                fflush(stdin);

                //asks for phrase and key
                printf("Write the text you want to cipher: \n");
                scanf("%[^\n]s", phrase);


                printf("write the number of rotations: \n");
                scanf("%d", &off);

                //call the function and store the return value
                result = decipher_caesar(phrase, off);

                if (result == 0)
                {
                    //if return is 0, it says that the program was successful asks if you want to continue using the program
                    char rep = 0;
                    printf("\ndecipher completed\n\n");
                    printf("continue?: yes(y) no(n)\n");
                    fflush(stdin);
                    scanf("%c", &rep);
                    if (rep == 'y')
                    {
                        printf("\n\n");

                    }else if(rep == 'n'){
                        return 0;
                    }else{

                        while(rep != 'y' && rep != 'n'){
                            fflush(stdin);
                            printf("try again: yes(y) no (n)\n");
                            scanf("%c", &rep);
                        }
                        printf("\n\n");
                    }
                    //if it returns -1, it tells you that the cipher has failed
                }else{
                    printf("\nsomething went wrong, check your inputs\n\n");
                }




                break;

            //Mode 5: End the program
            case 5:

                //Exit
                return 0;

                break;

            //If the mode is not one of those, ask again
            default:

                printf("that is not an available option, try again\n\n");

                break;


        }
        mode = 0;
        fflush(stdin);

    }

    return 0;
}
