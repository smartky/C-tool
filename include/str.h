//
// Created by lxk on 18/6/5.
//

#ifndef C_TOOL_STR_H
#define C_TOOL_STR_H

#ifdef  __cplusplus
extern "C" {
#endif

//ignore the annotation.
//find the first word
//uppercase to lowercase
char *trim(unsigned char *str);

char * domain_check(register char *cp);

char * str2num(register char *cp, int *num);

//some name table check
char * str_name(register char *cp);

//find start word
char *find_head(char *str);

void trans_char(char* ids_s,char old_,char new_);

#ifdef  __cplusplus
}
#endif

#endif //C_TOOL_STR_H