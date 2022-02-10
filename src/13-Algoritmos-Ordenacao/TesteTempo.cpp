#include <iostream>
#include <chrono>
using namespace std::chrono;
using namespace std;

#define MAX 1000

void bubblesort(int A[], int n) {
  for (int i = 0; i < n-1; i++) {
    for (int j = n-1; j > i; j--) {
      if (A[j] < A[j-1]) {
        std::swap(A[j],A[j-1]);
      }
    }
  }
}

void bubblesortV2(int A[], int n) {
  bool trocou = true;
  for (int i = 0; i < n-1 && trocou; i++) {
    trocou = false;
    for (int j = n-1; j > i; j--) {
      if (A[j] < A[j-1]) {
        std::swap(A[j],A[j-1]);
        trocou = true;
      }
    }
  }
}

// Algoritmo de ordenação
void insertionsort(int A[], int n) {
    for(int j = 1; j < n; j++) {
        int key = A[j];
        int i = j-1;
        while(i >= 0 && A[i] > key) {
            A[i+1] = A[i];
            i--;
        }
        A[i+1] = key;
    }
}


/* A funcao recebe vetores crescentes A[p..q] e A[q+1..r] 
 * e rearranja A[p..r] em ordem crescente */
void Intercala (int A[], int p, int q, int r) {
  int *W = new int[r-p+1]; // Vetor auxiliar  
  int i = p;
  int j = q+1;
  int k = 0;
  
  // Intercala A[p..q] e A[q+1..r]
  while (i <= q && j <= r) {
    if (A[i] <= A[j])
      W[k++] = A[i++];
    else
      W[k++] = A[j++];
  }
  while (i <= q) W[k++] = A[i++];
  while (j <= r) W[k++] = A[j++];
  
  // Copia vetor ordenado W para o vetor A
  for (i = p; i <= r; i++)
    A[i] = W[i-p];
    
  delete[] W; // libera memoria alocada
}

void mergesort(int A[], int p, int r) {
    if (p < r) {
        // Dividir
        int q = (p + r) / 2; 
        // Conquistar
        mergesort(A, p, q);
        mergesort(A, q + 1, r);
        // Combinar
        Intercala(A, p, q, r);
    }
}

template<class T>
void print_array(T A[], int n) {
    for (int i = 0; i < n; i++)
        std::cout << A[i] << " ";
    std::cout << std::endl;
}


int main() {
    int v[MAX];
    int v2[MAX];
    int v3[MAX];
    int v4[MAX];

    srand(TIME_UTC);

    for(int i = 0; i < MAX; ++i) {
		  v[i] = 1 + (rand() % MAX); // 1 ... 1000
      v2[i] = v[i];
      v3[i] = v[i];
      v4[i] = v[i];
    }

    int n = sizeof(v)/sizeof(v[0]);

    //print_array(v, n);
    
    // Primeiro algoritmo
    auto start = high_resolution_clock::now();
    
    bubblesort(v,n);
    
    auto stop = high_resolution_clock::now();
    
    auto duration = duration_cast<microseconds>(stop - start);
    
    cout << duration.count() << " microseconds" << endl;

    // Segundo algoritmo
    auto start2 = high_resolution_clock::now();
    
    bubblesortV2(v2,n);
    
    auto stop2 = high_resolution_clock::now();
    
    auto duration2 = duration_cast<microseconds>(stop2 - start2);
    
    cout << duration2.count() << " microseconds" << endl;

    // Terceiro algoritmo
    auto start3 = high_resolution_clock::now();
    
    insertionsort(v3,n);
    
    auto stop3 = high_resolution_clock::now();
    
    auto duration3 = duration_cast<microseconds>(stop3 - start3);
    
    cout << duration3.count() << " microseconds" << endl;

    // Quarto algoritmo
    auto start4 = high_resolution_clock::now();
    
    mergesort(v4,0,n-1);
    
    auto stop4 = high_resolution_clock::now();
    
    auto duration4 = duration_cast<microseconds>(stop4 - start4);
    
    cout << duration4.count() << " microseconds" << endl;
    
    return 0;
}
