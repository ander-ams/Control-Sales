#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QVector>
#include <QMessageBox>
#include <QDebug>
#include <QFileDialog>
#include "stock.h"
#include "product.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

private:

    Stock estoque;
    void inserirNaTabela(Product a, int i);
    void inserirNaTabelaEstoque(Product a, int i);
    void atualizarTabela();
    void atualizarTabelaEstoque();
    void relatorio();

    void pesquisaVenda();
    void inserirTabelaPesquisa(Product a);
    void inserirTabelaVenda2(Product a);

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_actionAbrir_triggered();

    void on_actionSalvar_triggered();

    void on_btn_Sair_clicked();

    void on_btn_Ordena_Cod_clicked();

    void on_btn_Ordena_Nome_clicked();

    void on_btn_Ordena_Custo_clicked();

    void on_btn_Cadastrar_clicked();

    void on_btn_Ordenar_Cod_Estoque_clicked();

    void on_btn_Ordenar_Nome_Estoque_clicked();

    void on_btn_Ordenar_Fabricante_Estoque_clicked();

    void on_btn_Incluir_Venda_clicked();

    void on_btn_Finalizar_Venda_clicked();

    void on_btn_Pesquisar_venda_clicked();

    void on_tabela_Venda_cellDoubleClicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
