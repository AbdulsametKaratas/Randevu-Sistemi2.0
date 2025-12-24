#ifndef YAPILAR_H
#define YAPILAR_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SALON 5
#define INF 99999

// 1. Randevu Modeli
typedef struct Randevu {
    int id;
    char isim[50];
    int baslangic; 
    int bitis;     
} Randevu;

// 2. AVL + Interval Tree (Dengeli Ağaç Şartı)
typedef struct IntervalNode {
    Randevu *veri;
    int max_bitis; 
    struct IntervalNode *sol, *sag;
    int yukseklik; 
} IntervalNode;

// 3. Stack (Undo/Geri Al Şartı)
typedef struct StackNode {
    int id;
    struct StackNode *sonraki;
} StackNode;

// 4. Queue (Bekleme Listesi/Görev Kuyruğu Şartı)
typedef struct KuyrukNode {
    Randevu veri;
    struct KuyrukNode *sonraki;
} KuyrukNode;

typedef struct {
    KuyrukNode *bas, *son;
} Kuyruk;

#endif