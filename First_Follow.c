
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX 20
#define SIZE 20

char productions[MAX][SIZE];
char first[MAX][SIZE];
char follow[MAX][SIZE];
int numProductions;

int isNonTerminal(char c) {
    return c >= 'A' && c <= 'Z';
}

void addToSet(char *set, char val) {
    for (int i = 0; set[i]; i++) {
        if (set[i] == val)
            return;
    }
    int len = strlen(set);
    set[len] = val;
    set[len + 1] = '\0';
}

//void findFirst(char *result, char symbol);

void findFirst(char *result, char symbol) {
    if (!isNonTerminal(symbol)) {
        addToSet(result, symbol);
        return;
    }

    for (int i = 0; i < numProductions; i++) {
        if (productions[i][0] == symbol) {
            if (productions[i][2] == '#') {
                addToSet(result, '#');
            } else {
                int j = 2;
                while (productions[i][j]) {
                    char temp[SIZE] = "";
                    findFirst(temp, productions[i][j]);

                    for (int k = 0; temp[k]; k++) {
                        if (temp[k] != '#') {
                            addToSet(result, temp[k]);
                        }
                    }

                    if (!strchr(temp, '#'))
                        break;

                    j++;
                    if (!productions[i][j])
                        addToSet(result, '#');
                }
            }
        }
    }
}

void findFollow(char *result, char symbol) {
    if (symbol == productions[0][0]) {
        addToSet(result, '$'); // Start symbol
    }

    for (int i = 0; i < numProductions; i++) {
        for (int j = 2; productions[i][j]; j++) {
            if (productions[i][j] == symbol) {
                if (productions[i][j + 1]) {
                    char tempFirst[SIZE] = "";
                    findFirst(tempFirst, productions[i][j + 1]);
                    for (int k = 0; tempFirst[k]; k++) {
                        if (tempFirst[k] != '#')
                            addToSet(result, tempFirst[k]);
                    }

                    if (strchr(tempFirst, '#')) {
                        char tempFollow[SIZE] = "";
                        findFollow(tempFollow, productions[i][0]);
                        for (int k = 0; tempFollow[k]; k++) {
                            addToSet(result, tempFollow[k]);
                        }
                    }
                } else if (productions[i][0] != symbol) {
                    char tempFollow[SIZE] = "";
                    findFollow(tempFollow, productions[i][0]);
                    for (int k = 0; tempFollow[k]; k++) {
                        addToSet(result, tempFollow[k]);
                    }
                }
            }
        }
    }
}

int alreadyDone(char symbol, char done[], int doneCount) {
    for (int i = 0; i < doneCount; i++) {
        if (done[i] == symbol)
            return 1;
    }
    return 0;
}

int main() {
    int i;
    char result[SIZE];
    char doneFirst[SIZE] = "", doneFollow[SIZE] = "";
    int doneFirstCount = 0, doneFollowCount = 0;

    printf("Enter number of productions: ");
    scanf("%d", &numProductions);
    printf("Enter productions (e.g., E=TQ). Use '#' for epsilon:\n");
    for (i = 0; i < numProductions; i++)
        scanf("%s", productions[i]);

    printf("\nFIRST Sets:\n");
    for (i = 0; i < numProductions; i++) {
        char symbol = productions[i][0];
        if (!alreadyDone(symbol, doneFirst, doneFirstCount)) {
            result[0] = '\0';
            findFirst(result, symbol);
            printf("FIRST(%c) = { ", symbol);
            for (int j = 0; result[j]; j++)
                printf("%c ", result[j]);
            printf("}\n");
            doneFirst[doneFirstCount++] = symbol;
        }
    }

    printf("\nFOLLOW Sets:\n");
    for (i = 0; i < numProductions; i++) {
        char symbol = productions[i][0];
        if (!alreadyDone(symbol, doneFollow, doneFollowCount)) {
            result[0] = '\0';
            findFollow(result, symbol);
            printf("FOLLOW(%c) = { ", symbol);
            for (int j = 0; result[j]; j++)
                printf("%c ", result[j]);
            printf("}\n");
            doneFollow[doneFollowCount++] = symbol;
        }
    }

    return 0;
}
