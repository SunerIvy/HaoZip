/* Sort.c -- Sort functions
2008-08-17
Igor Pavlov
Public domain */

#include "algorithm/Sort.h"

#define HeapSortDown(p, k, size, temp) \
  { for (;;) { \
    uint32_t s = (k << 1); \
    if (s > size) break; \
    if (s < size && p[s + 1] > p[s]) s++; \
    if (temp >= p[s]) break; \
    p[k] = p[s]; k = s; \
  } p[k] = temp; }

void HeapSort(uint32_t *p, uint32_t size)
{
  if (size <= 1)
    return;
  p--;
  {
    uint32_t i = size / 2;
    do
    {
      uint32_t temp = p[i];
      uint32_t k = i;
      HeapSortDown(p, k, size, temp)
    }
    while (--i != 0);
  }
  /*
  do
  {
    uint32_t k = 1;
    uint32_t temp = p[size];
    p[size--] = p[1];
    HeapSortDown(p, k, size, temp)
  }
  while (size > 1);
  */
  while (size > 3)
  {
    uint32_t temp = p[size];
    uint32_t k = (p[3] > p[2]) ? 3 : 2;
    p[size--] = p[1];
    p[1] = p[k];
    HeapSortDown(p, k, size, temp)
  }
  {
    uint32_t temp = p[size];
    p[size] = p[1];
    if (size > 2 && p[2] < temp)
    {
      p[1] = p[2];
      p[2] = temp;
    }
    else
      p[1] = temp;
  }
}

/*
#define HeapSortRefDown(p, vals, n, size, temp) \
  { uint32_t k = n; uint32_t val = vals[temp]; for (;;) { \
    uint32_t s = (k << 1); \
    if (s > size) break; \
    if (s < size && vals[p[s + 1]] > vals[p[s]]) s++; \
    if (val >= vals[p[s]]) break; \
    p[k] = p[s]; k = s; \
  } p[k] = temp; }

void HeapSortRef(uint32_t *p, uint32_t *vals, uint32_t size)
{
  if (size <= 1)
    return;
  p--;
  {
    uint32_t i = size / 2;
    do
    {
      uint32_t temp = p[i];
      HeapSortRefDown(p, vals, i, size, temp);
    }
    while (--i != 0);
  }
  do
  {
    uint32_t temp = p[size];
    p[size--] = p[1];
    HeapSortRefDown(p, vals, 1, size, temp);
  }
  while (size > 1);
}
*/