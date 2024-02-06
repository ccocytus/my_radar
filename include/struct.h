/*
** EPITECH PROJECT, 2023
** struct.h
** File description:
** typedef
*/

#ifndef STRUCT_H_
    #define STRUCT_H_

typedef struct flag_s {
    char flag;
    int (*ptr_function)(va_list);
} flag_t;

#endif
