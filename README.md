# C_Projects

All my C practice and testing. This repo is under constuction, and many things must still change:
 - Combine scripts to create refresher/teacher programs.
 - Create another Repo for the best C projects for showcasing.

## Getting Started

This project is written in the C programming language. To run it, you will need to compile the source code on your local machine. This guide provides instructions for compiling on Windows, macOS, and Linux.

### Prerequisites

You will need a C compiler installed on your system.
* **Linux**: GCC is usually pre-installed. If not, you can get it via your distribution's package manager.
* **macOS**: Clang is included with the Xcode Command Line Tools.
* **Windows**: MinGW-w64 is a popular choice that provides a GCC compiler for Windows.

## How to Compile and Run

The process of compiling and running a C program differs slightly between operating systems. Below are the specific commands for each platform.

---

### 🍎 macOS and 🐧 Linux

On Unix-like systems such as macOS and Linux, you compile the code to create a binary executable file. You then run this file from the terminal.

1.  **Open your Terminal.**

2.  **Navigate to the project directory:**
    ```bash
    cd path/to/your/repo
    ```

3.  **Compile the code:**
    This command tells the compiler (`gcc` or `clang`) to take the source file (`your_source_file.c`) and create an output executable file (`-o my_program`).

    * Using `gcc` (common on Linux):
        ```bash
        gcc your_source_file.c -o my_program
        ```
    * Using `clang` (default on macOS):
        ```bash
        clang your_source_file.c -o my_program
        ```

4.  **Run the program:**
    The `./` tells the shell to look for `my_program` in the current directory.
    ```bash
    ./my_program
    ```

---

### 🪟 Windows

On Windows, the process is similar, but you will generate an `.exe` file, which can be run from the Command Prompt or PowerShell.

1.  **Open Command Prompt (cmd) or PowerShell.**

2.  **Navigate to the project directory:**
    ```powershell
    cd path\to\your\repo
    ```

3.  **Compile the code:**
    Assuming you have a compiler like MinGW-w64 installed and configured, this command will create `my_program.exe`.
    ```powershell
    gcc your_source_file.c -o my_program.exe
    ```

4.  **Run the program:**
    You can run the executable by simply typing its name.
    ```powershell
    my_program.exe
    ```
    *or just*
    ```powershell
    .\my_program.exe
    ```

---

## An Easier Way: Using a Makefile

For a more streamlined process, you can use the provided `Makefile`. The `make` tool automatically uses the correct compiler commands for your system.

### Step 1: Install `make`

* **Linux**: `make` is usually included with the `build-essential` package.
    ```bash
    sudo apt-get install build-essential # For Debian/Ubuntu
    ```
* **macOS**: `make` is included with the Xcode Command Line Tools.
* **Windows**: `make` is often included with MinGW-w64 or can be installed separately.

### Step 2: Compile with `make`

Once `make` is installed, just navigate to the project directory in your terminal and run:

```bash
make
```

This will automatically compile the source code and create the correct executable for your system (`my_program` on Linux/macOS and `my_program.exe` on Windows).

### Step 3: Run the program

* On macOS/Linux:
    ```bash
    ./my_program
    ```
* On Windows:
    ```powershell
    my_program.exe
    ```

### Optional: Cleaning up
To remove the compiled files, you can run:
```bash
make clean
```