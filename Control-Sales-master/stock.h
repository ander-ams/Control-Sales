#ifndef STOCK_H
#define STOCK_H

#include <QObject>
#include <QVector>
#include <QFile>
#include <algorithm>
#include "product.h"

class Stock
{
private:
    QVector<Product> produto;
    QVector<Product> search;
    QVector<double> somatorio_venda;
    QVector<double> relatorioVendasTotais;

public:
    Stock();
    void inserirProduto(Product a);
    void inserirPesquisa(Product a);
    bool verificaNome(Product a);
    void ordenarCod();
    void ordenarCodEstoque();
    void ordenarNome();
    void ordenarNomeEstoque();
    void ordenarCusto();
    void ordenarVenda();
    void ordenarFabricante();
    Product operator[](int i);
    int size();
    bool salvarEstoque(QString arquivo);
    bool abrirEstoque(QString arquivo);
    QString inserirLinha(Product a);
    double getTotalVendas();
    double getTotalCusto();
    double getTotalLucros();
    double getMediaVendas();
    double getMediaLucros();

    Product pesquisa(Product a);
    Product selecionaItem(int row);
    void insereSomaVenda(Product a);
    void insereTotalVendas(double a);
    double somaVenda();
    double relatorioTotalVendas();


};

bool compararNome(Product a, Product b);
bool compararCusto(Product a, Product b);
bool compararVenda(Product a, Product b);
bool compararCod(Product a, Product b);
bool compararFabricante(Product a, Product b);

#endif // STOCK_H
