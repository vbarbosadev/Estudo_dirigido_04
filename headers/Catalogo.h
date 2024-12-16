#ifndef CATALOGO_H
#define CATALOGO_H

#include "Produto.h"
#include <vector>
#include <memory>

class Catalogo {
private:
    std::vector<std::shared_ptr<Produto>> produtos;

public:
    void adicionarProduto(const std::shared_ptr<Produto> &produto);
    void listarProdutos() const;
    std::shared_ptr<Produto> buscarProdutoPorId(int id) const;
};

#endif // CATALOGO_H
