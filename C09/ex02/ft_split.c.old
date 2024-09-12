#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

char **ft_split(char *, char *);
int *delimiter_idx(char *, char *, int *);
char *fill_str(char *, int, int);
int ft_strlen(char *);
int is_delimiter(char, char *);
void ft_free(void **ptr);

int main() {
  char str[] = ", hello, ,hi,hola, hey,,,,,,heey,";
  char charset[] = ", |";
  char **strs = ft_split(str, charset);
  printf("str -> %s\n", str);
  for (int i = 0; strs[i]; i++) {
    printf("%d - %s\n", i, strs[i]);
  }
  ft_free((void **)strs);
}

void ft_free(void **ptr) {
  int i;
  for (i = 0; ptr[i]; i++) {
    free(ptr[i]);
  }
  free(ptr);
}

int is_delimiter(char c, char *delimiter) {
  for (int i = 0; delimiter[i]; i++)
    if (c == delimiter[i])
      return TRUE;

  return FALSE;
}

int ft_strlen(char *str) {
  int i;

  for (i = 0; str[i]; i++) {
  }
  return i;
}

int *delimiter_idx(char *str, char *charset, int *size) {
  int mem_alloc, index;
  int *arr;

  mem_alloc = 2;
  index = 0;
  arr = (int *)malloc(sizeof(int) * mem_alloc);
  if (!arr)
    return NULL;

  arr[index++] = -1;
  for (int i = 0; str[i]; i++) {
    if (mem_alloc == index)
      arr = realloc(arr, sizeof(int) * ++mem_alloc);
    if (is_delimiter(str[i], charset))
      arr[index++] = i;
  }

  if (mem_alloc == index)
    arr = realloc(arr, sizeof(int) * ++mem_alloc);
  arr[index++] = ft_strlen(str);
  *size = index;
  return arr;
}

char *fill_str(char *str, int start, int end) {
  char *buffer;
  int i;

  if (start >= end)
    return NULL;

  buffer = (char *)malloc(sizeof(char) * (end - start + 1));
  if (!buffer)
    return NULL;

  for (i = start; i < end; i++)
    buffer[i - start] = str[i];

  buffer[i - start] = '\0';

  return buffer;
}

char **ft_split(char *str, char *charset) {
  int *idx_arr, index, size, words_count;
  char **strs;

  idx_arr = delimiter_idx(str, charset, &size);
  if (!idx_arr)
    return NULL;

  // calculate number of words
  words_count = 0;
  for (int i = 0; i < size - 1; i++) {
    if ((idx_arr[i + 1] - idx_arr[i]) >= 2)
      words_count++;
  }

  strs = (char **)malloc(sizeof(char *) * (words_count + 1));
  if (!strs) {
    free(idx_arr);
    return NULL;
  }

  index = 0;
  for (int i = 0; i < size - 1; i++) {
    if ((idx_arr[i + 1] - idx_arr[i]) >= 2)
      strs[index++] = fill_str(str, idx_arr[i] + 1, idx_arr[i + 1]);
  }
  strs[index] = NULL;
  free(idx_arr);
  return strs;
}
