libcompat
=========

This library provides some functions needed for porting more modern code to CodeWarrior Pro 1.
With the exception of `snprintf` (which is not mine) consider this public domain code.

- C99 integer types
- `size_t`
- `__time()` relative to UNIX epoch
- `strdup`
- `snprintf` (Mark Martinec's)
