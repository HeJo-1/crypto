#include <stdio.h>
#include <string.h>

int prime_map[] = {2, 3, 5, 7, 11, 13, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59};

void encrypt_text_and_log(const char* text) {
    FILE *file = fopen("output.txt", "w");
    if (file == NULL) {
        printf("Hata: Dosya açılamadı!\n");
        return;
    }

    int text_len = strlen(text);

    printf("\n--- Sonuçlar ---\n");

    for (int i = 0; i < text_len; ++i) {
        char character = text[i];
        long long result = 1;

        for (int j = 0; j < 8; ++j) {
            int bit = (character >> j) & 1;
            if (bit == 1) {
                result *= prime_map[j];
            }
        }
        
        printf("%c : %lld\n", character, result);

        for (int k = 0; k < result; ++k) {
            fputc('-', file);
        }

        if (i < text_len - 1) {
            fputc('|', file);
        }
    }

    fclose(file);
    printf("\nDosyaya başarıyla kaydedildi.\n");
}

int encrypt() {
    char input[100];

    printf("Lütfen bir metin girin: ");
    fgets(input, sizeof(input), stdin);

    input[strcspn(input, "\n")] = 0; 
    
    encrypt_text_and_log(input);

    return 0;
}

