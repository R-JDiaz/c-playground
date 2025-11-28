#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *file;

    file = fopen("test.dat","wb");
    if (!file) {
        perror("Cannot open file");
        return 1;
    }

    fclose(file);
}