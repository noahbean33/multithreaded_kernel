// Header guard to prevent multiple inclusions.
// #ifndef PATHPARSER_H
// #define PATHPARSER_H

// --- Path Root Structure ---
// Represents the root of a parsed path, including the drive number.
// struct path_root
// {
    // The drive number (e.g., 0 for '0:').
    // int drive_no;
    // A pointer to the first part of the path (e.g., 'path' in '0:/path/to/file').
    // struct path_part* first;
// };

// --- Path Part Structure ---
// Represents a single component of a path, forming a linked list.
// struct path_part
// {
    // The name of this part of the path (e.g., 'path', 'to', 'file').
    // const char* part;
    // A pointer to the next part of the path.
    // struct path_part* next;
// };

// --- Path Parser Functions ---

// Parses a given path string (e.g., "0:/path/to/file.txt") into a `path_root` structure.
// It can also handle relative paths if `current_directory_path` is provided.
// struct path_root* pathparser_parse(const char* path, const char* current_directory_path);

// Frees the memory allocated for a `path_root` structure and all its `path_part` components.
// void pathparser_free(struct path_root* root);

// End of header guard.
// #endif