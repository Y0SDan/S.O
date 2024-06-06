#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>

int main(void) {
    const char* filename = "db.personas";
    FILE* input_file = fopen(filename, "rb");
    if (!input_file) {
        perror("Error al abrir el archivo");
        exit(EXIT_FAILURE);
    }

    struct stat sb;
    if (stat(filename, &sb) == -1) {
        perror("Error al obtener el tamaño del archivo");
        exit(EXIT_FAILURE);
    }

    char* file_contents = malloc(sb.st_size);
    fread(file_contents, sb.st_size, 1, input_file);
    printf("%s\n", file_contents);

    fclose(input_file);
    free(file_contents);
    exit(EXIT_SUCCESS);
}
