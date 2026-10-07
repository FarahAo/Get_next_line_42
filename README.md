*This activity has been created as part of the 42 curriculum by fabo-ome*

# get_next_line

## Description

`get_next_line` is a 42 project where the goal is to write a function that reads and returns one line at a time from a file descriptor.

The function must return the line including the `\n` character, except when the end of the file is reached without a `\n`. It must also work when reading from standard input.

The project contains:

```text
get_next_line.c
get_next_line_utils.c
get_next_line.h
```

The function prototype is:

```c
char	*get_next_line(int fd);
```

It returns `NULL` when there is nothing left to read or when an error occurs.

## Instructions

Compile the project with:

```bash
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c main.c
```

`BUFFER_SIZE` determines how many bytes are read at a time.

## Algorithm

The function uses a static `saved` variable to keep data between calls.

First, `read_and_add()` allocates a buffer and reads from the file descriptor until a `\n` is found or the end of the file is reached. Each buffer is added to `saved`.

Then, `extract_line()` finds the first `\n` in `saved` and allocates the line that will be returned. The `\n` is included when it exists.

After that, `extract_saved()` finds the data after the first `\n`. This remaining data is stored as the new `saved` value so it can be used during the next call.

This allows `get_next_line()` to return one line at a time while keeping any data that belongs to the following line.

## Resources

* `read`, `malloc`, and `free` manual pages.
* [System Calls Introduction](https://web.eecs.utk.edu/~mbeck/classes/cs560/360/notes/Syscall-Intro/lecture.html) — Introduction to the operating system, kernel, system calls, and how programs interact with the OS.
* [YouTube — get_next_line](https://youtu.be/KM5sRWAYqaw?si=LSQAkEKv17WVb7jR) — Explanation of file descriptors (`fd`) and related concepts.
* GeeksforGeeks articles about C, file descriptors, and file handling.
* Discussions and explanations with friends.

### AI Usage

AI was used as a tool to understand concepts needed for the project, including the operating system, kernel, file descriptors, `read()`, buffers, `BUFFER_SIZE`, static variables, and how `get_next_line` works.

