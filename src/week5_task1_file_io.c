#include <stdio.h>

int main(void)
{
    FILE *fp;

    printf("Writing lines to data.txt...\n");

    fp = fopen("data.txt", "w");

    if (fp == NULL)
    {
        perror("Error opening file");
        return 1;
    }

    fprintf(fp, "Hello, file I/O in C!\n");
    fprintf(fp, "This is another line.\n");

    fclose(fp);

    printf("Reading contents:\n");

    fp = fopen("data.txt", "r");

    if (fp == NULL)
    {
        perror("Error opening file");
        return 1;
    }

    char line[100];
    int count = 0;

    while (fgets(line, sizeof(line), fp) != NULL)
    {
        printf("%s", line);
        count++;
    }

    fclose(fp);

    printf("Lines read: %d\n", count);

    return 0;
}

