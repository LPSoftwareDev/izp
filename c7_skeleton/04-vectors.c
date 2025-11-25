#include <stdio.h>
#include <stdlib.h>

// datovy typ pro vektor
typedef struct {
    int *data;
    unsigned int size;
} vector_t;

/// @brief Funkce inicializuje vektor.
/// @param v Vektor
/// @param size Velikost vektoru
/// @return 1 pokud se vse podarilo, 0 jinak
int vector_ctor(vector_t *v, unsigned int size) {
    v->data = malloc(size * sizeof(int));
    if (v->data == NULL) {
        return 0;
    }
    v->size = size;
    return 1;
}

/// @brief  Funkce uvolni vektor z pameti.
/// @param v Vektor
void vector_dtor(vector_t *v) {
    free(v->data);
}

/// @brief Funkce inicializuje vektor na hodnoty 1,2,3, ...
/// @param v Vektor
void vector_init(vector_t *v) {
    for (int idx = 0; idx < v->size; idx++) {
        v->data[idx] = idx + 1;
    }
}

/// @brief Funkce vektor vytiskne na obrazovku
/// @param v Vektor
void vector_print(vector_t *v) {
    for (int idx = 0; idx < v->size; idx++) {
        printf("%i ", v->data[idx]);
    }
}

/// @brief Funkce vynasobi vektor konstantou.
/// @param v Vektor
/// @param c Konstanta
void vector_mult(vector_t *v, int c) {
    for (int idx = 0; idx < v->size; idx++) {
        v->data[idx] = v->data[idx] * c;
    }
}

/// @brief Funkce pricte k vektoru v1 vektor v2, v1 = v1 + v2
/// @param v1 Vektor
/// @param v2 Vektor
/// @return 0 pokud nelze vektory secist, 1 jinak
int vector_add(vector_t *v1, vector_t *v2) {
    if (v1->size != v2->size) {
        return 0;
    }
    for (int idx = 0; idx < v1->size; idx++) {
        v1->data[idx] = v1->data[idx] + v2->data[idx];
    }
    return 1;
}

int main() {
    int ok;
    vector_t v1;
    vector_t v2;

    ok = vector_ctor(&v1, 10);
    if (ok == 0) {
        printf("failed to allocate vector_1");
        return 1;
    }
    ok = vector_ctor(&v2, 3);
    if (ok == 0) {
        printf("failed to allocate vector_2");
        return 1;
    }

    vector_init(&v1);
    vector_init(&v2);

    printf("vector_1:\n");
    vector_print(&v1);
    printf("\n");

    printf("vector_2:\n");
    vector_print(&v2);
    printf("\n");

    printf("vector_1 + vector_2:\n");
    ok = vector_add(&v1, &v2);
    if (ok == 0) {
        printf("cant add vectors with different size");
    } else {
        vector_print(&v1);
    }
    printf("\n");

    printf("mul vector_1 by 2:\n");
    vector_mult(&v1, 2);
    vector_print(&v1);
    printf("\n");

    vector_dtor(&v1);
    vector_dtor(&v2);

    return 0;
}
