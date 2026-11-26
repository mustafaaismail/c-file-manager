
# C File Manager

A lightweight command-line file manager written in C.

Create, delete, read, write, list, and search files directly from your terminal.

![Language: C](https://img.shields.io/badge/Language-C-blue)
![Version: v0.2.0](https://img.shields.io/badge/Version-v0.2.0-green)
![Status: In Development](https://img.shields.io/badge/Status-In%20Development-orange)

---

## Overview

**C File Manager** is a command-line application developed in C to perform basic file and directory operations.

The project uses a modular structure, separating function declarations, implementations, and application logic.

It is an ongoing learning project focused on improving C programming skills, file handling, and software development practices.

The application includes a modular logging system that records file operations, errors, and application events with timestamps and log levels.

## Features

- **File Creation** – Create new files.
- **File Deletion** – Delete existing files.
- **File Writing** – Append content to files.
- **File Reading** – Display file contents.
- **Directory Listing** – List files and directories.
- **Keyword Search** – Search for keywords inside text files.
- **Error Codes** – Use enumerated error codes to represent operation results.
- **Modular Architecture** – Separate header and source files.
- **Logging System** – Record file operations, errors, and application events.
- **Log Levels** – Support INFO and ERROR severity levels.
- **Timestamps** – Add date and time information to each log entry.
- **Detailed Log Messages** – Include filenames, directory paths, and search keywords.

## Project Structure

```text
c-file-manager/
│
├── include/
│   ├── error_codes.h
│   ├── file_ops.h
│   └── logger.h
│
├── src/
│   ├── main.c
│   ├── file_ops.c
│   └── logger.c
│
├── logs/
│   └── .gitkeep
│
├── .gitignore
└── README.md
```

## Requirements

- GCC compiler
- C development environment
- Support for the `dirent.h` header

## Installation

Clone the repository:

```bash
git clone https://github.com/mustafaaismail/c-file-manager.git
cd c-file-manager
```

## Build

Compile all source files from the project root directory.

**Windows:**

```bash
gcc -Wall -Wextra src/main.c src/file_ops.c src/logger.c -o file-manager.exe
```

**Linux / macOS:**

```bash
gcc -Wall -Wextra src/main.c src/file_ops.c src/logger.c -o file-manager
```

## Usage

Run the application from the project root directory.

**Windows (PowerShell):**

```powershell
.\file-manager.exe
```

**Linux / macOS:**

```bash
./file-manager
```

### Available Commands

| Command | Description |
|---|---|
| `create filename` | Create a new file or truncate an existing file |
| `delete filename` | Delete a file |
| `write filename content` | Append content to a file |
| `read filename` | Display file contents |
| `list [path]` | List directory contents |
| `search filename keyword` | Search for a keyword inside a file |
| `exit` | Exit the application |

### Example Usage

```text
file-manager> create test.txt
File created successfully

file-manager> write test.txt Hello World
Content written successfully

file-manager> read test.txt
Hello World
File read successfully

file-manager> search test.txt Hello

file-manager> list

file-manager> delete test.txt
File deleted successfully

file-manager> exit
```

## Logging System

The application includes a modular logging system that records application events, file operations, and errors.

Log entries are automatically stored in:

```text
logs/system.log
```

The application must be executed from the project root directory, and the `logs/` directory must exist.

### Log Levels

| Level | Description |
|---|---|
| INFO | Successful operations and application events |
| ERROR | Failed operations and missing required parameters |

### Log Format

```text
[YYYY-MM-DD HH:MM:SS] [LEVEL] Message
```

### Example Log Output

```text
[2026-11-26 20:30:00] [INFO] Program started
[2026-11-26 20:30:05] [INFO] File created successfully: test.txt
[2026-11-26 20:30:10] [INFO] Content written successfully: test.txt
[2026-11-26 20:30:15] [INFO] File read successfully: test.txt
[2026-11-26 20:30:20] [INFO] Search completed successfully: 'test.txt' for keyword 'Hello'
[2026-11-26 20:30:25] [INFO] Directory listed successfully: .
[2026-11-26 20:30:30] [INFO] File deleted successfully: test.txt
[2026-11-26 20:30:35] [ERROR] Failed to delete file: missing.txt
[2026-11-26 20:30:40] [ERROR] No filename specified
[2026-11-26 20:30:45] [INFO] Program terminated
```

### Log Management

- Log entries are appended to the log file, preserving previous records.
- Each log entry includes a timestamp and severity level.
- Generated log files are excluded from version control.
- The `.gitkeep` file preserves the `logs/` directory in the repository.

## Development Roadmap

| Version | Planned Features | Status |
|---|---|---|
| v0.1.0 | Basic file operations and keyword search | Completed |
| v0.2.0 | Logger system | Completed |
| v0.3.0 | Improved error handling | Planned |
| v0.4.0 | Makefile and build automation | Planned |
| v1.0.0 | First complete release | Planned |

## Contributing

This project is currently under development.

Suggestions, bug reports, and contributions are welcome.

## License

No license has been selected yet.
