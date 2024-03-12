#include <stdio.h>
#include <string.h>

#define MAX 256

int max(int a, int b) {
    return (a > b) ? a : b;
}

void badCharHeuristic(char *pattern, int patternLength, int badChar[MAX]) {
    int i;
    for (i = 0; i < MAX; i++)
        badChar[i] = -1;
    for (i = 0; i < patternLength; i++)
        badChar[(int)pattern[i]] = i;
}
void search(char *text, char *pattern) {
    int patternLength = strlen(pattern);
    int textLength = strlen(text);
    int badChar[MAX];
    badCharHeuristic(pattern, patternLength, badChar);
    int shift = 0;
    while (shift <= (textLength - patternLength)) {
        int j = patternLength - 1;

        while (j >= 0 && pattern[j] == text[shift + j])
            j--;

        if (j < 0) {
            printf("Pattern found at index %d\n", shift);
            return;
        } else {
            shift += max(1, j - badChar[(int)text[shift + j]]);
        }
    }
    printf("Pattern not found in the given text.\n");
}

int main() {
    char text[1000], pattern[100];
    
    printf("Enter the text: ");
    scanf("%s",&text);
    printf("Enter the pattern: ");  
    scanf("%s",&pattern);

    search(text, pattern);
    return 0;
}