# Monty

Monty is a bytecode interpreter implemented in C. It reads and executes bytecode files containing Monty bytecodes.

## Table of Contents

- [Introduction](#introduction)
- [Usage](#usage)
- [Bytecode Instructions](#bytecode-instructions)
- [File Structure](#file-structure)
- [Code Structure](#code-structure)
- [Memory Management](#memory-management)
- [Error Handling](#error-handling)
- [Examples](#examples)
- [Testing](#testing)
- [Contributing](#contributing)
- [License](#license)

## Introduction

Monty is a programming language that uses stack-based memory management. The Monty interpreter reads bytecode instructions from a file and executes them accordingly. It supports various stack operations such as push, pop, swap, arithmetic operations, and more.

Monty was created as a project for ALX SE program to learn about interpreters, stacks, queues concepts.

## Usage

To use the Monty interpreter:

1. clone the repo

   ```bash
   git clone https://github.com/mohamedtharwat000/monty.git
   cd monty
   ```

2. Compile the source code:

   ```
   gcc -Wall -Wextra -Werror -pedantic -std=c89 -o monty source_code_files.c
   ```

3. Run the interpreter on a Monty bytecode file:

   ```
   $ ./monty <file_name>
   ```

The interpreter prints the results of running the bytecode program to `stdout`.

## Bytecode Instructions

Monty supports the following instructions:

- `push <value>`: Pushes an element to the stack
- `pall`: Prints all values on the stack
- `pint`: Prints the value at the top of the stack
- `pop`: Removes the top element of the stack
- `swap`: Swaps the top two elements of the stack
- `nop`: No operation
- `add`: Adds the top two elements of the stack
- `sub`: Subtracts the top element from the second top element
- `div`: Divides the second top element by the top element
- `mul`: Multiplies the top two elements of the stack
- `mod`: Computes the modulus of the second top element divided by the top element

The interpreter expects one instruction per line in the bytecode file. Blank lines and lines starting with `#` are ignored.

## File Structure

The core Monty files are:

- **monty.c**: Main program entry point, instruction execution loop
- **monty.h**: Header file with function prototypes, structs

The stack functions are implemented in:

- `stack_*.c` files like `stack_push.c`

Utility functions are in:

- `helper_*.c` files

## Code Structure

Key components of the code base:

- **Stack data structure**: Linked list based stack to hold program data
- **Instruction execution**: Loop to read and process opcode commands
- **Memory management**: Custom functions for managing stack memory
- **Error handling**: Checks for common errors like invalid opcodes

The code is structured into modules based on functionality.

## Memory Management

Memory is allocated for the stack when the program starts. Each `push` allocates a new node. The stack is freed before the program exits using a custom `stack_free` function.

Values are stored in the stack nodes as `void *` data.

## Error Handling

The interpreter checks for common errors such as:

- Invalid opcode name
- Missing opcode argument
- Invalid argument type
- Stack overflow
- Stack underflow

On any error, it prints an error message and exits cleanly using `clean_exit`.

## Contributing

Contributions are welcome! Here are some ways you can contribute to this project:

- Report bugs and issues by creating a new GitHub issue.
- Fix bugs and issues by submitting pull requests.
- Add new validation functionality to enhance the form's capabilities.
- Improve styling and overall user experience.
- Refactor code to improve code quality and maintainability.
- Write documentation and improve existing docs to help others understand the project.

To contribute:

1. Fork the repository.
2. Create a new branch for your feature or bug fix.
3. Make your changes and commit them.
4. Push your branch to your forked repository.
5. Submit a pull request, describing your changes in detail.

I will review pull requests and provide feedback.

## License

This project is open source and available under the [MIT License](LICENSE).

## Credits

Created by [Mohamed Tharwat](https://github.com/mohamedtharwat000). Feel free to reach out with any questions or feedback.
