//Making code for the hill cipher
#include <stdio.h>
#include <conio.h>
#include <string.h>

#define SIZE 2

void multiply_matrices(int matrix1[SIZE][SIZE], int matrix2[SIZE][SIZE], int result[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            result[i][j] = 0;
            for (int k = 0; k < SIZE; k++) {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
            result[i][j] = result[i][j] % 26; // modulo 26 for alphabet size
        }
    }
}

void hill_cipher_encrypt(char plaintext[], int key[SIZE][SIZE], char ciphertext[]) {
    int plaintext_matrix[SIZE][1];
    int ciphertext_matrix[SIZE][1];

    for (int i = 0; i < strlen(plaintext); i += SIZE) {
        for (int j = 0; j < SIZE; j++) {
            plaintext_matrix[j][0] = plaintext[i + j] - 'A';
        }
        int result[SIZE][1];
        multiply_matrices(key, plaintext_matrix, result);
        for (int j = 0; j < SIZE; j++) {
            ciphertext_matrix[j][0] = result[j][0];
            ciphertext[i + j] = 'A' + ciphertext_matrix[j][0];
        }
    }
    ciphertext[strlen(plaintext)] = '\0';
}

void hill_cipher_decrypt(char ciphertext[], int key[SIZE][SIZE], char plaintext[]) {
    int key_inverse[SIZE][SIZE];
    int determinant = key[0][0] * key[1][1] - key[0][1] * key[1][0];
    determinant = determinant % 26;
    int mod_inverse = 1;
    while ((determinant * mod_inverse) % 26!= 1) {
        mod_inverse++;
    }
    key_inverse[0][0] = (key[1][1] * mod_inverse) % 26;
    key_inverse[0][1] = (-key[0][1] * mod_inverse) % 26;
    key_inverse[1][0] = (-key[1][0] * mod_inverse) % 26;
    key_inverse[1][1] = (key[0][0] * mod_inverse) % 26;

    int plaintext_matrix[SIZE][1];
    int ciphertext_matrix[SIZE][1];

    for (int i = 0; i < strlen(ciphertext); i += SIZE) {
        for (int j = 0; j < SIZE; j++) {
            ciphertext_matrix[j][0] = ciphertext[i + j] - 'A';
        }
        int result[SIZE][1];
        multiply_matrices(key_inverse, ciphertext_matrix, result);
        for (int j = 0; j < SIZE; j++) {
            plaintext_matrix[j][0] = result[j][0];
            plaintext[i + j] = 'A' + plaintext_matrix[j][0];
        }
    }
    plaintext[strlen(ciphertext)] = '\0';
}

int main() {
    int key[SIZE][SIZE];
    printf("Enter the 2x2 key matrix:\n");
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            scanf("%d", &key[i][j]);
        }
    }

    char plaintext[100];
    printf("Enter the plaintext:\n");
    scanf("%s", plaintext);

    char ciphertext[SIZE * strlen(plaintext) + 1];
    hill_cipher_encrypt(plaintext, key, ciphertext);
    printf("Ciphertext: %s\n", ciphertext);

    char decrypted[SIZE * strlen(ciphertext) + 1];
    hill_cipher_decrypt(ciphertext, key, decrypted);
    printf("Decrypted: %s\n", decrypted);

    return 0;
}