#include <iostream>
using namespace std;

// exercício 4,5 e 6
float calcMedia(int n, float vet[])
{

    int soma = 0;
    for (int i = 0; i < n; i++)
        soma += vet[i];
    return (float)soma /
           n;
}

float *alocaVetor(int n)
{

    float *vetor = new float[n];

    for (int i = 0; i < n; i++)
    {
        cout << "digite um número para o vetor" << endl;
        cin >> vetor[i];
    }

    return vetor;
}

int main()
{
    int tam;
    cout << "digite o tamanho do vetor" << endl;
    cin >> tam;

    float *pt;
    pt = alocaVetor(tam);

    cout << "a média dos elementos do vetor é: " << calcMedia(tam, pt) << endl;
    delete[] pt;

    return 0;
}