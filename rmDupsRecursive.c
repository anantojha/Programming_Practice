#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void remov(char *src, char *dest, int iter);

int main()
{
   char src[100];
   char dest[100];

   // enter input string from which to remove duplicates
   // EXAMPLE:   AAABBABCCABA
   scanf("%s",src);

   remov(src, dest, 0);
   
   // OUTPUT:    ABC
   printf("%s\n", dest);

   return 0;
}



void remove_Dups_recursively(char *src, char *dest, int iter){
   // base case 1
   if(strlen(src) <= 1){
      dest = src;
      return;
   }
   
   // base case 2
   if(iter == strlen(src)){
      return;
   }

   // current 'iter' element has been encountered before
   if(strchr(dest, src[iter]) == NULL){
       dest[strlen(dest)] = src[iter]; 
       iter++;
       remov(src, dest, iter);
   }
   // current 'iter' element has not been encountered before
   else{
      iter++;
      remov(src, dest, iter);
   }
   
}


