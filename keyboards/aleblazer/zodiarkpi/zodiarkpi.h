#ifndef ZODIARKPI_H
#define ZODIARKPI_H

// Define the layout modes
typedef enum {
    KB_MODE0,
    KB_MODE1,
    KB_MODE2,
    KB_MODE3
} kb_mode_t;

// Declare the current layout mode and image variables
extern kb_mode_t current_layout_mode;
extern const char* current_image;

// Function to set the layout mode
void set_layout_mode(kb_mode_t mode);

#endif // ZODIARKPI_H
