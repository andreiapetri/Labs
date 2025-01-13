#include <stdio.h>
#include <stdint.h>
union ipv4{
    uint32_t address;
    uint8_t octets[4];
};
int main(){
    union ipv4 addr;
    printf("Enter IPv4 address (e.g., 192.168.23.24): ");
    scanf("%hhu.%hhu.%hhu.%hhu", &addr.octets[0], &addr.octets[1], &addr.octets[2], &addr.octets[3]);
    printf("Octet form: %hhu.%hhu.%hhu.%hhu\n",
           addr.octets[0], addr.octets[1], addr.octets[2], addr.octets[3]);
    printf("Hexadecimal form: 0x%08X\n", addr.address);
    return 0;
}
