#ifndef __ERRORS_HPP__
#define __ERRORS_HPP__

#include <QMessageBox>

enum errors
{
    OK,
    NO_MODEL,
    FILE_ERR,
    ALLOC_ERR,
    READ_ERR,
    LSIZE_ERR,
    PSIZE_ERR,
    MEMORY_ERR,
    UNKNOWN_COMMAND
};

using err_t = enum errors;

void handle_error(const err_t &code);

#endif // __ERRORS_HPP__
