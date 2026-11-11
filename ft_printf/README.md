*This project has been created as part of the 42 curriculum by mabuhila.*

# ft_printf

## Description

The goal of this project is to recreate the standard C `printf()` function. It introduces variadic functions, formatted output, and recursion.

Supported conversions:

- `%c` — Prints a single character.
- `%s` — Prints a string.
- `%p` — Prints a pointer address in hexadecimal.
- `%d` — Prints a signed decimal integer.
- `%i` — Prints a signed decimal integer.
- `%u` — Prints an unsigned decimal integer.
- `%x` — Prints an unsigned integer in lowercase hexadecimal.
- `%X` — Prints an unsigned integer in uppercase hexadecimal.
- `%%` — Prints a literal percent sign (`%`).

## Instructions

**Requirements:** A C compiler (`cc`) and `make`.

Compile the project:

```bash
make
```

Clean object files:

```bash
make clean
```

Remove all generated files:

```bash
make fclean
```

Rebuild the project:

```bash
make re
```

## Algorithm and Data Structures

The program reads the format string character by character. When it encounters `%`, it identifies the conversion and calls the appropriate helper function.

Variadic arguments are handled using `va_list` and related functions. Recursive functions print decimal and hexadecimal numbers by dividing them into smaller parts. A lookup string converts hexadecimal digits into their corresponding characters.

Each helper function returns the number of characters printed, allowing `ft_printf` to return the total count.

## Resources

- [printf documentation](https://en.cppreference.com/w/c/io/fprintf)
- [Variadic functions in C](https://en.cppreference.com/w/c/variadic)
- [write() documentation](https://man7.org/linux/man-pages/man2/write.2.html)

**AI Usage:** AI was used to help understand variadic functions, recursion, pointer handling, Makefiles, and documentation.

