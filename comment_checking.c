#include <stdio.h>
#include <string.h>

int main() {
    char line[1000];

    printf("Enter a line: ");
    fgets(line, sizeof(line), stdin);

    if (line[0] == '/' && line[1] == '/') {
        printf("It is a single-line comment.\n");
    } else if (line[0] == '/' && line[1] == '*') {
        int len = strlen(line);
        if (len > 0 && line[len - 1] == '\n') {
            line[len - 1] = '\0';
            len--;
        }

        if (len >= 2 && line[len - 1] == '/' && line[len - 2] == '*') {
            printf("It is a multi-line comment.\n");
        } else {
            printf("It is not a multiline comment.\n");
        }
    } else {
        printf("It is not a comment.\n");
    }

    return 0;
}
