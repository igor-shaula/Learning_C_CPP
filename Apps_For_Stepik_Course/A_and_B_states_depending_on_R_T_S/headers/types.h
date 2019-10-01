#ifndef TYPES_H
#define TYPES_H

#define ui unsigned int

#define FALSE 0
#define TRUE 1
#define BOOL ui

#define DIMENSION 2 * 2 * 2 // 2 variants for each of R, S & T booleans

typedef struct
{
    BOOL r, s, t;
} RST;

// typedef enum
// {
//      false,
//      true
// } bool;

typedef struct
{
    BOOL a, b;
} AB;

#endif