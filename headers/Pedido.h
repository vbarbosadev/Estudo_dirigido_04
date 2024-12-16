#ifndef PEDIDO_H
#define PEDIDO_H

#include "Produto.h"
#include <vector>
#include <memory>
#include <string>

class Pedido {
private:
    std::vector<std::shared_ptr<Produto>> produtos;
    std::string cliente;

public:
    explicit Pedido(const std::string &cliente);
    void adicionarProduto(const std::shared_ptr<Produto> &produto);
    float calcularTotal() const;
    void exibirResumo() const;
};

#endif // PEDIDO_H
