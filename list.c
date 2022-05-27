#ifndef LIST_C
#define LIST_C

#include "list.h"

/* ** Prototype   **  */
/* ** Test List Kosong **  */
boolean ListEmpty(List  L)                        
{  /*  Mengirim true jika List kosong  */

   	return(First(L)==NULL);	
}

/* Pembuatan  List Kosong  */
void CreateList(List *L)
{  /* I.S  :  Sembarang    		*/
   /* F.S  :  Terbentuk  List kosong  	*/
   First(*L)=NULL;
}

/* ********  MANAJEMEN MEMORY  ********* */
address Alloct(infoPenyakit  X)
{/* Mengirimkan  address  hasil alokasi    sebuah elemen */
 /* Jika alokasi  berhasil, maka  address tidak NULL, dan misalnya  */
 /* menghasilkan   P,  maka info(P)=X,  Next(P)=NULL;               */
 /* Jika alokasi  gagal,  mengirimkan  NULL 			   */
   address P;
   P=(address)malloc(sizeof(NodeList));
   if(P!=NULL) { /* Berhasil  */
   		Info(P)=X;
		Next(P)=NULL;
   }
   return P;	   
}

void Dealloct(address *P)
{ /* I.S  : P terdefinisi      				*/
  /* F.S  : P dikembalikan ke  sistem 			*/
  /*   	    Melakukan dealokasi, pengembalian address P */
    Next(*P)=NULL; 	
    free(*P);	
}

/*   ** PENCARIAN SEBUAH ELEMEN LIST **   */   

boolean FSearch(List L, address P)
{ /* Mencari apakah ada elemen List yang beralamat P  */
  /* Mengirimkan true jika ada, false jika tidak ada  */
  /* List Tidak mungkin kosong  */

  address PTemp=First(L);
  boolean found=false;
  
  while((PTemp!=NULL)&&(!found)){
    if(PTemp==P) {
		found=true;
    } else { 
		PTemp=Next(PTemp);     
    }
      
  } /* PTemp==NULL or found / ketemu */
  return found;
}

/* ** PRIMITIF BERDASARKAN NULLAI ** */

/* ** Penambahan Elemen ** */
void InsertFirst(List *L, infoPenyakit X)
{  /* I.S  : L mungkin kosong          */
   /* F.S  : Melakukan alokasi sebuah elemen dan             */
   /*        menambahkan elemen pertama dengan NULLai X jika  */
   /*        Alokasi berhasil 				     */
   address P=Alloct(X);
   if(P!=NULL) { /* Alokasi Berhasil */
       Next(P)=First(*L);
       First(*L)=P;
	}
}

void InsertLast(List *L, infoPenyakit X)
{ /* I.S  : L mungkin kosong          */
  /* F.S  : Melakukan alokasi sebuah elemen dan                */
  /*        menambahkan elemen list di akhir; elemen terakhir  */
  /*        yang baru berNULLai X jika alokasi berhasil,        */	
  /*	    Jika alokasi gagal: I.S = F.S		       */
      	
     address P=Alloct(X);
     if(P!=NULL){
		address Last;
	      if(ListEmpty(*L)) { /* Jika kosong, Insert elemen pertama */
		        Next(P)=First(*L);
	       		First(*L)=P;     
	      } else { /* tdk kosong */
		    Last=First(*L);  
	            while(Next(Last)!=NULL)  { /* menuju ke last */
		          Last=Next(Last);
		    } /* Next(Last)==NULL */
		  
		  Next(Last)=P;	  
	      }
     }
}

/* *** Penghapusan Elemen  ***  */

void DelFirst(List *L, infoPenyakit *X)
{ /* I.S    : List tidak kosong  		                 */
  /* F.S    : Elemen pertama List dihapus, NULLai info disimpan   */
  /*	      pada X dan alamat elemen pertama  di-dealokasi 	 */
  /* Kamus */
  address  P;
  
   P=First(*L);
    First(*L)=Next(First(*L));
    Next(P)=NULL;
  *X=Info(P); 		/* info dari First disimpan di X       */
  Dealloct(&P);	  
}

void DelLast(List *L, infoPenyakit *X)
{  /* I.S    : List tidak kosong  		                 */
   /* F.S    : Elemen terakhir list dihapus, NULLai info disimpan */
   /*	      pada X dan alamat elemen terakhir di-dealokasi 	 */
   address P;
   address Last,PrecLast;
  
  Last=First(*L);
  /* dari catatan di kelas */	
  if(Next(Last)==NULL)  { /* hanya 1 elemen */
	  P=First(*L);
      First(*L)=Next(First(*L));
      Next(P)=NULL;
  }	else { /* Lebih dr 1 elemen */
	  PrecLast=NULL;
	  while(Next(Last)!=NULL){   /* Maju sampai elemen terakhir */
		  PrecLast=Last;     
		  Last=Next(Last);
	  } /* Next(Last)=NULL */
	  P=Last;
	  Next(PrecLast)=NULL;
    }
        /* Hapus Elemen Terakhir, addressnya disimpan di P, */
        /* Belum diDealokasi, masih bisa dibaca isinya      */
   *X=Info(P);	/* Info dari address P, ditampung  */ 
   Dealloct(&P);
}
	

void InsertAfter(List *L, address P, address Prec)
{ /* I.S   : Prec pastilah elemen  dan bukan elemen terakhir  */
  /*         P sudah dialokasi 					  */
  /* F.S   : Insert P sebagai elemen sesudah elemen beralamat Prec*/
	Next(P)=Next(Prec);
	Next(Prec)=P;
}

void PrintInfo(List L, char **kategoriPenyakit)
{ 
	/* Kamus Lokal */
    address P;

    /* Algoritma */
    P = First(L);
    if (P == NULL) {
      printf("List kosong\n");
    }else{
    	int i = 0;
    	do{
    		printf("                                                              %d. %s (%s)\n", i+1, kategoriPenyakit[Info(P).Penyakit-1], Info(P).kategori);
    		i++;
    		P=Next(P);
		}while (P!=NULL);
	}
}

int NbElmt(List L)
{ /* Mengirimkan banyaknya elemen list, mengirimkan Nol jika kosong */
  address P;
  int NbEl=0;
  if(ListEmpty(L)){
 	return 0;
  } else { /* Tidak kosong */
	      P=First(L);
       	  do {
		    	NbEl++;  
		    	P=Next(P);  
	      }while(P!=NULL);
  	}
    return NbEl;		      
}

void DelAll(List *L)
{ /* Delete semua elemen list, dan alamat elemen di-dealokasi */
   infoPenyakit X;
   while(!ListEmpty(*L)) {
	  DelFirst(&(*L),&X);
   } /* kosong */
}


void DelAfter (List *L, char *X) {
	/* Kamus Lokal */
	address P, Prec;
	infoPenyakit Y;
	boolean kehapus;
	/* Algoritma*/
	kehapus = false;
	P = First(*L);
	if (strcmp(Info(P).kategori,X) == 0) {
		DelFirst(L,&Y);
	} else {
		Prec = NULL;
		while ((P != NULL)&&(!kehapus)) {
			if (strcmp(Info(P).kategori,X) == 0) {
				P=Next(Prec);
				Next(Prec)=Next(P);
				Dealloct(&P);
        		kehapus = true;
      		}else {
        		Prec = P;
       			P = Next(P);
      		}
    	}
  	}
}


#endif
