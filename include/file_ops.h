#ifndef FILE_OPS_H
#define FILE_OPS_H

#include "error_codes.h"



error_codes_t create_file(const char *filename);
error_codes_t delete_file(const char *filename);
error_codes_t write_file(const char *filename, const char *content);
error_codes_t read_file(const char *filename);
error_codes_t list_files(const char *path);
error_codes_t search_file(const char *filename, const char *keyword);


#endif
