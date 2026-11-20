#ifndef ERROR_CODES_H
#define ERROR_CODES_H

typedef enum{
    FS_SUCCESS = 0 ,
    FS_ERR_FILE_NOT_FOUND,
    FS_ERR_FILE_OPEN,
    FS_ERR_INVALID_INPUT,
    FS_ERR_MEMORY,
    FS_ERR_DIR_OPEN
}error_codes_t;
#endif