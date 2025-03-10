

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define AZ 26


/* prompt user for input message and allocate memory for said input */
char* allocate_message() {
    char *input = NULL;
    size_t size = 0;
    
    printf("Enter message to be encrypted\n");
    getline(&input, &size, stdin);
    size_t length = strlen(input) + 2;
    if (length > 0 && input[length - 1] == ' ') {
        input[length - 1] = '\0';
    }
    printf("Size: %d\n", length);
    return input;

}

char* padIt(char* plaintext, int plaintext_len) {
    int padding = (3 - ((plaintext_len - 1) % 3));
    printf("%d\n", padding);
    char* padder = "z";
    if (padding != 0) {
        for (int i = 0; i < padding; i++) {
            plaintext[(plaintext_len - 1) + i] = *padder;
        }
    }
    return plaintext;
}

/* take plaintext message and convert each letter to an integer */
void cton(char* plaintext, int plaintext_length, int* arr) {
    int n = -1;
    static const char * const alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    for (int i = 0; i < plaintext_length; i++) {   
        char *p = strchr(alphabet, toupper((unsigned char)plaintext[i]));
        if (p) {
            n = p - alphabet;
            arr[i] = n;
        }
        n = -1;
    }
}


void gatherKey(const char* keyFile, int keyMatrix[][9]) {
    FILE* file = fopen(keyFile, "r");
    if (file == NULL) {
        return;
    }

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            fscanf(file, "%d ", &keyMatrix[i][j]);
        }
    }
    fclose(file);
}


void encryptPlaintext(int keyMatrix[][9], char* plaintext, char* ciphertext, int plaintext_len) {
    int block = 3; // IN PROGRESS
}


int main(int argc, char* argv[]) {
    const char* keyFile = argv[1];
    int keyMatrix[9][9];
    char ciphertext[1024];

    /* get sacred text */
    char *encrypt_me = allocate_message();
    int plaintext_len = strlen(encrypt_me);
    
    /* PAD the sacred text */
    char *encryptable = padIt(encrypt_me, plaintext_len);
    
    /* make the sacred text legible for the BOX */
    int plaintext_to_ints[plaintext_len + 1]; 
    cton(encryptable, plaintext_len, plaintext_to_ints);
    
    /* let the little sucker GO! */
    free(encrypt_me);

    /* gather THE Matrix */
    gatherKey(keyFile, keyMatrix);
    
    

    return 0;
}

















