#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int *data;
    unsigned int size;
} vector_t;

vector_t *vector_ctor() {
    vector_t *vec = malloc(sizeof(vector_t));
    if (vec == NULL) {
        return NULL;
    }
    vec->data = NULL;
    vec->size = 0;
    return vec;
}

void vector_dtor(vector_t *vec) {
    if (vec->data != NULL) {
        free(vec->data);
        return;
    }
    free(vec);
}

bool expand_vector(vector_t *vec) {
    int *resized = realloc(vec->data, (vec->size + 1) * sizeof(int));
    if (resized == NULL) {
        return false;
    }
    vec->data = resized;
    vec->size++;
    return true;
}

bool shrink_vector(vector_t *vec) {
    int *resized = realloc(vec->data, (vec->size - 1) * sizeof(int));
    if (resized == NULL) {
        return false;
    }
    vec->data = resized;
    vec->size--;
    return true;
}

bool vector_append(vector_t *vec, int val) {
    bool ok = expand_vector(vec);
    if (vec->data == NULL && ok != true) {
        return false;
    }
    vec->data[vec->size - 1] = val;
    return true;
}

bool vector_prepend(vector_t *vec, int val) {
    bool ok = expand_vector(vec);
    if (vec->data == NULL && ok != true) {
        return false;
    }
    for (int idx = vec->size - 2; idx >= 0; idx--) {
        vec->data[idx + 1] = vec->data[idx];
    }
    vec->data[0] = val;
    return true;
}

int vector_pop_first(vector_t *vec, bool *ok) {
    if (vec->data == NULL) {
        *ok = false;
        return 0;
    }
    int result = vec->data[0];
    for (int idx = 1; idx < vec->size; idx++) {
        vec->data[idx - 1] = vec->data[idx];
    }

    *ok = shrink_vector(vec);
    if (!ok) {
        return 0;
    } else {
        return result;
    }
}

int vector_pop(vector_t *vec, int idx, bool *ok) {
    if (vec->data == NULL && idx > vec->size) {
        *ok = false;
        return 0;
    }

    int result = vec->data[idx];

    for (int i = idx + 1; i <= vec->size - 1; i++) {
        vec->data[i - 1] = vec->data[i];
    }

    *ok = shrink_vector(vec);
    if (!ok) {
        return 0;
    } else {
        return result;
    }
}

void vector_print(vector_t *vec) {
    if (vec->data == NULL) {
        return;
    }
    for (int idx = 0; idx < vec->size; idx++) {
        printf("%d", vec->data[idx]);
    }
    printf("\n");
}

int main(void) {
    bool ok;
    vector_t *vec = vector_ctor();
    vector_append(vec, 3);
    vector_print(vec);
    vector_append(vec, 2);
    vector_print(vec);
    vector_append(vec, 7);
    vector_print(vec);
    vector_prepend(vec, 1);
    vector_print(vec);
    int poped = vector_pop_first(vec, &ok);
    printf("poped: %d\n", poped);
    vector_print(vec);

    poped = vector_pop(vec, 1, &ok);
    printf("poped: %d\n", poped);
    vector_print(vec);

    poped = vector_pop(vec, 0, &ok);
    printf("poped: %d\n", poped);
    vector_print(vec);

    return EXIT_SUCCESS;
}
