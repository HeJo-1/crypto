#include <stdio.h>
#include <stdlib.h>

#include "encrypt.h"
#include "decrypt.h"
#include "ing_encrypt.h"
#include "ing_decrypt.h"

int ing();
int tr();

int main(){
    int d; 
    printf("Hoşgeldiniz\nWelcome\n\n\nLütfen bir dil seçiniz\nPlease select a language\n");
    printf("1- Türkçe\n2- English\n");
    scanf("%d", &d);
    
    int cd;
    while ((cd = getchar()) != '\n' && cd != EOF) { }

    switch (d) { 
        case 1:
            tr();
            break;
        case 2:
            ing();
            break;
        default:
            printf("\nGeçersiz seçim lütfen 1 veya 2 giriniz.\nInvalid selection! Please enter 1 or 2.\n");
            break;
    }

    return 0; 
}

int ing() {
    int si; 
    printf("Welcome to the Encryption Application\n");
    printf("1- Encrypt\n");
    printf("2- Decrypt the code\n"); 
    printf("Please enter an operation : ");
    scanf("%d", &si);

    int c;
    while ((c = getchar()) != '\n' && c != EOF) { }

    switch (si) {
        case 1:
            ing_encrypt();
            break;
        case 2:
            ing_decrypt();
            break;
        default:
            printf("\nInvalid selection! Please enter 1 or 2.\n");
            break;
    }

    return 0;
}

int tr() {
    int s; 
    printf("Şifreleme Uygulamasına hoşgeldiniz\n");
    printf("1- Şifrele\n");
    printf("2- Şifreyi Çöz\n");
    printf("Bir işlem giriniz : ");
    scanf("%d", &s);

    int c;
    while ((c = getchar()) != '\n' && c != EOF) { }

    switch (s) {
        case 1:
            encrypt();
            break;
        case 2:
            decrypt();
            break;
        default:
            printf("\nGeçersiz seçim! Lütfen 1 veya 2 yazınız.\n");
            break;
    }

    return 0;
}
