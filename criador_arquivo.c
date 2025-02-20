#include <stdio.h>
#include <windows.h>
#include <shlwapi.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>

#pragma comment(lib, "Shlwapi.lib")




bool func_extensao(const char *extensaos){ // creates function to check if the extension the user entered is existing

    char apppath[MAX_PATH]; // it also serves as a type of buffer to prevent wasted memory
    // creating variable that represents a character would be a char
    //square brackets are used to indicate that it is an array of characters or a string
    // MAX_PATH is a constant defined in windows
    // this means apppath can support 260 characters

    DWORD size = MAX_PATH;
    //DWORD would e the same as an int or long used to store a 32-bit value


    HRESULT result = AssocQueryStringA(ASSOCF_INIT_DEFAULTTOSTAR,
        ASSOCSTR_EXECUTABLE, // indicates that we want the full path of the executable associated with the giver extension
        extensaos,// must be a string cantaining the extension that the user privided
        NULL,
        apppath,
        &size);
    //Flag is a value that adjusts the behavior of functions and structures.
    //They are often combined with bitwise operations.
    //Make it easy to control and customize functions with a single call
    
    // ASSOCF_INIT_DEFAULTTOSTAR
    //This flag tells the function that, if it 
    //does not find a specific association 
    //for the given extension, it should use * as the default value.




    if (result == S_OK){
        return "Criando arquivo";
    }
    else{
        printf("not existing this extension\n");
        getchar();
        //criar_arquivo();
    }

}

void create_arquive(char namearquive[MAX_PATH]){
        HANDLE hfile = CreateFile(namearquive,GENERIC_WRITE,0,NULL,CREATE_NEW,FILE_ATTRIBUTE_NORMAL,NULL);
            if (hfile == INVALID_HANDLE_VALUE ){
            printf("Error file not created");
            }
            else{
                printf("file created successfully\n");
                CloseHandle(hfile);
            }
}


void archive_txt(char txt[MAX_PATH]){
    if (strstr(txt,".txt")){
        FILE *file = fopen(txt,"a");
        if (file ==NULL){
            printf("ERROR THE OPEN ARQUIVE");
            return;
        }
        char conteudo[1024];
        printf("Digite o Conteudo a ser escrito no seu TXT: ");
        getchar();
        fgets(conteudo,sizeof(conteudo),stdin);
        fprintf(file,"%s", conteudo);
        fclose(file);
    }



}


void start_creation(){
    char nomearquivo[MAX_PATH];
    char extensao[10]; //// Declara uma string com tamanho máximo permitido para caminhos no Windows
    printf("Nome do arquivo a ser criado: ");
    scanf("%s", nomearquivo);


    printf("o arquivo ira ser .exe .txt etc: ");
    scanf("%s", &extensao);
    if (func_extensao(extensao)){
        
        if (strstr(extensao, ".")){
            strcat(nomearquivo,extensao);
            create_arquive(nomearquivo);
            
            
            if (strstr(extensao, ".txt")){archive_txt(nomearquivo);}
                
        }
        else{
            getchar();
        }
    }
    else{
        printf("Extensao invalida");
    }
    


    
}

void delete_file(){
    char delete[MAX_PATH];
    
    printf("write the name of the file you want to delete: ");
    scanf("%s", delete);

    if(DeleteFile(delete)){
        printf("file deleted success ");
    }
    else{
        printf("file not existing");
    }
}
void renamefile(){
    char nomeantigo[MAX_PATH], nomenovo[MAX_PATH];
    printf("Write the name current file you want to change: ");
    scanf("%s", nomeantigo);

    printf("write the name of the file you want to change the name: ");
    scanf("%s", nomenovo);

    if (MoveFile(nomeantigo,nomenovo)){
        printf("Sucess");
    }
    else{
        printf("erro");
    }    
    
}


int main(){
    int choice;
   for (int i = 0; i <= 100; i++ ){
    printf("choose\n1 for file creation\n2 to delete files\n3 to rename files: ");
    scanf("%d", &choice);
    switch (choice)
    {
        case 1: 
        start_creation();
        break;
        
        case 2: 
        delete_file();
        break;
        
        case 3: 
        renamefile();
        break;

        case 4:
            return 0;

        default:
            printf("invalide choice. try again.\n");
    }
   }

}



