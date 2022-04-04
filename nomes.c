#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

char nomesFemininos[][50] = {"Helena", "Alice", "Laura", "Manuela", "Valentina", "Sophia", "Isabella", "Heloísa", "Luiza", "Júlia", "Lorena", "Lívia", "Maria Luiza", "Cecília", "Eloá", "Giovanna", "Maria Clara", "Maria Eduarda", "Mariana", "Lara", "Beatriz", "Antonella", "Maria Júlia", "Emanuelly", "Isadora", "Ana Clara", "Melissa", "Ana Luiza", "Ana Júlia", "Esther", "Lavínia", "Maitê", "Maria Cecília", "Maria Alice", "Sarah", "Elisa", "Liz", "Yasmin", "Isabelly", "Alícia", "Clara", "Isis", "Rebeca", "Rafaela", "Marina", "Ana Laura", "Maria Helena", "Agatha", "Gabriela", "Catarina", "Letícia", "Mirella", "Nicole", "Luna", "Maria Vitória", "Olívia", "Vitória", "Maria", "Maria Fernanda", "Ana Beatriz", "Allana", "Maria Valentina", "Milena", "Emilly", "Ayla", "Maria Flor", "Maya", "Bianca", "Clarice", "Aurora", "Larissa", "Mariah", "Pietra", "Laís", "Stella", "Eduarda", "Maria Heloísa", "Ana Lívia", "Ana Sophia", "Maria Laura", "Carolina", "Ana Vitória", "Malu", "Gabrielly", "Ana Liz", "Analu", "Maria Sophia", "Ana Cecília", "Amanda", "Louise", "Heloise", "Fernanda", "Ana", "Melina", "Maria Isis", "Bella", "Joana", "Isabel", "Melinda", "Pérola"};
char nomesMasculinos[][50] = {"Miguel", "Arthur", "Heitor", "Bernardo", "Davi", "Théo", "Lorenzo", "Gabriel", "Pedro", "Benjamin", "Matheus", "Lucas", "Nicolas", "Joaquim", "Samuel", "Henrique", "Rafael", "Guilherme", "Enzo", "Murilo", "Benício", "Gustavo", "Isaac", "João Miguel", "Lucca", "Enzo Gabriel", "Pedro Henrique", "Felipe", "João Pedro", "Pietro", "Anthony", "Daniel", "Bryan", "Davi Lucca", "Leonardo", "Vicente", "Eduardo", "Gael", "Antônio", "Vitor", "Noah", "Caio", "João", "Emanuel", "Cauã", "João Lucas", "Calebe", "Enrico", "Vinícius", "Bento", "Davi Lucas", "João Gabriel", "João Guilherme", "João Vitor", "Luiz Miguel", "Francisco", "Otávio", "Henry", "Levi", "Augusto", "Thomas", "Yuri", "Tomás", "Arthur Miguel", "Yan", "Thiago", "Theodoro", "Davi Luiz", "Ryan", "Erick", "Arthur Gabriel", "Breno", "Nathan", "Pedro Lucas", "Anthony Gabriel", "Luiz Felipe", "Luan", "Vitor Hugo", "Ravi", "Pedro Miguel", "Rodrigo", "Valentim", "Raul", "Martim", "Oliver", "Mathias", "Lucas Gabriel", "Luiz Otávio", "Davi Miguel", "Kaique", "Luiz Henrique", "José", "Arthur Henrique", "Luiz Gustavo", "Fernando", "Bruno", "Kauê", "Carlos Eduardo", "Miguel Henrique", "Derick"};
char sobrenomes[][50] = {"Abreu", "Adães", "Adorno", "Aguiar", "Albuquerque", "Alcântara", "Alencar", "Almeida", "Altamirano", "Alvarenga", "Álvares", "Alves", "Alvim", "Amaral", "Amigo", "Amor", "Amorim", "Anchieta", "Andrada", "Andrade", "Andrioli", "Anes", "Anjos", "Antunes", "Anunciação", "Apolinário", "Aragão", "Araújo", "Arruda", "Ascensão", "Assis", "Azeredo", "Azevedo", "André", "Asvilla", "Auth", "Badu", "Bandeira", "Barbosa", "Barreto", "Barros", "Barroso", "Baseggio", "Bastos", "Batista", "Bermudes", "Bernades", "Bernardes", "Bicalho", "Bispo", "Bizzo", "Bocaiuva", "Bolsonaro", "Borba", "Borges", "Borsoi", "Botelho", "Braga", "Bragança", "Brandão", "Brasil", "Brasiliense", "Brito", "Bruscato", "Bueno", "Cabral", "Café", "Camacho", "Camargo", "Caminha", "Camões", "Cândido", "Cardoso", "Carmo", "Carnaval", "Carneiro", "Carvalhal", "Carvalho", "Carvalhosa", "Castilho", "Castro", "Cauduro", "Cerejeira", "Chaves", "Coelho", "Coentrão", "Coimbra", "Conceição", "Constante", "Cordeiro", "Costa", "Cotrim", "Coutinho", "Couto", "Cruz", "Cunha", "Curado", "Dambros", "Dantas", "Delfino", "Dias", "Diegues", "Dorneles", "Duarte", "Eça", "Encarnação", "Esteves", "Evangelista", "Exaltação", "Fagundes", "Faleiros", "Falópio", "Falqueto", "Faria", "Farias", "Faro", "Ferrão", "Ferraz", "Ferro", "Ferreira", "Ferrolho", "Fernandes", "Figo", "Figueira", "Figueiredo", "Figueiroa", "Fioravante", "Fonseca", "Fontes", "Fortaleza", "França", "Freire", "Freitas", "Frota", "Furquim", "Furtado", "Feitosa", "Galvão", "Gama", "Garcia", "Garrastazu", "Gato", "Gomes", "Gonçales", "Gonçalves", "Gonzaga", "Gouveia", "Guarato", "Guimarães", "Gusmão", "Guerreiro", "Henriques", "Hernandes", "Hidelfonso", "Hoffmann", "Holanda", "Homem", "Hora", "Hungria", "Idelfonso", "Igrejas", "Ildefonso", "Jardim", "Jesus", "Jordão", "Junqueira", "Lacerda", "Lange", "Leitão", "Leite", "Leme", "Lima", "Lins", "Lira", "Locatelli", "Louzada", "Lopes", "Lutz", "Luz", "Leonor", "Macedo", "Machado", "Madureira", "Maduro", "Magalhães", "Mairinque", "Malafaia", "Malta", "Marinho", "Mariz", "Marques", "Martins", "Mascarenhas", "Massa", "Matos", "Médici", "Medeiros", "Meireles", "Mello", "Melo", "Mendes", "Mendonça", "Menino", "Messias", "Mesquita", "Milhomem", "Miranda", "Monteiro", "Moraes", "Morais", "Morato", "Morbeck", "Moreira", "Moretti", "Moro", "Muniz", "Namorado", "Nantes", "Nascimento", "Navalhes", "Navarro", "Naves", "Neis", "Negreiros", "Negrete", "Neves", "Nóbrega", "Nogueira", "Noronha", "Nunes", "Oliva", "Oliveira", "Outeiro", "Pacheco", "Padrão", "Paes", "Pais", "Paiva", "Paixão", "Papanicolau", "Parga", "Pascal", "Pascoal", "Pasquim", "Patriota", "Peçanha", "Pedrosa", "Pedroso", "Peixoto", "Pellegrini", "Penna", "Pensamento", "Penteado", "Pereira", "Peres", "Pessoa", "Pestana", "Pimenta", "Pimentel", "Pinheiro", "Pinto", "Pires", "Placides", "Poeta", "Policarpo", "Porto", "Portugal", "Prado", "Prudente", "Quaresma", "Queirós", "Queiroz", "Ramalhete", "Ramalho", "Ramires", "Ramos", "Rangel", "Reis", "Resende", "Ribeiro", "Rios", "Rocha", "Rodrigues", "Roma", "Romão", "Roçadas", "Sá", "Sacramento", "Sampaio", "Sampaulo", "Sampedro", "Sanches", "Sandes", "Santacruz", "Santana", "Santander", "Santarrosa", "Santiago", "Santos", "Saragoça", "Saraiva", "Saramago", "Seixas", "Serra", "Serrano", "Silva", "Silveira", "Simões", "Siqueira", "Soares", "Soeiro", "Spiassi", "Sousa", "Souza", "Stein", "Tavares", "Teixeira", "Teles", "Torquato", "Trindade", "Uchoa", "Uribe", "Ustra", "Valadares", "Valença", "Valente", "Valverde", "Varela", "Vasconcelos", "Vasques", "Vaz", "Veiga", "Velasques", "Veloso", "Viana", "Vieira", "Vilela", "Vilhena", "Vicente", "Wagner", "Xavier", "Young", "Zampol", "Zema"};
char dominio[][20] = {"yahoo.com.br","google.com","hotmail.com","outlook.com","uol.com.br","terra.com.br"};


const char* getCPF(int i){     
    char *cpf;
    long long int ref = i*i*i+1000000000;  
    sprintf(cpf,"%03d.%03d.%03d-%02d",ref/10000000L,(ref/1000L)%1000L,ref%1000L,i*17%100);
    return cpf;
}

const char *getRG(int i){
    char *rg;
    int rgNum = i*i+100;
    sprintf(rg,"%d.%03d.%03d",i%10,rgNum/1000,rgNum%1000);    
    return rg;
}

const char* getTelefone(int i){
    char *telefone;
    int cod = i%89+10;
    sprintf(telefone,"+55 (%02d) 9 %04d-%04d",cod,i*i*31/10000,(i*37*i)%10000);   
    return telefone;
}

void limparutf8(char *nome){
    int j=0;
    while(nome[j]!='\0'){
        if(nome[j]>=65 && nome[j]<=90){
            nome[j]+=32;
        }
        if(nome[j]==135){
            nome[j]='c';
        }else if(nome[j]==128){
            nome[j]='C';
        }else if(nome[j]==130 || (nome[j]>=136 && nome[j]<=138)){
            nome[j]='e';
        }else if(nome[j] == 161 || (nome[j]>=139 && nome[j]<=141)){
            nome[j]='i';
        }else if(nome[j]==162 || (nome[j]>=147 && nome[j]<=149)){
            nome[j]='o';
        }else if(nome[j]==163 || (nome[j]>=150 && nome[j]<=151)){
            nome[j]='u';
        }else if(nome[j]==128){
            nome[j]='C';
        }else if(nome[j]==160 ||(nome[j]>=131 && nome[j]<=134)||nome[j]==198){
            nome[j]='a';
        }else if(nome[j]==153 ||(nome[j]>=224 && nome[j]<=229)){
            nome[j]='O';
        }else if(nome[j]==199 ||(nome[j]>=142 && nome[j]<=143)||(nome[j]>=181 && nome[j]<=183)){
            nome[j]='A';
        }else if(nome[j]>=233 && nome[j]<=235){
            nome[j]='U';
        }else if(nome[j]>=214 && nome[j]<=216){
            nome[j]='I';
        }
        j++;
    }
}

int main(){
    //setlocale(LC_ALL,"portuguese");
    srand(time(NULL));
    int random;
    //FILE *saida = fopen("saida.txt","w,ccs=UTF-8");
    char *nome;
    char sexo;
    unsigned long int rg;
    for(int i=0;i<1000;i++){
        int varia = (i+2)*i;
        int digito = 13;
        rg = 1000000+(i+1)*i;
        random = rand()%100;
        if(i%2==1 || i%10==0){
            sexo = 'f';
            nome = nomesFemininos[random];            
        }else{
            sexo = 'm';
            nome = nomesMasculinos[random];
        }
        random = rand()%344;     
        int qtdSobrenomes =  rand()%3;
        char sobrenome[100];
        int j=0;
        for(int i=0;i<qtdSobrenomes;i++){
            random = rand()%344;                        
            char *novoNome = sobrenomes[random];
            int k=0;
            while(novoNome[k]!='\0'){
                sobrenome[j++]=novoNome[k++];
            }
            sobrenome[j++]=' ';
        }        
        sobrenome[j]='\0';
        random = rand()%344;                        
        char *ultimoNome = sobrenomes[random];        
        printf("('%s',",getCPF(i));
        printf("'%s',",getRG(i));
        printf("'%c',",sexo);
        printf("'%s',",nome);
        printf("'%s',",sobrenome);
        printf("'%s',",ultimoNome);
        printf("'%s',",getTelefone(i));
        random = rand()%6;
        limparutf8(nome);
        limparutf8(ultimoNome);
        printf("'%s",nome);
        printf("%02d",i%100);
        printf("%s",ultimoNome);
        printf("@%s),\n",dominio[random]);
        for(int i=0;nome[i]!='\0';i++){
            if(nome[i]==' '){
                nome[i]='_';
            }
        }
        //printf("'%s%d'),\n",limparutf8(nome),i%100);
        /*fprintf(saida,"('%s',",getCPF(i));
        fprintf(saida,"'%s',",getRG(i));
        fprintf(saida,"'%c',",sexo);
        fprintf(saida,"'%s',",nome);
        fprintf(saida,"'%s',",sobrenome);
        fprintf(saida,"'%s',",ultimoNome);
        fprintf(saida,"'%s',",getTelefone(i));
        fprintf(saida,"'%s%d%s@%s'),\n",nome,i%100,ultimoNome,dominio[random]);*/
    }
    return 0;
}