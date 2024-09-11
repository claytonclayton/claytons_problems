#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NODES 101

int solve(FILE *file) {
    int in[MAX_NODES] = {0};
    int out[MAX_NODES] = {0}; // Array to store graph nodes, initialized to 0
    
    char line[256];             // Buffer for reading lines

    // Skip the first line
    fgets(line, sizeof(line), file);

    // Read lines until end of file
    while (fgets(line, sizeof(line), file)) {
        // Strip newline character
        line[strcspn(line, "\n")] = '\0';

        // Ignore blank lines
        if (strlen(line) == 0) {
            continue;
        }

        int a, b;
        sscanf(line, "%d %d", &a, &b);

        // Check condition and update graph
        if (in[b] != 0 || out[a] != 0)
            return 1;
        in[b] = a;
        out[a] = b;
    }

    return 0;
}

int main() {
    FILE *file = fopen("/dev/stdin", "r");
    if (!file) {
        perror("Error opening file");
        return EXIT_FAILURE;
    }

    if (solve(file)) {
        printf("SLAY\n");
    } else {
        printf("NAY\n");
    }

    fclose(file);
    return EXIT_SUCCESS;
}