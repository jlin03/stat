#include <sys/types.h>
#include <sys/stat.h>
#include <sys/time.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
  char *f = "file.txt";
  struct stat info;
  stat(f, &info);

  printf("\"%s\"  Size: %ld bytes  Permissions: %o  Last Access: %ld",f,info.st_size,info.st_mode,info.st_atim.tv_sec);



  return 0;
}
