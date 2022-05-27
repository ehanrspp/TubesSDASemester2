#ifndef LIST_H
#define LIST_H

#include <stdio.h>
#include "boolean.h"
#include <string.h>
#include <stdlib.h>

#define Info(P) (P)->info
#define Next(P) (P)->next
#define First(L) (L).First

typedef struct{
	int Penyakit;
	int waktuEstimasi;
	char kategori[9];
}infoPenyakit;
typedef struct NodeList *address;
typedef struct NodeList{
	infoPenyakit info;
	address next;  
}NodeList;

typedef struct{
	address First;
}List;

/* ** Prototype   **  */
/* ** Test List Kosong **  */
boolean ListEmpty(List  L);                        
/*  Mengirim true jika List kosong  */

/* Pembuatan  List Kosong  */
void CreateList(List *L);
/* I.S  :  Sembarang    		*/
/* F.S  :  Terbentuk  List kosong  	*/

/* Manajeman  memory  			*/
address Alloct(infoPenyakit  X);
 /* Mengirimkan  address  hasil alokasi    sebuah elemen */
 /* Jika alokasi  berhasil, maka  address tidak nil, dan misalnya  */
 /* menghasilkan   P,  maka info(P)=X,  Nest(P)=Nil;               */
 /* Jika alokasi  gagal,  mengirimkan  Nil 			   */

void Dealloct(address *P);
/* I.S  :   P  terdefinisi         	*/
/* F.S  :   P dikembalikan ke  sistem 	*/
/*   	    Melakukan  dealokasi, pengembalian address  P */


/*   ** PENCARIAN SEBUAH ELEMEN LIST **   */

boolean FSearch(List L, address P);
/* Mencari apakah  ada elemen List yang  beralamat   P   */
/* Mengirimkan true jika ada, false jika tidak ada  	 */


/* ** PRIMITIF BERDASARKAN NILAI ** */

/* ** Penambahan Elemen ** */
void InsertFirst(List *L, infoPenyakit X);
/* I.S  : L mungkin kosong          */
/* F.S  : Melakukan alokasi sebuah elemen dan                */
/*        menambahkan elemen pertama dengan nilai X jika     */
/*        Alokasi berhasil 				     */

void InsertLast(List *L, infoPenyakit X);
/* I.S  : L mungkin kosong          */
/* F.S  : Melakukan alokasi sebuah elemen dan                */
/*        menambahkan elemen list di akhir; elemen terakhir  */
/*        yang baru bernilai X jika alokasi berhasil, 	     */	
/*	  Jika alokasi gagal: I.S = F.S			     */

/* *** Penghapusan Elemen  ***  */
	  

/* *******  PRIMITIF BERDASARKAN ALAMAT ********	*/
/* Penambahan Elemen Berdasarkan Alamat 		*/

void InsertAfter(List *L, address P, address Prec);
/* I.S   : Prec pastilah elemen list dan bukan elemen terakhir  */
/*         P sudah dialokasi 					*/
/* F.S   : Insert P sebagai elemen sesudah elemen beralamat Prec*/


/* ****** PENGHAPUSAN SEBUAH ELEMEN	*********   */
void DelFirst(List *L, infoPenyakit *X);
  /* I.S    : List tidak kosong  		                 */
  /* F.S    : Elemen pertama List dihapus, nilai info disimpan   */
  /*	      pada X dan alamat elemen pertama  di-dealokasi 	 */

void DelLast(List *L, infoPenyakit *X);
  /* I.S    : List tidak kosong  		                 */
  /* F.S    : Elemen terakhir list dihapus, nilai info disimpan  */
  /*	      pada X dan alamat elemen terakhir di-dealokasi 	 */

void DelAfter (List *L, char *X);
/* void DelP(List *L, infoPenyakit X);
/* I.S   : Sembarang  */
/* F.S   : Jika ada elemen  list beraddress P,dengan info (P)=X    */
/*         Maka P dihapus dari List dan di-dealokasi		   */
/*	   Jika tidak ada elemen List dengan info(P)=X, maka list  */
/*         tetap. List mungkin menjadi kosomg karena penghapusan   */


/* *************PROSES SEMUA ELEMEN ****************   */
void PrintInfo(List L, char **kategoriPenyakit);
/* I.S   : List mungkin kosong 	*/
/* F.S   : Jika list tidak kosong, semua info yang disimpan pada */
/*         elemen list di-print					 */
/*         Jika list kosong, hanya menuliskan "List Kosong"	 */

int NbElmt(List L);
/* Mengirimkan banyaknya elemen list, mengirimkan Nol jika kosong */

void DelAll(List *L);
/* Delete semua elemen list, dan alamat elemen di-dealokasi */

#endif
