#ifndef GENERAL_TYPES_H
#define GENERAL_TYPES_H

/* =================================================
*  Define variable types
*  ================================================= */

#define C_NULL        (null)

#define C_TRUE        (true)
#define C_FALSE       (false)

typedef bool           t_bool;
typedef char           t_int8;
typedef unsigned char  t_int8u;
typedef int            t_int32;
typedef unsigned int   t_int32u;

typedef enum t_error {
    E_OK  = 0,
    E_NOK = 0
};


#endif /* GENERAL_TYPES_H */