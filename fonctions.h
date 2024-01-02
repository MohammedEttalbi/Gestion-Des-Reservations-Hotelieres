#ifndef FONCTIONS_H_INCLUDED
#define FONCTIONS_H_INCLUDED
///***Structure DATE *///
typedef struct Date Date ;
struct Date
{
    int jour;
    int mois;
    int an;
};
///***Structure Client *///
typedef struct Client Client ;
struct Client
{
    char id_client[20];
    char nom[20];
    char prenom[20];
    char cin[20];
    char tel[20];
};
///***Structure Chambre*///
typedef struct Chambre Chambre ;
struct Chambre
{
    int num_chambre;
    char type_chambre[20];
    float prix;
};
///***Structure Reservation*///
typedef struct Reservation Reservation ;
struct Reservation
{
    char id_reservation[20];
    Date date_reservation;
    int nb_nuit;
    Date debut_sejour;
    Date fin_sejour;
    float montant_avance;
    char id_client[20];
    int num_chambre;
};
///***Cellule de Client*///
typedef struct Cellule_Client Cellule_Client;
struct Cellule_Client
{
    Client client;
    Cellule_Client *prev;
    Cellule_Client *next;
};
///***liste des Clients*///
typedef struct liste_Client liste_Client;
struct liste_Client
{
    Cellule_Client *First;
    Cellule_Client *Last;
};
///***Cellule de Chambre*///
typedef struct Cellule_Chambre Cellule_Chambre;
struct Cellule_Chambre
{
    Chambre chambre;
    Cellule_Chambre *prev;
    Cellule_Chambre *next;
};
///***liste des Chambres*///
typedef struct liste_Chambre liste_Chambre;
struct liste_Chambre
{
    Cellule_Chambre *First;
    Cellule_Chambre *Last;
};
///***Cellule de Reservation*///
typedef struct Cellule_Reservation Cellule_Reservation;
struct Cellule_Reservation
{
    Reservation reservation;
    Cellule_Reservation *prev;
    Cellule_Reservation *next;
};
///***liste des Clients*///
typedef struct liste_Reservation liste_Reservation;
struct liste_Reservation
{
    Cellule_Reservation *First;
    Cellule_Reservation *Last;
};
///***************************

void init_Client_liste(liste_Client *Lc);
void init_Chambre_liste(liste_Chambre *Lch);
void init_Reservation_liste(liste_Reservation *Lr);
void init_toute_liste(liste_Client *Lc,liste_Chambre *Lch,liste_Reservation *Lr);
int check_num_Client(liste_Client *Lc,char num[20]);
Cellule_Client *cree_Cellule_Client(liste_Client *Lc);
void nouveau_Client(liste_Client *lc,Cellule_Client *S);
void consulter_Client(Cellule_Client *S);
void consulter_all_Clients(liste_Client *lc);
void modifier_Client(liste_Client *lc);
void supprimer_Client(liste_Client *lc);
void navigation_Client(liste_Client *lc);
int menu();
int bar_menu();
void Charger_Fclient(liste_Client *cl);
void Supprimer_Fclient();
void Sauvgarder_Fclient(liste_Client *cl);
int check_num_Chambre(liste_Chambre *Lc,int num);
Cellule_Chambre *cree_Cellule_Chambre(liste_Chambre *Lc);
void nouveau_Chambre(liste_Chambre *lc,Cellule_Chambre *S);
void consulter_Chambre(Cellule_Chambre *S);
void consulter_all_Chambre(liste_Chambre *lc);
void modifier_Chambre(liste_Chambre *lc);
void supprimer_Chambre(liste_Chambre *lc);
void navigation_Chambre(liste_Chambre *lc);
void Charger_Fchambre(liste_Chambre *cl);
void Supprimer_Fchambre();
void Sauvgarder_Fchambre(liste_Chambre *cl);
int check_num_Reservation(liste_Reservation *Lc,char num[20]);
int check_type_Chambre(liste_Chambre *Lc,char type[20],int num_prec);
Date Date_fin_sejour(liste_Reservation *Lrv,int num_ch);
int comparerDates( Date date1, Date date2);
int difference_dates(Date date1, Date date2);
Cellule_Reservation *cree_Cellule_Reservation(liste_Reservation *Lrv,liste_Client *Lcl,liste_Chambre *Lch);
void nouveau_Reservation(liste_Reservation *lc,Cellule_Reservation *S);
void consulter_Reservation(Cellule_Reservation *S);
void consulter_all_Reservation(liste_Reservation *lc);
void supprimer_Reservation(liste_Reservation *lc);
void modifier_Reservation(liste_Reservation *lc,liste_Client *Lcl,liste_Chambre *Lch);
void navigation_Reservation(liste_Reservation *lc);
void Charger_Freservation(liste_Reservation *cl);
void Supprimer_Freservation() ;
void Sauvgarder_Freservation(liste_Reservation *cl);
void Reservation_en_cours(liste_Reservation *lrv,liste_Client *lcl,liste_Chambre *lch );
void Facture(liste_Reservation *lrv,liste_Client *lcl ,liste_Chambre *lch);





















#endif // FONCTIONS_H_INCLUDED
