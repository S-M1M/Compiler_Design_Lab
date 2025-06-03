#include <stdio.h>
#include <ctype.h>
#include <string.h>

// List of common keywords
const char* keywords[] = {
    "int", "float", "char", "double", "if", "else",
    "for", "while", "do", "return", "void",
    "switch", "break", "continue"
};

int isKeyword(char str[]) {
    for (int i = 0; i < 14; i++) {
        if (strcmp(str, keywords[i]) == 0) {
            return 1;
        }
    }
    return 0;
}

int main() {
    char str[100];
    int flag = 0;

    printf("Enter an identifier: ");
    scanf("%s", str);

    if (isalpha(str[0]) || str[0] == '_') {
        for (int i = 1; str[i] != '\0'; i++) {
            if (!(isalnum(str[i]) || str[i] == '_')) {
                flag = 1;
                break;
            }
        }

        if (flag == 1 || isKeyword(str)) {
            printf("Invalid Identifier.\n");
        } else {
            printf("Valid Identifier.\n");
        }
    } else {
        printf("Invalid Identifier.\n");
    }

    return 0;
}

