//
// Created by Lex on 02/12/20.
//

#ifndef LISTLINEARREK_LLR_H
#define LISTLINEARREK_LLR_H
/* contoh ADT list berkait dengan representasi fisik pointer secara rekursif */
/* Representasi address dengan pointer */
/* infotype adalah integer */
/* Program   : LLR.h */
/* Deskripsi : file Header modul list rekursif */
/* NIM/Nama  : 24010316140048 / Ahmad Alexander*/
/* Tanggal   :2 Desember 2020 */
/***********************************/
#include <stdlib.h>
#include <stdio.h>
#include "boolean.h"
#include "curses.h"
#define Nil NULL
#define info(P) (P)->info
#define next(P) (P)->next
#define First(L) ((L).First)

typedef int infotype;
typedef struct tElmtlist *address;
typedef struct tElmtlist {
    infotype info;
    address next;
} ElmtList;

/* Definisi list : */
/* List kosong : First(L) = Nil */
/* Setiap elemen dengan address P dapat diacu info(P), Next(P) */
/* Elemen terakhir list : jika addressnya Last, maka Next(Last)=Nil */
typedef  address List;

/****************** PEMBUATAN LIST KOSONG ******************/
/* I.S. sembarang */
/* F.S. Terbentuk list kosong */
void CreateList (List * L);

/****************** Manajemen Memori ******************/
/* Mengirimkan address hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka address tidak nil, dan misalnya */
/* menghasilkan P, maka info(P)=X, Next(P)=Nil */
/* Jika alokasi gagal, mengirimkan Nil */
address Alokasi (infotype X);

/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian address P */
void Dealokasi (address P);

/* PROTOTYPE */
/* menghasilkan true jika list kosong */
boolean IsEmpty (List L);

/* I.S. L terdefinisi */
/* F.S. Setiap elemen list diprint*/
void PrintList(List L);

/*Mengirimkan banyaknya elemen list L, Nol jika L kosong*/
int NBElmtlist(List L);

/* I.S. L terdefinisi */
/*F.S. N berisi banyaknya elemen list*/
void NBElmtlist1(List L, int * N);

/*I.S. L terdefinisi*/
/*F.S. N berisi banyaknya elemen list*/
void NBElmtlistAcc(List L, int * ACC, int * N);

/*Mengirim true jika X adalah anggota list, false jika tidak*/
boolean Search(List L, infotype X);

/*Mengirimkan elemen pertama sebuah list L yang tidak kosong*/
List FirstElmt(List L);

/*Mengirimkan list L tanpa elemen pertamanya, mungkin yang dikirimkan adalah sebuah list kosong*/
List Tail(List L);

/*Mengirimkan list L dengan tambahan e sebagai elemen pertamanya*/
/*Jika alokasi gagal, mengirimkan L */
List Konso(List L, infotype e);

/*Mengirimkan list L dengan tambahan e sebagai elemen terakhir*/
/*Jika alokasi gagal, mengirimkan L*/
List Kons0(List L, infotype e);

/*Mengirimkan salinan list L*/
/*Jika alokasi gagal, mengirimkan L*/
List Copy(List L);

/* I.S. Lin terdefinisi */
/* F.S. Lout berisi salinan dari Lin */
/* Proses : menyalin Lin ke Lout */
/*Jika alokasi gagal, Lout adalah ??? */
void MengCopy(List Lin, List * Lout);

/*Mengirimkan salinan hasil konkatenasi list L1 dan L2 */
List Concat(List L1, List L2);

/*Mengirimkan salinan hasil konkatenasi list L1 dan L2*/
void Meng_Concat(List L1, List L2, List * LHsl);

#endif //LISTLINEARREK_LLR_H
