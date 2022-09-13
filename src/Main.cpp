#include "include/CadastroUsuario.h"

void menu() {
    cout << "========= MENU =========\n";
    cout << "1-Cadastrar novo usuário\n";
    cout << "2-Exibir usuários cadastrados\n";
    cout << "3-Exibir quantidade de usuários cadastrado\n";
    cout << "4-Remover último usuário cadastrado\n";
    cout << "5-Sair\n";
    cout << ": ";
}

int main(int argc, char** argv) {
    unsigned int op(0);
    usuarios listaUsuarios;
    init_list(&listaUsuarios);

    do {
        menu();
        cin >> op;

        switch (op) {
            case 1:
                usuario u;
                cout << "Digite o nome: ";
                cin.ignore();
                cin.getline(u.nome, sizeof(u.nome));
                cout << "Digite o CPF (apenas numeros): ";
                cin.getline(u.CPF, sizeof(u.CPF));
                cout << "Digite o RG (apenas numeros): ";
                cin.getline(u.RG, sizeof(u.RG));
                cout << "Digite o endereço: ";
                cin.getline(u.Endereco, sizeof(u.Endereco));

                cadastrar_usuario(u, &listaUsuarios);
                break;
            case 2:
                listar_usuarios(&listaUsuarios);

                break;
            case 3:
                cout << "Quantidade de usuários: " << quantidade_usuarios(&listaUsuarios) << endl;

                break;
            case 4:
                remover_ultimo_usuario(&listaUsuarios);
                break;
        }

    } while (op > 0 && op < 5);

    kill_list(&listaUsuarios);
    return 0;
}
