#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int key;
int a;
char text[100];

int main()
{
   printf("Hello and Welcome to The Ceasar Cipher Program :) !\n");

   printf("Please enter your plaintext to be encrypted [In All Capitals]: ");
   gets(text);
   printf("\n");
   //scanf("%s", text);

   printf("Please enter your key for this encryption [Natural Number]: ");
   scanf("%d",&key);
   printf("\n");

   if(key  > 26) {
     key=key % 26;
   }

   for(a=0; a < strlen(text); a++) {
       if(text[a]== ' ') {
          printf(" ");
        }

       else {
          if(text[a] >= 'z') {
             text[a] = text[a] - 26;
           }

         text[a] = text[a] + key;
        }
    }

    printf("The ciphertext is: %s\n",text);
    printf("Goodbye! See you soon I hope! :)\n");
    return 0;
}
