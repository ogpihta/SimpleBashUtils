#include <getopt.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define BUFFER_SIZE 4096

typedef struct {
  int b;
  int e;
  int n;
  int s;
  int t;
  int v;
} option;

int parser(int argc, char *argv[], option *flag, int *error);
void cat(char *path, option flag);

int main(int argc, char *argv[]) {
  int error = 0;
  int indexParametrArgv;
  option option = {0};
  indexParametrArgv = parser(argc, argv, &option, &error);

  if (error == 1) {
    fprintf(stderr, "OK");
  } else {
    while (indexParametrArgv < argc) {
      char *path;
      path = argv[indexParametrArgv];
      cat(path, option);
      indexParametrArgv++;
    }
  }
  return 0;
}

int parser(int argc, char *argv[], option *flag, int *error) {
  struct option long_options[] = {{"number-nonblank", no_argument, NULL, 'b'},
                                  {"number", no_argument, NULL, 'n'},
                                  {"squeeze-blank", no_argument, NULL, 's'},
                                  {NULL, 0, NULL, 0}};

  int opt = 0;

  while ((opt = getopt_long(argc, argv, "beEnstTv", long_options, NULL)) !=
         -1) {
    switch (opt) {
      case 'b':
        flag->b = 1;
        break;
      case 'e':
        flag->e = flag->v = 1;
        break;
      case 'E':
        flag->e = 1;
        break;
      case 'n':
        flag->n = 1;
        break;
      case 's':
        flag->s = 1;
        break;
      case 't':
        flag->t = flag->v = 1;
        break;
      case 'T':
        flag->t = 1;
        break;
      case 'v':
        flag->v = 1;
        break;
      default:
        printf("Неверно введен флаг");
        *error = 1;
    }
  }
  return optind;
}

void cat(char *path, option flag) {
  if (access(path, F_OK) == 0) {
    FILE *filename;
    filename = fopen(path, "r");

    int ch, prev;

    int current_line = 1;
    int squeeze = 0;
    for (prev = '\n'; (ch = getc(filename)) != EOF; prev = ch) {
      if (flag.s == 1) {
        if (ch == '\n' && prev == '\n') {
          if (squeeze == 1) {
            continue;
          }
          squeeze++;
        } else
          squeeze = 0;
      }

      if (flag.b == 1) {
        if (prev == '\n' && ch != '\n') {
          printf("%*d\t", 6, current_line);
          current_line++;
        }
      }

      if (flag.n == 1 && flag.b == 0 && prev == '\n') {
        printf("%*d\t", 6, current_line);
        current_line++;
      }

      if (flag.e == 1 && ch == '\n') {
        putchar('$');
      }

      if (flag.t == 1 && ch == '\t') {
        printf("^");
        ch = 'I';
      }

      if (flag.v == 1) {
        if ((ch >= 0 && ch <= 31) && ch != '\t' && ch != '\n') {
          printf("^");
          ch += 64;

        } else if (ch == 127) {
          printf("^");
          ch = '?';
        } else if ((ch >= 128 && ch < 128 + 32) && ch != '\t' && ch != '\n') {
          printf("M-^");
          ch -= 64;
        }
      }
      putchar(ch);
    }
    fclose(filename);
  } else {
    fprintf(stderr, "No such file or directory: %s\n", path);
  }
}
