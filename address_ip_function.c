#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "address_ip_console.h"


void menu()
{
    int i;
    char *menu;
    menu  = "\t\t\t\tBienvenue sur le console sur verification de l'addresse ip\n\n\n" ;
        printf("%s",menu);

}

void choose(int *choice)
{
    char c_choice[512];
    printf("\t\t\t\t 1-  SE CONNECTER\n\n\n");
    printf("\t\t\t\t 2-  CREER UN COMPTE\n\n\n");
    printf("Votre choix :");

    do
    {    
        *choice  = -1;
        scanf("%s",c_choice);
        sscanf(c_choice , "%d",choice);
    }while(*choice != 1 && *choice != 2);
}


/*---------------------------------------------------------------------------------------------------*/
void connect(user *user )
{
    char chaine[8192];
        FILE *file;
        file=fopen("login.txt","r");
            printf("\t\t\t\tSE CONNECTER A UN COMPTE\n");
            printf("Entrer le nom du compte : ");
            scanf("%s",user->name);
            printf("Entrer le mot de passe : ");
            scanf("%s",user->password);

        while(fgets(chaine , 255 , file))
        {
            if(strstr(chaine , user->name) && strstr(chaine , user->password))
            {
                int deconnection;
                do
                {
                ip_address();
                printf("Appuyez sur d pour se deconnecter : ");
                deconnection=getchar();
                }while((deconnection=getchar()) != 'd');
                if((deconnection=getchar()) == 'd')
                {
                    fprintf(file,"deconnectee\n");
                }
                break;
            }
        }

            if(strstr(chaine , user->name) && strstr(chaine , user->password))
            {

            }

        else
        {
                while(fgets(chaine , 255 , file))
                {
                    if(strstr(chaine , user->name) && strstr(chaine , user->password))
                    {
                        break;
                    }
                    else if(strstr(chaine , user->name) && !strstr(chaine , user->password))
                    {
                        printf("Mot de passe incorrect\n");
                        break;
                    }
                }

                while(fgets(chaine , 255 , file))
                {
                    if(strstr(chaine , user->name) && strstr(chaine , user->password))
                    {
                        break;
                    }
                    else if(!strstr(chaine , user->name))
                    {
                        printf("Aucun utilisateur de ce type\n");
                        break;
                    }
                }
        }
}


/*---------------------------------------------------------------------------------------------------*/
void create_account(user *user)
{

    FILE *file;
    file=fopen("login.txt","a+");
    printf("\t\t\t\tCREATION D'UN NOUVEAU COMPTE\n");
    printf("Entrer le nom du compte : ");
    scanf("%s",user->name);
    printf("Entrer le mot de passe : ");
    scanf("%s",user->password);
    fprintf(file, "%s %s \n\n",user->name , user->password);


}


/*---------------------------------------------------------------------------------------------------*/
void ip_address()
{
    char address_ip[20];
    ip address;
    objet();
    get_ip(address_ip , &address);
    verifie(address);

}



/*---------------------------------------------------------------------------------------------------*/


void objet()
{
    printf("Verifie si c'est un address ip....\n");
}

void get_ip(char ad_ip[512] ,ip *address)
{

    do
    {
        printf("Entrer l'address ip\n");
        address->a = -1, address->b = -1 , address->c = -1 , address->d = -1;
        scanf("%s",ad_ip);
        sscanf(ad_ip,"%d.%d.%d.%d\n",&address->a,&address->b,&address->c,&address->d);
            
            if(address->a > 255 || address->b > 255 || address->c > 255 || address->d > 255 || address->a < 0 || address->b < 0 || address->c < 0 || address->d < 0)
            {
                printf("Ce n'est pas un addresse ip\n");
            }

            else
            {

            }
    }while(address->a > 255 || address->b > 255 || address->c > 255 || address->d > 255 || address->a < 0 || address->b < 0 || address->c < 0 || address->d < 0);
}


/*---------------------------------------------------------------------------------------------------*/


void verifie(ip address)
{
    if(address.a >= 0 && address.a < 128)
    {
        printf("L'addresse ip est de class A \n");
    }

    else if(address.a >= 128 && address.a < 192)
    {
        printf("L'addresse ip est de class B \n");
    }

    else if(address.a >= 192 && address.a < 224)
    {
        printf("L'addresse ip est de class C \n");
    }

    else if(address.a >= 224 && address.a < 240)
    {
        printf("L'addresse ip est de class D \n");
    }

    else if(address.a >= 240 && address.a <= 255)
    {
        printf("L'addresse ip est de class E \n");
    }
}