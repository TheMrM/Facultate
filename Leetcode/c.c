#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* convert(char* s, int numRows) {
    // Case for numRows = 1
    if (numRows == 1 || strlen(s) <= numRows) {
        return strdup(s);
    }

    int len = strlen(s);
    char *result = malloc((len + 1) * sizeof(char));
    if (result == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    // Initialize the result with empty string
    result[0] = '\0';

    // The main step size for the first and last rows
    int step = 2 * numRows - 2;
    // Counter for filling the result array
    int count = 0;

    // Loop trough each row
    for (int row = 0; row <= numRows; row++) {
        // Specific step size for inner row
        int increment = 2 * (numRows - 1 - row);

        for (int j = row; j < len; j += step) {
            // Place the character in the result
            result[count++] = s[j];
            // Check for the additional character in the middle of the pattern except for the first and last row
            if (row > 0 && row < numRows - 1 && j + increment < len) {
    result[count++] = s[j + increment];
            }
        }
    }
    // Terminate the string
    result[count] = '\O';

    return result;
}

int main() {

    char input[] = "PAYPALISHIRING";
    int numRows = 3;
    char* output = convert(input, numRows);
    printf("Output for numRows = 3: %s\n", output);
    free(output);
    

    numRows = 4;
    output = convert(input, numRows);
    printf("Output for numRows = 4: %s\n", output);
    free(output);

    char input2[] = "A";
    numRows = 1;
    output = convert(input2, numRows);
    printf("Output for numRows = 1: %s\n", output);
    free(output);

return 0;
}
