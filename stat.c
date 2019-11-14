#include <sys/types.h>
#include <sys/stat.h>
#include <sys/time.h>
#include <time.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  char *f = "main.c";
  struct stat info;
  stat(f, &info);
  
  int p = info.st_mode;
  
    int oct = 0, i = 1;
    while (p != 0) {
        oct += (p % 8) * i;
        p /= 8;
        i *= 10;
    }
    
  p = oct;
    
  char perms[10];
  for(int i = 0; i < 3; i++) {
      int digit = p % 10;
      p = p / 10;
      if(digit == 1) {
          perms[((3-i)*3)-1] = 'e';
          perms[((3-i)*3)-2] = '-';
          perms[((3-i)*3)-3] = '-';
      }
      if(digit == 2) {
          perms[((3-i)*3)-1] = '-';
          perms[((3-i)*3)-2] = 'w';
          perms[((3-i)*3)-3] = '-';
      }
      if(digit == 3) {
          perms[((3-i)*3)-1] = 'e';
          perms[((3-i)*3)-2] = 'w';
          perms[((3-i)*3)-3] = '-';
      }
      if(digit == 4) {
          perms[((3-i)*3)-1] = '-';
          perms[((3-i)*3)-2] = '-';
          perms[((3-i)*3)-3] = 'r';
      }
      if(digit == 5) {
          perms[((3-i)*3)-1] = 'e';
          perms[((3-i)*3)-2] = '-';
          perms[((3-i)*3)-3] = 'r';
      }
      if(digit == 6) {
          perms[((3-i)*3)-1] = '-';
          perms[((3-i)*3)-2] = 'w';
          perms[((3-i)*3)-3] = 'r';
      }
      if(digit == 7) {
          perms[((3-i)*3)-1] = 'e';
          perms[((3-i)*3)-2] = 'w';
          perms[((3-i)*3)-3] = 'r';
      }
  }
  perms[9] = NULL;
  
  
  float size = (float)info.st_size;
  int power = 0;
  char *s;
  while((int)size % 1024 > 1) {
      size = size/1024;
      power++;
  }
  if(power == 0) {
      s = strdup("B");
  }
  if(power == 1) {
      s = strdup("KB");
  }
  if(power == 2) {
      s = strdup("MB");
  }
  if(power == 3) {
      s = strdup("GB");
  }
  if(power == 4) {
      s = strdup("TB");
  }
 

  printf("\"%s\"  Size: %f %s  Permissions: %s  Last Access: %s",f,size,s,perms,ctime(&info.st_atime));



  return 0;
}
