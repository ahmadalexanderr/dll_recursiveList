//
// Created by Lex on 02/12/20.
//
/* contoh ADT list berkait dengan representasi fisik pointer secara rekursif */
/* Representasi address dengan pointer */
/* infotype adalah integer */
/* Program   : LLR.h */
/* Deskripsi : file Body modul list rekursif */
/* NIM/Nama  : 24010316140048 / Ahmad Alexander*/
/* Tanggal   :05 November 2020 */

#include "LLR.h"

/****************** PEMBUATAN LIST KOSONG ******************/
/* I.S. sembarang */
/* F.S. Terbentuk list kosong */
void CreateList (List * L){
    //kamus lokal
    //algoritma
    *L = Nil;
}

address Alokasi (infotype X){
    //kamus lokal
    address P;

    //algoritma
    P = (address)malloc(sizeof(ElmtList));
    if (P != Nil){
        info(P) = X;
        next(P) = Nil;
        return P;
    }else{
        return Nil;
    }
}

void Dealokasi (address P){
    //kamus lokal

    //algoritma
    info(P) = 0;
    next(P) = Nil;
    (P) = Nil;
}

/* PROTOTYPE */
/* menghasilkan true jika list kosong */
boolean IsEmpty (List L){
    return L == Nil;
}

/* I.S. L terdefinisi */
/* F.S. Setiap elemen list diprint*/
void PrintList(List L){
    if (IsEmpty(L)){
        return; //do nothing
    }else{
        printf("[%d]; ", info(L));
        PrintList(next(L));
    }
}

/*Mengirimkan banyaknya elemen list L, Nol jika L kosong*/
int NBElmtlist(List L){
    //kamus lokal
    //algoritma
    if (IsEmpty(L)){
        return 0;
    }else{
        return 1 + NBElmtlist(next(L));
    }
}

/* I.S. L terdefinisi */
/*F.S. N berisi banyaknya elemen list*/
void NBElmtlist1(List L, int * N){
    //kamus lokal
    int * N1;

    //algoritma
    if (IsEmpty(L)){
        (*N)= 0;
        printf("", N);
    }else {
        printf("", N);
        NBElmtlist1(next(L), N1);
        (*N) = 1 + (*N1);
    }
}

/*I.S. L terdefinisi*/
/*F.S. N berisi banyaknya elemen list*/
void NBElmtlistAcc(List L, int * Acc, int * N){
    //kamus lokal
    //algoritma
    if (IsEmpty(L)){
        (*N) = (*Acc);
        printf("", Acc, N);
    }else{
        (*Acc) = (*Acc) + 1;
        NBElmtlistAcc(next(L), Acc, N);
        printf("", Acc, N);
    }
}

/*Mengirim true jika X adalah anggota list, false jika tidak*/
boolean Search(List L, infotype X){
    //kamus lokal
    //algoritma
    if (IsEmpty(L)){
        return false;
    }
    if (info(L) == X){
        return true;
    }
    return Search(next(L), X);
}

/*Mengirimkan elemen pertama sebuah list L yang tidak kosong*/
List FirstElmt(List L){
    //kamus lokal
    //algoritma
    return info(L);
}

/*Mengirimkan list L tanpa elemen pertamanya, mungkin yang dikirimkan adalah sebuah list kosong*/
List Tail(List L){
    //kamus lokal
    //algoritma
    return next(L);
}

/*Mengirimkan list L dengan tambahan e sebagai elemen pertamanya*/
/*Jika alokasi gagal, mengirimkan L */
List Konso(List L, infotype e){
    //kamus lokal
    address P;

    //algoritma
    P = Alokasi(e);
    if (P==Nil){
        return L;
    }else{
        //insert first
        next(P) = L;
        return P;
    }
}

/*Mengirimkan list L dengan tambahan e sebagai elemen terakhir*/
/*Jika alokasi gagal, mengirimkan L*/
List Kons0(List L, infotype e){
    //kamus lokal
    address P, Last;

    //algoritma
    P = Alokasi(e);
    if (P == Nil){
        return L;
    }else{
        //insert last
        if (IsEmpty(L)){
            return L;
        }else{
            Last = L;
            while(next(Last)!=Nil){
                Last = next(Last);
            }
           //next(Last) == Nil adalah elemen terakhir
           //insert last
           next(Last) = P;
            return L;
        }
    }
}

/*Mengirimkan salinan list L*/
/*Jika alokasi gagal, mengirimkan L*/
List Copy(List L){
    //kamus lokal
    List newL;

    //algoritma
    if (IsEmpty(L)){
        return L;
    }else{
        newL = Alokasi(L);
        info(newL) = info(L);
        next(newL) = Copy(next(L));
        return newL;
    }
}

/* I.S. Lin terdefinisi */
/* F.S. Lout berisi salinan dari Lin */
/* Proses : menyalin Lin ke Lout */
/*Jika alokasi gagal, Lout adalah ??? */
void MengCopy(List Lin, List * Lout){
    //kamus lokal
    List *Ltemp;

    //algoritma
    CreateList(Lout);
    if (IsEmpty(Lin)){
        (*Lout) = Lin;
    }else{
        *Ltemp = Alokasi(Lin);
        info(*Ltemp) = info(Lin);
        next(*Ltemp) = Copy(next(Lin));
        (*Lout) = (*Ltemp);
    }
}

/*Mengirimkan salinan hasil konkatenasi list L1 dan L2 */
List Concat(List L1, List L2){
    //kamus lokal
    List LTemp;

    //algoritma
    if (IsEmpty(L1)){
        return Copy(L2);
    }else if (IsEmpty(L2)){
        return Copy(L1);
    }else{
//      return Konso(FirstElmt(L1), Concat(Tail(L1), L2));
        LTemp = Copy(L1);
        next(LTemp) = Concat(next(LTemp), L2);
        return LTemp;
    }
}

/*Mengirimkan salinan hasil konkatenasi list L1 dan L2*/
void Meng_Concat(List L1, List L2, List * LHsl){
    //kamus lokal
    //algoritma
    if (IsEmpty(L1)){
        (*LHsl) = Copy(L2);
    }else if (IsEmpty(L2)){
        (*LHsl) = Copy(L1);
    }
    else{
        //(*LHsl) = Konso(FirstElmt(L1), Concat(L1, Tail(L2)));
        (*LHsl) = Copy(L1);
        next(*LHsl) = Concat(next(*LHsl), L2);
    }
}
