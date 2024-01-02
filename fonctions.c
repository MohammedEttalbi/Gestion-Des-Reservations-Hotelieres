#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "fonctions.h"
#include "conio2.h"
#define MAX_SIZE 80

/***initialisation des listes****/
void init_Client_liste(liste_Client *Lc)
{
    Lc->First=NULL;
    Lc->Last=NULL;
}
void init_Chambre_liste(liste_Chambre *Lch)
{
    Lch->First=NULL;
    Lch->Last=NULL;
}
void init_Reservation_liste(liste_Reservation *Lr)
{
    Lr->First=NULL;
    Lr->Last=NULL;
}
void init_toute_liste(liste_Client *Lc,liste_Chambre *Lch,liste_Reservation *Lr)
{
    init_Client_liste(Lc);
    init_Chambre_liste(Lch);
    init_Reservation_liste(Lr);

}


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



/***la gestion des fonctions de client ***/
/*verifie l'unicite de l'id de client */
int check_num_Client(liste_Client *Lc,char num[20])
{
    Cellule_Client *temp= Lc->First;
    while(temp !=NULL)
    {
        if(strcmp(temp->client.id_client,num)==0)
            return 0;
        temp=temp->next;
    }
    return 1;

}
/*cree un nouveau noeud*/
Cellule_Client *cree_Cellule_Client(liste_Client *Lc)
{
    Cellule_Client *S=(Cellule_Client *)malloc(sizeof(Cellule_Client));
    if(S)
    {
        printf("any key ");getchar();printf("\n");
        do
        {
            printf("Num%cro De Client :",130);
            gets(S->client.id_client);
        }
        while(check_num_Client(Lc,S->client.id_client)==0);
        printf("Nom              :");
        gets(S->client.nom);
        printf("Pr%cnom           :",130);
        gets(S->client.prenom);
        printf("CIN              :");
        gets(S->client.cin);
        printf("T%cl.             :",130);
        gets(S->client.tel);

    S->next=S->prev=NULL;
    char Enregistrer;
    textcolor(BLUE);
    printf("Voulez vous enregistrer y/n :");
    scanf("%c",&Enregistrer);
    if(Enregistrer =='y')
        return S;
    else
        return NULL;
    }
}
/*inserer un noeud dans la liste */
void nouveau_Client(liste_Client *lc,Cellule_Client *S)
{
    /*Cellule_Client *S=(Cellule_Client *)malloc(sizeof(Cellule_Client));
    if(S)
    {
        printf("any key ");getchar();printf("\n");
        do
        {
            printf("Num%cro De Client :",130);
            gets(S->client.id_client);
        }
        while(check_num_Client(lc,S->client.id_client)==0);
        printf("Nom              :");
        gets(S->client.nom);
        printf("Pr%cnom           :",130);
        gets(S->client.prenom);
        printf("CIN              :");
        gets(S->client.cin);
        printf("T%cl.             :",130);
        gets(S->client.tel);
    }
    S->next=S->prev=NULL;*/
    //Cellule_Client *S=cree_Cellule_Client(lc);

    /*printf("Voulez vous enregistrer ");

    char Enregistrer;scanf("%c",&Enregistrer);
    if(Enregistrer =='y')
    {*/


        S->next=NULL;
        if(lc->First==NULL)
        {
            lc->First=S;

        }
        else
        {
            S->prev=lc->Last;
            lc->Last->next=S;
        }
        lc->Last=S;
    /*}
    else
    {
        free(S);//return;
    }*/

}
/*on consulte un seul client pour la navigation */

void consulter_Client(Cellule_Client *S)
{
    if(S){
    printf("Num%cro De Client :",130);
    puts(S->client.id_client);
    printf("Nom              :");
    puts(S->client.nom);
    printf("Pr%cnom           :",130);
    puts(S->client.prenom);
    printf("CIN              :");
    puts(S->client.cin);
    printf("T%cl.             :",130);
    puts(S->client.tel);
    }
    else
        printf("rein a afficher \n\n");
}
void consulter_all_Clients(liste_Client *lc){
    Cellule_Client *temp = lc->First;
    while(temp!=NULL){
        consulter_Client(temp);
        printf("****************\n");
        temp= temp->next;
    }
}
///**modifier un client les modification sont des parametres donner au niveau de main**//

void modifier_Client(liste_Client *lc)
{

         Cellule_Client *S=(Cellule_Client *)malloc(sizeof(Cellule_Client));
    if(S)
    {
        printf("any key ");getchar();printf("\n");
        do
        {
            printf("Num%cro De Client (existant dans la liste ):",130);
            gets(S->client.id_client);
        }
        while(check_num_Client(lc,S->client.id_client)!=0);
        printf("Nom              :");
        gets(S->client.nom);
        printf("Pr%cnom           :",130);
        gets(S->client.prenom);
        printf("CIN              :");
        gets(S->client.cin);
        printf("T%cl.             :",130);
        gets(S->client.tel);
    }
    char Enregistrer;
    textcolor(BLUE);
    printf("Voulez vous enregistrer y/n :");
    scanf("%c",&Enregistrer);
    textcolor(BLUE);
    if(Enregistrer =='y'){

        Cellule_Client *temp=lc->First;
        while(temp)
        {
            if(strcmp(temp->client.id_client,S->client.id_client)==0)
                break;
            temp=temp->next;
        }
        if(temp !=NULL)
        {
            strcpy(temp->client.cin,S->client.cin);
            strcpy(temp->client.id_client,S->client.id_client);
            strcpy(temp->client.nom,S->client.nom);
            strcpy(temp->client.prenom,S->client.prenom);
            strcpy(temp->client.tel,S->client.tel);
        }
    }
    else
        return;

}
void supprimer_Client(liste_Client *lc)
{
    char id[20];
    printf("any key ");getchar();printf("\n");
    printf("Saisir id :");
    scanf("%s",id);
    char Supp;
    textcolor(BLUE);
    printf("Voulez vous supprimmer  y/n :");
    scanf(" %c",&Supp);textcolor(WHITE);
    if(Supp == 'y'){
    Cellule_Client *temp=lc->First;

    if(lc->First !=NULL)
    {
        while(temp->next!=NULL && strcmp(temp->client.id_client, id)!=0)
        {
            temp= temp->next;
        }
        if(strcmp(temp->client.id_client, id)==0)
        {
            if(temp->prev!=NULL)
                temp->prev->next=temp->next;
            else
                lc->First=temp->next;
            if(temp->next!=NULL)
                temp->next->prev=temp->prev;
            else
                lc->Last=temp->prev;

            free(temp);

            printf("un %cl%cment a %ct%c supprim%c \n",130,130,130,130,130);
        }
        else
            printf("l'element n'existe pas \n");
    }
    }
}
void navigation_Client(liste_Client *lc){
    Cellule_Client *temp=lc->First;
    int var;
    consulter_Client(temp);
    do{
        textcolor(GREEN);
        printf("1.d%cbut\t 2.pr%cc%cdent\t 3.suivant\t 4.fin\t 0.Menu\t\n\t\t Votre choix :",130,130,130);
        scanf("%d",&var);
        textcolor(WHITE);
        if(var==1){
            consulter_Client(lc->First);
            temp=lc->First;
        }
        if(var == 2){
            if(temp==lc->First)
            {consulter_Client(lc->Last);
                temp=lc->Last;
            }
            else
            {
                consulter_Client(temp->prev);
                temp=temp->prev;
            }
        }
        if(var == 3){

                if(temp==lc->Last)
                {consulter_Client(lc->First);
                temp=lc->First;
                }
            else{
                consulter_Client(temp->next);
                temp=temp->next;
            }

        }
        if(var == 4){
             consulter_Client(lc->Last);
            temp=lc->Last;
        }
    }while(var !=0);
}

/**************************************************************************Les Menus********************************************************/
int menu(){
    int k;
    do{

        textcolor(RED);gotoxy(35,3);printf("----------------------------------------------------------------------------------\n");
        textcolor(BLUE);gotoxy(35,4);printf("|               GESTION DE RESERVATION HOTELIERE                                 |\n");
        textcolor(RED);gotoxy(35,5);printf("----------------------------------------------------------------------------------\n");
        textcolor(RED);gotoxy(35,6);printf("----------------------------------------------------------------------------------\n");
        textcolor(GREEN);gotoxy(35,7);printf("|        1. GESTION DES CLIENTS                                                  |\n");
                         gotoxy(35,8);printf("|        2. GESTION DES CHAMBRES                                                 |\n");
                         gotoxy(35,9);printf("|        3. GESTION DES RESERVATIONS                                             |\n");
                         gotoxy(35,10);printf("|        4. RESERVATION EN COURS                                                 |\n");
                         gotoxy(35,11);printf("|        5. FACTURE                                                              |\n");
                         gotoxy(35,12);printf("|        0. QUITTER                                                              |\n");
        textcolor(RED);gotoxy(35,13);printf("----------------------------------------------------------------------------------\n");
        gotoxy(35,14);printf("             Votre Choix:");scanf("%d",&k);
    if(k<0 || k>5)
        system("cls");
    }while(k<0 || k>5);
    return k;
}

int bar_menu(/*int y*/){
    int k;
    //get y by wherey();
    do{
    textcolor(5);/*gotoxy(10,y);*/printf("1 : Nouveau\t\t 2 : Consulter\t\t 3 : Consulterall\t\t 4 : Modifier\t\t 5 : Supprimer\t\t 0 : MENU\n");
    printf("\t\t\t\t\t\t Votre Choix:");scanf("%d",&k);
    textcolor(WHITE);
    if(k<0 || k>4)
        system("cls");
    }while(k<0 || k>5);
    return k;
}

///**************************Gestion des fichiers Clients *****************************/////////////////////////////////////////////////////

void Charger_Fclient(liste_Client *cl) {
    FILE* file = fopen("Client.txt", "r");
    if (file == NULL) {
        exit(2);
    }
    Client client ;
    while (!feof(file)){

              Cellule_Client *S=(Cellule_Client *)malloc(sizeof(Cellule_Client));
    if(S){
            fscanf(file,"%s ;%s ;%s ;%s ;%s ;%s  \n",client.id_client,client.nom,client.prenom,client.cin,client.tel);
        S->client=client;
        S->prev=S->next=NULL;
        nouveau_Client(cl,S);
    }
    else
            printf("Pas d'Espace memoire ");

    }
    fclose(file);
}

void Supprimer_Fclient() {
    const char* Fichier = "Client.txt";

    // Ouvre le fichier en mode écriture (truncate)
    FILE* fichier = fopen(Fichier, "w");

    if (fichier != NULL) {
        // Ferme le fichier sans rien écrire, ce qui le vide
        fclose(fichier);
        //printf("Le contenu du fichier a été supprimé avec succès.\n");
    } else {
        printf("Erreur lors de l'ouverture du fichier.\n");
    }
}

void Sauvgarder_Fclient(liste_Client *cl)
{
    FILE *file;
    file= fopen("Client.txt","w");
    Cellule_Client *temp=cl->First;
    while(temp != NULL){
        fprintf(file,"%s ;%s ;%s ;%s ;%s  \n",temp->client.id_client,temp->client.nom,temp->client.prenom,temp->client.cin,temp->client.tel);
        temp=temp->next;
    }
     fclose(file);
}
///*****************************




/***la gestion des fonctions de chambre ***/
int check_num_Chambre(liste_Chambre *Lc,int num)
{
    Cellule_Chambre *temp= Lc->First;
    while(temp !=NULL)
    {
        if(temp->chambre.num_chambre ==num)
            return 0;
        temp=temp->next;
    }
    return 1;

}

Cellule_Chambre *cree_Cellule_Chambre(liste_Chambre *Lc)
{
    Cellule_Chambre *S=(Cellule_Chambre *)malloc(sizeof(Cellule_Chambre));
    if(S)
    {
       // printf("any key ");getchar();printf("\n");
        do
        {
            printf("Num%cro De Chambre :",130);
            scanf("%d",&S->chambre.num_chambre);
        }
        while(check_num_Chambre(Lc,S->chambre.num_chambre)==0);
            getchar();
        printf("Type de Chambre :");
        gets(S->chambre.type_chambre);
        printf("Prix           :");
        scanf("%f",&S->chambre.prix);

    S->next=S->prev=NULL;
    char Enregistrer;
    textcolor(BLUE);
    printf("Voulez vous enregistrer y/n :");
    textcolor(BLUE);
    scanf(" %c",&Enregistrer);
    if(Enregistrer =='y')
        return S;
    else
        return NULL;
    }
}

void nouveau_Chambre(liste_Chambre *lc,Cellule_Chambre *S)
{
     S->next=NULL;
        if(lc->First==NULL)
        {
            lc->First=S;
            lc->Last=S;

        }
        else{
            Cellule_Chambre *temp =lc->First;
            while (temp->next !=NULL && temp->chambre.num_chambre < S->chambre.num_chambre)
            {
                temp=temp->next;
            }
            if(lc->Last->chambre.num_chambre < S->chambre.num_chambre) ///push last
            {
                S->prev=lc->Last;
            S->next=NULL;
            lc->Last->next=S;
            lc->Last=S;
            }
            else  if(lc->First->chambre.num_chambre >  S->chambre.num_chambre) ///push first
                {
                    S->next=lc->First;
                    lc->First->prev=S;
                    lc->First=S;
                }
            else
                {
                    S->next=temp;
                    S->prev=temp->prev;
                    temp->prev->next=S;
                    temp->prev=S;
                }
        }
}

void consulter_Chambre(Cellule_Chambre *S)
{
    if(S){
    printf("Num%cro De Chambre :%d\n",130,S->chambre.num_chambre);
    printf("Prix              :%.2f\n",S->chambre.prix);
    printf("type           :%s\n",S->chambre.type_chambre);
    //puts(S->chambre.type_chambre);
    }
    else
        printf("rein a afficher \n\n");
}

void consulter_all_Chambre(liste_Chambre *lc){
    Cellule_Chambre *temp = lc->First;
    while(temp!=NULL){
        consulter_Chambre(temp);
        printf("****************\n");
        temp= temp->next;
    }
}


void modifier_Chambre(liste_Chambre *lc)
{
        int num_chambre;
        char type_chambre[20];
        float prix;


       // printf("any key ");getchar();printf("\n");
        do
        {
            printf("Num%cro De Chambre (existant dans la liste ):",130);
            scanf("%d",&num_chambre);

        }while(check_num_Chambre(lc,num_chambre)!=0);

        //getchar();
        printf("Type de Chambre              :");
        scanf("%s",type_chambre);
        do{
        printf("Prix           :");
        scanf("%f",&prix);
        }while (prix<0);


    char Enregistrer;
    textcolor(BLUE);
    printf("Voulez vous enregistrer y/n :");
    scanf(" %c",&Enregistrer);
    textcolor(BLUE);
    if(Enregistrer =='y'){

        Cellule_Chambre *temp=lc->First;
        while(temp != NULL)
        {
            if(temp->chambre.num_chambre== num_chambre)
                break;
            temp=temp->next;
        }
        if(temp !=NULL)
        {
            temp->chambre.num_chambre=num_chambre;
            temp->chambre.prix=prix;
            strcpy(temp->chambre.type_chambre,type_chambre);
        }
    }
    else
        return;

}



void supprimer_Chambre(liste_Chambre *lc)
{
    int num;

    printf("Saisir Num%cro :",130);
    scanf("%d",&num);
    char Supp;
    textcolor(BLUE);
    printf("Voulez vous supprimmer  y/n :");
    scanf(" %c",&Supp);
    textcolor(WHITE);
    if(Supp == 'y'){
    Cellule_Chambre *temp=lc->First;

    if(lc->First !=NULL)
    {
        while(temp->next!=NULL && temp->chambre.num_chambre != num)
        {
            temp= temp->next;
        }
        if(temp->chambre.num_chambre == num)
        {
            if(temp->prev!=NULL)
                temp->prev->next=temp->next;
            else
                lc->First=temp->next;
            if(temp->next!=NULL)
                temp->next->prev=temp->prev;
            else
                lc->Last=temp->prev;

            free(temp);

            printf("un %cl%cment a %ct%c supprim%c \n",130,130,130,130,130);
        }
        else
            printf("l'element n'existe pas \n");
    }
    }
}

void navigation_Chambre(liste_Chambre *lc){
    Cellule_Chambre *temp=lc->First;
    int var;
    consulter_Chambre(temp);
    do{
        textcolor(GREEN);
        printf("1.d%cbut\t 2.pr%cc%cdent\t 3.suivant\t 4.fin\t 0.Menu\t\n\t\t Votre choix :",130,130,130);
        scanf("%d",&var);
        textcolor(WHITE);
        if(var==1){
            consulter_Chambre(lc->First);
            temp=lc->First;
        }
        if(var == 2){
            if(temp==lc->First)
            {consulter_Chambre(lc->Last);
                temp=lc->Last;
            }
            else
            {
                consulter_Chambre(temp->prev);
                temp=temp->prev;
            }
        }
        if(var == 3){

                if(temp==lc->Last)
                {consulter_Chambre(lc->First);
                temp=lc->First;
                }
            else{
                consulter_Chambre(temp->next);
                temp=temp->next;
            }

        }
        if(var == 4){
             consulter_Chambre(lc->Last);
            temp=lc->Last;
        }
    }while(var !=0);
}

///********************************Gestion de fichier chambre**********************************************************///

void Charger_Fchambre(liste_Chambre *cl) {
    FILE* file = fopen("Chambre.txt", "r");
    if (file == NULL) {
        exit(2);
    }
    Chambre chambre ;
    while (!feof(file)){

              Cellule_Chambre *S=(Cellule_Chambre *)malloc(sizeof(Cellule_Chambre));
    if(S){
            fscanf(file,"%d ;%s ;%f  \n",&chambre.num_chambre,chambre.type_chambre,&chambre.prix);
        S->chambre=chambre;
        S->prev=S->next=NULL;
        nouveau_Chambre(cl,S);
    }
    else
            printf("Pas d'Espace memoire ");

    }
    fclose(file);
}

void Supprimer_Fchambre() {
    const char* Fichier = "Chambre.txt";

    // Ouvre le fichier en mode écriture (truncate)
    FILE* fichier = fopen(Fichier, "w");

    if (fichier != NULL) {
        // Ferme le fichier sans rien écrire, ce qui le vide
        fclose(fichier);
       // printf("Le contenu du fichier a été supprimé avec succès.\n");
    } else {
        printf("Erreur lors de l'ouverture du fichier.\n");
    }
}

void Sauvgarder_Fchambre(liste_Chambre *cl)
{
    FILE *file;
    file= fopen("Chambre.txt","w");
    Cellule_Chambre *temp=cl->First;
    while(temp != NULL){
        fprintf(file,"%d ;%s ;%f  \n",temp->chambre.num_chambre,temp->chambre.type_chambre,temp->chambre.prix);
        temp=temp->next;
    }
     fclose(file);
}
/***************************************/

///********************************************Reservation fonctions d'aide***********************************/

int check_num_Reservation(liste_Reservation *Lc,char num[20])
{
    Cellule_Reservation *temp= Lc->First;
    while(temp !=NULL)
    {
        if(strcmp(temp->reservation.id_reservation,num)==0)
            return 0;
        temp=temp->next;
    }
    return 1;

}

int check_type_Chambre(liste_Chambre *Lc,char type[20],int num_prec)
{
    Cellule_Chambre *temp= Lc->First;
    while(temp !=NULL)
    {

        if(strcmp(temp->chambre.type_chambre,type)==0 && temp->chambre.num_chambre != num_prec )
            return temp->chambre.num_chambre;

        temp=temp->next;
    }

    return -1;

}

Date Date_fin_sejour(liste_Reservation *Lrv,int num_ch){//date fin de sejour d'une chambre
    Date date ;
    date.jour =0;date.mois=0;date.an=0;
    Cellule_Reservation *temp= Lrv->First;
    while(temp !=NULL){
        if(temp->reservation.num_chambre == num_ch){
            date.an = temp->reservation.fin_sejour.an;
            date.jour= temp->reservation.fin_sejour.jour;
            date.mois=temp->reservation.fin_sejour.mois;

        }
        temp=temp->next;
    }
        return date;
}

int comparerDates( Date date1, Date date2) {//compararer deux dates
    if (date1.an < date2.an)
        return -1;
    else if (date1.an > date2.an)
        return 1;
    else {
        if (date1.mois < date2.mois)
            return -1;
        else if (date1.mois > date2.mois)
            return 1;
        else {
            if (date1.jour < date2.jour)
                return -1;
            else if (date1.jour > date2.jour)
                return 1;
            else
                return 0;
        }
    }
}
int difference_dates(Date date1, Date date2) {
    int jours_par_mois[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int jours1 = date1.jour;
    int jours2 = date2.jour;

    // Ajouter les jours des mois précédents
    for (int i = 0; i < date1.mois - 1; i++) {
        jours1 += jours_par_mois[i];
    }
    for (int i = 0; i < date2.mois - 1; i++) {
        jours2 += jours_par_mois[i];
    }

    // Ajouter les jours des années précédentes
    jours1 += (date1.an - 1) * 365 + (date1.an - 1) / 4 - (date1.an - 1) / 100 + (date1.an - 1) / 400;
    jours2 += (date2.an - 1) * 365 + (date2.an - 1) / 4 - (date2.an - 1) / 100 + (date2.an - 1) / 400;

    // Ajouter les jours de l'année en cours
    jours1 += date1.an % 4 == 0 && (date1.an % 100 != 0 || date1.an % 400 == 0) && date1.mois > 2;
    jours2 += date2.an % 4 == 0 && (date2.an % 100 != 0 || date2.an % 400 == 0) && date2.mois > 2;

    int difference = jours2 - jours1;
    difference = abs(difference);
    return difference +1;
}

//creation d'une reservation
Cellule_Reservation *cree_Cellule_Reservation(liste_Reservation *Lrv,liste_Client *Lcl,liste_Chambre *Lch)
{
    char type[20];
    char choix;
    Date date;

    Cellule_Reservation *S=(Cellule_Reservation *)malloc(sizeof(Cellule_Reservation));
    if(S)
    {
        printf("Saisir le type de chambre ");
        scanf("%s",type);
        int num_prec = -1;
        etiq :
            num_prec=check_type_Chambre(Lch,type,num_prec);

        if(num_prec>0){

            date = Date_fin_sejour(Lrv,num_prec);
            printf("la date de derniere reservation :%d/%d/%d\n",date.jour,date.mois,date.an);
            if(date.an !=0){
            //num_prec = check_type_Chambre(Lch,type,num_prec)>0;
            printf("vouler vous resserver a pres y/n:");
            scanf(" %c",&choix);
            if(choix == 'n' && num_prec !=-1 )
                goto etiq;//chercher une chambre de meme type avec une date convenable ;
            else if(num_prec ==-1){
            printf("changer le type ou la date ");return NULL;
            }
            }
        }
        else {
            printf("Ce type n'existe pas \n");return NULL;
        }

        getchar();printf("\n");
        do
        {
            printf("Num%cro De Reservation :",130);
           scanf("%s",S->reservation.id_reservation);

        }while(check_num_Reservation(Lrv,S->reservation.id_reservation)==0);

        time_t timestamp = time( NULL );//
    struct tm * pTime = localtime( & timestamp );
        printf("Date date_reservation :");
        S->reservation.date_reservation.jour=pTime->tm_mday;
        S->reservation.date_reservation.mois=pTime->tm_mon+1;
        S->reservation.date_reservation.an=pTime->tm_year+1900;
        printf("%d/%d/%d\n",S->reservation.date_reservation.jour,S->reservation.date_reservation.mois,S->reservation.date_reservation.an);


        do{
        printf("Date debut_sejour :");
        scanf("%d/%d/%d",&S->reservation.debut_sejour.jour,&S->reservation.debut_sejour.mois,&S->reservation.debut_sejour.an);
        if (comparerDates( date, S->reservation.debut_sejour)>=0 || S->reservation.debut_sejour.jour >31 || S->reservation.debut_sejour.jour <1 || S->reservation.debut_sejour.mois >12 || S->reservation.debut_sejour.mois <1 || S->reservation.debut_sejour.an <2010){
            textcolor(RED);
            printf("date est incorrect \n");textcolor(WHITE);
        }
        }while(comparerDates( date, S->reservation.debut_sejour)>=0 || S->reservation.debut_sejour.jour >31 || S->reservation.debut_sejour.jour <1 || S->reservation.debut_sejour.mois >12 || S->reservation.debut_sejour.mois <1 || S->reservation.debut_sejour.an <2010  );

        do{
        printf("Date fin_sejour :");
        scanf("%d/%d/%d",&S->reservation.fin_sejour.jour,&S->reservation.fin_sejour.mois,&S->reservation.fin_sejour.an);
        if (comparerDates( S->reservation.debut_sejour, S->reservation.fin_sejour)>0 || S->reservation.fin_sejour.jour >31 || S->reservation.fin_sejour.jour <1 || S->reservation.fin_sejour.mois >12 || S->reservation.fin_sejour.mois <1 || S->reservation.fin_sejour.an <2010){
            textcolor(RED);
            printf("date est incorrect \n");textcolor(WHITE);
        }
        }while(comparerDates( date, S->reservation.fin_sejour)>=0 || S->reservation.fin_sejour.jour >31 || S->reservation.fin_sejour.jour <1 || S->reservation.fin_sejour.mois >12 || S->reservation.fin_sejour.mois <1 || S->reservation.fin_sejour.an <2010);

        S->reservation.nb_nuit= difference_dates(S->reservation.debut_sejour, S->reservation.fin_sejour);
        printf("nombre de nuits :%d\n",S->reservation.nb_nuit);



        do{
            printf("montant avance :");
        scanf("%f",&S->reservation.montant_avance);
        }while(S->reservation.montant_avance<=50);

        do
        {
            printf("Num%cro De Client :",130);getchar();
            gets(S->reservation.id_client);
        }
        while(check_num_Client(Lcl,S->reservation.id_client)!=0);

        printf("numero de chambre :");
        S->reservation.num_chambre = num_prec;
        printf("%d\n",S->reservation.num_chambre);

    S->next=S->prev=NULL;
    char Enregistrer;
    textcolor(BLUE);
    printf("Voulez vous enregistrer y/n :");
    textcolor(WHITE);
    scanf("%c",&Enregistrer);
    if(Enregistrer =='y')
        return S;
    else
        return NULL;
    }
}

void nouveau_Reservation(liste_Reservation *lc,Cellule_Reservation *S)
{



        S->next=NULL;
        if(lc->First==NULL)
        {
            lc->First=S;

        }
        else
        {
            S->prev=lc->Last;
            lc->Last->next=S;
        }
        lc->Last=S;


}

void consulter_Reservation(Cellule_Reservation *S)
{
    if(S){
    printf("Num%cro De Reservation :",130);
    puts(S->reservation.id_reservation);
    printf("Date de Reservation    :%d/%d/%d\n",S->reservation.date_reservation.jour,S->reservation.date_reservation.mois,S->reservation.date_reservation.an);
    printf("Date de debut de sejour    :%d/%d/%d\n",S->reservation.debut_sejour.jour,S->reservation.debut_sejour.mois,S->reservation.debut_sejour.an);
    printf("Date de fin de sejour    :%d/%d/%d\t\t\t\t\t",S->reservation.fin_sejour.jour,S->reservation.fin_sejour.mois,S->reservation.fin_sejour.an);
    printf("nb_nuit :%d\n",S->reservation.nb_nuit);
    printf("montant avanc%c :%.2f\n",130,S->reservation.montant_avance);
    printf("Num%cro De Client:",130);
    puts(S->reservation.id_client);
    printf("Num%cro De Chambre:%d\n",130,S->reservation.num_chambre);

    //puts(S->reservation.num_chambre);

    }
    else
        printf("rein a afficher \n\n");
}

void consulter_all_Reservation(liste_Reservation *lc){
    Cellule_Reservation *temp = lc->First;
    while(temp!=NULL){
        consulter_Reservation(temp);
        printf("\n****************\n");
        temp= temp->next;
    }
}

void supprimer_Reservation(liste_Reservation *lc)
{
    char id[20];
    printf("any key ");getchar();printf("\n");
    printf("Saisir id :");
    scanf("%s",id);
    char Supp;
    textcolor(BLUE);
    printf("Voulez vous supprimmer  y/n :");
    scanf("%c",&Supp);textcolor(WHITE);
    if(Supp == 'y'){
    Cellule_Reservation *temp=lc->First;

    if(lc->First !=NULL)
    {
        while(temp->next!=NULL && strcmp(temp->reservation.id_reservation, id)!=0)
        {
            temp= temp->next;
        }
        if(strcmp(temp->reservation.id_reservation, id)==0)
        {
            if(temp->prev!=NULL)
                temp->prev->next=temp->next;
            else
                lc->First=temp->next;
            if(temp->next!=NULL)
                temp->next->prev=temp->prev;
            else
                lc->Last=temp->prev;

            free(temp);

            printf("un %cl%cment a %ct%c supprim%c \n",130,130,130,130,130);
        }
        else
            printf("l'element n'existe pas \n");
    }
    }
}


void modifier_Reservation(liste_Reservation *lc,liste_Client *Lcl,liste_Chambre *Lch)
{
    supprimer_Reservation(lc);

         Cellule_Reservation *S =cree_Cellule_Reservation(lc,Lcl,Lch);
         if(S)
         nouveau_Reservation(lc,S);


}

void navigation_Reservation(liste_Reservation *lc){
    Cellule_Reservation *temp=lc->First;
    int var;
    consulter_Reservation(temp);
    do{
        textcolor(GREEN);
        printf("1.d%cbut\t 2.pr%cc%cdent\t 3.suivant\t 4.fin\t 0.Menu\t\n\t\t Votre choix :",130,130,130);
        scanf("%d",&var);
        textcolor(WHITE);
        if(var==1){
            consulter_Reservation(lc->First);
            temp=lc->First;
        }
        if(var == 2){
            if(temp==lc->First)
            {consulter_Reservation(lc->Last);
                temp=lc->Last;
            }
            else
            {
                consulter_Reservation(temp->prev);
                temp=temp->prev;
            }
        }
        if(var == 3){

                if(temp==lc->Last)
                {consulter_Reservation(lc->First);
                temp=lc->First;
                }
            else{
                consulter_Reservation(temp->next);
                temp=temp->next;
            }

        }
        if(var == 4){
             consulter_Reservation(lc->Last);
            temp=lc->Last;
        }
    }while(var !=0);
}



///**************************Gestion des fichiers Reservations *****************************/////////////////////////////////////////////////////

void Charger_Freservation(liste_Reservation *cl) {
    FILE* file = fopen("Reservation.txt", "r");
    if (file == NULL) {
        exit(2);
    }
    Reservation R ;
    while (!feof(file)){

              Cellule_Reservation *S=(Cellule_Reservation *)malloc(sizeof(Cellule_Reservation));
    if(S){
            fscanf(file,"%s ;%d ;%d ;%d ;%d ;%d ;%d ;%d ;%d ;%d ;%d ;%f ;%s ;%d  \n",R.id_reservation,&R.date_reservation.jour,&R.date_reservation.mois,&R.date_reservation.an,&R.debut_sejour.jour,&R.debut_sejour.mois,&R.debut_sejour.an,&R.fin_sejour.jour,&R.fin_sejour.mois,&R.fin_sejour.an,&R.nb_nuit,&R.montant_avance,R.id_client,&R.num_chambre);
        S->reservation=R;
        S->prev=S->next=NULL;
        nouveau_Reservation(cl,S);
    }
    else
            printf("Pas d'Espace memoire ");

    }
    fclose(file);
}

void Supprimer_Freservation() {
    const char* Fichier = "Reservation.txt";

    // Ouvre le fichier en mode écriture (truncate)
    FILE* fichier = fopen(Fichier, "w");

    if (fichier != NULL) {
        // Ferme le fichier sans rien écrire, ce qui le vide
        fclose(fichier);
        //printf("Le contenu du fichier a été supprimé avec succès.\n");
    } else {
        printf("Erreur lors de l'ouverture du fichier.\n");
    }
}

void Sauvgarder_Freservation(liste_Reservation *cl)
{
    FILE *file;
    file= fopen("Reservation.txt","w");
    Cellule_Reservation *temp=cl->First;
    while(temp != NULL){
        fprintf(file,"%s ;%d ;%d ;%d ;%d ;%d ;%d ;%d ;%d ;%d ;%d ;%f ;%s ;%d  \n",temp->reservation.id_reservation,temp->reservation.date_reservation.jour,temp->reservation.date_reservation.mois,temp->reservation.date_reservation.an,temp->reservation.debut_sejour.jour,temp->reservation.debut_sejour.mois,temp->reservation.debut_sejour.an,temp->reservation.fin_sejour.jour,temp->reservation.fin_sejour.mois,temp->reservation.fin_sejour.an,temp->reservation.nb_nuit,temp->reservation.montant_avance,temp->reservation.id_client,temp->reservation.num_chambre);
        temp=temp->next;
    }
     fclose(file);
}
///*****************************

///********************************
void Reservation_en_cours(liste_Reservation *lrv,liste_Client *lcl,liste_Chambre *lch ){
    Cellule_Reservation *S = lrv->First;
    char nom[20];
    char type[20];

    while(S!=NULL){
        Cellule_Client *client = lcl->First;
    Cellule_Chambre *ch = lch->First;
    printf("Num%cro De Reservation :",130);
    puts(S->reservation.id_reservation);
    while(client !=NULL){

        if(strcmp(client->client.id_client,S->reservation.id_client)==0  )
        {
            strcpy(nom,client->client.nom);
            break;
        }
        client =client->next;
    }
    printf("nom :%s\n",nom);
    printf("Date de fin de Reservation    :%d/%d/%d\n",S->reservation.date_reservation.jour,S->reservation.date_reservation.mois,S->reservation.date_reservation.an);
    printf("Date de debut de sejour    :%d/%d/%d\n",S->reservation.debut_sejour.jour,S->reservation.debut_sejour.mois,S->reservation.debut_sejour.an);
    printf("num_chambre :%d\n",S->reservation.num_chambre);

    while(ch !=NULL){

        if(ch->chambre.num_chambre==S->reservation.num_chambre  )
        {

            strcpy(type,ch->chambre.type_chambre);

            break;
        }

        ch = ch->next;
    }
    printf("type :%s\n",ch->chambre.type_chambre);
    //puts(type);

        printf("\n****************\n");

        S= S->next;
    }
}

void Facture(liste_Reservation *lrv,liste_Client *lcl ,liste_Chambre *lch){
    Cellule_Reservation *S = lrv->First;
    char nom[20];
    char id[20];
    float montant;


        Cellule_Client *client = lcl->First;
        Cellule_Chambre *chambre = lch->First;

    getchar();printf("\n");
        do
        {
            printf("Num%cro De Facture :",130);
           scanf("%s",id);

           if(check_num_Reservation(lrv,id)!=0){
            textcolor(RED);
            printf("Reservation n'existe pas \n");textcolor(WHITE);
           }


        }while(check_num_Reservation(lrv,id)!=0);

        while(S!=NULL){
            if(strcmp(S->reservation.id_reservation,id)==0){

            break;}

            S=S->next;
        }

         time_t timestamp = time( NULL );//
    struct tm * pTime = localtime( & timestamp );
        printf("Date date d'edition :");
        printf("%d/%d/%d\n",pTime->tm_mday,pTime->tm_mon+1,pTime->tm_year+1900);

    while(client !=NULL){
        if(strcmp(client->client.id_client,id)==0  )
        {
            strcpy(nom,client->client.nom);
            break;
        }
        client =client->next;
    }
    printf("nom du client :%s\n",nom);
    printf("P%criode : Du  %d/%d/%d\t Au",130,S->reservation.debut_sejour.jour,S->reservation.debut_sejour.mois,S->reservation.debut_sejour.an);
    printf("  %d/%d/%d\t\t\t\t",S->reservation.fin_sejour.jour,S->reservation.fin_sejour.mois,S->reservation.fin_sejour.an);
    printf("Dur%ce :%d jour(s)\n",130,S->reservation.nb_nuit);
    printf("Montant avanc%c :%.2f  DH TTC\n",130,S->reservation.montant_avance);

    while(chambre!=NULL){
        if(chambre->chambre.num_chambre == S->reservation.num_chambre){
            montant=chambre->chambre.prix;
            break;
        }
        chambre=chambre->next;
    }

    int x = S->reservation.nb_nuit;
     montant=montant*x;
     x=S->reservation.montant_avance;
    montant =montant-x;
    montant = abs(montant);
    printf("Montant a payer :%.2f DH TTC\n",montant);

        printf("\n****************\n");



}












