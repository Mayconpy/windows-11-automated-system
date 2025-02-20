#include <stdio.h>
#include <windows.h>
#include <shlwapi.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>

void alt_tab(WORD key){
        INPUT input = {0};
        input.type = INPUT_KEYBOARD;
        input.ki.wVk = key;
        SendInput(1, &input, sizeof(INPUT));

        //MOUSEINPUT mi;   // Entrada de mouse
        //KEYBDINPUT ki;   // Entrada de teclado
       // HARDWAREINPUT hi; // Entrada de hardware

        
}


void string(const char* text){
    INPUT input = {0};
    input.type = INPUT_KEYBOARD;

    while (*text){
        // Configurar a entrada como caractere UNICODE
        input.ki.wScan = *text; //codigo do caractere
        input.ki.dwFlags = KEYEVENTF_UNICODE; //entrada unicode em vez de entrar com VK_A eu posso entrar com "oi hola"
        SendInput(1,&input,sizeof(INPUT)); //envia evento para o computador clicar a tecla

        input.ki.dwFlags = KEYEVENTF_UNICODE | KEYEVENTF_KEYUP;//soltar tecla
        SendInput(1,&input,sizeof(INPUT));

        text++;// avançar na string
        Sleep(50); // pequeno atraso na string

    } 

}


int main(){
    string("entrar");
    
    
}