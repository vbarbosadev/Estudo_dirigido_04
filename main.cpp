// main.cpp
#include "headers/Produto.h"
#include "headers/Catalogo.h"
#include "headers/Pedido.h"
#include <iostream>

void log(const std::string &message) {
    std::cout << "[LOG]: " << message << std::endl;
}

int main() {
    std::cout << "Sistema de loja virtual iniciado!\n";

    Catalogo catalogo;
    catalogo.adicionarProduto(std::make_shared<Produto>(1, "Notebook", 2500.00f));
    catalogo.adicionarProduto(std::make_shared<Produto>(2, "Mouse", 50.00f));

    Pedido pedido("Cliente Teste");
    pedido.adicionarProduto(catalogo.buscarProdutoPorId(1));
    pedido.adicionarProduto(catalogo.buscarProdutoPorId(2));

    pedido.exibirResumo();

    return 0;
}
