# Ideia visual

1. Cada só eu faço com uma strut 
strutc {
    int pointer;
    qualquerDado;
}


2. A estrutura inicial é null (pois não tem dado)

3. Posso fazer a inserção em qualquer lugar

4. Preciso atualizar a estrutura para ela saber dos novos nós e as referencias dos nós

5. Posso criar ponteiros para mostrar o primeiro elemento e o ultimo elemento (Caso necessario)

6. Busca, a partir do primeiro nó eu percorro a estrutura procurando os outros (Não existe indice) (Lembre-se: Caso tiver procurando '5', porém tem outro '5' no final da lista, ele vai dar apenas o primeiro '5' e não o ultimo que ta no final..)

7. Quando eu remover um 'nó' além de eu ter que referencia o nó anterior para null o nó removido tem que ser limpo da memoria