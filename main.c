#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "fonctions.h"
#include "conio2.h"
#define MAX_SIZE 80


int main()
{




    int k;
    int choix;

    Cellule_Client *C;
    Cellule_Chambre *CH;
    Cellule_Reservation *RV;

    liste_Client cl;
    liste_Chambre lch;
    liste_Reservation lrv;

    init_Client_liste(&cl);
    init_Chambre_liste(&lch);
    init_Reservation_liste(&lrv);

    Charger_Fclient(&cl);
    Charger_Fchambre(&lch);
    Charger_Freservation(&lrv);



     do{
            choix=menu();

    switch(choix){
 case 1 :
    do{

    k = bar_menu();
        switch(k){
            case 1: system("cls");
                    C=cree_Cellule_Client(&cl);
                    if(C)
                        nouveau_Client(&cl,C);
                    break;
            case 2 :
                    system("cls");
                    navigation_Client(&cl);
                    break;
            case 3 :
                    system("cls");
                    consulter_all_Clients(&cl);
                    break;
            case 4 :
                    system("cls");
                    modifier_Client(&cl);
                    break;
            case 5 :
                    supprimer_Client(&cl);
                    break;
            default : break;
        }
    }while(k!=0);
    system("cls");
    break;
    ///****************************Chambre*****************///
            case 2 :
                do{
    k = bar_menu();
        switch(k){
            case 1: system("cls");
                    CH=cree_Cellule_Chambre(&lch);
                    if(CH)
                        nouveau_Chambre(&lch,CH);
                    break;
            case 2 :
                    system("cls");
                    navigation_Chambre(&lch);
                    break;
            case 3 :
                    system("cls");
                    consulter_all_Chambre(&lch);
                    break;
            case 4 :
                    system("cls");
                    modifier_Chambre(&lch);
                    break;
            case 5 :
                    supprimer_Chambre(&lch);
                    break;
            default : break;
        }
    }while(k!=0);
    system("cls");
    break;
    ///****************************Reservation*****************///
            case 3 :
                do{
    k = bar_menu();
        switch(k){
            case 1: system("cls");
                    RV=cree_Cellule_Reservation(&lrv,&cl,&lch);
                    if(RV)
                       nouveau_Reservation(&lrv,RV);
                    break;
            case 2 :
                    system("cls");
                    navigation_Reservation(&lrv);
                    break;
            case 3 :
                    system("cls");
                    consulter_all_Reservation(&lrv);
                    break;
            case 4 :
                    system("cls");
                    modifier_Reservation(&lrv,&cl,&lch);
                    break;
            case 5 :
                    supprimer_Reservation(&lrv);
                    break;
            default : break;
        }
    }while(k!=0);
    system("cls");
    break;
            ///****************************Reservation_en_cours*****************///
            case 4 :


         system("cls");
         textcolor(WHITE);
        Reservation_en_cours(&lrv,&cl,&lch);
        char c;
        printf("\nappuyer sur n'importe quelle touche :");
        scanf(" %c",&c);
        system("cls");
        break;

    ///****************************Reservation_en_cours*****************///
            case 5 :

                textcolor(WHITE);

        Facture(&lrv,&cl,&lch);
        char l;
        printf("\nappuyer sur n'importe quelle touche :");
        scanf(" %c",&l);
        system("cls");
        break;
    ///*****************************
            default:break;



    }

     }while(choix !=0);
    //pour faire le update des donnes
    Supprimer_Fchambre();
    Supprimer_Fclient();
    Supprimer_Freservation();

    Sauvgarder_Fchambre(&lch);
    Sauvgarder_Fclient(&cl);
    Sauvgarder_Freservation(&lrv);



































    //printf("1.\t\t2.\t\t3.\t\t\n");
 /*   textcolor(RED);

    time_t timestamp = time( NULL );//
    struct tm * pTime = localtime( & timestamp );
    printf("%d\t",pTime->tm_sec);
    printf("%d\t",pTime->tm_min);
    printf("%d\t",pTime->tm_hour);
    printf("%d\t",pTime->tm_mday);
    printf("%d\t",pTime->tm_mon+1);
    printf("%d\t",pTime->tm_year+1900);
    printf("\n");
    char buffer[ MAX_SIZE ];
    strftime( buffer, MAX_SIZE, "%d/%m/%Y %H:%M:%S", pTime );
    printf( "Date and french time : %s\n", buffer );


    textcolor(5);

    nouveau_Client(&cl);
    nouveau_Client(&cl);
    /*nouveau_Client(&cl);
    nouveau_Client(&cl);*/




   // navigation_Client(&cl);

    return 0;
}
