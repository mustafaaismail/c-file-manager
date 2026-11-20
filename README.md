
# C File Manager

A lightweight command-line file manager written in C.

Create, delete, read, write, list, and search files directly from your terminal.

![Language: C](https://img.shields.io/badge/Language-C-blue)
![Version: v0.1.0](https://img.shields.io/badge/Version-v0.1.0-green)
![Status: In Development](https://img.shields.io/badge/Status-In%20Development-orange)

---

## Overview

**C File Manager** is a command-line application developed in C to perform basic file and directory operations.

The project uses a modular structure, separating function declarations, implementations, and application logic.

It is an ongoing learning project focused on improving C programming skills, file handling, and software development practices.

## Features

- **File Creation** – Create new files.
- **File Deletion** – Delete existing files.
- **File Writing** – Append content to files.
- **File Reading** – Display file contents.
- **Directory Listing** – List files and directories.
- **Keyword Search** – Search for keywords inside text files.
- **Error Codes** – Use enumerated error codes to represent operation results.
- **Modular Architecture** – Separate header and source files.

## Project Structure

```text
c-file-manager/
│
├── include/
│   ├── error_codes.h
│   └── file_ops.h
│
├── src/
│   ├── main.c
│   └── file_ops.c
│
├── logs/
│
├── .gitignore
└── README.md
```

## Requirements

- GCC compiler
- C development environment

## Installation

Clone the repository:

```bash
git clone https://github.com/mustafaaismail/c-file-manager.git
cd c-file-manager
```

## Build

Compile the source files from the project root directory.

**Windows:**

```bash
gcc src/main.c src/file_ops.c -o file-manager.exe
```

**Linux / macOS:**

```bash
gcc src/main.c src/file_ops.c -o file-manager
```

## Usage

Run the application:

**Windows:**

```bash
./file-manager.exe
```

**Linux / macOS:**

```bash
./file-manager
```

### Available Commands

| Command                   | Description                        |
| ------------------------- | ---------------------------------- |
| `create filename`         | Create a new file                  |
| `delete filename`         | Delete a file                      |
| `write filename content`  | Append content to a file           |
| `read filename`           | Display file contents              |
| `list [path]`             | List directory contents            |
| `search filename keyword` | Search for a keyword inside a file |
| `exit`                    | Exit the application               |

## Development Roadmap

| Version | Planned Features | Status |
|---|---|---|
| v0.1.0 | Basic file operations and keyword search | Completed |
| v0.2.0 | Logger system | Planned |
| v0.3.0 | Improved error handling | Planned |
| v0.4.0 | Makefile and build automation | Planned |
| v1.0.0 | First complete release | Planned |

## Contributing

This project is currently under development.

Suggestions, bug reports, and contributions are welcome.

## License

No license has been selected yet.
