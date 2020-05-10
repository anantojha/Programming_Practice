#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void remove_Dups_recursively(char *src, char *dest, int iter);

int main(){
   char src[100];
   char dest[100];

   // enter input string from which to remove duplicates
   scanf("%s",src);  // EXAMPLE:   AAABBABCCABA

   // remove deplicates (0 -> removes from entire string)
   remove_Dups_recursively(src, dest, 0);
   
   // print results 
   printf("%s\n", dest);  // OUTPUT:    ABC

   return 0;
}


/* @params:
 * src  -- input string pointer. String to remove dups from.
 * dest -- output string pointer. Passed in as empty string.  
 * iter -- index from where duplicate removal starts. (0)
 * ---------------------------------------------------------
 * Purpose:  
 * Removes duplicate characters from a string recursively. 
*/
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
       remove_Dups_recursively(src, dest, iter);
   }
   // current 'iter' element has not been encountered before
   else{
      iter++;
      remove_Dups_recursively(src, dest, iter);
   }
}
