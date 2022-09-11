#include "include/CadastroUsuario.h"

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
    for (int i = 0; i < listaUsuarios->qtd; i++) {
        cout << listaUsuarios->usuarios[i].nome << "\t";
        cout << listaUsuarios->usuarios[i].CPF << "\t";
        cout << listaUsuarios->usuarios[i].RG << "\t";
        cout << listaUsuarios->usuarios[i].Endereco << endl;
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