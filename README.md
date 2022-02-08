# Get_next_line-42
The aim of this project is to make you code a function that returns a line ending with a newline, read from a file descriptor.
> Reading a line from a fd is way too tedious

## Mandatory part
Repeated calls (e.g., using a loop) to your `get_next_line()` function should let
you read the text file pointed to by the file descriptor, one line at a time.

Your function should return the line that was read.
If there is nothing else to read or if an error occurred, it should return `NULL`.

Make sure that your function works as expected both when reading a file and when
reading from the standard input.

Please note that the returned line should include the terminating `\n` character,
except if the end of file was reached and does not end with a `\n` character.

Your header file `get_next_line.h` must at least contain the prototype of the
`get_next_line()` function.

Add all the helper functions you need in the `get_next_line_utils.c` file.

Because you will have to read files in get_next_line(), add this option to your
compiler call: `-D BUFFER_SIZE=n`
It will define the buffer size for `read()`.
The buffer size value will be modified by your peer-evaluators and the Moulinette
in order to test your code.

You will compile your code as follows (a buffer size of 42 is used as an example):
`cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 <files>.c`

We consider that `get_next_line()` has an undefined behavior if the file pointed to
by the file descriptor changed since the last call whereas `read()` didn’t reach the
end of file.

We also consider that `get_next_line()` has an undefined behavior when reading
a binary file. However, you can implement a logical way to handle this behavior if
you want to.

## Tests for project:
+ [Test 1](https://github.com/Mazoise/42TESTERS-GNL)
+ [Test 2](https://github.com/charMstr/GNL_lover/blob/master/README.md)
+ [Test 3](https://github.com/C4r4c0l3/gnl-war-machine-v2019)
+ [Test 4](http://phoenix.yizimg.com/harm-smits/gnl-unit-test)
+ [Test 5](https://github.com/Tripouille/gnlTester)
