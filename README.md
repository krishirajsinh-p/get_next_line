<h1 align="center">
	<p>
	📖 get_next_line
	</p>
</h1>

## 💡 About the project

> _The aim of this project is to make you code a function that returns a line, read from a file descriptor._

	You will understand how files are opened, read and closed in an OS,
	and how they are interpreted by a programming language for further analysis.
	This task is crucial to understand for a future programmer since much of the time is based
	on manipulating files for data management and persistence.
	This project consists of coding a function that returns one line at a time from a text file.

---

## 🛠️ Usage

### Requirements

The function is written in C language and thus needs the **`gcc` compiler** and some standard **C libraries** to run.

### Instructions

**1. Using it in your code**

To use the function in your code, simply include its header:

```C
#include "get_next_line.h"
```

and, when compiling your code, add the source files and the required flag:

```shell
get_next_line.c get_next_line_utils.c -D BUFFER_SIZE=<size>
```

## 📋 Testing

You only have make a main and a/few name.txt files for testing this project.
Then simply run this command (change "xx" with desired buffer size) :

```shell
gcc -Wall -Werror -Wextra -D BUFFER_SIZE=xx get_next_line.c get_next_line_utils.c && ./a.out
```