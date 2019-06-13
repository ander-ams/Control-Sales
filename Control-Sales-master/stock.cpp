#include "stock.h"

Stock::Stock()
{

}

void Stock::inserirProduto(Product a)
{
    produto.push_back(a);
}

void Stock::inserirPesquisa(Product a)
{
    search.push_back(a);
}

bool Stock::verificaNome(Product a)
{
    bool aux = false;

    for(int i = 0; i < produto.size(); i++)
        if(a.getNome() == produto[i].getNome()){
            aux = true;
        }
    return aux;
}

void Stock::ordenarCod()
{
    std::sort(produto.begin(), produto.end(), compararCod);
}

void Stock::ordenarCodEstoque()
{
    std::sort(produto.begin(), produto.end(), compararCod);
}

void Stock::ordenarNome()
{
    std::sort(produto.begin(), produto.end(), compararNome);
}

void Stock::ordenarNomeEstoque()
{
    std::sort(produto.begin(), produto.end(), compararNome);
}

void Stock::ordenarCusto()
{
    std::sort(produto.begin(), produto.end(), compararCusto);
}

void Stock::ordenarVenda()
{
    std::sort(produto.begin(), produto.end(), compararVenda);
}

void Stock::ordenarFabricante()
{
    std::sort(produto.begin(), produto.end(), compararFabricante);
}

Product Stock::operator[](int i)
{
    return produto[i];
}

int Stock::size()
{
    return produto.size();
}

bool Stock::salvarEstoque(QString arquivo)
{
    QFile file(arquivo);
    QString linha;
    if(!file.open(QIODevice::WriteOnly))
        return false;

    for(Product a : produto){
        linha = inserirLinha(a);
        file.write(linha.toLocal8Bit());
    }
    return true;
}

bool Stock::abrirEstoque(QString arquivo)
{
    QFile file(arquivo);
    if(!file.open(QIODevice::ReadOnly))
        return false;

    QString linha;
    Product a;
    while(!file.atEnd()){
        linha = file.readLine();
        QStringList dados = linha.split(",");
        a.setCod(dados[0].toInt());
        a.setNome(dados[1]);
        a.setFabricante(dados[2]);
        a.setQtd(dados[3].toInt());
        a.setCusto(dados[4].toDouble());
        a.setVenda(dados[5].toDouble());
        a.setMargem(dados[6].toDouble());
        inserirProduto(a);
    }
    return true;
}

QString Stock::inserirLinha(Product a)
{
    return QString::number(a.getCod()) + ',' + a.getNome() + ',' + a.getFabricante() + ','
            + QString::number(a.getQtd()) + ',' + QString::number(a.getCusto()) + ','
            + QString::number(a.getVenda()) + ',' + QString::number(a.getMargem()) + "\r\n";
}

double Stock::getTotalVendas()
{
    double totalVendas = 0;

    for(auto a : produto){
        totalVendas += a.getTotalvenda();
    }

    return totalVendas;
}

double Stock::getTotalCusto()
{
    double totalCustos = 0;

    for(auto a : produto){
        totalCustos += a.getCusto();
    }

    return totalCustos;
}

double Stock::getTotalLucros()
{
    double totalLucros = 0;

    for(auto a : produto){
        totalLucros = a.getTotalLucros();
    }

    return totalLucros;
}

double Stock::getMediaVendas()
{
    double mediaVendas = 0;

    for(auto a : produto){
        mediaVendas += a.getTotalVendas();
    }

    return mediaVendas / produto.size();
}

double Stock::getMediaLucros()
{
    double mediaLucros = 0;

    for(auto a : produto){
        mediaLucros += a.getTotalLucros();
    }

    return mediaLucros / produto.size();
}

Product Stock::pesquisa(Product a)
{
    if(a.getCod() != 0){
        for(int i = 0; i < produto.size(); i++){
            if(a.getCod() == produto[i].getCod()){
                return produto[i];
            }
        }
    }else if(a.getNome() != ""){
        for(int i = 0; i < produto.size(); i++){
            if(a.getNome() == produto[i].getNome()){
                return produto[i];
            }
        }
    }else if(a.getFabricante() != ""){
        for(int i = 0; i < produto.size(); i++){
            if(a.getFabricante() == produto[i].getFabricante()){
                return produto[i];
            }
        }
    }
}

Product Stock::selecionaItem(int row)
{
    return search[row];
}

void Stock::insereSomaVenda(Product a)
{
    somatorio_venda.push_back(a.getTotalvenda());
}

void Stock::insereTotalVendas(double a)
{
    relatorioVendasTotais.push_back(a);
}

double Stock::somaVenda()
{
    double soma = 0;

    for(auto i : somatorio_venda){
        soma += i;
    }

    return soma;
}

double Stock::relatorioTotalVendas()
{
    Product soma;

    soma.setTotalvenda(0);

    for(auto i : relatorioVendasTotais){
        soma += i;
    }

    return soma.getTotalvenda();
}

bool compararNome(Product a, Product b)
{
    return a.getNome() < b.getNome();
}

bool compararCusto(Product a, Product b)
{
    return a.getCusto() > b.getCusto();
}

bool compararVenda(Product a, Product b)
{
    return a.getVenda() > b.getVenda();
}

bool compararCod(Product a, Product b)
{
    return a.getCod() < b.getCod();
}

bool compararFabricante(Product a, Product b)
{
    return a.getFabricante() < b.getFabricante();
}
