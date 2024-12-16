#include "../headers/Produto.h"

Produto::Produto(int id, const std::string &nome, float preco)
    : id(id), nome(nome), preco(preco) {}

int Produto::getId() const { return id; }
std::string Produto::getNome() const { return nome; }
float Produto::getPreco() const { return preco; }

void Produto::display() const {
    std::cout << "ID: " << id << ", Nome: " << nome << ", Preco: R$ "
              << std::fixed << std::setprecision(2) << preco << '\n';
}
