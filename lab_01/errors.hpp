#ifndef ERRORS_HPP
#define ERRORS_HPP

#include <QMessageBox>

enum errors
{
    OK,
    NO_MODEL,
    FILE_ERR,
    ALLOC_ERR,
    READ_ERR,
    LINESN_ERR,
    LINEPTS_ERR,
    NONPOS_ERR,
    VERTECIESN_ERR,
    UNKNOWN_COMMAND
};

using err_t = enum errors;

void handle_error(const err_t &code);

#endif // ERRORS_HPP
