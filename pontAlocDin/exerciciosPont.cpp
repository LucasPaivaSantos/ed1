#include <iostream>

using namespace std;

// exercício 1
void imprimePtr(int *ptr)
{
    cout << "o endereço do ponteiro é: " << ptr << endl;
    cout << "o conteúdo apontado é: " << *ptr << endl;
}

// exercício 2
void func1()
{
    int mat[] = {1, 10, 100};
    for (int j = 0; j < 3; j++)
        cout << *(mat + j) << endl;
}

void func2()
{
    int mat[] = {1, 10, 100};
    for (int j = 0; j < 3; j++)
        cout << (mat + j) << endl;
}

void func3()
{
    int mat[] = {1, 10, 100};
    int *p = mat;
    for (int j = 0; j < 3; j++)
        cout << (*p)++ << endl;
}

// exercício 3
bool func(int tam, int *vet, int *par, int *imp, int *neg)
{
    for (int i = 0; i < tam; i++)
    {
        if ((vet[i] % 2) == 0)
            ++*par;
        else
        {
            ++*imp;
        }
        if (vet[i] < 0)
            ++*neg;
    }
    return *neg > 0;
}

int main()
{
    cout
        << "impressões--- do exercício 1---" << endl
        << endl;
    // exercício 1
    int i = 3;
    int j = 5;
    int *p;
    p = &i;
    int *q;
    q = &j;

    // a)
    p = &i;
    imprimePtr(p);

    // b)
    // *q = &j; expressão inválida!

    // c)
    p = &*&i;
    imprimePtr(p);

    // d)
    i = *&j;
    cout << i << endl;

    // e)
    i = *&*&j;
    cout << i << endl;

    // f)
    // q = &p; expressão inválida!

    // g)
    i = 3;
    i = ++(*p) + *q;
    cout << i << endl;

    // h)
    // if (p == i) i++; expressão inválida!

    cout << endl

         << "---impressões do exercício 2---" << endl
         << endl;
    // exercício 2
    // a função imprime cada valor do vetor em uma linha
    func1();

    // a função imprime cada endereço do vetor em uma linha
    func2();

    // a função imprime cada o valor do primeiro índice do vetor acrescido em um após cada iteração
    func3();
    cout << endl

         << "---impressões do exercício 3---" << endl
         << endl;
    // exercício 3
    int zero[3] = {0, 0, 0};
    int *par = &zero[0];
    int *imp = &zero[1];
    int *neg = &zero[2];

    int vet[10] = {10, -1, 4, 5, 3, 7, -3, 16, -7, 0};

    bool haNegativo = func(10, vet, par, imp, neg);
    cout << "há negativos no vetor? " << boolalpha << haNegativo << endl;
    cout << *neg << " são numeros negativos" << endl;
    cout << *par << " são numeros pares" << endl;
    cout << *imp << " são numeros ímpares" << endl;

    return 0;
}