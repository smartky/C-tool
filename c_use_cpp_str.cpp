//
// Created by apple on 18/6/5.
//

#include <string>
using std::string;

std_string* std_string_new()
{
    string *ret = new string;
    return ret;
}
void std_string_free(std_string *s)
{
    string *str = (string *)s;
    delete str;
    return;
}
void std_string_append(std_string *target, const char* source)
{
    string *str = (string *)target;
    str->append(source);
    return;
}
int std_string_append_printf(std_string *target, const char* format, ...)
{
    string *str = (string *)target;
    int ret = 0;
    va_list args;
    va_start(args, format);
    char buf[BUF_MAX_SIZE]={0};
    vsnprintf(buf, BUF_MAX_SIZE, format, args);
    va_end(args);
    str->append(buf);

    return ret;
}

const char *std_string_pointer(std_string *target)
{
    string *str = (string *)target;
    return str->c_str();
}

size_t std_string_len(std_string *target)
{
    string *str = (string *)target;
    return str->size();
}
size_t std_string_maxlen(std_string *target)
{
    string *str = (string *)target;
    return str->max_size();
}