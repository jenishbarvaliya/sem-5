#include <stdio.h>
#include <math.h>

// Function to perform Min-Max Normalization
void minMaxNormalization(float v[], int n) {
    float max, min, sr, er, ans;
    int i;
    
    printf("\nEnter min and max value: ");
    scanf("%f %f", &min, &max);
    
    printf("\nEnter the starting value and ending value of the range: ");
    scanf("%f %f", &sr, &er);
    
    for (i = 0; i < n; i++) {
        float a, b, c, d;
        a = v[i] - min;
        b = max - min;
        c = er - sr;
        ans = ((a * c) / b) + sr;
        printf("\nMin-Max normalization of %f is: %f", v[i], ans);
    }
}

int main() {
    float v[100];
    int n, i;
    
    printf("Enter number of values to enter: ");
    scanf("%d", &n);
    
    if (n > 100) {
        printf("Number of values exceeds the maximum limit of 100.\n");
        return 1;
    }
    
    for (i = 0; i < n; i++) {
        printf("\nEnter value %d: ", i + 1);
        scanf("%f", &v[i]);
    }
    
    minMaxNormalization(v, n);
    
    return 0;
}

