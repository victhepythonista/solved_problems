#include <stdio.h>
#include <string.h>

unsigned long long vowel_recognition(const char *s);

int isVowel(char c) {
    return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
            c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U');
}

unsigned long long vowel_recognition(const char *s) {
    unsigned long long total = 0;
    int n = strlen(s);

    for (int i = 0; i < n; i++) {
        if (isVowel(s[i])) {
            // Each vowel contributes to (i + 1) * (n - i) substrings
            total += (i + 1) * (n - i);
        }
    }

    return total;
}

int main() {
    printf("Testing...\n");

    char test_string[] = "aeiouAEIOU";
    unsigned long long expected = 220;
    unsigned long long result = vowel_recognition(test_string);
    
    printf("Expected: %llu, Got: %llu\n", expected, result);
    return 0;
}
