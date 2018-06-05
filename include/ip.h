//
// Created by lxk on 2018/6/5.
//

#ifndef C_TOOL_IP_H
#define C_TOOL_IP_H

#ifdef  __cplusplus
extern "C" {
#endif


//int cidr change to str cidr
//ip = 3232235520 , mask = 4294901760
//str = "192.168.0.0/16"
int cidr_int2str(unsigned int ip, unsigned int mask, char *str);


//str cidr change to int cidr
//str = "192.168.0.0/16"
//ip = 3232235520 , mask = 4294901760
char * cidr_str2int(register char *cp, unsigned int *p_ip,unsigned int *p_mask);

//str ip change to int ip
//str = "192.168.0.0"
//ip = 3232235520
char * ip_str2int(register char *cp, unsigned int *p_ip);

void ip_int2str(unsigned int ip_num,char * str);
void mask_int2str(unsigned int mask_num,char * str);

#ifdef  __cplusplus
}
#endif

#endif //C_TOOL_IP_H