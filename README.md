# Lab 6 - Vector Calculator

## Description

This program is a vector calculator written in C. It allows users to create, store, and perform mathematical operations on 3D vectors.

Users can also save their vectors to a `.csv` file and load previously saved vectors.

## Building and Running

The program is compiled using a Makefile.

**Compile the program:**
```bash
make
```

**Run the program:**
```bash
./lab5
```

## Available Commands

| Command | Description |
|---|---|
| `a = x, y, z` | Creates a vector named `a` with the given coordinates |
| `c = a + b` | Adds vectors `a` and `b`, storing the result in `c` |
| `c = a - b` | Subtracts vector `b` from vector `a` |
| `d = b * x` | Multiplies vector `b` by scalar `x` |
| `list` | Displays all currently stored vectors |
| `clear` | Clears the vector list |
| `load<filename>` | Loads vectors from a CSV file |
| `save<filename>` | Saves vectors to a CSV file |
| `quit` | Exits the program |

## Example Usage

```text
a = 1, 2, 3
b = 4, 5, 6
c = a + b
d = b * 2
list
save<vectors.csv>
quit
```

## Dynamic Memory Allocation

The program uses dynamic memory allocation to manage its array of vectors.

- The array initially has space for **10 vectors**.
- When the array reaches its capacity, additional memory is allocated.
- This allows the program to store more vectors without requiring a fixed maximum array size.

## File Storage

Vectors can be saved to and loaded from `.csv` files, allowing users to preserve their data between program executions.