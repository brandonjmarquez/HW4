#include <iostream>
#include "recursive.h"

static int sum_helper(list_t list,  int result) {
  if (list_isEmpty(list)) {
    return result;
  }
  else {
    return sum_helper(list_rest(list), list_first(list) + result);
  }
}

int sum(list_t list) {
  return sum_helper(list, 0);
}

static int product_helper(list_t list, int result) {
  if (list_isEmpty(list)) {
      return result;
  } else {
    return product_helper(list_rest(list), list_first(list) * result);
  }
}

int product(list_t list) {
  return product_helper(list, 1);
}

int accumulate(list_t l, int (*fn)(int, int), int identity) {
  if (list_isEmpty(l)) {
    return identity;
  } else {
    return accumulate(list_rest(l), fn, fn(identity, list_first(l)));
  }
}

static list_t reverse_helper(list_t list, list_t result) {
  if (list_isEmpty(list)) {
    return result;
  } else {
    return reverse_helper(list_rest(list), list_make(list_first(list), result));
  }
}

list_t reverse(list_t list) {
   return reverse_helper(list, list_make());
}

static list_t append_helper(list_t first, list_t second, list_t result) {
  if (list_isEmpty(first) && list_isEmpty(second)) {
    return reverse(result);
  } else if (!list_isEmpty(first)) {
    return append_helper(list_rest(first), second, list_make(list_first(first), result));
  } else {
    return append_helper(first, list_rest(second), list_make(list_first(second), result));
  }
}

list_t append(list_t first, list_t second) {
   return append_helper(first, second, list_make());
}

static list_t filter_odd_helper(list_t list, list_t result) {
  if(list_isEmpty(list)) {
    return reverse(result);
  } else if(list_first(list) % 2 == 1) {
    return filter_odd_helper(list_rest(list), list_make(list_first(list), result));
  } else {
    return filter_odd_helper(list_rest(list), result);
  }
}

list_t filter_odd(list_t list) {
   return filter_odd_helper(list, list_make());
}

static list_t filter_even_helper(list_t list, list_t result) {
  if(list_isEmpty(list)) {
    return reverse(result);
  } else if(list_first(list) % 2 == 0) {
    return filter_even_helper(list_rest(list), list_make(list_first(list), result));
  } else {
    return filter_even_helper(list_rest(list), result);
  }
}

list_t filter_even(list_t list) {
   return filter_even_helper(list, list_make());
}

static list_t filter_helper(list_t list, bool (*fn)(int), list_t result) {
  if(list_isEmpty(list)) {
    return result;
  } else if (fn) {
    return filter_helper(list_rest(list), fn, list_make(list_first(list), result));
  }
  else { 
    return filter_helper(list_rest(list), fn, result);
  }
}

list_t filter(list_t list, bool (*fn)(int)){
    return filter_helper(list, fn, list_make());
}

static list_t rotate_helper(list_t list, unsigned int n, list_t result) {
  if (list_isEmpty(list)) {
    return rotate_helper(reverse(result), n, list_make());
  } else if (n == 0) {
    return append(list, reverse(result));
  } else {
    return rotate_helper(list_rest(list), n - 1, list_make(list_first(list), result));
  }
}

list_t rotate(list_t list, unsigned int n) {
   return rotate_helper(list, n, list_make());
}

static list_t insert_list_helper(list_t first, list_t second, unsigned int n, list_t result) {
  return result;
}

list_t insert_list(list_t first, list_t second, unsigned int n){
  list_t first_reversed = reverse(first);
  list_t second_reversed = reverse(second);
   return insert_list_helper(first, second, n, list_make());
}

static list_t chop_helper(list_t l, unsigned int n, list_t result) {
  if (n == 0) {
    return reverse(l);
  } else {
    return chop_helper(list_rest(l), n - 1, list_make(list_first(l), result));
  }
}

list_t chop(list_t l, unsigned int n){
   list_t list_reversed = reverse(l);
   return chop_helper(list_reversed, n, list_make());
}

int fib(int n){
    /*
    // REQUIRES: n >= 0
    // EFFECTS: computes the Nth Fibonacci number
    //          fib(0) = 0
    //          fib(1) = 1
    //          fib(n) = fib(n-1) + fib(n-2) for (n>1).
    // This must be recursive but need not be tail recursive
    */
    return fib(n-1) + fib(n-2);
}

static int fib_tail_helper(int n, int fib0, int fib1) {
  if(n < 0) {
    return fib1;
  } else {
    return fib_tail_helper(n-1, fib0 + fib1, fib0 * 2 + fib1);
  }
}

int fib_tail(int n){
    /*
    // REQUIRES: n >= 0
    // EFFECTS: computes the Nth Fibonacci number
    //          fib(0) = 0
    //          fib(1) = 1
    //          fib(n) = fib(n-1) + fib(n-2) for (n>1).
    // MUST be tail recursive
    // Hint: instead of starting at n and workind down, start at
    // 0 and 1 and *upwards*.
    */
    return fib_tail_helper(n, 0, 1);
}