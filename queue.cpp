#include <iostream>
#include "queue.h"
using namespace std;

void createQueue(Queue &Q) {
    Q.head = 0;
    Q.tail = -1;
}

bool isEmptyQueue(Queue Q) {
    return Q.tail == -1;
}

bool isFullQueue(Queue Q) {
    return Q.tail == MAX_QUEUE - 1;
}

void enqueue(Queue &Q, infotype x) {
    if (isFullQueue(Q)) {
        cout << "Queue penuh, data " << x << " tidak dapat ditambahkan." << endl;
        return;
    }

    if (isEmptyQueue(Q)) {
        Q.head = 0;
    }

    Q.tail++;
    Q.info[Q.tail] = x;
}

infotype dequeue(Queue &Q) {
    if (isEmptyQueue(Q)) {
        cout << "Queue kosong, tidak ada data yang dapat dihapus." << endl;
        return -1;
    }

    infotype x = Q.info[Q.head];

    // Alternatif 1: head tetap, elemen digeser ke kiri, tail berkurang.
    for (int i = Q.head; i < Q.tail; i++) {
        Q.info[i] = Q.info[i + 1];
    }

    Q.tail--;
    if (Q.tail == -1) {
        Q.head = 0;
    }
    return x;
}

void printInfo(Queue Q) {
    if (isEmptyQueue(Q)) {
        cout << "0-0	 | Queue kosong" << endl;
        return;
    }

    cout << Q.head << "-" << Q.tail << "	 | ";
    for (int i = Q.head; i <= Q.tail; i++) {
        cout << Q.info[i];
        if (i < Q.tail) cout << " ";
    }
    cout << endl;
}
