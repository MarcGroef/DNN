/*
 ============================================================================
 Name        : mnist_label_parser.c
 Author      : Afroz Mohiuddin
 Version     : 1
 Description : Parser for mnist label file.
 ============================================================================
 */
//editted by Marc Groefsema
#define  _CRT_SECURE_NO_WARNINGS
#include <inttypes.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#include <MNIST/hex_lib.h>
#include <MNIST/macros.h>

#include <assert.h>

// Usage



int* parseLabel(char* fileDir) {
  int* labels;
  FILE* input_file_pointer = fopen(fileDir, "r");
  CHECK_NOTNULL(input_file_pointer);
  
  char magic_number_bytes[4];
  CHECK(fread(magic_number_bytes, sizeof(char), 4, input_file_pointer));
  // If MSB is first then magic_number_bytes will be 0x00000801
  if (magic_number_bytes[2] == 0x08 && magic_number_bytes[3] == 0x01) {
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
  LOG_INFO("number of labels: %d", hex_array_to_int(number_of_images_bytes, 4));

  labels = malloc(sizeof(int)*hex_array_to_int(number_of_images_bytes,4));
  assert(labels!=NULL);

  char label_byte;
  int nlabels= hex_array_to_int(number_of_images_bytes,4);
  
  for (int i=0;i<nlabels && fread(&label_byte, sizeof(char), 1, input_file_pointer);i++) {
    labels[i] = hex_char_to_int(label_byte);

  }

  fclose(input_file_pointer);
  return labels;
}
