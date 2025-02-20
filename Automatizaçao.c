#include <stdlib.h>
#include <stdio.h>
#include <windows.h>
void ShelPermision(){
        ShellExecute(NULL,"runas", "C:\\Windows\\System32\\notepad.exe",NULL,NULL,SW_SHOWNORMAL);
        return 0;
        //Solicitação de Permissões de Administrador (UAC)
        //Para executar com privilégios elevados:

        //Use a API ShellExecute com o verbo "runas":
}

void Messagebox(){
    MessageBox(NULL,"AUTOMACAO CONLUIDA", "aviso", MB_OK|MB_ICONINFORMATION); 
    // exibe uma mensagem na tela com botao OK e informaçao
    return 0;
}

void arquivos(){
    FILE *file = fopen("log.txt", "w");
    if (file){
        fprintf(file,"automaçao");
        fclose(file);
    }
    return 0;
}



int main(){
    arquivos();
    Messagebox();
    ShelPermision();

    
}