
#include <stdio.h>
#include <string.h>

int main() {
    char op[10];

    printf("Enter an operator: ");
    scanf("%s", op);

    if (
        strcmp(op, "+") == 0 || strcmp(op, "-") == 0 ||
        strcmp(op, "++") == 0 || strcmp(op, "--") == 0 ||
        strcmp(op, "*") == 0 || strcmp(op, "/") == 0 ||
        strcmp(op, "%") == 0 || strcmp(op, "%=") == 0 ||
        strcmp(op, "==") == 0 || strcmp(op, "<") == 0 ||
        strcmp(op, ">") == 0 || strcmp(op, "<=") == 0 ||
        strcmp(op, ">=") == 0 || strcmp(op, "&&") == 0 ||
        strcmp(op, "||") == 0 || strcmp(op, "!") == 0 ||
        strcmp(op, "&") == 0 || strcmp(op, "|") == 0 ||
        strcmp(op, "^") == 0 || strcmp(op, "~") == 0 ||
        strcmp(op, "<<") == 0 || strcmp(op, ">>") == 0 ||
        strcmp(op, "=") == 0 || strcmp(op, "+=") == 0 ||
        strcmp(op, "-=") == 0 || strcmp(op, "*=") == 0 ||
        strcmp(op, "/=") == 0 || strcmp(op, "%=") == 0 ||
        strcmp(op, "&=") == 0 || strcmp(op, "|=") == 0 ||
        strcmp(op, "^=") == 0
    ) {
        printf("Valid operator.\n");
    } else {
        printf("Invalid operator.\n");
    }

    return 0;
}
