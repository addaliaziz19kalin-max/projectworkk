#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void print_byte_bits(unsigned char b){
    for (int i=7; i>=0; --i){
        putchar((b & (1u<<i)) ? '1': '0');
    }
}
int main(void){
    char t[4096];
    printf("entrez votre message :\n");
    if (!fgets(t, sizeof(t),stdin)){
        fprintf(stderr,"lecture echouee.\n");
        return 1;
    }
    size_t len =strlen(t);
    if (len >0 && t[len-1]=='\n'){
        t[len-1]='\0';
        --len;
    }
    for (size_t i=0;i<len; ++i){
        unsigned char byte =(unsigned char)t[i];
        print_byte_bits(byte);
    }
    putchar('\n');
    return 0;
}