#include <string.h>
#include <stdio.h>

void encryptDecrypt(char *input, char *output) {
    char key[] = {'P', 'X', 'L'};
    
    int i;
    for(i = 0; i < strlen(input); i++) {
        output[i] = input[i] ^ key[i % (sizeof(key)/sizeof(char))];
    }
}

int main() {

        char xor[] = "94#&=<(4}bkxeU";

        const char *dict[3];

        dict[0] = "an unknown option";
        dict[1] = "School";
        dict[2] = "Vacation";

        printf("I prefer having:\n");
        printf("Option 1: School\n");
        printf("Option 2: Vacation\n");

        char option[20];
        size_t len = 13;

        printf("> ");
        fgets(option, 20, stdin);

        char decrypted[strlen(xor)];
        encryptDecrypt(xor, decrypted);

        if (strncmp(decrypted, option, len) == 0) {
                printf("This is a secret message, how did you find me?! Anyway, I love PXL!\n");
        } else {
                if(atoi(option) != 0 && atoi(option) < 3){
                    printf("You chose for %s\n", dict[atoi(option)]);
                }else{
                    printf("You chose for %s\n", dict[0]);
                }
                
        }


        return 0;
}