#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Aluno {
    string nome;
    string matricula;
    string dataNascimento;
    string plano;
    string dataPagamento;
};



void cadastrarAluno(vector<Aluno>& alunos) {
    Aluno novo;
    cin.ignore(); // Limpa o buffer do teclado

    cout << "\n===== CADASTRO DE ALUNO =====\n";

    cout << "Digite o nome do aluno:";
    getline(cin, novo.nome);

    cout << "Digite a matrícula do aluno:";
    getline(cin, novo.matricula);

    cout << "Digite a data de nascimento do aluno (dd/mm/aaaa):";
    getline(cin, novo.dataNascimento);

    cout << "Digite o plano do aluno:";
    getline(cin, novo.plano);

    cout << "Digite a data de pagamento do aluno (dd/mm/aaaa):";
    getline(cin, novo.dataPagamento);

    alunos.push_back(novo);

    cout << "Aluno cadastrado com sucesso!\n";

}


void listarAlunos(const vector<Aluno>& alunos){

    if (alunos.empty()){
        cout << "Nenhum aluno cadastrado.\n";
        return;
    }

    cout << "\n===== LISTA DE ALUNOS =====\n";

    for (int i = 0; i < alunos.size(); i++){
        const Aluno& aluno = alunos[i];
        cout << "Nome: " << aluno.nome << endl;
        cout << "Matricula: " << aluno.matricula << endl;
        cout << "Nascimento: " << aluno.dataNascimento << endl;
        cout << "Plano: " << aluno.plano << endl;
        cout << "Pagamento: " << aluno.dataPagamento << endl;
        cout << "--------------------------" << endl;
    }
}

void removerAluno(vector<Aluno>& alunos) {
    
    string matricula;

    cin.ignore();

    cout << "\n===== REMOVER ALUNO =====\n";
    cout << "Digite a matricula";

    getline(cin, matricula);

    for (int i = 0; i < alunos.size(); i++) {
        if(alunos[i].matricula == matricula) {
            alunos.erase(alunos.begin() + i);
            cout << "Aluno removido com sucesso" << endl;
            return;
        }
    }
    cout << "Aluno não encontrado" << endl;
}


void editarAluno(vector<Aluno>& alunos) {
    string matricula;

    cin.ignore();

    cout << "\n===== EDITAR ALUNO =====\n";

    cout << "Digite a matrícula do aluno a ser editado: ";

    getline(cin, matricula);

    for(int i = 0; i < alunos.size(); i++) {
        if(alunos[i].matricula == matricula) {
            cout << "Aluno encontrado. Digite os novos dados:\n";

            cout << "Digite o nome do aluno:";
            getline(cin, alunos[i].nome);

            cout << "Digite a matrícula do aluno:";
            getline(cin, alunos[i].matricula);

            cout << "Digite a data de nascimento do aluno (dd/mm/aaaa):";
            getline(cin, alunos[i].dataNascimento);

            cout << "Digite o plano do aluno:";
            getline(cin, alunos[i].plano);

            cout << "Digite a data de pagamento do aluno (dd/mm/aaaa):";
            getline(cin, alunos[i].dataPagamento);

            cout << "Aluno editado com sucesso!\n";
            return;
        }
    }
    cout << "Aluno não encontrado" << endl;
}


int main()
{

    //Váriaveis de controle
    int opcao;
    vector<Aluno> alunos;

    do
    {
        cout << "\n===== MENU =====\n";
        cout << "1. Cadastrar aluno\n";
        cout << "2. Listar alunos\n";
        cout << "3. Remover aluno\n";
        cout << "4. Editar aluno\n";
        cout << "5. Sair\n";
        cout << "Escolha: ";

        cin >> opcao;

        switch(opcao)
        {
            case 1:
                cout << "Cadastrar aluno\n";
                cadastrarAluno(alunos);
                break;

            case 2:
                cout << "Listar alunos\n";
                listarAlunos(alunos);
                break;

            case 3:
                cout << "Remover aluno\n";
                removerAluno(alunos);
                break;

            case 4:
                cout << "Editar aluno\n";
                break;

            case 5:
                cout << "Saindo...\n";
                break;

            default:
                cout << "Opção inválida!\n";
        }

    } while(opcao != 5);

    return 0;
}