#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
int main(void) {
    char bits[4096];
    printf("Entrez le code binaire à décoder:\n");

    if (!fgets(bits, sizeof(bits), stdin)) {
        fprintf(stderr, "Lecture échouée.\n");
        return 1;
    }

    size_t len = strlen(bits);
    if (len > 0 && bits[len - 1] == '\n') {
        bits[len - 1] = '\0';
        --len;
    }
    if (len % 8 != 0) {
        fprintf(stderr, "Erreur : la longueur du code binaire doit être multiple de 8.\n");
        return 1;
    }

    printf("\nMessage décodé : ");
    for (size_t i = 0; i < len; i += 8) {
        unsigned char byte = 0;
        for (int j = 0; j < 8; j++) {
            if (bits[i + j] == '1')
                byte = (byte << 1) | 1;
            else if (bits[i + j] == '0')
                byte = (byte << 1);
            else {
                fprintf(stderr, "\nErreur : le message doit contenir uniquement 0 et 1.\n");
                return 1;
            }
        }
        putchar(byte);
    }
    putchar('\n');
    return 0;
}