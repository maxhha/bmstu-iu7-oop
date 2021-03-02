#ifndef __MANAGER_H__
#define __MANAGER_H__

enum resp_t
{
    OK,
    UNKNOWN_COMMAND,
};

enum request_type_t
{
    LOAD,
};

typedef struct request_s
{
    request_type_t type;
} request_t;

resp_t request_model_manager(request_t req);

#endif // __MANAGER_H__