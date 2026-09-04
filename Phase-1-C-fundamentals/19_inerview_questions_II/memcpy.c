#include <stdio.h>
#include <string.h>

void safe_memcpy(void *dest, const void *src, size_t n){
   char * d = (char *)dest;
   const char * s = (const char*)src;

   if((d > s) && (d < s + n)){
    for(size_t i = n ; i > 0 ; i--){
        d[i-1] = s[i-1];
    }
   }
   else if((d < s) && (d + n > s )){
    for(size_t i = 0 ; i <= n-1 ; i++){
        d[i] = s[i];
    }
   }

   else{
    for(size_t i = 0 ; i < n; i++){
        d[i] = s[i];
    }
   }
};

int main(void) {
    char buf[20] = "ABCDEFGHIJKLMNOPQR";

    
    safe_memcpy(buf + 3, buf, 10);

    printf("%s\n", buf);
    // Predict the output : ABCABCDEFGHIJNOPQR
  

    return 0;
}