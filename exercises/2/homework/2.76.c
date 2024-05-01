#include <stdint.h>
#include <stdlib.h>
#include <string.h>

/*
 * Write an implementation of calloc that performs the allocation 
 * by a call to malloc and sets the memory to zero via memset. 
 * You code should not have any vulnerabilities due to arithmetic overflow, 
 * and it should work correctly regardless of the number of bits 
 * used to represent data of type size_t 
*/
void *test_calloc(size_t nmemb, size_t size)
{
  if (!nmemb || !size)
    return NULL;

  size_t request_size = nmemb * size;
  /* Check for overflow */
  if (request_size / nmemb == size)
  {
    void *buf = malloc(request_size);
    if (!buf)
    {
      memset(buf, 0, request_size);
    }
    return buf;
  }
  return NULL;
}
