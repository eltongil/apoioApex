#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>
#include <ctype.h>

char siglasInstCiv[][4] = {"UF","IF","TC","COR","HU","NEI","TRE"};
char intituicaoCivil[][40] = {"Universidade Federal ","Instituo Federal ","Tribunal de Contas","Corregedoria ","Hospital Universitário","Núcleo de Educação Infantil","Tribunal Regional Eleitoral"};
char siglasInstMil[][4] = {"EXE","MAR","AER"};
char instituicaoMilitar[][20] = {"Exercíto","Marinha","Aeronáutica"};
char siglasEstados[][3] = {"DF","AM","AC","BA","CE","ES","MA","PA","PB","PR","PI","TO","RJ","RN","RS","AL","GO","MG","MS","MG","PE","RO","RR","SC","SP","SE"};
char estados[][30] = {"de Brasilia","do Amazonas","do Acre","da Bahia","do Ceará","do Espírito Santo","do Maranhão","do Pará","da Paraíba","do Paraná","do Piauí","do Tocantins","do Rio de Janeiro","do Rio Grande do Norte","do Rio Grande do Sul","de Alagoas","de Goiás","de Mato Grosso","de Mato GRosso do Sul","de Minas Gerais","de Pernambuco","de Rondônia","de Roraima","de Santa Catarina","de São Paulo","de Sergipe"};
char cidades[][25] = {"Rio Branco - AC","Maceió - AL","Macapá - AP","Manaus - AM","Salvador - BA","Fortaleza - CE","Brasilia - DF","Vitória - ES","Goiânia - GO","São Luís - MA","Cuiabá - MT","Campo Grande - MS","Belo Horizonte - MG","Belém - PA"," João Pessoa - PB","Curitiva - PR","Recife - PE","Teresina - PI","Rio de Janeiro - RJ","Natal - RN","Porto Alegre - RS","Porto Velho - RO","Boa Vista - RR","Florianópolis - SC","São Paulo - SP","Aracaju - SE","Palmas - TO"};
char ruas[][20] = {"Av Brasil","Av Rio Branco","Rua Cascudo","Av Getúlio Vargas","Rua Margarida","Rua Belo Monte","Av Salgado Filho"};

int main(){
    FILE *saida = fopen("empresas.sql","w");

    for(int i=0;i<26;i++){
        for(int j=0;j<6;j++){
            fprintf(saida,"\nINSERT INTO apex_empresa (id_empresa,nome,endereco)\n");
            fprintf(saida,"VALUES");
            fprintf(saida," ('%s%s%03d%03d',",siglasInstCiv[j],siglasEstados[i],i*3,j*13);
            fprintf(saida,"'%s %s',",intituicaoCivil[j],estados[i]);
            fprintf(saida,"'%s %d,%s');\n",ruas[rand()%7],rand()%5000+2,cidades[rand()%27]);
        }
        for(int j=0;j<3;j++){
            fprintf(saida,"\nINSERT INTO apex_empresa (id_empresa,nome,endereco)\n");
            fprintf(saida,"VALUES");
            fprintf(saida,"('%s%s%03d%03d',",siglasInstMil[j],siglasEstados[i],i*3,j*13);
            fprintf(saida,"'%s %s',",instituicaoMilitar[j],estados[i]);
            fprintf(saida,"'%s %d,%s');\n",ruas[rand()%7],rand()%5000+2,cidades[rand()%27]);
        }
    }
    fclose(saida);
}