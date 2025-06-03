#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main() {
    char exp[1000];
    int i = 0, valid = 1, paren_count = 0;

    printf("Enter a mathematical statement: ");
    fgets(exp, sizeof(exp), stdin);

    int len = strlen(exp);
    if (exp[len - 1] == '\n') {
        exp[len - 1] = '\0'; // remove newline character
    }

    if (exp[0] == '+' || exp[0] == '-' || exp[0] == '*' || exp[0] == '/' || exp[0] == ')') {
        valid = 0;
    }

    for (i = 0; exp[i] != '\0'; i++) {
        if (isdigit(exp[i]) || exp[i] == ' ') {
            continue;
        }
        else if (exp[i] == '(') {
            paren_count++;
        }
        else if (exp[i] == ')') {
            paren_count--;
            if (paren_count < 0) { // more closing than opening
                valid = 0;
                break;
            }
        }
        else if (exp[i] == '+' || exp[i] == '-' || exp[i] == '*' || exp[i] == '/') {
            int j = i + 1;
            while (exp[j] == ' ') j++; // skip spaces
            if (!(isdigit(exp[j]) || exp[j] == '(')) {
                valid = 0;
                break;
            }
        }
        else {
            valid = 0;
            break;
        }
    }

    if (paren_count != 0) {
        valid = 0; // unmatched parentheses
    }

    if (valid) {
        printf("The mathematical statement is solvable.\n");
    } else {
        printf("The mathematical statement is not solvable.\n");
    }

    return 0;
}

