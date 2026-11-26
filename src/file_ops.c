#include <stdio.h>
#include <dirent.h>
#include <string.h>

#include "../include/file_ops.h"


error_codes_t create_file(const char *filename){

    FILE *file = fopen(filename,"w");

    if(file == NULL){
        return FS_ERR_FILE_OPEN;
    }
    
    fclose(file);
    return FS_SUCCESS;
}


error_codes_t delete_file(const char *filename){

    int result = remove(filename);

    if(result == -1){
    
        return FS_ERR_FILE_NOT_FOUND;
    }

    return FS_SUCCESS;
}


error_codes_t write_file(const char *filename, const char *content){

    FILE *file = fopen(filename,"a");

    if(file == NULL){
        return FS_ERR_FILE_OPEN;
    }

    fprintf(file,"%s\n",content);
    fclose(file);
    return FS_SUCCESS;
}

error_codes_t read_file(const char *filename){

    FILE *file = fopen(filename,"r");

    if(file == NULL){
        return FS_ERR_FILE_NOT_FOUND;
    }

    // Read the file character by character until EOF
    while(1){
        int ch = fgetc(file);

        if(ch == EOF){
            break;
        }
        printf("%c",ch);
    }

    fclose(file);
    return FS_SUCCESS;
}


error_codes_t list_files(const char *path){
    DIR *dir = opendir(path);
    

    if(dir == NULL){
        return FS_ERR_DIR_OPEN;
    }
    
    // Read directory entries until there are no more entries
    while(1){
        struct dirent *entry;
        entry = readdir(dir);
        
        if(entry == NULL){
            break;
        }

        printf("%s\n",entry->d_name);
    }
    closedir(dir);
    return FS_SUCCESS;
}


error_codes_t search_file(const char *filename,const char *keyword){
    FILE *file = fopen(filename, "r");

    if(file == NULL){
        return FS_ERR_FILE_NOT_FOUND;
    }

    char line[256];
    int line_num = 1;
    int found = 0;

    // Search for the keyword in each line
    while(fgets(line,sizeof(line),file) != NULL){
        if(strstr(line,keyword) != NULL){
            printf("Found (Line %d): %s", line_num, line);
            found = 1;

        }
        line_num++;
    }
    fclose(file);

    if(found == 0){
        printf("The searched word was not found\n");
    }
    
    return FS_SUCCESS;
}