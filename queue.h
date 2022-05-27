#ifndef QUEUE_H
#define QUEUE_H

#include <stdio.h>
#include "boolean.h"
#include "list.h"
#include <string.h>
#include <stdlib.h>

#define InfoHead(Q) (Q).HEAD->info
#define InfoTail(Q) (Q).TAIL->info
#define Info(P) (P)->info
#define Next(P) (P)->next
#define HEAD(Q) (Q).HEAD
#define TAIL(Q) (Q).TAIL

typedef struct{
	char nama[25];  // Nama Hewan
	int waktuDatang; // Waktu Kedatangan
	int waktuPelayanan; // lama waktu hean di proses
	int waktuTunggu; // Lama waktu tunggu jika masih ada antrian sebelumnya
	int waktuMulai; // waktu dimulai nya hewan di proses
	int waktuAkhir; // waktu selesai hewan di proses
	int nilaiPrioritas; // nilai prioritas berdasarkan jumlah dan jenis penyakit yang dipilih
	List listPenyakit; // list penyakit yang di derita hean
}infoPasien;

typedef struct NodeQueue *addrQ;
typedef struct NodeQueue{
	infoPasien info;
	addrQ next;
}NodeQueue;

typedef struct{
	addrQ HEAD;
	addrQ TAIL;
}Queue;

void CreateQueue (Queue *Q);
addrQ Alokasi (infoPasien X);
void Dealokasi (addrQ P);
boolean IsQueueEmpty(Queue Q);
void DelQueue (Queue *Q);
void AddQue (Queue *Q, infoPasien X);
void LihatDaftarAntrian(Queue Q);

// OTHERS //
void SortByValuePriority(Queue Q);
void SortByTimeArrive(Queue Q);
void SortQueue(Queue Q);
char *kategoriPenyakit(int Penyakit);
int HitungNilaiPrioritas(int Ringan, int Sedang, int Berat);
int CekWaktuPelayanan(int Penyakit);
int HitungWaktuPelayanan(int Ringan, int Sedang, int Berat);
void HitungWaktuMulaiAkhirTunggu(Queue *Q);
void Registrasi (Queue *Q);
void PrintDaftarPenyakit();
void ProsesAntrian(Queue *Q);

//UI
void UIRegistrasi(infoPasien X, int jumlahPenyakit);
#endif
