#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void fvuln(unsigned long age, char *str1)
{
   static char name2[32], *ptr1, name1[32], *ptr3;
   unsigned long local_age, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10;
   char *ptr2;
   a1 = age;
   a2 = age;
   a3 = age;
   a4 = age;
   a5 = age;
   a6 = age;
   a7 = age; 
   a8 = age;
   a9 = age;
   a10 = age;
   local_age = age;

   ptr1 = (char *) malloc(256);
   printf("\nPTR1 = [ %p ]", ptr1);
   strcpy(name1, str1);
   printf("\nPTR1 = [ %p ]\n", ptr1);

   free(ptr1);
   free(ptr3);

   ptr2 = (char *) malloc(60);

   snprintf(ptr2, 1024, "%s is %ld years oldAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA", name1, local_age);
   printf("\n%s\n", ptr2);
}

int main(int argc, char *argv[])
{
   if (argc == 3)
      fvuln(atoi(argv[2]), argv[1]);

   return 0;
}
