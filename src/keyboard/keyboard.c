/**
 * @file keyboard.c
 * @brief Implements the core keyboard subsystem, managing drivers and input buffers.
 */

// --- Static Globals ---

// The head of the linked list of registered keyboard drivers.
static struct keyboard* keyboard_list_head = 0;

// The last element in the linked list of keyboard drivers.
static struct keyboard* keyboard_list_last = 0;

// --- Public Functions ---

// Initializes the entire keyboard subsystem.
void keyboard_init()
{
    // Initialize and insert the classic PS/2 keyboard driver.
    keyboard_insert(classic_init());
}

// Inserts a new keyboard driver into the linked list and initializes it.
int keyboard_insert(struct keyboard* keyboard)
{
    // Check if the provided keyboard has a valid init function.
    // If not, return an error.
    int res = 0;
    if (keyboard->init == 0)
    {
        res = -EINVARG;
        goto out;
    }

    // If the list is not empty, append the new keyboard to the end.
    if (keyboard_list_last)
    {
        keyboard_list_last->next = keyboard;
        keyboard_list_last = keyboard;
    }
    // Else (the list is empty).
    else
    {
        keyboard_list_head = keyboard;
        keyboard_list_last = keyboard;
    }

    // Call the driver's specific init function.
    res = keyboard->init();
out:
    return res;
}

// Calculates the circular buffer index for the tail (write position).
static int keyboard_get_tail_index(struct process* process)
{
    // Return `process->keyboard.tail % size_of_buffer`.
    return process->keyboard.tail % sizeof(process->keyboard.buffer);
}

// Handles a backspace by moving the tail pointer back and clearing the character.
void keyboard_backspace(struct process* process)
{
    // Decrement the process's keyboard buffer tail pointer.
    process->keyboard.tail -= 1;
    // Calculate the real index in the circular buffer.
    int real_index = keyboard_get_tail_index(process);
    // Set the character at that index to null.
    process->keyboard.buffer[real_index] = 0x00;
}

// Sets the caps lock state for a given keyboard driver.
void keyboard_set_capslock(struct keyboard* keyboard, KEYBOARD_CAPS_LOCK_STATE state)
{
    keyboard->capslock_state = state;
}

// Retrieves the caps lock state for a given keyboard driver.
KEYBOARD_CAPS_LOCK_STATE keyboard_get_capslock(struct keyboard* keyboard)
{
    return keyboard->capslock_state;
}

// Pushes a character into the current process's keyboard buffer.
void keyboard_push(char c)
{
    // Get the currently running process.
    struct process* process = process_current();
    if (!process)
    {
        return;
    }

    // If the character is null, return.
    if (c == 0)
    {
        return;
    }

    // Calculate the real index for the tail (write position) in the circular buffer.
    int real_index = keyboard_get_tail_index(process);
    // Place the character `c` at that index.
    process->keyboard.buffer[real_index] = c;
    // Increment the tail pointer.
    process->keyboard.tail++;
}

// Pops a character from the current process's keyboard buffer.
char keyboard_pop()
{
    // If there is no current task, return 0.
    if (!task_current())
    {
        return 0;
    }

    // Get the current process from the current task.
    struct process* process = task_current()->process;
    // Calculate the real index for the head (read position) in the circular buffer.
    int real_index = process->keyboard.head % sizeof(process->keyboard.buffer);
    // Get the character `c` from that index.
    char c = process->keyboard.buffer[real_index];

    // If `c` is null, there is nothing to pop, so return 0.
    if (c == 0x00)
    {
        return 0;
    }

    // Clear the character at the read position in the buffer.
    process->keyboard.buffer[real_index] = 0;
    // Increment the head pointer.
    process->keyboard.head++;
    // Return the character `c`.
    return c;
}