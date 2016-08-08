
#include "string.h"
#include "buffer_circ.h"


int buffer_insert(buffer_circ_t *b,void *data, unsigned int size)
{
  int ret = -1;
  unsigned char *ptr = (unsigned char *)data;

  if(b == NULL) {
    return(ret);
  }

  if(size + b->items <= BUFFER_SIZE) {
    unsigned int i;
    for(i = 0; i < size; i++) {
        b->data[wr_ptr] = *ptr++;
        wr_ptr =  (wr_ptr + 1) % BUFFER_SIZE;
        b->items++;
    }
    ret = 0;
  }

  return(ret);
}
int buffer_retrieve(buffer_circ_t *b void *data, unsigned int size)
{
  int ret = 0;
  unsigned char *ptr = (unsigned char *)data;

  if(b == NULL) {
    return((ret = -1));
  }

  if(size + b->items <= BUFFER_SIZE) {
    unsigned int i;
    for(i = 0; (i < size) || (b->items != 0); i++) {
        *ptr++ = b->data[rd_ptr];
        rd_ptr =  (rd_ptr + 1) % BUFFER_SIZE;
        ret++;
        b->items--;
    }
  }
  return(ret);
}
int buffer_full(buffer_circ_t *b)
{
  int ret = 0;
  if(b->items ==  BUFFER_SIZE) {
    ret = 1;
  }
  return(ret);
}

int buffer_will_full(buffer_circ_t *b, unsigned int size)
{
  int ret = 0;

  if(b->items + size > BUFFER_SIZE ) {
    ret = 1;
  }
  return(ret);
}
int buffer_flush(buffer_circ_t *b)
{
  int ret = 0;
  b->wr_ptr = b->rd_ptr;
  b->items = 0;

  return(ret);
}
