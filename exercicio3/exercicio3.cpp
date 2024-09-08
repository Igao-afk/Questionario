#include <iostream>
#include <fstream>
#include <vector>
#include <nlohmann/json.hpp>

using json = nlohmann::json;
using namespace std;

struct Faturamento {
    int dia;
    double valor;
};

vector<Faturamento> lerFaturamento(const string& caminhoArquivo) {
    ifstream arquivo(caminhoArquivo);
    json j;
    arquivo >> j;
    vector<Faturamento> faturamentos;
    
    for (const auto& item : j["faturamento"]) {
        Faturamento f;
        f.dia = item["dia"];
        f.valor = item["valor"];
        faturamentos.push_back(f);
    }
    return faturamentos;
}

double encontrarMenorFaturamento(const vector<Faturamento>& faturamento) {
    double menor = std::numeric_limits<double>::max();
    for (const auto& f : faturamento) {
        if (f.valor > 0 && f.valor < menor) {
            menor = f.valor;
        }
    }
    return menor;
}


double encontrarMaiorFaturamento(const vector<Faturamento>& faturamento) {
    double maior = std::numeric_limits<double>::min();
    for (const auto& f : faturamento) {
        if (f.valor > 0 && f.valor > maior) {
            maior = f.valor;
        }
    }
    return maior;
}


double calcularMediaMensal(const vector<Faturamento>& faturamento) {
    double soma = 0;
    int count = 0;
    for (const auto& f : faturamento) {
        if (f.valor > 0) {
            soma += f.valor;
            count++;
        }
    }
    return (count > 0) ? (soma / count) : 0;
}


int contarDiasAcimaDaMedia(const vector<Faturamento>& faturamento, double media) {
    int contagem = 0;
    for (const auto& f : faturamento) {
        if (f.valor > media) {
            contagem++;
        }
    }
    return contagem;
}

int main() {
    string caminhoArquivo = "faturamento.json"; // Caminho para o arquivo JSON
    vector<Faturamento> faturamentos = lerFaturamento(caminhoArquivo);

    double menorFaturamento = encontrarMenorFaturamento(faturamentos);
    double maiorFaturamento = encontrarMaiorFaturamento(faturamentos);
    double mediaMensal = calcularMediaMensal(faturamentos);
    int diasAcimaDaMedia = contarDiasAcimaDaMedia(faturamentos, mediaMensal);

    cout << "Menor valor de faturamento: " << menorFaturamento << endl;
    cout << "Maior valor de faturamento: " << maiorFaturamento << endl;
    cout << "Número de dias acima da média mensal: " << diasAcimaDaMedia << endl;

    return 0;
}
