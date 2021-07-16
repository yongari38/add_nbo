#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <netinet/in.h>

uint32_t read_int(char* filename) {
    FILE *f = fopen(filename, "rb");
    uint32_t i;
    size_t readlen = fread(&i, 1, sizeof(uint32_t), f);
    
    if (readlen != sizeof(uint32_t)) {
        fprintf(stderr, "error: fread return %lu\n", readlen);
        exit(-1);
    }

    i = ntohl(i);

    fclose(f);
    return i;
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("syntax: %s <file1> <file2>\n", argv[0]);
        printf("sample: %s a.bin c.bin\n", argv[0]);
        exit(-1);
    }

    uint32_t i1, i2, res;
    i1 = read_int(argv[1]);
    i2 = read_int(argv[2]);
    res = i1 + i2;
    printf("%d(0x%x) + %d(0x%x) = %d(0x%x)\n", i1, i1, i2, i2, res, res);

    return 0;
}