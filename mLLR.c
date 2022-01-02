/* contoh ADT list berkait dengan representasi fisik pointer secara rekursif */
/* Representasi address dengan pointer */
/* infotype adalah integer */
/* Program   : LLR.h */
/* Deskripsi : file Driver modul list rekursif */
/* NIM/Nama  : 24010316140048 / Ahmad Alexander*/
/* Tanggal   :05 November 2020 */

#include "LLR.h"

/* Tambahan Tugas Praktikum: Studi Rekursif dalam konteks prosedural, tanpa ADT tipe bentukan */
/* Mengirim N! sesuai dengan definisi faktorial definisi rekursif: 0!=1; 1!=1; N! = N* (N-1)! */
long int factorial(int N);

/* Mengirim N! sesuai dengan definisi faktorial: 1*1*2*3*4 * .... (N-1)*N */
long int factorial1(int N);

/* Mengirim N! sesuai dengan definisi faktorial: N*N-1*N-2 * ... 3 * 2 * 1  */
long int factorial2(int N);

/* I.S. N>0
 F.S. F=N!
Proses : menghasilkan N! dengan memanggil prosedur iterasi yang sesuai */
void factorial3(int N, int *F);

/* I.S.
 * F.S.
 * Proses : Mengirim N! sesuai dengan definisi faktorial */
void factIter(int N, int *Akumulator, int *F);

/* I.S.
 * F.S.
 * Proses : menghasilkan N! yang salah. Mengapa ?? */
void factorialSalah1(int N, int *F);

/* I.S.
 * F.S.
 * Proses : menghasilkan N! yang salah. Mengapa ?? */
void factorialSalah2(int N, int *F);

/* I.S.
 * F.S.
 * Proses : menghasilkan N! yang salah. Mengapa ?? */
void factorialX(int N, int *F);

int main() {
    //kamus lokal
    List L1, L2, L3, L4, L5, L6, L7;
    infotype a, b, c, d, e, f, g, h, i, j, k;
    int x, y, z, n, A, B;

    //algoritma
//    printf("Tambahan tugas praktikum\n");
//    n = 12;
//    printf("Factorial of %d = %d", n, factorial(n));
//    n = 7;
//    printf("\nFactorial1 of %d = %d", n, factorial1(n));
//    n = 5;
//    printf("\nFactorial2 of %d = %d", n, factorial2(n));
//    n = 4;
//    A = 1;
//    printf("\nFactorial3 of %d = ", n);
//    factorial3(n, &A);
//    printf("%d", A);
//    n = 12;
//    A = 1;
//    printf("\nWrong Factorial1 of %d = ", n);
//    factorialSalah1(n, &A);
//    printf("%d", A);
//    n = 7;
//    A = 1;
//    printf("\nWrong Factorial2 of %d = ", n);
//    factorialSalah2(n, &A);
//    printf("%d", A);
//    n = 5;
//    A = 1;
//    printf("\nWrong FactorialX of %d = ", n);
//    factorialX(n, &A);
//    printf("%d", A);

    printf("Creating List L1\n");
    CreateList(&L1);
    printf("Is L1 empty List? ");
    if(IsEmpty(L1)==1){
        printf("Yup\n");
    }else{
        printf("Nah\n");
    }
    printf("Inserting 10 to Head List L1 = ");
    a = 10;
    L1 = Konso(L1, a);
    PrintList(L1);
    printf("\nInserting 20 to Tail L1 = ");
    b = 20;
    L1 = Kons0(L1, b);
    PrintList(L1);
    printf("\nInserting 30 to Tail L1 = ");
    c = 50;
    L1 = Kons0(L1, c);
    PrintList(L1);
    printf("\nInserting 9 to Head List L1 = ");
    d = 9;
    L1 = Konso(L1, d);
    PrintList(L1);
    printf("\nIs L1 now empty List? ");
    if(IsEmpty(L1)==1){
        printf("Yup");
    }else{
        printf("Nah");
    }
    printf("\nNBElmtlist in List L1 = %d", NBElmtlist(L1));
    x = 0;
    NBElmtlist1(L1, &x);
    printf("\nNBElmtlist1 in List L1 = %d ", x);
    y = 0;
    z = 0;
    NBElmtlistAcc(L1, &y, &z);
    printf("\nNBElmtlistAcc in List L1 = %d, %d", y, z);
    printf("\nFirst Element of L1 = %d", FirstElmt(L1));
    printf("\nTail of L1 = ");
    PrintList(Tail(L1));
    printf("\nDoes value 20 exist in L1? ");
    if (Search(L1, 20)==1){
        printf("Yup");
    }else{
        printf("Nope");
    }
    printf("\nDoes value 100 exist in L1? ");
    if (Search(L1, 100)==1){
        printf("Yup");
    }else{
        printf("Nope");
    }
    printf("\n\nCopy List L1 to L2 = ");
    CreateList(&L2);
    L2 = Copy(L1);
    PrintList(L2);
    printf("\nNBElmtlist in List L2 = %d", NBElmtlist(L2));
    x = 0;
    NBElmtlist1(L2, &x);
    printf("\nNBElmtlist1 in List L2 = %d ", x);
    y = 0;
    z = 0;
    NBElmtlistAcc(L2, &y, &z);
    printf("\nNBElmtlistAcc in List L2 = %d, %d", y, z);
    printf("\nFirst Element of L2 = %d", FirstElmt(L2));
    printf("\nTail of L2 = ");
    PrintList(Tail(L2));
    printf("\n\nMenCopy List L1 to L3 = ");
    MengCopy(L1, &L3);
    PrintList(L3);
    printf("\nNBElmtlist in List L3 = %d", NBElmtlist(L3));
    x = 0;
    NBElmtlist1(L3, &x);
    printf("\nNBElmtlist1 in List L3 = %d ", x);
    y = 0;
    z = 0;
    NBElmtlistAcc(L3, &y, &z);
    printf("\nNBElmtlistAcc in List L3 = %d, %d", y, z);
    printf("\nFirst Element of L3 = %d", FirstElmt(L3));
    printf("\nTail of L3 = ");
    PrintList(Tail(L3));
    printf("\nCreating List L4\n");
    CreateList(&L4);
    e = 11;
    f = 13;
    g = 100;
    h = 99;
    i = 28;
    printf("Inserting 28 to Head List L4\n");
    L4 = Konso(L4, 28);
    PrintList(L4);
    printf("\nInserting 13 to Head List L4\n");
    L4 = Konso(L4, 13);
    PrintList(L4);
    printf("\nInserting 11 to Head List L4\n");
    L4 = Konso(L4, 11);
    PrintList(L4);
    printf("\nInserting 99 to Tail List L4\n");
    L4 = Kons0(L4, 99);
    PrintList(L4);
    printf("\nInserting 100 to Tail List L4\n");
    L4 = Kons0(L4, 100);
    PrintList(L4);
    printf("\nNBElmtlist in List L4 = %d", NBElmtlist(L4));
    x = 0;
    NBElmtlist1(L4, &x);
    printf("\nNBElmtlist1 in List L4 = %d ", x);
    y = 0;
    z = 0;
    NBElmtlistAcc(L4, &y, &z);
    printf("\nNBElmtlistAcc in List L4 = %d, %d", y, z);
    printf("\nFirst Element of L4 = %d", FirstElmt(L4));
    printf("\nTail of L4 = ");
    PrintList(Tail(L4));
    printf("\n\nCreating List L5 as concatenation of L1 and L4 = ");
    CreateList(&L5);
    L5 = Concat(L1, L4);
    PrintList(L5);
    printf("\nNBElmtlist in List L5 = %d", NBElmtlist(L5));
    x = 0;
    NBElmtlist1(L5, &x);
    printf("\nNBElmtlist1 in List L5 = %d ", x);
    y = 0;
    z = 0;
    NBElmtlistAcc(L5, &y, &z);
    printf("\nNBElmtlistAcc in List L5 = %d, %d", y, z);
    printf("\nFirst Element of L5 = %d", FirstElmt(L5));
    printf("\nTail of L5 = ");
    PrintList(Tail(L5));
    printf("\n\nCreating List L6\n");
    j = 33;
    k = 52;
    CreateList(&L6);
    printf("Inserting 52 to Head List L6\n");
    L6 = Konso(L6, 52);
    PrintList(L6);
    printf("\nInserting 33 to Tail List L6\n");
    L6 = Kons0(L6, 33);
    PrintList(L6);
    printf("\nNBElmtlist in List L6 = %d", NBElmtlist(L6));
    x = 0;
    NBElmtlist1(L6, &x);
    printf("\nNBElmtlist1 in List L6 = %d ", x);
    y = 0;
    z = 0;
    NBElmtlistAcc(L6, &y, &z);
    printf("\nNBElmtlistAcc in List L6 = %d, %d", y, z);
    printf("\nFirst Element of L6 = %d", FirstElmt(L6));
    printf("\nTail of L6 = ");
    PrintList(Tail(L6));
    printf("\n\nList L7 is Meng_Concatenation of L6 and L5 = ");
    Meng_Concat(L6,L5,&L7);
    PrintList(L7);
    printf("\nNBElmtlist in List L7 = %d", NBElmtlist(L7));
    x = 0;
    NBElmtlist1(L7, &x);
    printf("\nNBElmtlist1 in List L7 = %d ", x);
    y = 0;
    z = 0;
    NBElmtlistAcc(L7, &y, &z);
    printf("\nNBElmtlistAcc in List L7 = %d, %d", y, z);
    printf("\nFirst Element of L7 = %d", FirstElmt(L7));
    printf("\nTail of L7 = ");
    PrintList(Tail(L7));
    printf("\nDoes value 53 exist in L7? ");
    if (Search(L7, 53)==1){
        printf("Yup");
    }else{
        printf("Nope");
    }
    printf("\nDoes value 99 exist in L7? ");
    if (Search(L7, 99)==1){
        printf("Yup");
    }else{
        printf("Nope");
    }

    return 0;
}

/* Tambahan Tugas Praktikum: Studi Rekursif dalam konteks prosedural, tanpa ADT tipe bentukan */
/* Mengirim N! sesuai dengan definisi faktorial definisi rekursif: 0!=1; 1!=1; N! = N* (N-1)! */
long int factorial(int N){
    //kamus lokal
    //algoritma
    if(N==0){
        return 1;
    }else{
        return N * factorial(N-1);
    }
}

/* Mengirim N! sesuai dengan definisi faktorial: 1*1*2*3*4 * .... (N-1)*N */
long int factorial1(int N){
    //kamus lokal
    int Count, F;

    //algoritma
    F = 1; //inisialisasi
    Count = 1; //first element
    while(Count<=N){
        F *= N;
        Count += 1;
    }
    return F;
}

/* Mengirim N! sesuai dengan definisi faktorial: N*N-1*N-2 * ... 3 * 2 * 1  */
long int factorial2(int N){
    //kamus lokal
    int F;

    //algoritma
    F = 1; //inisialisasi
    while(N>0){
        F *= N; //proses
        N -= 1; //next element
    }
    return F;
}

/* I.S. N>0
 F.S. F=N!
Proses : menghasilkan N! dengan memanggil prosedur iterasi yang sesuai */
void factorial3(int N, int *F){
    //kamus lokal
    int ACC;

    //algoritma
    ACC = 1;
    factIter(N,&ACC,F);
    printf("", F);
}

/* I.S.
 * F.S.
 * Proses : Mengirim N! sesuai dengan definisi faktorial */
void factIter(int N, int *Akumulator, int *F){
    //kamus lokal
    int ATemp;

    //algoritma
    if (N==0){
        (*F) = (*Akumulator);
    }else{
        ATemp = (*Akumulator) * N;
        factIter(N-1, &ATemp, F);
    }
}

/* I.S.
 * F.S.
 * Proses : menghasilkan N! yang salah. Mengapa ?? */
void factorialSalah1(int N, int *F){
    //kamus lokal
    //algoritma
    if (N==0){
        F = 1;
    }else{
        factorialSalah1(N-1, F);
        printf("", F);
    }
}

/* I.S.
 * F.S.
 * Proses : menghasilkan N! yang salah. Mengapa ?? */
void factorialSalah2(int N, int *F){
    //kamus lokal
    int Ftemp;

    //algoritma
    if (N==0){
        F = 1;
    }else{
        factorialSalah2(N-1, Ftemp);
    }
    F = Ftemp;
    printf("", F);
}

/* I.S.
 * F.S.
 * Proses : menghasilkan N! yang salah. Mengapa ?? */
void factorialX(int N, int *F){
    //kamus lokal
    int Ftemp;

    //algoritma
    if (N==0){
        F = 1;
    }else{
        factorialX(N-1, Ftemp);
    }
    F = Ftemp * N;
    printf("", F);
}


