#include <stdio.h>
#include <string.h>

int prime_map_d[] = {2, 3, 5, 7, 11, 13, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59};
int prime_map_size = sizeof(prime_map_d) / sizeof(prime_map_d[0]);

char decode_character(long long number) {
    int ascii_value = 0;
    
    for (int i = 0; i < prime_map_size; ++i) {
        if (number % prime_map_d[i] == 0) {
            ascii_value += (1 << i); 
        }
    }

    return (char)ascii_value;
}

void decode_manual() {
    long long number;
    printf("\nLütfen şifrelenmiş sayıları girin (durmak için harf veya sembol girin):\n");
    printf("Örnek: 22 190\n");

    printf("Çözümlenen metin: ");
    while (scanf("%lld", &number) == 1) {
        char decoded_char = decode_character(number);
        printf("%c", decoded_char);
    }
    printf("\n");
}

void decode_from_file() {
    char file_path[256];
    printf("\nLütfen şifrelenmiş dosyanın yolunu girin:\n");
    scanf("%s", file_path);

    FILE *file = fopen(file_path, "r");
    if (file == NULL) {
        printf("Hata: '%s' dosyası bulunamadı!\n", file_path);
        return;
    }

    int c;
    long long hyphen_count = 0;

    printf("Çözümlenen metin: ");

    while ((c = fgetc(file)) != EOF) {
        if (c == '-') {
            hyphen_count++;
        } else if (c == '|') {
            char decoded_char = decode_character(hyphen_count);
            printf("%c", decoded_char);
            hyphen_count = 0;
        }
    }

    if (hyphen_count > 0) {
        char decoded_char = decode_character(hyphen_count);
        printf("%c", decoded_char);
    }

    fclose(file);
    printf("\n");
}

int decrypt() {
    int choice;

    printf("--- Şifre Çözme Menüsü ---\n");
    printf("1. Yöntem: Sayıları manuel olarak gir\n");
    printf("2. Yöntem: Dosya yolu gir\n");
    printf("Seçiminizi yapın (1 veya 2): ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            decode_manual();
            break;
        case 2:
            decode_from_file();
            break;
        default:
            printf("\nGeçersiz seçim. Lütfen 1 veya 2 girin.\n");
            break;
    }

    return 0;
}


