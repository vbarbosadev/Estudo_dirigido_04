#ifndef PRODUTO_H
#define PRODUTO_H

#include <string>
#include <iostream>
#include <iomanip>

class Produto {
private:
    int id;
    std::string nome;
    float preco;

public:
    Produto(int id, const std::string &nome, float preco);
    int getId() const;
    std::string getNome() const;
    float getPreco() const;
    void display() const;
};

#endif // PRODUTO_H
