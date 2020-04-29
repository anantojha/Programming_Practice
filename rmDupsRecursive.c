#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void remov(char *src, char *dest, int iter);

int main()
{
   char src[100];
   char dest[100];

   scanf("%s",src);

   remov(src, dest, 0);

   printf("%s\n", dest);

   return 0;
}



void remove_Dups_recursively(char *src, char *dest, int iter){

   if(strlen(src) <= 1){
      dest = src;
      return;
   }
   if(iter == strlen(src)){
      return;
   }

   if(strchr(dest, src[iter]) == NULL){
       dest[strlen(dest)] = src[iter]; 
       iter++;
       remov(src, dest, iter);
   }
   else{
      iter++;
      remov(src, dest, iter);
   }
   
}


