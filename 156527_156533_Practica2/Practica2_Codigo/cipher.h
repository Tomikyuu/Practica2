/*
 * student 1 = Tomás
 * student 2 = Sergio
 * work = Práctica 2
 * date of creation = 06/11/2023
 * aim of the document = implement and define the header of the functions
 */

#ifndef PRACTICA2_APUNTES_CIPHER_H
#define PRACTICA2_APUNTES_CIPHER_H


/*
 * this function ciphers the message merging it with the key
 * parameters:
 * - plain text
 * - key
 * returns: 0, -1
 *
 * if it returns 0 the operation has been successful, but if it returns -1 the program lets you know that something
 * went wrong
 */
int cipher_vigenere(char PlainToCipher[], char key[]);


/*
 * this function deciphers the message merging it with the same key used to cipher it
 * parameters:
 * - cipher text
 * - key
 * returns: 0, -1
 *
 * if it returns 0 the operation has been successful, but if it returns -1 the program lets you know that something
 * went wrong
 */
int decipher_vigenere(char PlainToCipher[], char key[]);


/*
 * this function deciphers the message merging it with the key
 * parameters:
 * - cipher text
 * - key
 * returns: 0, -1
 *
 * if it returns 0 the operation has been successful, but if it returns -1 the program lets you know that something
 * went wrong
 */
int cipher_caesar(char PlainToCipher[], int offset);


/*
 * this function deciphers the message merging it with the same key used to cipher it
 * parameters:
 * - cipher text
 * - key
 * returns: 0, -1
 *
 * if it returns 0 the operation has been successful, but if it returns -1 the program lets you know that something
 * went wrong
 */
int decipher_caesar(char PlainToCipher[], int offset);

#endif //PRACTICA2_APUNTES_CIPHER_H
