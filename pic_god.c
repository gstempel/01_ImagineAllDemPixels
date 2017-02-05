#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>

int main() {

  int fd, r, g, b, i, j;
  char line[20];

  fd = open("image.ppm", O_CREAT | O_TRUNC | O_WRONLY, 0644);

  snprintf(line, sizeof(line), "P3 500 500 255\n");
  write(fd, line, strlen(line) );

  for(i=0; i < 500; i++) {
    for(j=0; j < 255; j++) {

      if (j % 2 == 0 && j % 3 == 0) {
	r = j/2;
	g = 0;
	b = j/2;
      }

      else if (j % 3 == 0) {
	r = 0;
	g = j/2;
	b = j/2;
      }

      else {
	r = j/2;
	g = j/2;
	b = 0;
      }
      snprintf(line, sizeof(line), "%d %d %d\n", r, g, b);
      write(fd, line, strlen(line) );
    }
    for(j=255; j >= 0; j--) {

      if (j % 2 == 0 && j % 3 == 0) {
	r = j/2;
	g = 0;
	b = j/2;
      }

      else if (j % 3 == 0) {
	r = 0;
	g = j/2;
	b = j/2;
      }

      else {
	r = j/2;
	g = j/2;
	b = 0;
      }
      snprintf(line, sizeof(line), "%d %d %d\n", r, g, b);
      write(fd, line, strlen(line) );
    }
  }
  close(fd);
}
