/*Original author: Copyright 2014 (c) Afroz Muhiuddin
 ============================================================================
 Name        : mnist_image_parser.c
 Author      : Afroz Mohiuddin
 Version     : 1
 Description : Parser for mnist image db file.
 ============================================================================
 */

//Modified by: Copyright 2015 (c) Marc Groefsema

#define  _CRT_SECURE_NO_WARNINGS
#include <inttypes.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#include "../include/hex_lib.h"
#include "../include/macros.h"



int parseImage(char* input_file,int nImages,float** data) {
  if (nImages>10000) {
    printf("mnist_image_parser: parseImage(%s,%d)\n",input_file,nImages);
    return 1;
  }
  FILE* input_file_pointer = fopen(input_file, "r");
  CHECK_NOTNULL(input_file_pointer);
  char magic_number_bytes[4];
  CHECK(fread(magic_number_bytes, sizeof(char), 4, input_file_pointer));
  // If MSB is first then magic_number_bytes will be 0x00000803
  if (magic_number_bytes[2] == 0x08 && magic_number_bytes[3] == 0x03) {
    LOG_INFO("Little Endian : MSB first");
  } else if (magic_number_bytes[0] == 0x01 && magic_number_bytes[1] == 0x08) {
    // I haven't taken into account big indian-ness, yet.
    LOG_FATAL("Big Endian : MSB last");
  } else {
    LOG_FATAL("This doesn't correspond to a MNIST Label file.");
  }
  LOG_INFO("magic number: %d", hex_array_to_int(magic_number_bytes, 4));
  char number_of_images_bytes[4];
  CHECK(fread(number_of_images_bytes, sizeof(char), 4, input_file_pointer));
  int32_t number_of_images = hex_array_to_int(number_of_images_bytes, 4);
  LOG_INFO("number of images: %d", number_of_images);

  int32_t num_rows = 0, num_cols = 0;
  char num_row_cols[4];
  CHECK(fread(num_row_cols, sizeof(char), 4, input_file_pointer));
  num_rows = hex_array_to_int(num_row_cols, 4);
  CHECK(fread(num_row_cols, sizeof(char), 4, input_file_pointer));
  num_cols = hex_array_to_int(num_row_cols, 4);
  LOG_INFO("pixel rows: %d and pixel columns: %d", num_rows, num_cols);



  int32_t num_pixles_in_image = num_cols * num_rows;
  //char images_pixels_bytes[num_pixles_in_image];
  char* images_pixels_bytes = malloc(num_pixles_in_image);
  int images_done = 0;
  while (images_done++ < number_of_images) {
    CHECK(fread(images_pixels_bytes, sizeof(char), num_pixles_in_image, input_file_pointer));
    int32_t idx = 0;
    for (idx = 0; idx < num_pixles_in_image; ++idx) {
      int32_t image_pixel_value = hex_char_to_int(images_pixels_bytes[idx]);

      // A graphic of the number this represents.
      if (idx % num_cols == 0) printf("\n");
      if (image_pixel_value < 10) {
        printf(".");
      } else {
        printf("*");
      }
    }
    printf("\n----------------------------------------------------------\n");
    
  }
  free(images_pixels_bytes);
  fclose(input_file_pointer);
  
  return 0;
}
