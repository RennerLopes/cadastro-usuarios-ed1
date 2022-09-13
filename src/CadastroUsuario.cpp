#include "include/CadastroUsuario.h"

FILE *arq;

void init_list(usuarios *listaUsuarios) {
    listaUsuarios->qtd = 0;
    listaUsuarios->usuarios = NULL;
}

void kill_list(usuarios *listaUsuarios) {
    free(listaUsuarios->usuarios);
    init_list(listaUsuarios);
}

void cadastrar_usuario(usuario dadosUsuario, usuarios *listaUsuarios) {
    listaUsuarios->qtd++;

    if (listaUsuarios->qtd == 1) {
        listaUsuarios->usuarios = (usuario *)malloc(listaUsuarios->qtd * sizeof(usuario));
    } else {
        listaUsuarios->usuarios = (usuario *)realloc(listaUsuarios->usuarios, listaUsuarios->qtd * sizeof(usuario));
    }

    listaUsuarios->usuarios[listaUsuarios->qtd - 1] = dadosUsuario;
}

void listar_usuarios(usuarios *listaUsuarios) {
    if (listaUsuarios->usuarios == NULL) {
        cout << "Não possui usuários cadastrados!" << endl;
        return;
    }

    for (int i = 0; i < listaUsuarios->qtd; i++) {
        cout << "--------------" << endl;
        cout << "Nome: " << listaUsuarios->usuarios[i].nome << endl;
        cout << "CPF: " << listaUsuarios->usuarios[i].CPF << endl;
        cout << "RG: " << listaUsuarios->usuarios[i].RG << endl;
        cout << "Endereço: " << listaUsuarios->usuarios[i].Endereco << endl;
    }
}

int quantidade_usuarios(usuarios *listaUsuarios) {
    return listaUsuarios->qtd;
}

void remover_ultimo_usuario(usuarios *listaUsuarios) {
    if (listaUsuarios->qtd != 0) {
        listaUsuarios->qtd--;

        if (listaUsuarios->qtd > 0) {
            listaUsuarios->usuarios = (usuario *)realloc(listaUsuarios->usuarios, listaUsuarios->qtd * sizeof(usuario));
        } else {
            kill_list(listaUsuarios);
        }
    }
}

void salva_base_dados(usuarios *listaUsuarios) {
    arq = fopen("usuarios.txt", "w");

    if (arq == NULL) {
        cout << "Erro na criação do arquivo\n";
        return;
    }

    for (int i = 0; i < listaUsuarios->qtd; i++) {
        usuario u = listaUsuarios->usuarios[i];
        fprintf(arq, "%s; %s; %s; %s\n", u.nome, u.RG, u.CPF, u.Endereco);
    }

    fclose(arq);
}

void carregar_base_dados(usuarios *listaUsuarios) {
    usuario u;

    if ((arq = fopen("usuarios.txt", "r")) == NULL) {
        cout << "Erro na abertura do arquivo\n";
        return;
    }

    while (fscanf(arq, "%[^;]; %[^;]; %[^;]; %[^;]\n", u.nome, u.RG, u.CPF, u.Endereco) != EOF) {
        cadastrar_usuario(u, listaUsuarios);
    }

    cout << "Base de dados carregada!" << endl;
    fclose(arq);
}