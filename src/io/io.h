// Header guard to prevent multiple inclusions.
// #ifndef IO_H
// #define IO_H

// --- I/O Port Functions ---

// Reads a single byte from the specified I/O port.
// This is a wrapper for the assembly `in` instruction.
// - port: The I/O port address to read from.
// - returns: The byte read from the port.
// unsigned char insb(unsigned short port);

// Reads a 16-bit word from the specified I/O port.
// - port: The I/O port address to read from.
// - returns: The word read from the port.
// unsigned short insw(unsigned short port);

// Writes a single byte to the specified I/O port.
// This is a wrapper for the assembly `out` instruction.
// - port: The I/O port address to write to.
// - val: The byte value to write.
// void outb(unsigned short port, unsigned char val);

// Writes a 16-bit word to the specified I/O port.
// - port: The I/O port address to write to.
// - val: The word value to write.
// void outw(unsigned short port, unsigned short val);

// End of header guard.
// #endif