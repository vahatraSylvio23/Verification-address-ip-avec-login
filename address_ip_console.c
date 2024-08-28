#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "address_ip_console.h"


int main()
{
    int choice;
    choice = -1;
    user user;
    menu();
    choose(&choice);
    printf("%d\n",choice);

    if(choice == 1)
    {
        connect(&user);
    }
    else if (choice == 2)
    {
        create_account(&user);
    }
    return 0;
}
