#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

char nomesFemininos[][50] = {"Helena", "Alice", "Laura", "Manuela", "Valentina", "Sophia", "Isabella", "Heloísa", "Luiza", "Júlia", "Lorena", "Lívia", "Maria Luiza", "Cecília", "Eloá", "Giovanna", "Maria Clara", "Maria Eduarda", "Mariana", "Lara", "Beatriz", "Antonella", "Maria Júlia", "Emanuelly", "Isadora", "Ana Clara", "Melissa", "Ana Luiza", "Ana Júlia", "Esther", "Lavínia", "Maitê", "Maria Cecília", "Maria Alice", "Sarah", "Elisa", "Liz", "Yasmin", "Isabelly", "Alícia", "Clara", "Isis", "Rebeca", "Rafaela", "Marina", "Ana Laura", "Maria Helena", "Agatha", "Gabriela", "Catarina", "Letícia", "Mirella", "Nicole", "Luna", "Maria Vitória", "Olívia", "Vitória", "Maria", "Maria Fernanda", "Ana Beatriz", "Allana", "Maria Valentina", "Milena", "Emilly", "Ayla", "Maria Flor", "Maya", "Bianca", "Clarice", "Aurora", "Larissa", "Mariah", "Pietra", "Laís", "Stella", "Eduarda", "Maria Heloísa", "Ana Lívia", "Ana Sophia", "Maria Laura", "Carolina", "Ana Vitória", "Malu", "Gabrielly", "Ana Liz", "Analu", "Maria Sophia", "Ana Cecília", "Amanda", "Louise", "Heloise", "Fernanda", "Ana", "Melina", "Maria Isis", "Bella", "Joana", "Isabel", "Melinda", "Pérola"};
char nomesMasculinos[][50] = {"Miguel", "Arthur", "Heitor", "Bernardo", "Davi", "Théo", "Lorenzo", "Gabriel", "Pedro", "Benjamin", "Matheus", "Lucas", "Nicolas", "Joaquim", "Samuel", "Henrique", "Rafael", "Guilherme", "Enzo", "Murilo", "Benício", "Gustavo", "Isaac", "João Miguel", "Lucca", "Enzo Gabriel", "Pedro Henrique", "Felipe", "João Pedro", "Pietro", "Anthony", "Daniel", "Bryan", "Davi Lucca", "Leonardo", "Vicente", "Eduardo", "Gael", "Antônio", "Vitor", "Noah", "Caio", "João", "Emanuel", "Cauã", "João Lucas", "Calebe", "Enrico", "Vinícius", "Bento", "Davi Lucas", "João Gabriel", "João Guilherme", "João Vitor", "Luiz Miguel", "Francisco", "Otávio", "Henry", "Levi", "Augusto", "Thomas", "Yuri", "Tomás", "Arthur Miguel", "Yan", "Thiago", "Theodoro", "Davi Luiz", "Ryan", "Erick", "Arthur Gabriel", "Breno", "Nathan", "Pedro Lucas", "Anthony Gabriel", "Luiz Felipe", "Luan", "Vitor Hugo", "Ravi", "Pedro Miguel", "Rodrigo", "Valentim", "Raul", "Martim", "Oliver", "Mathias", "Lucas Gabriel", "Luiz Otávio", "Davi Miguel", "Kaique", "Luiz Henrique", "José", "Arthur Henrique", "Luiz Gustavo", "Fernando", "Bruno", "Kauê", "Carlos Eduardo", "Miguel Henrique", "Derick"};
char sobrenomes[][50] = {"Abreu", "Adães", "Adorno", "Aguiar", "Albuquerque", "Alcântara", "Alencar", "Almeida", "Altamirano", "Alvarenga", "Álvares", "Alves", "Alvim", "Amaral", "Amigo", "Amor", "Amorim", "Anchieta", "Andrada", "Andrade", "Andrioli", "Anes", "Anjos", "Antunes", "Anunciação", "Apolinário", "Aragão", "Araújo", "Arruda", "Ascensão", "Assis", "Azeredo", "Azevedo", "André", "Asvilla", "Auth", "Badu", "Bandeira", "Barbosa", "Barreto", "Barros", "Barroso", "Baseggio", "Bastos", "Batista", "Bermudes", "Bernades", "Bernardes", "Bicalho", "Bispo", "Bizzo", "Bocaiuva", "Bolsonaro", "Borba", "Borges", "Borsoi", "Botelho", "Braga", "Bragança", "Brandão", "Brasil", "Brasiliense", "Brito", "Bruscato", "Bueno", "Cabral", "Café", "Camacho", "Camargo", "Caminha", "Camões", "Cândido", "Cardoso", "Carmo", "Carnaval", "Carneiro", "Carvalhal", "Carvalho", "Carvalhosa", "Castilho", "Castro", "Cauduro", "Cerejeira", "Chaves", "Coelho", "Coentrão", "Coimbra", "Conceição", "Constante", "Cordeiro", "Costa", "Cotrim", "Coutinho", "Couto", "Cruz", "Cunha", "Curado", "Dambros", "Dantas", "Delfino", "Dias", "Diegues", "Dorneles", "Duarte", "Eça", "Encarnação", "Esteves", "Evangelista", "Exaltação", "Fagundes", "Faleiros", "Falópio", "Falqueto", "Faria", "Farias", "Faro", "Ferrão", "Ferraz", "Ferro", "Ferreira", "Ferrolho", "Fernandes", "Figo", "Figueira", "Figueiredo", "Figueiroa", "Fioravante", "Fonseca", "Fontes", "Fortaleza", "França", "Freire", "Freitas", "Frota", "Furquim", "Furtado", "Feitosa", "Galvão", "Gama", "Garcia", "Garrastazu", "Gato", "Gomes", "Gonçales", "Gonçalves", "Gonzaga", "Gouveia", "Guarato", "Guimarães", "Gusmão", "Guerreiro", "Henriques", "Hernandes", "Hidelfonso", "Hoffmann", "Holanda", "Homem", "Hora", "Hungria", "Idelfonso", "Igrejas", "Ildefonso", "Jardim", "Jesus", "Jordão", "Junqueira", "Lacerda", "Lange", "Leitão", "Leite", "Leme", "Lima", "Lins", "Lira", "Locatelli", "Louzada", "Lopes", "Lutz", "Luz", "Leonor", "Macedo", "Machado", "Madureira", "Maduro", "Magalhães", "Mairinque", "Malafaia", "Malta", "Marinho", "Mariz", "Marques", "Martins", "Mascarenhas", "Massa", "Matos", "Médici", "Medeiros", "Meireles", "Mello", "Melo", "Mendes", "Mendonça", "Menino", "Messias", "Mesquita", "Milhomem", "Miranda", "Monteiro", "Moraes", "Morais", "Morato", "Morbeck", "Moreira", "Moretti", "Moro", "Muniz", "Namorado", "Nantes", "Nascimento", "Navalhes", "Navarro", "Naves", "Neis", "Negreiros", "Negrete", "Neves", "Nóbrega", "Nogueira", "Noronha", "Nunes", "Oliva", "Oliveira", "Outeiro", "Pacheco", "Padrão", "Paes", "Pais", "Paiva", "Paixão", "Papanicolau", "Parga", "Pascal", "Pascoal", "Pasquim", "Patriota", "Peçanha", "Pedrosa", "Pedroso", "Peixoto", "Pellegrini", "Penna", "Pensamento", "Penteado", "Pereira", "Peres", "Pessoa", "Pestana", "Pimenta", "Pimentel", "Pinheiro", "Pinto", "Pires", "Placides", "Poeta", "Policarpo", "Porto", "Portugal", "Prado", "Prudente", "Quaresma", "Queirós", "Queiroz", "Ramalhete", "Ramalho", "Ramires", "Ramos", "Rangel", "Reis", "Resende", "Ribeiro", "Rios", "Rocha", "Rodrigues", "Roma", "Romão", "Roçadas", "Sá", "Sacramento", "Sampaio", "Sampaulo", "Sampedro", "Sanches", "Sandes", "Santacruz", "Santana", "Santander", "Santarrosa", "Santiago", "Santos", "Saragoça", "Saraiva", "Saramago", "Seixas", "Serra", "Serrano", "Silva", "Silveira", "Simões", "Siqueira", "Soares", "Soeiro", "Spiassi", "Sousa", "Souza", "Stein", "Tavares", "Teixeira", "Teles", "Torquato", "Trindade", "Uchoa", "Uribe", "Ustra", "Valadares", "Valença", "Valente", "Valverde", "Varela", "Vasconcelos", "Vasques", "Vaz", "Veiga", "Velasques", "Veloso", "Viana", "Vieira", "Vilela", "Vilhena", "Vicente", "Wagner", "Xavier", "Young", "Zampol", "Zema"};

int main(){
    setlocale(LC_ALL,"pt_BR.UTF-8");
    srand(time(NULL));
    int random;
    //FILE *saida = fopen("saida.txt","w");
    char *nome;
    char sexo;
    char cpf[15] = "100.000.000-10";
    for(int i=0;i<10;i++){
        int varia = i*i*i;
        int digito = 14;
        while(varia>0){
            cpf[digito--] = varia%10+30;
            if(digito%4 == 0) digito--;
            varia/10;
        }
        printf("%s\t",cpf);
        random = rand()%100;
        if(i%2==1 || i%10==0){
            sexo = 'f';
            nome = nomesFemininos[random];            
        }else{
            sexo = 'm';
            nome = nomesFemininos[random];
        }
        printf("%c\t%s ",sexo,nome);
        random = rand()%344;     
        char *sobrenome = sobrenomes[random];
        int qtdSobrenomes =  rand()%3-1;
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
        printf("%s\n",sobrenome);
        free(sobrenome);
        //fprintf(saida,"%u \t %c \t %s %s\n",cpf,sexo,nome,sobrenome);
    }
    return 0;
}