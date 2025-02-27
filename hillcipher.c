

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* allocater() {
    char *input = NULL;
    size_t size = 0;
    
    printf("Enter message to be encrypted\n");
    getline(&input, &size, stdin);
    size_t length = strlen(input);
    if (length > 0 && input[length - 1] == '\n') {
        input[length - 1] = '\0';
    }
    return input;

}


int main() {
    // Step 1. Request user plaintext for encryption and malloc as necessary
    char *encrypt_me = allocater();
    
    // allocater() is functioning
    // now do something with it before you get rid of that sucker !

    free(encrypt_me);

    return 0;
}
















