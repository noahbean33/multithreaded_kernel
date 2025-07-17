/**
 * @file start.c
 * @brief This is the entry point for all user-space C programs.
 *        It retrieves process arguments and calls the application's main function.
 */

// // Include the PeachOS system call interface.
// #include "peachos.h"

// // Declare the external main function, which is the entry point of the user application.
// extern int main(int argc, char** argv);

// // The C entry point function, called by the assembly startup code.
// void c_start()
// {
//     // Define a structure to hold the process arguments.
//     // struct process_arguments arguments;

//     // Make a system call to get the arguments for the current process.
//     // peachos_process_get_arguments(&arguments);

//     // Call the application's main function with the retrieved arguments.
//     // int return_code = main(arguments.argc, arguments.argv);

//     // After main returns, exit the process.
//     // peachos_exit();
// }