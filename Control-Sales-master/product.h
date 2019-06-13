#ifndef PRODUCT_H
#define PRODUCT_H

#include <QObject>

class Product
{
private:
    int cod;
    QString nome;
    QString fabricante;
    int qtd;
    double custo;
    double venda;
    double totalvenda;
    double margem;
    double totalVendas;
    double totalCustos;
    double totalLucros;
    double mediaVendas;
    double mediaLucros;

public:
    Product();
    QString getNome() const;
    void setNome(const QString &value);
    double getCusto() const;
    void setCusto(double value);
    double getVenda() const;
    void setVenda(double value);
    double getMargem() const;
    void setMargem(double value);
    int getQtd() const;
    void setQtd(int value);
    QString getFabricante() const;
    void setFabricante(const QString &value);
    int getCod() const;
    void setCod(int value);
    double getTotalVendas() const;
    void setTotalVendas(double value);
    double getTotalCustos() const;
    void setTotalCustos(double value);
    double getTotalLucros() const;
    void setTotalLucros(double value);
    double getMediaVendas() const;
    void setMediaVendas(double value);
    double getMediaLucros() const;
    void setMediaLucros(double value);
    double getTotalvenda() const;
    void setTotalvenda(double value);
};

#endif // PRODUCT_H
