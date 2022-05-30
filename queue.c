#ifndef QUEUE_C
#define QUEUE_C

#include "queue.h"

//////////// VARIABEL GLOBAL //////////////

char *jenisPenyakit[9] = { // Daftar Jenis Penyakit //
	"Penyakit Kulit",
	"Luka Ringan",
	"Bersin",
	"Cacingan",
	"Diare",
	"Luka Dalam",
	"Kerongkongan Berlendir & Berbau Busuk",
	"Penyakit Kuning",
	"Terkena Virus"
};
int tempWaktuDatangPertama; // variabel untuk menyimpan waktu datang pasien pertama
infoPasien latest; // info pasien yang sudah dihapus

////////////////////////////////////////////


void CreateQueue (Queue *Q){
	// Algoritma
	HEAD(*Q) = NULL;
	TAIL(*Q) = NULL;
}

addrQ Alokasi (infoPasien X){
	// Kamus Lokal
	addrQ P;
	P = (addrQ)malloc(sizeof(NodeQueue));
	
	// Algoritma
	if (P!=NULL){
		Info(P) = X;
		Next(P) = NULL;
		return P;
	}else{
		return NULL;
	}
}


void Dealokasi (addrQ P){
	// Algoritma
	Next(P) = NULL;
	free(P);
}

boolean IsQueueEmpty(Queue Q){
	// Algoritma
	return (HEAD(Q)==NULL && TAIL(Q)==NULL);
}


void DelQueue (Queue *Q){
	// Kamus Lokal
	addrQ P;
	
	// Algoritma
	if (!IsQueueEmpty(*Q)){
		P = HEAD(*Q);
		HEAD(*Q) = Next(HEAD(*Q));
		Next(P) = NULL;
		Dealokasi (P);
	}else{
		printf("Antrian Kosong!");
	}
}

void AddQue(Queue *Q, infoPasien X){ 
	// kamus lokal //
	addrQ P,last;
	
	// algoritma //
	P = Alokasi (X);
	if (IsQueueEmpty(*Q)){
		Next(P) = HEAD(*Q);
		HEAD(*Q) = P;
	}else{
		last = HEAD(*Q);
		while (Next(last) != NULL){
			last = Next(last);
		} 
		Next(last) = P;
		TAIL(*Q) = P;
		SortInfo(*Q);
	}
}

void LihatDaftarAntrian(Queue Q){
	// kamus lokal //
	addrQ P;
	int i=0;
	
	// algoritma //
	system("cls");
	P = HEAD(Q);
	printf("				    \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\n");
	printf("					      DAFTAR ANTRIAN\n");
	printf("				    \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\n");
	if (P == NULL){
		printf("\n	                               ** ANTRIAN MASIH KOSONG! **\n");
	}else{
		while (P != NULL){
			i++;
			printf("				    		   NO.%d\n", i);
			printf("				    Nama Hewan              : %s\n", Info(P).nama);
			printf("				    Datang Menit ke         : %d\n", Info(P).waktuDatang);
			printf("				    Waktu Layanan           : %d Menit\n", Info(P).waktuPelayanan);
			printf("				    Jenis Penyakit          :\n");
			PrintInfo(Info(P).listPenyakit, jenisPenyakit);
			printf("				    Waktu Tunggu Pelayanan  : %d Menit\n", Info(P).waktuTunggu);
			printf("				    Nilai Prioritas         : %d\n", Info(P).nilaiPrioritas);
			printf("				    Waktu Mulai Pelayanan   : Menit Ke-%d\n", Info(P).waktuMulai);
			printf("				    Waktu Selesai Pelayanan : Menit Ke-%d\n", Info(P).waktuAkhir);
			printf("				    \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\n");
			P = Next(P);
		}
	}
}

/* OTHERS */
 
// Sorting Berdasarkan Nilai Prioritas
void SortByValuePriority(Queue Q){
	// Kamus Lokal
	addrQ P,setelah;
	infoPasien temp;
	
	// Algoritma
	if (IsPasienPertama(Q)){
		P = Next(HEAD(Q));
	}else{
		P = HEAD(Q);
	}
	while (P!=NULL){
		setelah = Next(P);
		
		while (setelah!=NULL){
			if (Info(P).nilaiPrioritas < Info(setelah).nilaiPrioritas){
				//swap Info
				temp = Info(P);
				Info(P) = Info(setelah);
				Info(setelah) = temp;		
			}
			setelah = Next(setelah);
		}
		P = Next(P);
	}
	
}

// Sorting Berdasarkan Waktu Datang
void SortByTimeArrive(Queue Q){
	// Kamus Lokal
	addrQ P,setelah;
	infoPasien temp;
	
	// Algoritma 
	if (IsPasienPertama(Q)){
		P = Next(HEAD(Q));
	}else{
		P = HEAD(Q);
	}
	while (P!=NULL){
		setelah = Next(P);
		
		while (setelah!=NULL){
			if (Info(P).waktuDatang > Info(setelah).waktuDatang && Info(P).nilaiPrioritas <= Info(setelah).nilaiPrioritas){
				//swap Info
				temp = Info(P);
				Info(P) = Info(setelah);
				Info(setelah) = temp;		
			}
			setelah = Next(setelah);
		}
		P = Next(P);
	}
}

// Sorting Info
void SortInfo(Queue Q){
	// Kamus Lokal
	addrQ P;
	infoPasien temp;
	
	// Algoritma 
	if (Info(HEAD(Q)).waktuDatang != 0){ //Handling jika Info waktu Datang di Head tidak sama dengan 0
		P = HEAD(Q);
		while(P!=NULL){
			if(Info(P).waktuDatang == 0){
				// swap //
				temp = Info(P);
				Info(P) = Info(HEAD(Q));
				Info(HEAD(Q)) = temp;
				break;
			}
			P = Next(P);
		}
	}
	// Memulai Sorting
	SortByValuePriority(Q);
	SortByTimeArrive(Q);
}


// Function yang berfungsi untuk menentukan kategori penyakit berdasarkan jenis penyakit yang dipilih
char *kategoriPenyakit(int Penyakit){
	// Algoritma 
	if (Penyakit >= 1 && Penyakit <= 3 ){
		return "Ringan";
	} else if (Penyakit >= 4 && Penyakit <= 6){
		return "Sedang";
	} else if (Penyakit >= 7 && Penyakit <= 9){
		return "Berat";
	}	
}

// Function yang berfungsi menghitung nilai prioritas
int HitungNilaiPrioritas(int Ringan, int Sedang, int Berat){
	// Kamus lokal
	int nilai = 1;
	
	// Algoritma 
	if (Berat >= 1){
		nilai += 3;
	}
	else if (Sedang >= 2){
		nilai += 2;
	}
	else if (Ringan >= 3){
		nilai += 1;
	}
	
	return nilai;
}

// Function yang berfungsi untuk mengecek waktu Pelayanan berdasarkan jenis penyakit yang dipilih
int CekWaktuPelayanan(int Penyakit){	
	// Algoritma 
	if (Penyakit >= 1 && Penyakit <= 3 ){
		return 15;
	} else if (Penyakit >= 4 && Penyakit <= 6){
		return 30;
	} else if (Penyakit >= 7 && Penyakit <= 9){
		return 45;
	}
}

// Function yang berfungsi untuk menghitung waktu Pelayanaan
int HitungWaktuPelayanan(int Ringan, int Sedang, int Berat){
	// Algoritma
	return (Ringan*15) + (Sedang*30) + (Berat*45);
}

// Procedure yang berfungsi untuk menghitung Nilai (waktu) yang dinamis
// Maksud dinamis disini yaitu Nilai yang berubah karena Kondisi Queue yang di sorting.
// Nilai (waktu) dinamisnya yaitu : Waktu Tunggu, Wwaktu Mulai, dan Waktu Akhir
void HitungWaktuMulaiAkhirTunggu(Queue *Q){
	// Kamus Lokal 
	addrQ P,sebelum;
	
	// Algoritma
	P = HEAD(*Q);
	
	// Inisialisasi waktu Tunggu, waktu Mulai, dan waktu Akhir Untuk Info di HEAD.
	if (IsPasienPertama(*Q)){ //Menghitung waktu tunggu, mulai, dan akhir di head jika pasien pertama
		Info(P).waktuTunggu = 0;
		Info(P).waktuMulai = Info(P).waktuDatang;
		Info(P).waktuAkhir = Info(P).waktuDatang + Info(P).waktuPelayanan;
	}else if (P == HEAD(*Q)){ //Menghitung waktu tunggu, mulai, dan akhir di head jika bukan pasien pertama
		Info(P).waktuTunggu = latest.waktuAkhir - Info(P).waktuDatang;
		Info(P).waktuMulai = Info(P).waktuTunggu + Info(P).waktuDatang;
		Info(P).waktuAkhir = Info(P).waktuMulai + Info(P).waktuPelayanan;
	}
	sebelum = P;
	P = Next(P);
		while(P != NULL){ // Jika Isi Queue nya lebih dari satu node
			Info(P).waktuTunggu = Info(sebelum).waktuAkhir - Info(P).waktuDatang;
			Info(P).waktuMulai = Info(P).waktuTunggu + Info(P).waktuDatang;
			Info(P).waktuAkhir = Info(P).waktuMulai + Info(P).waktuPelayanan; 
			sebelum = P;
			P = Next(P);
		}	
}

void PrintDaftarPenyakit(){
	int i;
	printf("\n				___________________________________________\n");
	printf("			       |	    - DAFTAR PENYAKIT -            |\n");
	printf("                               |                                           |\n");
	for (i=0;i<9;i++){
		printf("			       |%d. %-40s|\n", i+1, jenisPenyakit[i]);
	}
	printf("			       |___________________________________________|\n");
}

void Registrasi (Queue *Q){
	system("cls");
	// Kamus lokal 
	infoPasien X;
	infoPenyakit Y;
	int jumlahPenyakit,i;
	int CountRingan = 0;
	int CountSedang = 0;
	int CountBerat = 0;
	
	// Algoirtma
	CreateList(&X.listPenyakit);
	
	printf("				    \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\n");
	printf("					        REGISTRASI\n");
	printf("				    \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\n");
	printf("					Nama Hewan\t: ");
	scanf("%s", &X.nama); fflush(stdin);
	printf("					Waktu Datang\t: ");
	scanf("%d", &X.waktuDatang); fflush(stdin);
	if (IsQueueEmpty(*Q)){
		tempWaktuDatangPertama = X.waktuDatang;
	}
	PrintDaftarPenyakit();
	printf("\n					Jumlah Penyakit\t\t: ");
	scanf("%d", &jumlahPenyakit);
	printf("					Pilih No.Jenis Penyakit\t: \n");
	for (i=0;i<jumlahPenyakit;i++){
		printf("					                          ");
		scanf("%d", &Y.Penyakit); fflush(stdin);
		strcpy(Y.kategori, kategoriPenyakit(Y.Penyakit));
		Y.waktuEstimasi = CekWaktuPelayanan(Y.Penyakit);
		InsertLast(&X.listPenyakit, Y);
		if (Y.Penyakit > 0 && Y.Penyakit < 4){
			CountRingan++;
		}else if (Y.Penyakit > 3 && Y.Penyakit < 7){
			CountSedang ++;
		}else if (Y.Penyakit > 6 && Y.Penyakit < 10){
			CountBerat ++;
		}
	}
	X.nilaiPrioritas = HitungNilaiPrioritas (CountRingan,CountSedang,CountBerat);
	X.waktuPelayanan = HitungWaktuPelayanan (CountRingan,CountSedang,CountBerat);
	AddQue (&(*Q),X);
	HitungWaktuMulaiAkhirTunggu (&(*Q));
	printf("\n\n");
	printf("	                          ======= HEWAN ANDA TELAH TERDAFTAR! ========\n");
	
}

void ProsesAntrian(Queue *Q){
	system("cls");
	// Kamus //
	addrQ P;
	char inputProses[5];
	
	// Algoritma //
	P = HEAD(*Q);
	
	printf("				    \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\n");
	printf("					     PROSES ANTRIAN!\n");
	printf("				    \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\n");
	if (P == NULL){
		printf("\n	                               ** ANTRIAN MASIH KOSONG! **\n");
	}else{
			printf("				    Nama Hewan              : %s\n", Info(P).nama);
			printf("				    Datang Menit ke         : %d\n", Info(P).waktuDatang);
			printf("				    Waktu Layanan           : %d Menit\n", Info(P).waktuPelayanan);
			printf("				    Jenis Penyakit          :\n");
			PrintInfo(Info(P).listPenyakit, jenisPenyakit);
			printf("				    Waktu Tunggu Pelayanan  : %d Menit\n", Info(P).waktuTunggu);
			printf("				    Nilai Prioritas         : %d\n", Info(P).nilaiPrioritas);
			printf("				    Waktu Mulai Pelayanan   : Menit Ke-%d\n", Info(P).waktuMulai);
			printf("				    Waktu Selesai Pelayanan : Menit Ke-%d\n", Info(P).waktuAkhir);
			printf("				    \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\n");
			printf("\n\n				    Memulai Proses untuk %s? [YES/NO] ", Info(P).nama);
			P = Next(P);
			scanf("%s", inputProses);
			if (strcmp(inputProses, "YES") == 0 || strcmp(inputProses, "yes") == 0){
				latest = Info(HEAD(*Q));
				DelQueue (&(*Q));
				printf("\n				** SABAR YA KUCING MU SEDANG PROSES PENGOBATAN **\n");
				printf("				                       ^_^\n");
			}else if (strcmp(inputProses, "NO") == 0 || strcmp(inputProses, "no") == 0){
				printf("\n				            ** KEMBALI KE MENU **\n");
			}			
	}
}

boolean IsPasienPertama(Queue Q){
	return (tempWaktuDatangPertama == Info(HEAD(Q)).waktuDatang);
}

#endif
