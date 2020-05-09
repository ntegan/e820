#include "includes.h"


// ASM https://gcc.gnu.org/onlinedocs/gcc/Extended-Asm.html
void testing_basic_extended_asm();
void testing_int_fifteen_h();

void testing_main() {
  //testing_basic_extended_asm();
  testing_int_fifteen_h();

}







// https://en.wikipedia.org/wiki/E820
// http://www.uruk.org/orig-grub/mem64mb.html
// osdev https://wiki.osdev.org/Detecting_Memory_(x86)#BIOS_Function:_INT_0x15.2C_EAX_.3D_0xE820
void testing_int_fifteen_h() {
  // goal: find formatting for int 15h with GNU extendedinlineasm
  
  // look at example https://wiki.osdev.org/Detecting_Memory_(x86)#Getting_an_E820_Memory_Map

  // set AX register to 0xE820 (clear upper bits)
  // clear ebx
  // point ES:DI to dst buf for list
  // set EDX to 0x534D4150 (arbitrary magic num?)
  // set ECX to 24
  // do an int 15h
  
  // if first call succeeds, EAX set to the magic num
  // and the carry flag will be clear
  // EBX will be nonzero and should be preserved for next call
  // CL contain number of bytes actually stored at ES:DI (prob20)

  // for subsequent calls,
  // increment DI by list entry size, reset EAX to 0xE820, ECXto24
  
  // when at end of list, EBX MAY reset to 0.
  // if you call again with EBX=0 it will start over.
  // if it doesn't reset to 0, the int will return with
  // carry set when try to access entry after last valid entry
}
void testing_basic_extended_asm() {
  int src = 1;
  int dst;
  asm ("mov %1, %0\n\t"
      "add %1, %0"
      : "=r" (dst)
      : "r" (src)
      );
  printf("%d\n", dst);
}
