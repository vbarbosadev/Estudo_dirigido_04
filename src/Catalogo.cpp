#include "../headers/Catalogo.h"
#include <iostream>

void Catalogo::adicionarProduto(const std::shared_ptr<Produto> &produto) {
    produtos.push_back(produto);
    std::cout << "[LOG]: Produto adicionado ao catalogo: " << produto->getNome() << std::endl;
}

void Catalogo::listarProdutos() const {
    if (produtos.empty()) {
        std::cout << "[LOG]: Nenhum produto disponivel no catalogo.\n";
        std::cout << "Nenhum produto disponivel no catalogo.\n";
    } else {
        std::cout << "[LOG]: Listando produtos do catalogo.\n";
        for (const auto &produto : produtos) {
            produto->display();
        }
    }
}

std::shared_ptr<Produto> Catalogo::buscarProdutoPorId(int id) const {
    for (const auto &produto : produtos) {
        if (produto->getId() == id) {
            std::cout << "[LOG]: Produto encontrado com ID = " << id << std::endl;
            return produto;
        }
    }
    std::cout << "[LOG]: Produto nao encontrado com ID = " << id << std::endl;
    return nullptr;
}
