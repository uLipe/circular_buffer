#ifndef __BUFFER_CIRC_H
#define __BUFFER_CIRC_H

#define BUFFER_SIZE 128


typedef struct {
  unsigned char data[BUFFER_SIZE];
  unsigned int  items
  unsigned int  wr_ptr;
  unsigned int  rd_ptr;
} buffer_circ_t;


int buffer_insert(buffer_circ_t *b,void *data, unsigned int size);
int buffer_retrieve(buffer_circ_t *b void *data, unsigned int size);
int buffer_full(buffer_circ_t *b);
int buffer_will_full(buffer_circ_t *b, unsigned int size);
int buffer_flush(buffer_circ_t *b);


#define CIRCULAR_BUFFER_DECLARE(name)  \
        buffer_circ_t ##name = {       \
          .data = {0},                 \
          .items = 0,                  \
          .wr_ptr = 0,                 \
          .rd_ptr = 0,                 \
        }

#endif
