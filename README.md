# Secret Messages Project [September 2024]

Welcome to the **Secret Messages Project**, a simple yet intriguing way to communicate hidden messages using a book or text as a shared key. This project is written in C and dives into file handling, array manipulation, and efficient data processing. It serves as a fantastic opportunity to learn and practice fundamental concepts of C programming, especially when it comes to file I/O and character-level data handling.

## Overview

The core idea behind this project is to encode and decode secret messages using a text as a key, like a classic book cipher. By selecting a text (e.g., *A Tale of Two Cities* from Project Gutenberg) and using specific lines and characters, two individuals can create and decipher coded messages.

## Features

- **Decode Secret Messages**: Given a code file, the program extracts hidden chunks of text from a provided key file and outputs the decoded message.
- **Encode Secret Messages**: Using a fixed chunk size, the program generates a code file from a given message and text key. This allows easy reconstruction of the message when decoded.
- **Simple and Efficient**: The programs are designed to read and process text files line-by-line, ensuring efficient memory usage and straightforward data handling.

## Project Structure

- **decode.c**: The main program to decode messages. It reads a code file and extracts the corresponding characters from the text key, printing the resulting message.
- **encode.c**: The main program to encode messages. It reads a text key and outputs a code file that can later be used to decode the original message.
- **testing/**: Contains test files and scenarios to validate the programs. Each test is small and manageable, making it easy to spot errors or confirm successful decoding/encoding.
- **testing.txt**: A comprehensive guide to the test cases, explaining the rationale, expected outcomes, and command-line examples.

## How It Works

### Decoding

- Run `./decode <text_file> <code_file>`.
- The program reads and processes the code file line-by-line.
- Each line in the code file specifies which characters to extract from the text key. It outputs the decoded message or errors if the code file is invalid.

### Encoding

- Run `./encode <chunk_size> <text_file> "<message>"`.
- The program encodes the given message into a code file, ensuring that chunks are found in the text key without spanning multiple lines.
- It handles cases where the chunk size is fixed, providing an efficient and straightforward encoding method.

## Constraints & Requirements

- No use of string functions like `strlen` or `memcpy` for decoding.
- Use of `fgets` for reading text files and `strtol` for parsing integers.
- The programs process data as it is read, ensuring low memory usage and efficient handling of large text files.
- Both programs print error messages to `stderr` if any issues are encountered, exiting with a status of 1.

## Example Use Case

Suppose you want to send a secret message "think" using a text key. You’d prepare a code file specifying which characters to extract. The `decode` program reads the text file and extracts "th," "in," and "k" to reveal the message. Conversely, the `encode` program can turn a given message into a new code file, ready to be shared and later decoded by your trusted recipient.

## Testing

To ensure reliability, a set of test cases is included:

1. **Decoding Tests**: Three scenarios with expected outputs to validate character extraction.
2. **Encoding Tests**: Three scenarios to ensure messages are encoded correctly and chunk constraints are met.

## Getting Started

1. Clone the repository and navigate to the project directory.
2. Add your text key and code files to the appropriate directory.
3. Compile the programs using `gcc decode.c -o decode` and `gcc encode.c -o encode`.
4. Run your tests using the provided examples or create your own.

## What's Next?

Experiment with different texts, code files, and messages to see how flexible and fun secret messaging can be. Feel free to expand the project or integrate it into your own applications!

---

This project was a delightful challenge and an excellent way to deepen my understanding of C programming. I hope you find it as engaging and educational as I did! Feel free to contribute, share feedback, or ask questions—I'm always open to improvements and learning together.
