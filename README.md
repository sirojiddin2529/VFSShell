# VFSShell

VFSShell is a simple command-line program that simulates a virtual file system shell. It allows users to navigate a tree-structured directory, create files and directories, and perform basic file system operations.

## Features

- **File and Directory Management**
  - Create files with the `touch` command.
  - Create directories with the `mkdir` command.
- **Navigation**
  - Enter directories with the `enter` command.
  - Go back to the parent directory with the `back` command.
  - Display the current path with the `pwd` command.
- **Listing and Searching**
  - List files and directories in the current directory with the `ls` command.
  - Search for a file or directory by name with the `find` command.
- **Tree View**
  - Display the directory structure recursively with the `tree` functionality (part of the `print_tree` function).
- **Exit**
  - Exit the shell with the `exit` command.

## How It Works

VFSShell uses a tree data structure to simulate the file system:

- Each directory or file is represented as a `Node` structure.
- Nodes have a name, type (file or directory), and pointers to their parent, child, and sibling nodes.
- The root directory is initialized as "root," and all operations are performed relative to it.

## Commands

| Command      | Description                                      |
|--------------|--------------------------------------------------|
| `pwd`        | Print the full path of the current directory.    |
| `ls`         | List all files and directories in the current directory. |
| `touch <name>` | Create a new file in the current directory.     |
| `mkdir <name>` | Create a new directory in the current directory.|
| `enter <name>` | Enter a specified directory.                   |
| `back`       | Go back to the parent directory.                |
| `find <name>` | Search for a file or directory by name.         |
| `exit`       | Exit the shell.                                 |

## Usage

1. Compile the program using a C compiler:

   ```bash
   gcc vfsshell.c -o vfsshell
   ```

2. Run the compiled program:

   ```bash
   ./vfsshell
   ```

3. Use the commands listed above to navigate and manage the virtual file system.

## Example

```bash
➜ root mkdir docs
➜ root enter docs
➜ docs touch file1.txt
➜ docs mkdir images
➜ docs enter images
➜ images pwd
root/docs/images/
➜ images back
➜ docs ls
file1.txt
images/
➜ docs find file1.txt
root/docs/file1.txt/
➜ docs exit
```

## Code Overview

### Key Functions

- `init()`: Initializes the root directory.
- `create_node()`: Creates a new node (file or directory).
- `insert_node()`: Inserts a node as a child or sibling of the current directory.
- `search_node()`: Searches for a child node by name.
- `print_tree()`: Recursively prints the directory tree.
- `find()`: Searches for a node in the entire file system and prints its path.

### Data Structure

```c
typedef struct Node {
    char name[50];
    int is_file;
    struct Node *next;
    struct Node *child;
    struct Node *parent;
} Node;
```

## Future Improvements

- Add support for deleting files and directories.
- Implement permissions and file size attributes.
- Add command history and tab-completion for commands.
- Improve memory management to handle dynamic input sizes.

## License

This project is released under the MIT License.

---

Happy coding with VFSShell!
