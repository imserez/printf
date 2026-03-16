# ft_printf: Custom Variadic Formatter

![Language](https://img.shields.io/badge/Language-C-blue.svg)
![Type](https://img.shields.io/badge/Type-Variadic_Function-orange.svg)
![License](https://img.shields.io/badge/License-MIT-lightgrey.svg)

## Overview

**ft_printf** is a custom implementation of the standard C library function `printf`.

From a **Systems Engineering** perspective, this project is an exploration of **Variadic Functions** in C. The core challenge lies in interacting with the **Application Binary Interface (ABI)** conventions to retrieve a variable number of arguments from the stack (or registers) based on a format string parser.

Unlike high-level string formatting, this implementation requires manual handling of data types, memory addressing for pointers, and efficient buffer management to write to `stdout` with minimal syscall overhead.

## Technical Concepts

* **Variadic Arguments (`stdarg.h`):** Using macros (`va_start`, `va_arg`, `va_end`) to traverse the stack frame and retrieve undefined arguments.
* **Format String Parsing:** Implementing a state machine to detect flags and dispatch execution to the correct type handler.
* **Base Conversion:** Algorithms to convert numerical values (integers, memory addresses) into ASCII representations in varying bases (decimal, hexadecimal).
* **Pointer Arithmetic:** Handling `void *` memory addresses for the `%p` conversion.

## Supported Conversions

The function handles the following standard format specifiers:

| Specifier | Description | Argument Type |
| :---: | :--- | :--- |
| `%c` | Prints a single character. | `int` (promoted) |
| `%s` | Prints a string (as defined by the common C convention). | `char *` |
| `%p` | The `void *` pointer argument has to be printed in hexadecimal format. | `void *` |
| `%d` | Prints a decimal (base 10) number. | `int` |
| `%i` | Prints an integer in base 10. | `int` |
| `%u` | Prints an unsigned decimal (base 10) number. | `unsigned int` |
| `%x` | Prints a number in hexadecimal (base 16) lowercase format. | `unsigned int` |
| `%X` | Prints a number in hexadecimal (base 16) uppercase format. | `unsigned int` |
| `%%` | Prints a percent sign. | None |

## Usage

### Prototype
```c
int ft_printf(const char *format, ...);
```

### 1. Compilation

The project compiles into a static library `libftprintf.a`

```bash
make
```

### 2. Integration example

```c
#include "ft_printf.h"

int main(void)
{
    int count;

    // Example 1: String and Char
    ft_printf("Hello %s, your grade is %c.\n", "User", 'A');

    // Example 2: Numbers and Hex
    count = ft_printf("Memory Address: %p | Hex: %x\n", &count, 255);
    
    // Return value check (bytes written)
    ft_printf("Bytes written: %d\n", count);

    return (0);
}
```
To use it in your project, link the previously compiled static library `libftprintf.a` during compilation:

```bash
gcc main.c libftprintf.a -o my_program
```

**Compile with bonus:**
```bash
gcc -Wall -Wextra -Werror -D BUFFER_SIZE=1024 \
    main.c get_next_line_bonus.c get_next_line_utils_bonus.c -o multi_fd_reader
```

## Author

**Sergi Juarez**

- **GitHub:** [imserez](https://github.com/imserez)
- **LinkedIn:** [sergijuarez](https://www.linkedin.com/in/sergijuarez)

---
*This project is part of the 42 Barcelona curriculum.*
