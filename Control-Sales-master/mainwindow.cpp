#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "stock.h"
#include "product.h"

void MainWindow::inserirNaTabela(Product a, int i)
{
    ui->tabela_Cadastro->setItem(i, 0, new QTableWidgetItem(QString::number(a.getCod())));
    ui->tabela_Cadastro->setItem(i, 1, new QTableWidgetItem(a.getNome()));
    ui->tabela_Cadastro->setItem(i, 2, new QTableWidgetItem(a.getFabricante()));
    ui->tabela_Cadastro->setItem(i, 3, new QTableWidgetItem("R$ " + QString::number(a.getCusto())));
}

void MainWindow::inserirNaTabelaEstoque(Product a, int i)
{
    ui->tabela_Estoque->setItem(i, 0, new QTableWidgetItem(QString::number(a.getCod())));
    ui->tabela_Estoque->setItem(i, 1, new QTableWidgetItem(a.getNome()));
    ui->tabela_Estoque->setItem(i, 2, new QTableWidgetItem(a.getFabricante()));
    ui->tabela_Estoque->setItem(i, 3, new QTableWidgetItem(QString::number(a.getQtd())));
}

void MainWindow::atualizarTabela()
{
    ui->tabela_Cadastro->clearContents();
    for(int i=0; i < estoque.size(); i++){
        inserirNaTabela(estoque[i], i);
    }
}

void MainWindow::atualizarTabelaEstoque()
{
    ui->tabela_Estoque->clearContents();
    for(int i=0; i < estoque.size(); i++){
        inserirNaTabelaEstoque(estoque[i], i);
    }
}

void MainWindow::relatorio()
{
    double totalVendas = estoque.relatorioTotalVendas();
    double totalCustos = estoque.getTotalCusto();
    double totalLucros = estoque.getTotalLucros();
    double mediaVendas = estoque.getMediaVendas();
    double mediaLucros = estoque.getMediaLucros();

    ui->label_Total_Vendas->setText("R$ " + QString::number(totalVendas));
    ui->label_Total_custos->setText("R$ " + QString::number(totalCustos));
    ui->label_Total_Lucros->setText("R$ " + QString::number(totalLucros));
    ui->label_Media_Vendas->setText("R$ " + QString::number(mediaVendas));
    ui->label_Media_Lucros->setText("R$ " + QString::number(mediaLucros));
}

void MainWindow::pesquisaVenda()
{
    Product search;

    search.setCod(ui->lineCodVenda->text().toInt());
    search.setNome(ui->lineNomeVenda->text().toUpper());
    search.setFabricante(ui->lineFabricanteVenda->text().toUpper());

    ui->label_Secreta_Cod->setText(ui->lineCodVenda->text());

    inserirTabelaPesquisa(estoque.pesquisa(search));

    ui->lineCodVenda->clear();
    ui->lineNomeVenda->clear();
    ui->lineFabricanteVenda->clear();
}

void MainWindow::inserirTabelaPesquisa(Product a)
{
    //int linha = ui->tabela_Venda->rowCount();

    ui->tabela_Venda->insertRow(0);

    ui->tabela_Venda->setItem(0, 0, new QTableWidgetItem(QString::number(a.getCod())));
    ui->tabela_Venda->setItem(0, 1, new QTableWidgetItem(a.getNome()));
    ui->tabela_Venda->setItem(0, 2, new QTableWidgetItem(a.getFabricante()));
    ui->tabela_Venda->setItem(0, 3, new QTableWidgetItem(QString::number(a.getQtd())));
    ui->tabela_Venda->setItem(0, 4, new QTableWidgetItem(QString::number(a.getVenda())));

}

void MainWindow::inserirTabelaVenda2(Product a)
{
    int linha = ui->tabela_Venda_2->rowCount();

    ui->tabela_Venda_2->insertRow(linha);

    ui->tabela_Venda_2->setItem(linha, 0, new QTableWidgetItem(QString::number(a.getCod())));
    ui->tabela_Venda_2->setItem(linha, 1, new QTableWidgetItem(a.getNome()));
    ui->tabela_Venda_2->setItem(linha, 2, new QTableWidgetItem(a.getFabricante()));
    ui->tabela_Venda_2->setItem(linha, 3, new QTableWidgetItem(QString::number(a.getQtd())));
    ui->tabela_Venda_2->setItem(linha, 4, new QTableWidgetItem("R$ " + QString::number(a.getVenda())));
    ui->tabela_Venda_2->setItem(linha, 5, new QTableWidgetItem("R$ " + QString::number(a.getTotalvenda())));

    estoque.insereSomaVenda(a);
    estoque.insereTotalVendas(a.getTotalvenda());

    ui->label_Total_a_pagar->setText("R$ " + QString::number(estoque.somaVenda()));

}

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionAbrir_triggered()
{
    QString endArquivo = QFileDialog::getOpenFileName(this, "Abrir", "", "CSV(*.csv)");

    estoque.abrirEstoque(endArquivo);

    for(int i=0;i<estoque.size();i++){
        ui->tabela_Estoque->insertRow(i);
        inserirNaTabelaEstoque(estoque[i],i);
    }
}

void MainWindow::on_actionSalvar_triggered()
{
    QString endArquivo = QFileDialog::getSaveFileName(this, "Salvar", "", "CSV(*.csv)");
    estoque.salvarEstoque(endArquivo);
}

void MainWindow::on_btn_Sair_clicked()
{
    close();
}

void MainWindow::on_btn_Ordena_Cod_clicked()
{
    estoque.ordenarCod();
    atualizarTabela();
}

void MainWindow::on_btn_Ordena_Nome_clicked()
{
    estoque.ordenarNome();
    atualizarTabela();
}

void MainWindow::on_btn_Ordena_Custo_clicked()
{
    estoque.ordenarCusto();
    atualizarTabela();
}

void MainWindow::on_btn_Cadastrar_clicked()
{
    Product produto;

    produto.setNome(ui->lineNome->text().toUpper());
    produto.setFabricante(ui->lineFabricante->text().toUpper());
    produto.setQtd(ui->lineQtd->text().toInt());
    produto.setMargem(ui->lineMargem->text().toDouble());
    produto.setCusto(ui->lineCusto->text().toDouble());

    if(produto.getNome() == ""){
        QMessageBox::critical(this,"Sales Control","Erro! Não é permitido inserir nome com menos de 3 caracteres.");
    }else if(estoque.verificaNome(produto) != false){
        QMessageBox::critical(this,"Sales Control","Erro! Produto já cadastrado");
        ui->lineNome->clear();
        ui->lineFabricante->clear();
        ui->lineQtd->clear();
        ui->lineCusto->clear();
        ui->lineMargem->clear();
    }else if(produto.getFabricante() == ""){
        QMessageBox::critical(this,"Sales Control","Erro! Insira um fabricante ao item.");
    }else if(produto.getQtd() == 0.00){
            QMessageBox::critical(this,"Sales Control","Erro! Insira um valor válido à qantidade.");
    }else if(produto.getCusto() == 0.00){
        QMessageBox::critical(this,"Sales Control","Erro! Insira um valor válido ao custo.");
    }else if(produto.getMargem() == 0.00){
        QMessageBox::critical(this,"Sales Control","Erro! Insira um valor válido à margem.");
    }else{

        produto.setVenda(produto.getCusto() * produto.getMargem());

        int linha = ui->tabela_Cadastro->rowCount();
        int linha2 = ui->tabela_Estoque->rowCount();

        produto.setCod(linha + 1);

        estoque.inserirProduto(produto);
        estoque.inserirPesquisa(produto);

        ui->tabela_Cadastro->insertRow(linha);
        ui->tabela_Estoque->insertRow(linha2);

        inserirNaTabela(produto, linha);
        inserirNaTabelaEstoque(produto, linha);
        relatorio();

        ui->lineNome->clear();
        ui->lineFabricante->clear();
        ui->lineQtd->clear();
        ui->lineCusto->clear();
        ui->lineMargem->clear();
    }
}

void MainWindow::on_btn_Ordenar_Cod_Estoque_clicked()
{
    estoque.ordenarCodEstoque();
    atualizarTabelaEstoque();
}

void MainWindow::on_btn_Ordenar_Nome_Estoque_clicked()
{
    estoque.ordenarNomeEstoque();
    atualizarTabelaEstoque();
}

void MainWindow::on_btn_Ordenar_Fabricante_Estoque_clicked()
{
    estoque.ordenarFabricante();
    atualizarTabelaEstoque();
}

void MainWindow::on_btn_Incluir_Venda_clicked()
{
    Product a;

    a.setCod(ui->label_Confirma_Cod->text().toInt());
    a.setNome(ui->label_Confirma_None->text());
    a.setQtd(ui->line__Confirma_Qtd->text().toInt());
    a.setVenda(ui->label_Confirma_Valor_Und->text().toDouble());
    a.setFabricante(ui->label_Confirma_Fabricante->text());
    a.setTotalvenda(a.getVenda() * a.getQtd());

    inserirTabelaVenda2(a);

    ui->label_Confirma_Cod->clear();
    ui->label_Confirma_None->clear();
    ui->label_Confirma_Fabricante->clear();
    ui->label_Confirma_Valor_Und->clear();
    ui->line__Confirma_Qtd->clear();
    ui->label_RS->clear();


}

void MainWindow::on_btn_Finalizar_Venda_clicked()
{
    estoque.insereTotalVendas(ui->label_Total_a_pagar->text().toDouble());

    ui->tabela_Venda_2->clearContents();
    ui->label_Total_a_pagar->clear();

    ui->tabela_Venda_2->removeRow(0);

}

void MainWindow::on_btn_Pesquisar_venda_clicked()
{
    pesquisaVenda();
}

void MainWindow::on_tabela_Venda_cellDoubleClicked()
{
    int i = ui->label_Secreta_Cod->text().toInt();

    Product a = estoque.selecionaItem(i - 1); //Falta extrair texto do cod da tabela e trocar por row.

    QMessageBox::StandardButton resp = QMessageBox::question(this, "Selecionar produto", "Você deseja selecionar este item?");

    if(resp == QMessageBox::Yes){

        ui->tabela_Venda->clearContents();

        ui->label_Confirma_Cod->setText(QString::number(a.getCod()));
        ui->label_Confirma_None->setText(a.getNome());
        ui->label_Confirma_Fabricante->setText(a.getFabricante());
        ui->label_RS->setText("R$ ");
        ui->label_Confirma_Valor_Und->setText(QString::number(a.getVenda()));

     }

    ui->tabela_Venda->removeRow(0);
}

void MainWindow::on_lineCodVenda_returnPressed()
{
    on_btn_Pesquisar_venda_clicked();
}

void MainWindow::on_lineNomeVenda_returnPressed()
{
    on_btn_Pesquisar_venda_clicked();
}

void MainWindow::on_lineFabricanteVenda_returnPressed()
{
    on_btn_Pesquisar_venda_clicked();
}

void MainWindow::on_line__Confirma_Qtd_returnPressed()
{
    on_btn_Incluir_Venda_clicked();
}

void MainWindow::on_lineNome_returnPressed()
{
    ui->lineFabricante->setFocus();
}

void MainWindow::on_lineFabricante_returnPressed()
{
    ui->lineQtd->setFocus();
}

void MainWindow::on_lineQtd_returnPressed()
{
    ui->lineCusto->setFocus();
}

void MainWindow::on_lineCusto_returnPressed()
{
    ui->lineMargem->setFocus();
}

void MainWindow::on_lineMargem_returnPressed()
{
    on_btn_Cadastrar_clicked();
}
