#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *fp1, *fp2;
    char ch;

    // Open file1.txt for reading
    fp1 = fopen("file1.txt", "r");
    if (fp1 == NULL) {
        perror("Error opening file1.txt");
        return 1;
    }

    // Open file2.txt for writing
    fp2 = fopen("file2.txt", "w+");

    // Read from file1.txt and write to file2.txt
    while ((ch = fgetc(fp1)) != EOF) {
        fputc(ch, fp2);
    }

    // Close both files
    fclose(fp1);
    fclose(fp2);

    return 0;
}
