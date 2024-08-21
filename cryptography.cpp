#include <iostream>

using namespace std;

const char letras[]={
'a','d','e','f','s','g','i','k','m','W',
'o','p','q','K','r','t','u','$','y','F',
'c','\\','/','8','X','z','0','1','3','4',
'5','w','x','H','6','7','Q','9','O',',',
'.','?','{','j','}','n',' ','!','v','"',
'b','\'','_','(',')','2','&','#','@','+',
'<','>','A','B','l','h','D','-','E','G',
'I','J','M','C','N','P','R','S','T','U',
'V','L','Y',':','Z',';','*','='};

/*
-> You can use any channel number between 1 and 87.
Encrypted text will be readable only with the same
channel number that was initially encrypted.

-> You can change the channel number and re-encrypt a
previously encrypted text to have more protection. Remember
the channel numbers when going backwards.
*/
const int channel_number=87;

string encriptar(string texto){
    string output;
    for(int i=0;texto[i]!='\0';i++){
        for(unsigned j=0;j<sizeof(letras);j++){
            if(texto[i]==letras[j]){
                if(j+channel_number<sizeof(letras)){
                    output+=letras[j+channel_number];
                    break;
                }else{
                    output+=letras[j+channel_number-sizeof(letras)];
                    break;
                }
            }
        }
    }
    return output;
}

string desencriptar(string texto){
    string output;
    for(int i=0;texto[i]!='\0';i++){
        for(unsigned j=0;j<sizeof(letras);j++){
            if(texto[i]==letras[j]){
                if(j>=channel_number){
                    output+=letras[j-channel_number];
                }else{
                    output+=letras[sizeof(letras)+j-channel_number];
                }
            }
        }
    }
    return output;
}

int main(){
    system("color 0a");
    int opcion;
    string texto;
    while(!((opcion==1)||(opcion==2)||(opcion==-1))){
        cout<<"1=Encrypt || 2=Decrypt"<<endl;
        cout<<"Enter your option(1|2): ";
        cin>>opcion;

        switch(opcion)
        {
        case 1:
            cout<<"Enter your text to be encrypted: ";
            getline(cin>>ws,texto);
            cout<<endl<<"Encrypted text:"<<endl<<"-->"<<encriptar(texto)<<"<--"<<endl;
            break;
        case 2:
            cout<<"Enter your text to be decrypted: ";
            getline(cin>>ws,texto);
            cout<<endl<<"Descrypted text:"<<endl<<"-->"<<desencriptar(texto)<<"<--"<<endl;
            break;
        }
        opcion=0;
    }
    return 0;
}