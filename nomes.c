#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>
#include <ctype.h>

char nomesFemininos[][50] = {"Helena", "Alice", "Laura", "Manuela", "Valentina", "Sophia", "Isabella", "Heloísa", "Luiza", "Júlia", "Lorena", "Lívia", "Maria Luiza", "Cecília", "Eloá", "Giovanna", "Maria Clara", "Maria Eduarda", "Mariana", "Lara", "Beatriz", "Antonella", "Maria Júlia", "Emanuelly", "Isadora", "Ana Clara", "Melissa", "Ana Luiza", "Ana Júlia", "Esther", "Lavínia", "Maitê", "Maria Cecília", "Maria Alice", "Sarah", "Elisa", "Liz", "Yasmin", "Isabelly", "Alícia", "Clara", "Isis", "Rebeca", "Rafaela", "Marina", "Ana Laura", "Maria Helena", "Agatha", "Gabriela", "Catarina", "Letícia", "Mirella", "Nicole", "Luna", "Maria Vitória", "Olívia", "Vitória", "Maria", "Maria Fernanda", "Ana Beatriz", "Allana", "Maria Valentina", "Milena", "Emilly", "Ayla", "Maria Flor", "Maya", "Bianca", "Clarice", "Aurora", "Larissa", "Mariah", "Pietra", "Laís", "Stella", "Eduarda", "Maria Heloísa", "Ana Lívia", "Ana Sophia", "Maria Laura", "Carolina", "Ana Vitória", "Malu", "Gabrielly", "Ana Liz", "Analu", "Maria Sophia", "Ana Cecília", "Amanda", "Louise", "Heloise", "Fernanda", "Ana", "Melina", "Maria Isis", "Bella", "Joana", "Isabel", "Melinda", "Pérola"};
char nomesMasculinos[][50] = {"Miguel", "Arthur", "Heitor", "Bernardo", "Davi", "Théo", "Lorenzo", "Gabriel", "Pedro", "Benjamin", "Matheus", "Lucas", "Nicolas", "Joaquim", "Samuel", "Henrique", "Rafael", "Guilherme", "Enzo", "Murilo", "Benício", "Gustavo", "Isaac", "João Miguel", "Lucca", "Enzo Gabriel", "Pedro Henrique", "Felipe", "João Pedro", "Pietro", "Anthony", "Daniel", "Bryan", "Davi Lucca", "Leonardo", "Vicente", "Eduardo", "Gael", "Antônio", "Vitor", "Noah", "Caio", "João", "Emanuel", "Cauã", "João Lucas", "Calebe", "Enrico", "Vinícius", "Bento", "Davi Lucas", "João Gabriel", "João Guilherme", "João Vitor", "Luiz Miguel", "Francisco", "Otávio", "Henry", "Levi", "Augusto", "Thomas", "Yuri", "Tomás", "Arthur Miguel", "Yan", "Thiago", "Theodoro", "Davi Luiz", "Ryan", "Erick", "Arthur Gabriel", "Breno", "Nathan", "Pedro Lucas", "Anthony Gabriel", "Luiz Felipe", "Luan", "Vitor Hugo", "Ravi", "Pedro Miguel", "Rodrigo", "Valentim", "Raul", "Martim", "Oliver", "Mathias", "Lucas Gabriel", "Luiz Otávio", "Davi Miguel", "Kaique", "Luiz Henrique", "José", "Arthur Henrique", "Luiz Gustavo", "Fernando", "Bruno", "Kauê", "Carlos Eduardo", "Miguel Henrique", "Derick"};
char sobrenomes[][50] = {"Abreu", "Adães", "Adorno", "Aguiar", "Albuquerque", "Alcântara", "Alencar", "Almeida", "Altamirano", "Alvarenga", "Álvares", "Alves", "Alvim", "Amaral", "Amigo", "Amor", "Amorim", "Anchieta", "Andrada", "Andrade", "Andrioli", "Anes", "Anjos", "Antunes", "Anunciação", "Apolinário", "Aragão", "Araújo", "Arruda", "Ascensão", "Assis", "Azeredo", "Azevedo", "André", "Asvilla", "Auth", "Badu", "Bandeira", "Barbosa", "Barreto", "Barros", "Barroso", "Baseggio", "Bastos", "Batista", "Bermudes", "Bernades", "Bernardes", "Bicalho", "Bispo", "Bizzo", "Bocaiuva", "Bolsonaro", "Borba", "Borges", "Borsoi", "Botelho", "Braga", "Bragança", "Brandão", "Brasil", "Brasiliense", "Brito", "Bruscato", "Bueno", "Cabral", "Café", "Camacho", "Camargo", "Caminha", "Camões", "Cândido", "Cardoso", "Carmo", "Carnaval", "Carneiro", "Carvalhal", "Carvalho", "Carvalhosa", "Castilho", "Castro", "Cauduro", "Cerejeira", "Chaves", "Coelho", "Coentrão", "Coimbra", "Conceição", "Constante", "Cordeiro", "Costa", "Cotrim", "Coutinho", "Couto", "Cruz", "Cunha", "Curado", "Dambros", "Dantas", "Delfino", "Dias", "Diegues", "Dorneles", "Duarte", "Eça", "Encarnação", "Esteves", "Evangelista", "Exaltação", "Fagundes", "Faleiros", "Falópio", "Falqueto", "Faria", "Farias", "Faro", "Ferrão", "Ferraz", "Ferro", "Ferreira", "Ferrolho", "Fernandes", "Figo", "Figueira", "Figueiredo", "Figueiroa", "Fioravante", "Fonseca", "Fontes", "Fortaleza", "França", "Freire", "Freitas", "Frota", "Furquim", "Furtado", "Feitosa", "Galvão", "Gama", "Garcia", "Garrastazu", "Gato", "Gomes", "Gonçales", "Gonçalves", "Gonzaga", "Gouveia", "Guarato", "Guimarães", "Gusmão", "Guerreiro", "Henriques", "Hernandes", "Hidelfonso", "Hoffmann", "Holanda", "Homem", "Hora", "Hungria", "Idelfonso", "Igrejas", "Ildefonso", "Jardim", "Jesus", "Jordão", "Junqueira", "Lacerda", "Lange", "Leitão", "Leite", "Leme", "Lima", "Lins", "Lira", "Locatelli", "Louzada", "Lopes", "Lutz", "Luz", "Leonor", "Macedo", "Machado", "Madureira", "Maduro", "Magalhães", "Mairinque", "Malafaia", "Malta", "Marinho", "Mariz", "Marques", "Martins", "Mascarenhas", "Massa", "Matos", "Médici", "Medeiros", "Meireles", "Mello", "Melo", "Mendes", "Mendonça", "Menino", "Messias", "Mesquita", "Milhomem", "Miranda", "Monteiro", "Moraes", "Morais", "Morato", "Morbeck", "Moreira", "Moretti", "Moro", "Muniz", "Namorado", "Nantes", "Nascimento", "Navalhes", "Navarro", "Naves", "Neis", "Negreiros", "Negrete", "Neves", "Nóbrega", "Nogueira", "Noronha", "Nunes", "Oliva", "Oliveira", "Outeiro", "Pacheco", "Padrão", "Paes", "Pais", "Paiva", "Paixão", "Papanicolau", "Parga", "Pascal", "Pascoal", "Pasquim", "Patriota", "Peçanha", "Pedrosa", "Pedroso", "Peixoto", "Pellegrini", "Penna", "Pensamento", "Penteado", "Pereira", "Peres", "Pessoa", "Pestana", "Pimenta", "Pimentel", "Pinheiro", "Pinto", "Pires", "Placides", "Poeta", "Policarpo", "Porto", "Portugal", "Prado", "Prudente", "Quaresma", "Queirós", "Queiroz", "Ramalhete", "Ramalho", "Ramires", "Ramos", "Rangel", "Reis", "Resende", "Ribeiro", "Rios", "Rocha", "Rodrigues", "Roma", "Romão", "Roçadas", "Sá", "Sacramento", "Sampaio", "Sampaulo", "Sampedro", "Sanches", "Sandes", "Santacruz", "Santana", "Santander", "Santarrosa", "Santiago", "Santos", "Saragoça", "Saraiva", "Saramago", "Seixas", "Serra", "Serrano", "Silva", "Silveira", "Simões", "Siqueira", "Soares", "Soeiro", "Spiassi", "Sousa", "Souza", "Stein", "Tavares", "Teixeira", "Teles", "Torquato", "Trindade", "Uchoa", "Uribe", "Ustra", "Valadares", "Valença", "Valente", "Valverde", "Varela", "Vasconcelos", "Vasques", "Vaz", "Veiga", "Velasques", "Veloso", "Viana", "Vieira", "Vilela", "Vilhena", "Vicente", "Wagner", "Xavier", "Young", "Zampol", "Zema"};
char dominio[][20] = {"yahoo.com.br","google.com","hotmail.com","outlook.com","uol.com.br","terra.com.br"};
char estados[][25] = {"Rio Branco - AC","Maceió - AL","Macapá - AP","Manaus - AM","Salvador - BA","Fortaleza - CE","Brasilia - DF","Vitória - ES","Goiânia - GO","São Luís - MA","Cuiabá - MT","Campo Grande - MS","Belo Horizonte - MG","Belém - PA"," João Pessoa - PB","Curitiva - PR","Recife - PE","Teresina - PI","Rio de Janeiro - RJ","Natal - RN","Porto Alegre - RS","Porto Velho - RO","Boa Vista - RR","Florianópolis - SC","São Paulo - SP","Aracaju - SE","Palmas - TO"};
char ruas[][20] = {"Av Brasil","Av Rio Branco","Rua Cascudo","Av Getúlio Vargas","Rua Margarida","Rua Belo Monte","Av Salgado Filho"};

void putCPF(FILE *f,int i){     
    fprintf(f,"('%03u.%03u.%03u-%02u',",rand()%1000,rand()%1000,rand()%1000,i%100);
}
void getCPF(int i){     
    printf("('%03u.%03u.%03u-%02u',",rand()%1000,rand()%1000,rand()%1000,i%100);
}

void getRG(int i){
    int ref = i*i;
    printf("'%d.%03d.%03d',",i%10,ref%1000,(ref*73)%1000);       
}

void putRG(FILE *f,int i){
    int ref = i*i;
    fprintf(f,"'%d.%03d.%03d',",i%10,ref%1000,(ref*73)%1000);       
}

void getTelefone(int i){
    int cod = i%89+10;
    printf("'+55 (%02d) 9 %04d-%04d',",cod,(i*i*31+2222)/10000,(i*37*i+3578)%10000);   
}

void putTelefone(FILE *f,int i){
    int cod = i%89+10;
    fprintf(f,"'+55 (%02d) 9 %04d-%04d',",cod,(i*i*31+2222)/10000,(i*37*i+3578)%10000);   
}
    
void limpar(char *nome){
    while(*nome!='\0'){
        if(*nome <='Z' && *nome>='A') *nome += 32;
        if(*nome == ' ') *nome = '_';
        nome++;
    }
}

void getEmail(char *nome,char *ultimo,int i){
    printf("'%s%02u%s@%s'",nome,i%100,ultimo,dominio[rand()%6]);
}

void putEmail(FILE *f,char *nome,char *ultimo,int i){
    fprintf(f,"'%s%02u%s@%s'",nome,i%100,ultimo,dominio[rand()%6]);
}

int main(){
    setlocale(LC_ALL,"pt-BR.UFT-8");
    srand(time(NULL));
    int random;
    FILE *saida = fopen("saida.sql","w");

    char *nome;
    char sexo;
    for(int i=0;i<1000;i++){
        random = rand()%100;
        if(i%2==1 || i%10==0){
            sexo = 'f';
            nome = nomesFemininos[random];            
        }else{
            sexo = 'm';
            nome = nomesMasculinos[random];
        }
        random = rand()%344;       
        char *ultimoNome = sobrenomes[random];    
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
            if(qtdSobrenomes-i>1)sobrenome[j++]=' ';
        }        
        sobrenome[j]='\0';               
        getCPF(i);
        getRG(i);
        
    fprintf(saida,"INSERT INTO apex_pessoa (cpf,rg,sexo,nome_primeiro,nome_meio,nome_ultimo,data_nascimento,endereco,telefone,email)\n");
    fprintf(saida,"VALUES");
        printf("'%c',",sexo);
        printf("'%s',",nome);
        printf("'%s',",sobrenome);
        printf("'%s',",ultimoNome);
        printf("'%u%02u%02u',",1900+rand()%100,rand()%12,rand()%28);
        printf("%s %d,%s",ruas[rand()%7],rand()%1000+2,estados[rand()%27]);
        getTelefone(i);

        putCPF(saida,i);
        putRG(saida,i);
        //fprintf(saida,"'%s',",getRG(i));
        fprintf(saida,"'%c',",sexo);
        fprintf(saida,"'%s',",nome);
        fprintf(saida,"'%s',",sobrenome);
        fprintf(saida,"'%s',",ultimoNome);
        fprintf(saida,"'%u%02u%02u',",1900+rand()%100,rand()%12,rand()%28);
        fprintf(saida,"'%s %d,%s',",ruas[rand()%7],rand()%1000+2,estados[rand()%27]);
        putTelefone(saida,i);

        random = rand()%6;
        getEmail(nome,ultimoNome,i);
        putEmail(saida,nome,ultimoNome,i);        
        printf("),\n");
        fprintf(saida,");\n");
    }
    fclose(saida);
    return 0;
}