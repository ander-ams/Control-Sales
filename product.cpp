#include "product.h"

QString Product::getNome() const
{
    return nome;
}

void Product::setNome(const QString &value)
{
    QString teste = value;
       if(teste.size() < 3){
           nome = "";
       }else{
        nome = value;
       }
}

double Product::getCusto() const
{
    return custo;
}

void Product::setCusto(double value)
{
    double teste = value;
        QString aux;
        int cont = 0;

        aux = QString::number(teste);

        if(teste < 0){
            cont = 1;
        }else {
            for(auto i : aux){
                if(i < 48 || i > 57){
                    if(i == 46){
                        cont = 0;
                    }else{
                        cont++;
                    }
                }
            }
        }

        if(cont != 0){
            custo = 0;
        }else{
            custo = value;
            setVenda(custo);
        }
}

double Product::getVenda() const
{
    return venda;
}

void Product::setVenda(double value)
{
    venda = value;
}

double Product::getMargem() const
{
    return margem;
}

void Product::setMargem(double value)
{
    double teste = value;
        QString aux;
        int cont = 0;

        aux = QString::number(teste);

        if(teste < 0){
            cont = 1;
        }else {
            for(auto i : aux){
                if(i < 48 || i > 57){
                    if(i == 46){
                        cont = 0;
                    }else{
                        cont++;
                    }
                }
            }
        }

        if(cont != 0){
            margem = 0;
        }else{
            margem = value;
        }
}

int Product::getQtd() const
{
    return qtd;
}

void Product::setQtd(int value)
{
    qtd = value;
}

QString Product::getFabricante() const
{
    return fabricante;
}

void Product::setFabricante(const QString &value)
{
    QString teste = value;
       if(teste.size() == 0){
            fabricante = "";
       }else{
            fabricante = value;
       }
}

int Product::getCod() const
{
    return cod;
}

void Product::setCod(int value)
{
    cod = value;
}

double Product::getTotalVendas() const
{
    return totalVendas;
}

void Product::setTotalVendas(double value)
{
    totalVendas = value;
}

double Product::getTotalCustos() const
{
    return totalCustos;
}

void Product::setTotalCustos(double value)
{
    totalCustos = value;
}

double Product::getTotalLucros() const
{
    return totalLucros;
}

void Product::setTotalLucros(double value)
{
    totalLucros = value;
}

double Product::getMediaVendas() const
{
    return mediaVendas;
}

void Product::setMediaVendas(double value)
{
    mediaVendas = value;
}

double Product::getMediaLucros() const
{
    return mediaLucros;
}

void Product::setMediaLucros(double value)
{
    mediaLucros = value;
}

double Product::getTotalvenda() const
{
    return totalvenda;
}

void Product::setTotalvenda(double value)
{
    totalvenda = value;
}

Product::Product()
{
    nome = "0";
    fabricante = "0";
    custo = 0;
    venda = 0;
    totalvenda = 0;
    margem = 0;
    qtd = 0;
    cod = 0;
}
