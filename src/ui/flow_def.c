#include <eez/core/vars.h>

#include "flow_def.h"
#include "vars.h"

// ASSETS DEFINITION
const uint8_t assets[348] = {
    0x7E, 0x65, 0x65, 0x7A, 0x03, 0x00, 0x06, 0x00, 0xBC, 0x02, 0x00, 0x00, 0x6E, 0x24, 0x00, 0x00,
    0x00, 0x24, 0x00, 0x01, 0x00, 0x17, 0x20, 0x0C, 0x00, 0x53, 0x40, 0x01, 0xF0, 0x00, 0x01, 0x28,
    0x00, 0x13, 0x01, 0x1C, 0x00, 0x00, 0x08, 0x00, 0xA6, 0x1C, 0x00, 0x00, 0x00, 0x05, 0x00, 0x00,
    0x00, 0xF4, 0x01, 0x2C, 0x00, 0x13, 0x0C, 0x08, 0x00, 0x93, 0x10, 0x00, 0x00, 0x00, 0x34, 0x00,
    0x00, 0x00, 0x02, 0x08, 0x00, 0x00, 0x28, 0x00, 0x17, 0x30, 0x54, 0x00, 0x00, 0x33, 0x00, 0x2E,
    0xD0, 0x01, 0x78, 0x00, 0xD3, 0x64, 0x65, 0x66, 0x61, 0x75, 0x6C, 0x74, 0x00, 0xFF, 0xFF, 0x08,
    0x42, 0x14, 0x34, 0x00, 0x90, 0x4C, 0x00, 0x00, 0x00, 0x68, 0x00, 0x00, 0x00, 0x88, 0x58, 0x00,
    0x16, 0x27, 0x2C, 0x00, 0x53, 0x03, 0x00, 0x00, 0x00, 0x94, 0x4C, 0x00, 0x9B, 0x98, 0x00, 0x00,
    0x00, 0xFF, 0xFF, 0x00, 0x00, 0x11, 0x20, 0x00, 0x13, 0x84, 0x20, 0x00, 0x13, 0x88, 0x20, 0x00,
    0x22, 0x10, 0x27, 0x10, 0x00, 0x13, 0x7C, 0x20, 0x00, 0x26, 0x78, 0x00, 0x10, 0x00, 0x00, 0x20,
    0x00, 0x2A, 0xF3, 0x03, 0xA4, 0x00, 0x13, 0x68, 0xC4, 0x00, 0x13, 0x64, 0x20, 0x00, 0x5B, 0x04,
    0x00, 0x00, 0x00, 0xED, 0x24, 0x00, 0x13, 0x50, 0x24, 0x00, 0x13, 0x4C, 0x24, 0x00, 0x26, 0x4C,
    0x00, 0x04, 0x00, 0x00, 0x1C, 0x00, 0x1B, 0x58, 0x04, 0x00, 0x00, 0x01, 0x00, 0x17, 0x5C, 0x04,
    0x00, 0x13, 0x60, 0x68, 0x00, 0x00, 0x04, 0x00, 0x13, 0x70, 0x94, 0x00, 0x00, 0x04, 0x00, 0x10,
    0x80, 0x29, 0x00, 0x12, 0xE0, 0x04, 0x00, 0x10, 0x02, 0x27, 0x00, 0x39, 0xC0, 0x00, 0xE0, 0x2D,
    0x01, 0x03, 0x1C, 0x00, 0x2F, 0x00, 0x60, 0x18, 0x00, 0x03, 0x10, 0x03, 0xAB, 0x01, 0x0B, 0x34,
    0x00, 0x12, 0x04, 0x1E, 0x00, 0x05, 0xBC, 0x00, 0x04, 0xD8, 0x01, 0x01, 0x01, 0x00, 0x1E, 0x60,
    0x1C, 0x00, 0x04, 0xD0, 0x01, 0x13, 0x08, 0x04, 0x00, 0x13, 0x02, 0x04, 0x00, 0x13, 0x18, 0x38,
    0x00, 0x00, 0xA0, 0x01, 0x6F, 0x3C, 0x00, 0x00, 0x00, 0x48, 0x00, 0x01, 0x00, 0x03, 0x0C, 0xE3,
    0x01, 0x13, 0x0E, 0x08, 0x00, 0x1B, 0x28, 0x10, 0x00, 0x04, 0x84, 0x00, 0x1B, 0x02, 0x38, 0x00,
    0x71, 0x77, 0x64, 0x20, 0x76, 0x61, 0x72, 0x3A, 0x8F, 0x02, 0xF0, 0x01, 0x69, 0x6E, 0x70, 0x75,
    0x74, 0x20, 0x28, 0x77, 0x61, 0x74, 0x63, 0x68, 0x29, 0x3A, 0x20, 0x00
};

native_var_t native_vars[] = {
    { NATIVE_VAR_TYPE_NONE, 0, 0 },
    { NATIVE_VAR_TYPE_BOOLEAN, get_var_wd, set_var_wd }, 
};

