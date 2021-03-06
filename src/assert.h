/*!
 * @author Ravil Bikbulatov
 * @date 08.04.18
 */

#include <stdlib.h>

enum {
  testy_SUCCESS = 0,
  testy_ERROR = 1
};

#define testy_check(expr, format, ...) \
  if(!(expr)) {   \
    printf("Assertion failed on line %d: "format"\n", __LINE__, ## __VA_ARGS__); \
    exit(testy_ERROR); \
  }

#define testy_assert_int(x, op, y) do { \
  int _testy_x = (x); \
  int _testy_y = (y); \
  testy_check(_testy_x op _testy_y, "Assertion '%s' failed: %s = %jd, %s = %jd", #x" "#op" "#y, #x, _testy_x, #y, _testy_y) \
} while(0)

#define testy_assert_uint(x, op, y) do { \
  uint _testy_x = (x); \
  uint _testy_y = (y); \
  testy_check(_testy_x op _testy_y, "Assertion '%s' failed: %s = %jd, %s = %jd", #x" "#op" "#y, #x, _testy_x, #y, _testy_y) \
} while(0)

#define testy_assert_string(x, op, y) do { \
  const char* _testy_x = (x); \
  const char* _testy_y = (y); \
  testy_check(0 op strcmp(_testy_x, _testy_y), "Assertion '%s' failed: %s = %jd, %s = %jd", #x" "#op" "#y, #x, _testy_x, #y, _testy_y) \
} while(0)

#define testy_assert_ptr(x, op, y) do { \
  const void* _testy_x = (x); \
  const void* _testy_y = (y); \
  testy_check(_testy_x op _testy_y, "Assertion '%s' failed: %s = %jd, %s = %jd", #x" "#op" "#y, #x, _testy_x, #y, _testy_y) \
} while(0)

#define testy_assert_int_eq(x, y) testy_assert_int(x, ==, y)
#define testy_assert_int_ne(x, y) testy_assert_int(x, !=, y)
#define testy_assert_int_lt(x, y) testy_assert_int(x, <, y)
#define testy_assert_int_le(x, y) testy_assert_int(x, <=, y)
#define testy_assert_int_gt(x, y) testy_assert_int(x, >, y)
#define testy_assert_int_ge(x, y) testy_assert_int(x, >=, y)

#define testy_assert_uint_eq(x, y) testy_assert_uint(x, ==, y)
#define testy_assert_uint_ne(x, y) testy_assert_uint(x, !=, y)
#define testy_assert_uint_lt(x, y) testy_assert_uint(x, <, y)
#define testy_assert_uint_le(x, y) testy_assert_uint(x, <=, y)
#define testy_assert_uint_gt(x, y) testy_assert_uint(x, >, y)
#define testy_assert_uint_ge(x, y) testy_assert_uint(x, >=, y)

#define testy_assert_string_eq(x, y) testy_assert_string(x, ==, y)
#define testy_assert_string_ne(x, y) testy_assert_string(x, !=, y)
#define testy_assert_string_lt(x, y) testy_assert_string(x, <, y)
#define testy_assert_string_le(x, y) testy_assert_string(x, <=, y)
#define testy_assert_string_gt(x, y) testy_assert_string(x, >, y)
#define testy_assert_string_ge(x, y) testy_assert_string(x, >=, y)

#define testy_assert_ptr_eq(x, y) testy_assert_ptr(x, ==, y)
#define testy_assert_ptr_ne(x, y) testy_assert_ptr(x, !=, y)