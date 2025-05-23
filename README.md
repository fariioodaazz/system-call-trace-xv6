# system-call-trace-xv6
xv6 Tracer Shell

A custom shell implementation for the xv6 operating system that enables tracing and logging of all system calls invoked by child processes. Inspired by tools like strace, this shell helps visualize syscall activity by printing detailed logs—including syscall name, arguments, and process ID—after each command execution.

🔧 Features

    Lightweight system call tracer for xv6

    Logs:

        Process ID

        Syscall name

        Argument values

    All logs are printed in the shell after process termination

📷 Example

pid 6: syscall exec
pid 6: syscall open
pid 6: syscall read
pid 6: syscall write
pid 6: syscall exit

📂 File Structure

Kernel changes:

    kernel/proc.h — 	Defined Traced Switch

    kernel/syscall.c — captures syscall arguments and logs them

    kernel/syscall.h — declares syscall numbers

    kernel/usys.S — syscall user wrapper

    kernel/trd - Add trd.c test for trace() syscall
    

User changes:

    user/user.h — exposes syscall API to user space

    Makefile — adds to UPROGS

🚀 Getting Started

Step 1: Clone and setup xv6

git clone https://github.com/mit-pdos/xv6-riscv
cd xv6-riscv

Step 2: Apply this project’s changes

Copy or merge the following files:

    user/tracersh.c → user/

    Modify syscall.c to log detailed trace messages

    Add syscall wrappers in usys.S and user.h

    Add traced buffer in proc.h

    Add to Makefile under UPROGS

Step 3: Build and run

make qemu
