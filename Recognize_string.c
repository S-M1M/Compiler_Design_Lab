#include <stdio.h>
#include <string.h>

int main() {
    char str[1000];

    printf("Enter the string: ");
    scanf("%s", str);

    // check for "a"
    if (strcmp(str, "a") == 0) {
        printf("String matches the pattern 'a'.\n");
    }
    // check for "aab"
    else if (strcmp(str, "aab") == 0) {
        printf("String matches the pattern 'aab'.\n");
    }
    // check for "a+b+"
    else {
        int valid = 1;
        int i = 0;
        while (str[i] == 'a') {
            i++;
        }
        if (str[i] == '\0') {
            valid = 0;
        }
        else {
            while (str[i] == 'b') {
                i++;
            }
            if (str[i] != '\0') {
                valid = 0;
            }
        }

        if (valid) {
            printf("String matches the pattern 'a+b+'.\n");
        } else {
            printf("String does not match any pattern.\n");
        }
    }

    return 0;
}

