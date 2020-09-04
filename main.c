#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/utsname.h>

int main(void) {

   struct  utsname buffer;

   errno = 0;
   if (uname(&buffer) != 0) {
      perror("uname");
      exit(EXIT_FAILURE);
   }

   printf("Nome do Sistema = %s\n", buffer.sysname);
   printf("Nome do nó   = %s\n", buffer.nodename);
   printf("Release     = %s\n", buffer.release);
   printf("Versão     = %s\n", buffer.version);
   printf("Arquitetura     = %s\n", buffer.machine);

   #ifdef _GNU_SOURCE
      printf("Nome de dominio = %s\n", buffer.domainname);
   #endif

   return EXIT_SUCCESS;
}
