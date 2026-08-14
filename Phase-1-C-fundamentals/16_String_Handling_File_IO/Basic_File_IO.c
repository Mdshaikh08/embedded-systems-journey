#include<stdio.h>




int main(){


FILE *fp = fopen("test.txt", "w");
if (fp == NULL) {
    printf("Failed to open file\n");
    return 1;
}
fprintf(fp, "Hello from file I/O\n");
fclose(fp);


fp = fopen("test.txt", "r");
char line[100];
fgets(line, sizeof(line), fp);
printf("Read: %s", line);
fclose(fp);



}