#include<stdio.h>

void my_strcpy(char *dest, const char *src);
void my_strcat(char *dest, const char *src);
int  my_strcmp(const char *s1, const char *s2);
void my_strrev(char *src);

int main(){
    char mybuffer[50];

    my_strcpy(mybuffer, "Hello");
    printf("%s\n", mybuffer);

    my_strcat(mybuffer, " World");
    printf("%s\n", mybuffer);

    printf("%d\n", my_strcmp("abc", "abc"));  
    printf("%d\n", my_strcmp("abc", "abd"));

    my_strrev(mybuffer);
    printf("%s\n", mybuffer);
}


void my_strcpy(char *dest , const char *src){
    int i = 0;
    while(src[i] != '\0'){
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
}

void my_strcat(char *dest , const char *src){
    int i = 0;
    while(dest[i] != '\0'){
        i++;
    }
    int j =0;
    while(src[j] != 0){
        dest[i] = src[j];
        i++; 
        j++;
    }
    dest[i] = '\0';
}

int my_strcmp(const char *str1 , const char *str2){
    int i = 0;
    while(str1[i] == str2[i] ){
        if(str1[i] == '\0' && str2[i] == '\0'){
            return 0;
        }
        i++;
    }
    return -1;
}

void my_strrev(char *src){
    int j = 0;
    while(src[j + 1] != '\0'){
        j++;
    }
    char temp;
    int k = j;
    for(int i = 0; i <= k/2 ; i++){
        temp = src[i];
        src[i] = src[j];
        src[j] = temp;
        j--;
    }
}