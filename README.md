# Project3CS315
Project 3 of CS315
# Project 3 Part 1 - Huffman Coding Scanner

## Student Information
- **Name:** Emmanuel Torbor
- **SSU ID:** 008281371
- **GITRepository:**

## Collaboration & Sources
This project represents my own work with assistance for specific technical challenges.

**External Help Used:**
- Used AI assistance for debugging Scanner tokenization logic and understanding std::filesystem path handling and for readme file style.
- AI helped identify a bug in main.cpp where the Scanner constructor was receiving the output file path instead of the input file path. It is fixed now.
-
- All final implementation decisions and code structure are my own

**My Own Work:**
- Implementation of the readWord() tokenization logic
- Integration with the provided utility functions
- Error handling and program flow
- Testing and validation on sample inputs

## Implementation Details

### Design
The program follows a modular design with separate classes for scanning and utility functions:

- **Scanner Class:** Handles file tokenization with two overloaded tokenize() methods
- **Utils Module:** Provides file system operations and error handling
- **Main Program:** Coordinates the workflow and error checking

### Algorithms & Data Structures
- **Tokenization Algorithm:** Character-by-character scanning with state tracking
  - Reads input stream character by character
  - Builds tokens from consecutive letters and internal apostrophes
  - Converts all characters to lowercase
  - Uses peek() and putback() for lookahead and separator handling

- **Data Structures:**
  - `std::vector<std::string>` for storing tokens
  - `std::filesystem::path` for portable file path handling
  - Enum-based error system for consistent error reporting

### Key Features
- Implements exact tokenization rules: letters a-z with optional internal apostrophes only
- Handles edge cases: empty input, single tokens, punctuation, numbers, and hyphens
- Proper error handling for file operations
- Deterministic output matching project specifications

## Testing & Status

### What Works
- ✅ Complete tokenization according to project specifications
- ✅ Proper handling of all edge cases (apostrophes, punctuation, numbers)
- ✅ File I/O operations with error checking
- ✅ Command-line argument validation
- ✅ Output file generation in correct format (one token per line)

### What Does Not Work
- All required functionality for Part 1 is implemented and working

### How to Test
I already know you will be using the tests command lines you have but figured to add this anyway.
1. **Compile the program:**
   ```bash
   g++ -std=c++20 -Wall *.cpp -o p3_part1
