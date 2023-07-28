#include <iostream>
using namespace std;

// exercício 1
int somatorioAte0(int n, int i)
{
    if (i == n)
    {
        return 0;
    }
    else
        return n - i + somatorioAte0(n, i + 1);
}

int auxSomatorioAte0(int n)
{
    return somatorioAte0(n, 0);
}

// exercício 2
float encontraMenor(float *vet, int n, float menor)
{

    if (vet[n - 1] < menor)
        menor = vet[n - 1];
    if (n == 1)
        return menor;
    else
        return encontraMenor(vet, n - 1, menor);
}

float auxEncontraMenor(float *vet, int n)
{
    float menor = vet[n - 1];
    return encontraMenor(vet, n - 1, menor);
}

// exercício 3
float somaVetor(float *vet, int n, float soma)
{
    if (n == 0)
        return soma;
    else
        return somaVetor(vet, n - 1, soma) + vet[n - 1];
}

float auxSomaVetor(float *vet, int n)
{
    float soma = 0;
    return somaVetor(vet, n, soma);
}

int contaPares(int *v, int n, int pares)
{
    if (v[n - 1] % 2 == 0)
        ++pares;
    if (n == 1)
        return pares;
    else
        return contaPares(v, n - 1, pares);
}

int auxContaPares(int *v, int n)
{
    int pares = 0;
    return contaPares(v, n, pares);
}

char *converteBinario(char *binario, int decimal, int n)
{
    if (decimal % 2 == 0)
        binario[n - 1] = '0';
    else
        binario[n - 1] = '1';

    if (decimal / 2 == 0)
    {
        binario[n - 1] = '1';
        return binario;
    }
    else
        return converteBinario(binario, decimal / 2, n - 1);
}

void imprimeStringBinaria(char *string)
{
    for (int i = 0; i < 32; i++)
    {
        if (string[i] == '0' || string[i] == '1')
            cout << string[i];
    }
    cout << endl;
}

int main()
{
    // exercício 1
    //  int numero;
    //  cout << "digite um número para calcular o somatorio" << endl;
    //  cin >> numero;
    //  cout << auxSomatorioAte0(numero) << endl;

    float vet[5] = {3, 4, 1, 5, 0};

    // exercício 2
    cout << "o menor valor do vetor é: " << auxEncontraMenor(vet, 5) << endl;

    // exercício 3
    cout << "a soma dos elementos do vetor é: " << auxSomaVetor(vet, 5) << endl;

    // exercício 4
    int v[7] = {1, 2, 4, 6, 10, 8, 9};
    cout << "existem " << auxContaPares(v, 7) << " números pares no vetor" << endl;

    // exercício 5
    char binario[32];
    int x;
    cin >> x;
    char *string;
    string = converteBinario(binario, x, 32);
    cout << "em binário o número é: ";
    imprimeStringBinaria(string);

    return 0;
}