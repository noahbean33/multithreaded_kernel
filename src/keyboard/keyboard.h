/**
 * @file keyboard.h
 * @brief Defines the core structures and function prototypes for the keyboard driver system.
 * This file provides a generic interface for different keyboard drivers (e.g., classic PS/2).
 */

// --- Constants for Caps Lock State ---
// #define KEYBOARD_CAPS_LOCK_ON 1
// #define KEYBOARD_CAPS_LOCK_OFF 0

// --- Type Definitions ---

// Represents the state of the Caps Lock key.
// typedef int KEYBOARD_CAPS_LOCK_STATE;

// Forward declaration of the process struct, needed for the backspace function.
// struct process;

// A function pointer type for a keyboard driver's initialization routine.
// typedef int (*KEYBOARD_INIT_FUNCTION)();

// --- Structures ---

// Represents a generic keyboard driver.
// The kernel maintains a linked list of these structures to support multiple keyboard types.
// struct keyboard
// {
//     // A function pointer to the driver's specific initialization function.
//     KEYBOARD_INIT_FUNCTION init;
//
//     // The name of the keyboard driver (e.g., "Classic PS/2").
//     char name[20];
//
//     // The current state of the Caps Lock key for this keyboard.
//     KEYBOARD_CAPS_LOCK_STATE capslock_state;
//
//     // A pointer to the next keyboard driver in the linked list.
//     struct keyboard* next;
// };

// --- Public Function Prototypes ---

// Initializes the keyboard subsystem, including all registered keyboard drivers.
// void keyboard_init();

// Handles a backspace key press for a given process.
// void keyboard_backspace(struct process* process);

// Pushes a character into the global keyboard buffer.
// void keyboard_push(char c);

// Pops a character from the global keyboard buffer, blocking if it's empty.
// char keyboard_pop();

// Inserts (registers) a new keyboard driver into the system's linked list.
// int keyboard_insert(struct keyboard* keyboard);

// Sets the Caps Lock state for a specific keyboard driver.
// void keyboard_set_capslock(struct keyboard* keyboard, KEYBOARD_CAPS_LOCK_STATE state);

// Gets the current Caps Lock state for a specific keyboard driver.
// KEYBOARD_CAPS_LOCK_STATE keyboard_get_capslock(struct keyboard* keyboard);