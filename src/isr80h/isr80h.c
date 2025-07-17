// Include the main ISR80H header and headers for all sub-modules
// that provide system call handlers (e.g., misc, io, heap, process).

// This function is called once during kernel initialization to set up the
// system call dispatch table.
// void isr80h_register_commands()
// {
//     // For each system call, it calls the `isr80h_register_command` function
//     // from the IDT module. This function maps a command number (from the
//     // `SystemCommands` enum) to a specific handler function.

//     // Example: Register the handler for printing a string.
//     // isr80h_register_command(SYSTEM_COMMAND1_PRINT, isr80h_command1_print);

//     // ... and so on for all other system calls, including:
//     // - A test command (sum)
//     // - Keyboard input (getkey, putchar)
//     // - Heap memory management (malloc, free)
//     // - Process management (load/start process, get arguments, exit)
// }