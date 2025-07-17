// Include headers for PeachOS and string manipulation.
// #include "peachos.h"
// #include "string.h"

// Parses a command string into a linked list of arguments.
// command: The command string to parse.
// max: The maximum length of the command string.
// Returns a pointer to the first argument in the linked list.
// struct command_argument* peachos_parse_command(const char* command, int max)
// {
    // // Initialize the root of the argument list to null.
    // struct command_argument* root_command = 0;

    // // Create a buffer to hold a copy of the command string.
    // char scommand[1025];

    // // Check if the command is too long for the buffer.
    // if (max >= (int) sizeof(scommand))
    // {
        // return 0;
    // }

    // // Copy the command string to the buffer.
    // strncpy(scommand, command, sizeof(scommand));

    // // Tokenize the string by spaces.
    // char* token = strtok(scommand, " ");
    // if (!token)
    // {
        // goto out;
    // }

    // // Allocate memory for the root argument.
    // root_command = peachos_malloc(sizeof(struct command_argument));
    // if (!root_command)
    // {
        // goto out;
    // }

    // // Copy the first token to the root argument.
    // strncpy(root_command->argument, token, sizeof(root_command->argument));
    // root_command->next = 0;

    // // Set the current argument to the root.
    // struct command_argument* current = root_command;

    // // Continue tokenizing the rest of the string.
    // token = strtok(NULL, " ");
    // while(token != 0)
    // {
        // // Allocate memory for the next argument.
        // struct command_argument* new_command = peachos_malloc(sizeof(struct command_argument));
        // if (!new_command)
        // {
            // break;
        // }

        // // Copy the token to the new argument.
        // strncpy(new_command->argument, token, sizeof(new_command->argument));
        // new_command->next = 0x00;

        // // Link the new argument to the list.
        // current->next = new_command;
        // current = new_command;

        // // Get the next token.
        // token = strtok(NULL, " ");
    // }

// out:
    // // Return the root of the argument list.
    // return root_command;
// }

// Blocks until a key is pressed and returns it.
// int peachos_getkeyblock()
// {
    // int val = 0;
    // // Loop until a key is pressed.
    // do
    // {
        // val = peachos_getkey();
    // }
    // while(val == 0);
    // return val;
// }

// Reads a line from the terminal.
// out: The buffer to store the line.
// max: The maximum number of characters to read.
// output_while_typing: If true, echo characters to the screen.
// void peachos_terminal_readline(char* out, int max, bool output_while_typing)
// {
    // int i = 0;
    // // Loop until the buffer is full or enter is pressed.
    // for (i = 0; i < max -1; i++)
    // {
        // char key = peachos_getkeyblock();

        // // If enter is pressed, break the loop.
        // if (key == 13) // ASCII for carriage return
        // {
            // break;
        // }

        // // Echo the character if enabled.
        // if (output_while_typing)
        // {
            // peachos_putchar(key);
        // }

        // // Handle backspace.
        // if (key == 0x08 && i >= 1)
        // {
            // out[i-1] = 0x00;
            // i -= 2; // Decrement i to overwrite the character.
            // continue;
        // }

        // // Store the character in the buffer.
        // out[i] = key;
    // }

    // // Add a null terminator to the string.
    // out[i] = 0x00;
// }

// Runs a system command.
// command: The command string to execute.
// int peachos_system_run(const char* command)
// {
    // char buf[1024];
    // strncpy(buf, command, sizeof(buf));

    // // Parse the command string into arguments.
    // struct command_argument* root_command_argument = peachos_parse_command(buf, sizeof(buf));
    // if (!root_command_argument)
    // {
        // // If parsing fails, return an error.
        // return -1;
    // }

    // // Execute the parsed command via a system call.
    // return peachos_system(root_command_argument);
// }