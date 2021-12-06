#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#define block 512
typedef uint8_t BYTE;

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./recover image\n");
        return 1;
    }
    char *input = argv[1];
    FILE *inptr = fopen(input, "r");
    if (inptr == NULL)
    {
        printf("%s cannot be opened.\n", input);
        return 2;
    }

    BYTE buffer[block];
    int count = 0;
    FILE *outptr = NULL;

    while (fread(&buffer, block, 1, inptr) == 1)
    {
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            if (count >= 1)
            {
                fclose(outptr);
            }
            char filename[8];
            sprintf(filename, "%03i.jpg", count);
            outptr = fopen(filename, "w");
            count++;
        }
        if (count >= 1)
        {
            fwrite(&buffer, block, 1, outptr);
        }
    }
    if (outptr == NULL)
    {
        fclose(outptr);
        return 3;
    }
    fclose(inptr);
    fclose(outptr);
    return 0;
}