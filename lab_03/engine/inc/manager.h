#ifndef __MANAGER_H__
#define __MANAGER_H__

enum resp_t
{
    OK,
    UNKNOWN_COMMAND,
};

resp_t request_model_manager(void);

#endif // __MANAGER_H__