//
// Created by apple on 18/6/5.
//

#ifndef MYGITHUB_C_USE_CPP_STR_H
#define MYGITHUB_C_USE_CPP_STR_H


#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

typedef void std_string;

//allocate a string buffer which is variable-length
std_string* std_string_new();

//free string buffer which is allocated by std_string_new
void std_string_free(std_string *s);

//append a sub-string to target
void std_string_append(std_string *target, const char* source);

//append a sub-string to target with
int std_string_append_printf(std_string *target, const char* format, ...);

const char *std_string_pointer(std_string *target);
size_t std_string_len(std_string *target);
size_t std_string_maxlen(std_string *target);

#ifdef __cplusplus
}
#endif /* __cplusplus */


#endif //MYGITHUB_C_USE_CPP_STR_H
