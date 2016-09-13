/**
 * @brief Simple circular buffer implementation with basic management functions
 */

#ifndef __BUFFER_CIRC_H
#define __BUFFER_CIRC_H

#define BUFFER_SIZE 128

/** circular buffer management structure */
typedef struct {
  unsigned char data[BUFFER_SIZE];
  unsigned int  items;
  unsigned int  wr_ptr;
  unsigned int  rd_ptr;
} buffer_circ_t;



/**
 * @brief insert a stream data with size lenght to the buffer
 */
int buffer_insert(buffer_circ_t *b,void *data, unsigned int size);

/**
 *  @brief retrieves a stream of dat with specified size
 */
int buffer_retrieve(buffer_circ_t *b, void *data, unsigned int size);

/**
 *  @brief check if buffer is already full
 */
int buffer_full(buffer_circ_t *b);

/**
 * @brief check if a data stream with specified size will full the buffer
 */
int buffer_will_full(buffer_circ_t *b, unsigned int size);

/**
 * @brief makes the buffer empty
 */
int buffer_flush(buffer_circ_t *b);

/**
 * @brief  check if buffer is empty
 */
int buffer_empty(buffer_circ_t *b);

/** declare a initialized circular buffer */
#define CIRCULAR_BUFFER_DECLARE(name)  \
        buffer_circ_t name = {         \
          .data = {0},                 \
          .items = 0,                  \
          .wr_ptr = 0,                 \
          .rd_ptr = 0,                 \
        }

#endif
