#include <stdbool.h>
#include <stdio.h>
#include <wctype.h>

#define WIDTH 4
#define HEIGHT 4

struct RGB {
    int red;
    int green;
    int blue;
};

bool load_file(struct RGB image[HEIGHT][WIDTH]) {
    FILE *file = fopen("data.txt", "r");
    if (file == NULL) {
        fprintf(stderr, "Failed to load data.txt");
        return false;
    }

    for (int row = 0; row < HEIGHT; row++) {
        for (int col = 0; col < WIDTH; col++) {
            fscanf(file, "%d %d %d", &image[row][col].red, &image[row][col].green, &image[row][col].blue);
        }
    }

    fclose(file);
    return true;
}

void convert(struct RGB image[HEIGHT][WIDTH], float gImage[HEIGHT][WIDTH]) {
    for (int row = 0; row < HEIGHT; row++) {
        for (int col = 0; col < WIDTH; col++) {
            gImage[row][col] = (image[row][col].red + image[row][col].green + image[row][col].blue) / 3.0;
        }
    }
}

bool save_image(float gImage[HEIGHT][WIDTH]) {
    FILE *file = fopen("out.txt", "w");
    if (file == NULL) {
        fprintf(stderr, "Failed to load out.txt");
        return false;
    }
    for (int row = 0; row < HEIGHT; row++) {
        for (int col = 0; col < WIDTH; col++) {
            fprintf(file, "%f ", gImage[row][col]);
        }
        fprintf(file, "\n");
    }
    fclose(file);
    return true;
}

int main(void) {
    struct RGB image[HEIGHT][WIDTH];
    float gImage[HEIGHT][WIDTH];

    load_file(image);

    convert(image, gImage);

    save_image(gImage);

    return 0;
}
