
#include "string.h"
#include "buffer_circ.h"


int buffer_insert(buffer_circ_t *b,void *data, unsigned int size)
{
  int ret = -1;
  unsigned char *ptr = (unsigned char *)data;

  if(b == NULL) {
    /* check your buffer parameter */
    return(ret);
  }

  if(size + b->items <= BUFFER_SIZE){

    /* the buffer has enough room, insert
     * stream.
     */
    unsigned int i;
    for(i = 0; i < size; i++) {
        b->data[b->wr_ptr] = *ptr++;

        /* increment the input index in form  if it
         * reach the buffer end, its placed in it
         * initial address again
         */
        b->wr_ptr =  (b->wr_ptr + 1) % BUFFER_SIZE;
        b->items++;
    }
    ret = 0;
  }

  return(ret);
}
int buffer_retrieve(buffer_circ_t *b,  void *data, unsigned int size)
{
  int ret = 0;
  unsigned char *ptr = (unsigned char *)data;

  if(b == NULL) {
    /* check your buffer parameter */
    return((ret = -1));
  }

  /* if the size requested fits on
   * current contents, extract
   * the data stream
   */
  unsigned int i;
  for(i = 0; (i < size) && (b->items != 0); i++) {
      *ptr++ = b->data[b->rd_ptr];
      b->rd_ptr =  (b->rd_ptr + 1) % BUFFER_SIZE;
      ret++;
      b->items--;
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

  if(b != NULL) {
    b->wr_ptr = b->rd_ptr;
    b->items = 0;
  } else {
    ret = -1;
  }

  return(ret);
}
int buffer_empty(buffer_circ_t *b)
{
  return((b->items == 0? 1: 0));
}
