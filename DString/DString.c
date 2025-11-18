#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  char *data;
  size_t length;
  size_t capacity;
} DString;

DString* dstr_create(const char *init_str) {
  DString *ds = malloc(sizeof(DString));
  if (!ds) return NULL;

  size_t init_len = init_str ? strlen(init_str) : 0;
  ds->length = init_len;
  ds->capacity = init_len + 16;

  ds->data = malloc(ds->capacity);
  if (!ds->data) {
    free(ds);
    return NULL;
  }
  if (init_str) {
    memcpy(ds->data, init_str, init_len);
  }
  ds->data[ds->length] = '\0';

  return ds;
}

int dstr_free(DString *ds) {
  if (ds) {
    free(ds->data);
    free(ds);
  }
  return 0;
}

static int dstr_ensure_capacity(DString *ds, size_t needed) {
  if (needed <= ds->capacity) return 1;

  size_t new_cap = ds->capacity * 2;
  while (new_cap < needed) {
    new_cap *= 2;
  }
  char *new_data = realloc(ds->data, new_cap);
  if (!new_data) return 0;

  ds->data = new_data;
  ds->capacity = new_cap;
  return 1;
}

int dstr_concat(DString *ds, const char *str) {
  if (!ds || !str) return 0;

  size_t str_len = strlen(str);
  size_t new_len = ds->length + str_len;

  if (!dstr_ensure_capacity(ds, new_len + 1)) return 0;

  memcpy(ds->data + ds->length, str, str_len);
  ds->length = new_len;
  ds->data[ds->length] = '\0';

  return 1;
}

DString* dstr_substr(const DString *ds, size_t start, size_t len) {
  if (!ds || start >= ds->length) return dstr_create("");

  if (start + len > ds->length) {
    len = ds->length - start;
  }

  DString *result = malloc(sizeof(DString));
  if (!result) return NULL;

  result->capacity = len + 16;
  result->length = len;
  result->data = malloc(result->capacity);

  if (!result->data) {
    free(result);
    return NULL;
  }

  memcpy(result->data, ds->data + start, len);
  result->data[len] = '\0';

  return result;
}

const char* dstr_cstr(const DString *ds) {
  return ds ? ds->data : NULL;
}

size_t dstr_length(const DString *ds) {
  return ds ? ds->length : 0;
}

void dstr_clear(DString *ds) {
  if (ds) {
    ds->length = 0;
    ds->data[0] = '\0';
  }
}

int main(void) {
  DString *str = dstr_create("Hello");
  printf("Initial: '%s' (length: %zu)\n", dstr_cstr(str), dstr_length(str));

  dstr_concat(str, " World");
  printf("After concat '%s' (length: %zu)\n", dstr_cstr(str), dstr_length(str));

  dstr_concat(str, "! This is a dynamic string.");
  printf("After more concat: '%s' (length: %zu)\n", dstr_cstr(str), dstr_length(str));

  DString *sub = dstr_substr(str, 6, 5);
  printf("Substring [6,5]: '%s'\n", dstr_cstr(sub));

  dstr_clear(str);
  printf("After clear: '%s' (length: %zu)\n", dstr_cstr(str), dstr_length(str));

  dstr_free(str);
  dstr_free(sub);

  return 0;
}