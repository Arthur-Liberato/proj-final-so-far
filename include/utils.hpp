#ifndef UTILS_H
#define UTILS_H

#include <string>
#include <algorithm>
#include <cctype>
#include <stdexcept>

/**
 * @class Utils
 * @brief Funções utilitárias para conversão e manipulação de strings.
 *
 * Contém métodos estáticos para converter strings para números com verificação,
 * transformar para caixa baixa e remover espaços em branco nas extremidades.
 */
class Utils {
public:
    /**
     * @brief Converte com segurança uma string para inteiro.
     *
     * Internamente usa std::stoi, mas captura exceções e lança std::invalid_argument
     * ou std::out_of_range com mensagem que inclui o nome do campo.
     *
     * @param str        A string a ser convertida.
     * @param fieldName (opcional) Nome do campo ou contexto para incluir na mensagem de erro.
     * @return O valor inteiro convertido.
     * @throws std::invalid_argument Se a string não contiver um número válido.
     * @throws std::out_of_range     Se o número for fora do alcance de um int.
     */
    static int safeStoi(const std::string& str, const std::string& fieldName = "");

    /**
     * @brief Converte todos os caracteres de uma string para minúsculas.
     *
     * Percorre cada caractere de @p str e retorna uma nova string com
     * todos os caracteres convertidos para sua forma minúscula.
     *
     * @param str A string original.
     * @return Uma nova string em caixa baixa.
     */
    static std::string toLower(const std::string& str);

    /**
     * @brief Remove espaços em branco no início e no fim de uma string.
     *
     * Elimina caracteres de espaço, tabulação ou nova linha das extremidades
     * de @p str, retornando a substring "trimmed".
     *
     * @param str A string a ser aparada.
     * @return Uma nova string sem espaços nas extremidades.
     */
    static std::string trim(const std::string& str);
};

#endif // UTILS_H
