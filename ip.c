//
// Created by lxk on 18/6/5.
//

#include "include/ip.h"
#include "stdio.h"

//num_table()
int num_table[] =
{
        -1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,
        -1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,
        -1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,
        0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	-1,	-1,	-1,	-1,	-1,	-1,
        -1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,
        -1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,
        -1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,
        -1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,
        -1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,
        -1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,
        -1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,
        -1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,
        -1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,
        -1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,
        -1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,
        -1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,
        };

unsigned int mask_table[] =
{
        0x00000000,

        0x80000000,
        0xc0000000,
        0xe0000000,
        0xf0000000,

        0xf8000000,
        0xfc000000,
        0xfe000000,
        0xff000000,

        0xff800000,
        0xffc00000,
        0xffe00000,
        0xfff00000,

        0xfff80000,
        0xfffc0000,
        0xfffe0000,
        0xffff0000,

        0xffff8000,
        0xffffc000,
        0xffffe000,
        0xfffff000,

        0xfffff800,
        0xfffffc00,
        0xfffffe00,
        0xffffff00,

        0xffffff80,
        0xffffffc0,
        0xffffffe0,
        0xfffffff0,

        0xfffffff8,
        0xfffffffc,
        0xfffffffe,
        0xffffffff,
};

//int cidr change to str cidr
//ip = 3232235520 , mask = 4294901760
//str = "192.168.0.0/16"
int
cidr_int2str(unsigned int ip, unsigned int mask, char *str)
{
    unsigned int ip_part1;
    unsigned int ip_part2;
    unsigned int ip_part3;
    unsigned int ip_part4;

    unsigned int masklen = 0;

    ip_part1 = (ip >> (8+8+8)) % 256;
    ip_part2 = (ip >> (8+8  )) % 256;
    ip_part3 = (ip >> (8    )) % 256;
    ip_part4 = (ip >> (0    )) % 256;

    switch(mask) {
        case 0xffffffffu:
            masklen = 32;
            break;
        case 0xfffffffeu:
            masklen = 31;
            break;
        case 0xfffffffcu:
            masklen = 30;
            break;
        case 0xfffffff8u:
            masklen = 29;
            break;
        case 0xfffffff0u:
            masklen = 28;
            break;
        case 0xffffffe0u:
            masklen = 27;
            break;
        case 0xffffffc0u:
            masklen = 26;
            break;
        case 0xffffff80u:
            masklen = 25;
            break;
        case 0xffffff00u:
            masklen = 24;
            break;
        case 0xfffffe00u:
            masklen = 23;
            break;
        case 0xfffffc00u:
            masklen = 22;
            break;
        case 0xfffff800u:
            masklen = 21;
            break;
        case 0xfffff000u:
            masklen = 20;
            break;
        case 0xffffe000u:
            masklen = 19;
            break;
        case 0xffffc000u:
            masklen = 18;
            break;
        case 0xffff8000u:
            masklen = 17;
            break;
        case 0xffff0000u:
            masklen = 16;
            break;
        case 0xfffe0000u:
            masklen = 15;
            break;
        case 0xfffc0000u:
            masklen = 14;
            break;
        case 0xfff80000u:
            masklen = 13;
            break;
        case 0xfff00000u:
            masklen = 12;
            break;
        case 0xffe00000u:
            masklen = 11;
            break;
        case 0xffc00000u:
            masklen = 10;
            break;
        case 0xff800000u:
            masklen = 9;
            break;
        case 0xff000000u:
            masklen = 8;
            break;
        case 0xfe000000u:
            masklen = 7;
            break;
        case 0xfc000000u:
            masklen = 6;
            break;
        case 0xf8000000u:
            masklen = 5;
            break;
        case 0xf0000000u:
            masklen = 4;
            break;
        case 0xe0000000u:
            masklen = 3;
            break;
        case 0xc0000000u:
            masklen = 2;
            break;
        case 0x80000000u:
            masklen = 1;
            break;
        case 0x00000000u:
            masklen = 0;
            break;
        default:
            return -1;
    }

    sprintf(str,"%u.%u.%u.%u/%u",
            ip_part1, ip_part2, ip_part3, ip_part4, masklen);
    return 0;
}

//str cidr change to int cidr
//str = "192.168.0.0/16"
//ip = 3232235520 , mask = 4294901760
char * cidr_str2int(register char *cp, unsigned int *p_ip,unsigned int *p_mask)
{
    register unsigned int val;
    register unsigned int val2;
    register unsigned int c;
    unsigned int parts[4];
    register unsigned int *pp = parts;

    c = *cp;
    for (;;)
    {
        if (num_table[c] == -1)
        {
            return NULL;
        }

        val = 0;
        for (;;)
        {
            if (num_table[c] == 0)
            {
        val = (val * 10) + (c - '0');
        c = *++cp;
            }
            else
            {
        break;
            }
        }

        if (c == '.')
        {
            if (pp >= parts + 3)
            {
        return NULL;
            }

            if (val > 0xfful)
            {
        return NULL;
            }

            *pp++ = val;
            c = *++cp;
        }
        else
        {
            break;
        }
    }

    if (pp - parts + 1 != 4)
    {
        return NULL;
    }

    if (c != '/')
    {
        return NULL;
    }
    else
    {
        c = *++cp;
    }

    val2 = 0;
    for (;;)
    {
        if (num_table[c] == 0)
        {
            val2 = (val2 * 10) + (c - '0');
            c = *++cp;
        }
        else
        {
            break;
        }
    }

    if (val2 > 32)
    {
        return NULL;
    }

    val |= (parts[0] << 24) | (parts[1] << 16) | (parts[2] << 8);
    *p_ip = val;
    *p_mask = mask_table[val2];

    return ++cp;
}

//str ip change to int ip
//str = "192.168.0.0"
//ip = 3232235520
char * ip_str2int(register char *cp, unsigned int *p_ip)
{
    register unsigned int val;
    register unsigned int c;
    unsigned int parts[4];
    register unsigned int *pp = parts;

    c = *cp;
    for (;;)
    {
        if (num_table[c] == -1)
        {
            return NULL;
        }

        val = 0;
        for (;;)
        {
            if (num_table[c] == 0)
            {
                val = (val * 10) + (c - '0');
                c = *++cp;
            }
            else
            {
                break;
            }
        }

        if (c == '.')
        {
            if (pp >= parts + 3)
            {
                return NULL;
            }

            if (val > 255)
            {
                return NULL;
            }

            *pp++ = val;
            c = *++cp;
        }
        else
        {
            break;
        }
    }

    if (pp - parts + 1 != 4)
    {
        return NULL;
    }

    if (val > 255)
    {
        return NULL;
    }

    val |= (parts[0] << 24) | (parts[1] << 16) | (parts[2] << 8);
    *p_ip = val;
    return ++cp;
}

void ip_int2str(unsigned int ip_num,char * str)
{
    int ip_i[4];
    ip_i[0] = ip_num & 0x000000ff;
    ip_i[1] = (ip_num & 0x0000ff00)>>8;
    ip_i[2] = (ip_num & 0x00ff0000)>>16;
    ip_i[3] = (ip_num & 0xff000000)>>24;
    sprintf(str,"%u.%u.%u.%u",
            ip_i[0], ip_i[1], ip_i[2], ip_i[3]);
}
void mask_int2str(unsigned int mask_num,char * str)
{
    int mask_i = 0;
    unsigned int mask_num_con = ~mask_num;
    while((mask_num_con & 1)==1)
    {
        mask_num_con >>= 1;
        ++mask_i;
    }
    sprintf(str , "%d",32 - mask_i);
}