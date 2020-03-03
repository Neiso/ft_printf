#include "ft_printf.h"

int main()
{
    int ret = 0, ret2 = 0;
    ret = ft_printf("%--45c%05.137i%-27.123x%-132.121i%-137c%2c%c%-25.*s\n" ,-1,1728041455,2447203785u,126274169,101, 0, 0, 4, NULL);
    ret2 =   printf("%--45c%05.137i%-27.123x%-132.121i%-137c%2c%c%-25.*s\n" ,-1,1728041455,2447203785u,126274169,101, 0, 0, 4, NULL);
    
    if (ret != ret2)
    {
        ft_printf("ret1 : %d\nret2 : %d\n", ret, ret2);
        ft_printf("AIE");
    }
    return (0);
}