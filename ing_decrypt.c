#include <stdio.h>
#include <string.h>

int ing_prime_map_d[] = {2, 3, 5, 7, 11, 13, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59};
int ing_prime_map_size = sizeof(ing_prime_map_d) / sizeof(ing_prime_map_d[0]);

char ing_decode_character(long long number) {
    int ascii_value = 0;
    
    for (int i = 0; i < ing_prime_map_size; ++i) {
        if (number % ing_prime_map_d[i] == 0) {
            ascii_value += (1 << i); 
        }
    }

    return (char)ascii_value;
}

void ing_decode_manual() {
    long long number;
    printf("\nPlease enter the encrypted numbers (to stop, enter a letter or symbol):\n");
    printf("Example: 22 190\n");

    printf("Decode Text: ");
    while (scanf("%lld", &number) == 1) {
        char decoded_char = ing_decode_character(number);
        printf("%c", decoded_char);
    }
    printf("\n");
}

void ing_decode_from_file() {
    char file_path[256];
    printf("\nPlease enter the path to the encrypted file (exapmle : home/user/output.txt):\n");
    scanf("%s", file_path);

    FILE *file = fopen(file_path, "r");
    if (file == NULL) {
        printf("Error: '%s' file not found!\n", file_path);
        return;
    }

    int c;
    long long hyphen_count = 0;

    printf("DEcode Text: ");

    while ((c = fgetc(file)) != EOF) {
        if (c == '-') {
            hyphen_count++;
        } else if (c == '|') {
            char decoded_char = ing_decode_character(hyphen_count);
            printf("%c", decoded_char);
            hyphen_count = 0; 
        }
    }

    if (hyphen_count > 0) {
        char decoded_char = ing_decode_character(hyphen_count);
        printf("%c", decoded_char);
    }

    fclose(file);
    printf("\n");
}

int ing_decrypt() {
    int choice;

    printf("--- Password Decryption Menu ---\n");
    printf("Method 1: Enter numbers manually\n");
    printf("Method 2: Enter file path\n");
    printf("Make your selection (1 or 2): ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            ing_decode_manual();
            break;
        case 2:
            ing_decode_from_file();
            break;
        default:
            printf("\nInvalid selection. Please enter 1 or 2.\n");
            break;
    }

    return 0;
}


