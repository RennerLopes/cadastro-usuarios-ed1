#include <stdio.h>
#include <stdlib.h>

#include <iostream>
using namespace std;

struct Usuario {
    char nome[30];
    char RG[8];
    char CPF[12];
    char Endereco[120];
};
typedef struct Usuario usuario;

struct Usuarios {
    int qtd;
    Usuario* usuarios;
};
typedef struct Usuarios usuarios;

void init_list(usuarios* listaUsuarios);
void kill_list(usuarios* listaUsuarios);
void cadastrar_usuario(usuario dadosUsuario, usuarios* listaUsuarios);
void listar_usuarios(usuarios* listaUsuarios);
int quantidade_usuarios(usuarios* listaUsuarios);
void remover_ultimo_usuario(usuarios* listaUsuarios);