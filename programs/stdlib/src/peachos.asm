; Use 32-bit assembly syntax.
; [BITS 32]

; Define the code section.
; section .asm

; Export symbols to be linked with C code.
; global print:function
; global peachos_getkey:function
; global peachos_malloc:function
; global peachos_free:function
; global peachos_putchar:function
; global peachos_process_load_start:function
; global peachos_process_get_arguments:function
; global peachos_system:function
; global peachos_exit:function

; System call wrapper for printing a string.
; Arguments: const char* message
; print:
    ; // Standard function prologue.
    ; // Set up stack frame.

    ; // Push the message pointer argument onto the stack.
    ; // Set EAX to 1 (system call number for 'print').
    ; // Trigger software interrupt 0x80 to enter kernel mode.

    ; // Clean up the stack.
    ; // Standard function epilogue.
    ; // Return to caller.

; System call wrapper for getting a key from the keyboard.
; Arguments: None
; Returns: The character code of the key pressed.
; peachos_getkey:
    ; // Standard function prologue.

    ; // Set EAX to 2 (system call number for 'getkey').
    ; // Trigger software interrupt 0x80.
    ; // The result (key code) is returned in EAX.

    ; // Standard function epilogue.
    ; // Return to caller.

; System call wrapper for printing a single character.
; Arguments: char c
; peachos_putchar:
    ; // Standard function prologue.

    ; // Push the character argument onto the stack.
    ; // Set EAX to 3 (system call number for 'putchar').
    ; // Trigger software interrupt 0x80.

    ; // Clean up the stack and return.

; System call wrapper for allocating memory.
; Arguments: size_t size
; Returns: A pointer to the allocated memory.
; peachos_malloc:
    ; // Standard function prologue.

    ; // Push the size argument onto the stack.
    ; // Set EAX to 4 (system call number for 'malloc').
    ; // Trigger software interrupt 0x80.
    ; // The result (pointer) is returned in EAX.

    ; // Clean up the stack and return.

; System call wrapper for freeing allocated memory.
; Arguments: void* ptr
; peachos_free:
    ; // Standard function prologue.

    ; // Push the pointer argument onto the stack.
    ; // Set EAX to 5 (system call number for 'free').
    ; // Trigger software interrupt 0x80.

    ; // Clean up the stack and return.

; System call wrapper for loading and starting a new process.
; Arguments: const char* filename
; peachos_process_load_start:
    ; // Standard function prologue.

    ; // Push the filename argument onto the stack.
    ; // Set EAX to 6 (system call number for 'process_load_start').
    ; // Trigger software interrupt 0x80.

    ; // Clean up the stack and return.

; System call wrapper for executing a system command.
; Arguments: struct command_argument* arguments
; Returns: The result of the command.
; peachos_system:
    ; // Standard function prologue.

    ; // Push the arguments pointer onto the stack.
    ; // Set EAX to 7 (system call number for 'system').
    ; // Trigger software interrupt 0x80.
    ; // The result is returned in EAX.

    ; // Clean up the stack and return.

; System call wrapper for getting process arguments.
; Arguments: struct process_arguments* arguments
; peachos_process_get_arguments:
    ; // Standard function prologue.

    ; // Push the arguments pointer onto the stack.
    ; // Set EAX to 8 (system call number for 'get_arguments').
    ; // Trigger software interrupt 0x80.

    ; // Clean up the stack and return.

; System call wrapper for exiting the current process.
; Arguments: None
; peachos_exit:
    ; // Standard function prologue.

    ; // Set EAX to 9 (system call number for 'exit').
    ; // Trigger software interrupt 0x80 to terminate the process.

    ; // This part is unreachable if the exit is successful.
    ; // Standard function epilogue.
    ; // Return to caller.