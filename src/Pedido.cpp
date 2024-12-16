#include "../headers/Pedido.h"
#include <iostream>
#include <iomanip>

Pedido::Pedido(const std::string &cliente) : cliente(cliente) {
    std::cout << "[LOG]: Pedido criado para cliente: " << cliente << std::endl;
}

void Pedido::adicionarProduto(const std::shared_ptr<Produto> &produto) {
    produtos.push_back(produto);
    std::cout << "[LOG]: Produto adicionado ao pedido: " << produto->getNome() << std::endl;
}

float Pedido::calcularTotal() const {
    float total = 0.0f;
    for (const auto &produto : produtos) {
        total += produto->getPreco();
    }

    if (total > 100.0f) {
        std::cout << "[LOG]: Aplicando desconto de 10% no pedido." << std::endl;
        total *= 0.9f; // Aplicar desconto de 10%
    }
    std::cout << "[LOG]: Total do pedido calculado: R$ " << total << std::endl;
    return total;
}

void Pedido::exibirResumo() const {
    std::cout << "Pedido de: " << cliente << '\n';
    for (const auto &produto : produtos) {
        produto->display();
    }
    std::cout << "Total: R$ " << std::fixed << std::setprecision(2) << calcularTotal() << '\n';
}
