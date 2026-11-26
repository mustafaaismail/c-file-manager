#include <stdio.h>
#include <time.h>
#include "../include/logger.h"

void log_message(log_level_t level, const char *message)
{
    FILE *file = fopen("logs/system.log","a");

    if(file == NULL){
        return;
    }

    time_t now = time(NULL);
    struct tm *t = localtime(&now);
    char time_str[20];
    strftime(time_str,sizeof(time_str), "%Y-%m-%d %H:%M:%S", t);
    
    const char *level_str;
    if(level == LOG_INFO){
        level_str = "INFO";
    } else {
        level_str = "ERROR";
    }

    fprintf(file,"%s [%s] %s\n",time_str, level_str, message);
    fclose(file);
}