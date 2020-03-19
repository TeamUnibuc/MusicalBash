# ConsoleManipulation

### Static class used to display stuff on the terminal.

## Available methods:

```c++
/// prints a character at a given location in the terminal
void WriteCharAt(char what, int poz_x, int poz_y);

/// prints a string at a given location
void WriteStringAt(string what, int poz_x, int poz_y);

/// returns curent dimensions of the terminal
pair <int, int> getConsoleDimensions();

/// sets curent dimensions of the terminal
void setConsoleDimensions(int dim_x, int dim_y);
```
