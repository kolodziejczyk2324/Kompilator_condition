%{
#include <cstdio>
#include <iostream>
#include <math.h>
#include <vector>
#include <map>
#include <string>
#include <sstream>
#include "Biblioteki/library.h"
#include "Biblioteki/MyStack.h"

#define STORE(X) code.push_back(concatStringInt("STORE ", X));
#define LOAD(X) code.push_back(concatStringInt("LOAD ", X));
#define ADD(X) code.push_back(concatStringInt("ADD ", X));
#define SUB(X) code.push_back(concatStringInt("SUB ", X));
#define PUT(X) code.push_back(concatStringInt("PUT ", X));
#define GET(X) code.push_back(concatStringInt("GET ", X));
#define ZERO(X) code.push_back(concatStringInt("ZERO ", X));
#define COPY(X) code.push_back(concatStringInt("COPY ", X));
#define JZERO(X, Y) code.push_back(concatStringInt("JZERO ", X)+string(" ")+Y);
#define JUMP(X) code.push_back("JUMP " + X);

#define PUSH_ETYK(X) etykiety.push(concatStringInt("E", X));
#define POP_AND_WRITE_ETYK code.push_back(etykiety.pop());

#define EQ_1 PUSH_ETYK(ety+1) PUSH_ETYK(ety+2) PUSH_ETYK(ety+1)\
	PUSH_ETYK(ety+2) PUSH_ETYK(ety) PUSH_ETYK(ety+1)\
	PUSH_ETYK(ety) ety+=3;
#define EQ_2 JZERO(1, etykiety.pop())\
	create_number(code, 0, 1);\
	JUMP(etykiety.pop())\
	POP_AND_WRITE_ETYK
#define EQ_3 JZERO(1, etykiety.pop())\
	create_number(code, 0, 1);\
	JUMP(etykiety.pop())\
	POP_AND_WRITE_ETYK\
	create_number(code, 1, 1);\
	POP_AND_WRITE_ETYK

#define NEQ_1 PUSH_ETYK(ety+1) PUSH_ETYK(ety) PUSH_ETYK(ety+1)\
	PUSH_ETYK(ety) ety+=2;
#define NEQ_2 JZERO(1, etykiety.pop())\
	JUMP(etykiety.pop())\
	POP_AND_WRITE_ETYK
#define NEQ_3 POP_AND_WRITE_ETYK

#define XOET_1 PUSH_ETYK(ety+1) PUSH_ETYK(ety) PUSH_ETYK(ety+1)\
	PUSH_ETYK(ety) ety+=2;
#define XOET_2 JZERO(1, etykiety.pop())\
	JUMP(etykiety.pop())\
	POP_AND_WRITE_ETYK
#define XOET_3 POP_AND_WRITE_ETYK

using namespace std;

void yyerror(const char *s);
void check_identifier(string name, int isArray);
void check_double_declaration(string name);
void load_memory_to_register(int memory, int reg);
void save_register_to_memory(int reg, int memory);
void save_number_to_memory(int number, int memory);

void odejmowanie_number_number(int a, int b);
void odejmowanie_identifier_number(int num);
void odejmowanie_number_identifier(int num);
void odejmowanie_identifier_identifier(int a, int b);
void rowne_number_number(int a, int b);
void rowne_identifier_number(int num);
void rowne_identifier_identifier();

extern "C" int yylex();
extern int yylineno;

struct var_data{
	int store;
	int isArray;
};

vector<string> code;
map<string, struct var_data> zmienne;
MyStack etykiety;
int i = 4;
int mem_to_save_id = 1;
int ety = 1;

%}
%union {
	int	ival;
        char*	sval;
}

%token <sval> IDENTIFIER
%token VAR _BEGIN END READ WRITE SKIP
%token IF THEN ELSE ENDIF
%token GT LT EQ NEQ GOET LOET
%token LB RB
%token SREDNIK 
%token PRZYPISANIE 
%token PLUS MINUS
%token <ival>NUMBER

%start program
%%

program:	VAR vdeclarations _BEGIN commands END
	;

vdeclarations:	
	|	vdeclarations IDENTIFIER	{	check_double_declaration($2);
							struct var_data v = { i++, 0 };
							zmienne[$2] = v;				}
	|	vdeclarations IDENTIFIER 
		LB NUMBER RB			{	check_double_declaration($2);
							struct var_data v = { i, 1 };
							zmienne[$2] = v;
							i += $4;					}
	;
commands:	commands command
	|	command
	;
command:	READ identifier SREDNIK		{	load_memory_to_register(1,0);
							GET(1) 
							STORE(1)				}					
	|	WRITE NUMBER SREDNIK		{	create_number(code, $2, 1);
							PUT(1)						}
	|	WRITE identifier SREDNIK	{	mem_to_save_id = 1;
							load_memory_to_register(1,0);
							LOAD(1)
							PUT(1)						} 
	|	identifier			{	mem_to_save_id = 1;
							load_memory_to_register(1, 1);
							save_register_to_memory(1, 3);			} 
		PRZYPISANIE exp SREDNIK		{	load_memory_to_register(3, 0);
							STORE(1)
							mem_to_save_id = 1;				}
        /***********************************************************************************************/
        /********** IF *********************************************************************************/
        /***********************************************************************************************/
        |       IF                              {       PUSH_ETYK(ety+1) PUSH_ETYK(ety)
                                                        PUSH_ETYK(ety+1) PUSH_ETYK(ety) ety+=2;         }
                condition                       {       JZERO(1, etykiety.pop()) mem_to_save_id=1;	}
                THEN
                commands                        {       JUMP(etykiety.pop())
                                                        POP_AND_WRITE_ETYK				}
                ELSE
                commands
                ENDIF                           {       POP_AND_WRITE_ETYK				}
	|	SKIP SREDNIK			{ }		
	;
exp:	        NUMBER                          {       create_number(code, $1, 1);                     }
        |       identifier                      {       create_number(code, 1, 0);
                                                        LOAD(1)
                                                        COPY(1)
                                                        LOAD(1)                                         }
        /***********************************************************************************************/
        /********* DODAWANIE ***************************************************************************/
        /***********************************************************************************************/
	|	NUMBER PLUS NUMBER		{	create_number(code, $1+$3, 1);			}
	|	identifier PLUS NUMBER		{	load_memory_to_register(1, 0);
							create_number(code, $3, 1);
							ADD(1)						}
	|	NUMBER PLUS identifier		{	load_memory_to_register(1,0);
							create_number(code, $1, 1);
							ADD(1)						}
	|	identifier PLUS identifier	{	load_memory_to_register(1,0);
							LOAD(1)						
							load_memory_to_register(2,0);						
							ADD(1)						}
	/************************************************************************************************/
	/******** ODEJMOWANIE ***************************************************************************/
	/************************************************************************************************/
	|	NUMBER MINUS NUMBER		{	odejmowanie_number_number($1, $3);		}
	|	identifier MINUS NUMBER		{	odejmowanie_identifier_number($3);		}
	|	NUMBER MINUS identifier		{	odejmowanie_number_identifier($1);		}
	|	identifier MINUS identifier	{	odejmowanie_identifier_identifier(1,2);		}
	;
	/***********************************************************************************************/
	/********** WARUNKI ****************************************************************************/
	/***********************************************************************************************/
	/* warunki zwracaja w pierwszym rejestrze liczbe
	   w przypadku gdy liczba ta jest rowna 0 oznacza to falsz
	   gdy zas liczba jest rozna od 0 oznacza to prawde */
	/***********************************************************************************************/
	/**********    >    ****************************************************************************/
	/***********************************************************************************************/
condition:	NUMBER GT NUMBER		{	odejmowanie_number_number($1, $3);		}
        |       identifier GT NUMBER		{       odejmowanie_identifier_number($3);		}
        |       NUMBER GT identifier         	{       odejmowanie_number_identifier($1);		}
        |       identifier GT identifier     	{       odejmowanie_identifier_identifier(1,2);		}
	/***********************************************************************************************/
	/*********    <     ****************************************************************************/
	/***********************************************************************************************/
	/* robimy X LT Y to r1 <- Y-X */
	|	NUMBER LT NUMBER		{	odejmowanie_number_number($3, $1);	}
	|	identifier LT NUMBER		{	odejmowanie_number_identifier($3);	}
	|	NUMBER LT identifier		{	odejmowanie_identifier_number($1);	}
	|	identifier LT identifier	{	odejmowanie_identifier_identifier(2,1);	}
	/***********************************************************************************************/
	/*********    =    *****************************************************************************/
	/***********************************************************************************************/
	/* robimy X LT Y to X-Y = 0 = Y-X */
	|	NUMBER EQ NUMBER		{	rowne_number_number($1, $3);		}
	|	identifier EQ NUMBER		{	rowne_identifier_number($3);		}
	|	NUMBER EQ identifier		{	rowne_identifier_number($1);		}
	|	identifier EQ identifier	{	rowne_identifier_identifier();		}
	/***********************************************************************************************/
	/*********** >= ********************************************************************************/
	/***********************************************************************************************/
	/* robimy X GOET Y wtedy
			{ tak : wyskocz
		X>Y = 	{
			{ nie : sprawdz X=Y	*/
	|	NUMBER	GOET NUMBER		{	XOET_1
                                                        odejmowanie_number_number($1, $3); 	//wieksze
                                                        XOET_2
                                                        rowne_number_number($1, $3);		//rowne
                                                        XOET_3				}
	|	identifier GOET NUMBER		{	XOET_1
							odejmowanie_identifier_number($3);	//wieksze
							XOET_2
							rowne_identifier_number($3);		//rowne
							XOET_3				}
	|	NUMBER GOET identifier		{	XOET_1
							odejmowanie_number_identifier($1);	//wieksze
							XOET_2
							rowne_identifier_number($1);		//rowne
							XOET_3				}
	|	identifier GOET identifier	{	XOET_1
							odejmowanie_identifier_identifier(1,2);	//wieksze
							XOET_2
							rowne_identifier_identifier();		//rowne
							XOET_3				}
	/***********************************************************************************************/
        /*********** >= ********************************************************************************/
        /***********************************************************************************************/
        /* robimy X LOET Y wtedy
                        { tak : wyskocz
                X<Y =   {
                        { nie : sprawdz X=Y     */
	|	NUMBER LOET NUMBER		{	XOET_1
							odejmowanie_number_number($3, $1); 	//mniejsze
							XOET_2
							rowne_number_number($1, $3);		//rowne
							XOET_3				}
	|	identifier LOET NUMBER		{	XOET_1
							odejmowanie_number_identifier($3);
							XOET_2
							rowne_identifier_number($3);
							XOET_3				}
	|	NUMBER LOET identifier		{	XOET_1
							odejmowanie_identifier_number($1);
							XOET_2
							rowne_identifier_number($1);
							XOET_3				}
	|	identifier LOET identifier	{	XOET_1
							odejmowanie_identifier_identifier(2,1);
							XOET_2
							rowne_identifier_identifier();
							XOET_3				}
	/***********************************************************************************************/
        /*********** <> ********************************************************************************/
        /***********************************************************************************************/
        /* robimy X NEQ Y wtedy
                        { 0 : zwroc Y-X
                X-Y =   {
                        { >0 : wyskocz z ta wartoscia     */
	|	NUMBER NEQ NUMBER		{	NEQ_1
							odejmowanie_number_number($1, $3);
							NEQ_2
							odejmowanie_number_number($3, $1);
							NEQ_3				}
	|	identifier NEQ NUMBER		{	NEQ_1
							odejmowanie_identifier_number($3);
							NEQ_2
							odejmowanie_number_identifier($3);
							NEQ_3				}
	|	NUMBER NEQ identifier		{	NEQ_1
							odejmowanie_number_identifier($1);
							NEQ_2
							odejmowanie_identifier_number($1);
							NEQ_3				}
	|	identifier NEQ identifier	{	NEQ_1
							odejmowanie_identifier_identifier(1,2);
							NEQ_2
							odejmowanie_identifier_identifier(2,1);
							NEQ_3				}
							
	;
identifier:	IDENTIFIER			{	check_identifier($1, 0);
							create_number(code, mem_to_save_id, 0);
							create_number(code, zmienne[$1].store, 1);
							STORE(1)
							mem_to_save_id++;				}
	|	IDENTIFIER LB IDENTIFIER RB	{	check_identifier($1, 1);
							check_identifier($3, 0);
							create_number(code, zmienne[$3].store, 0);
							create_number(code, zmienne[$1].store, 1);
							ADD(1)
							create_number(code, mem_to_save_id, 0);
							STORE(1)
							mem_to_save_id++;				}
	|	IDENTIFIER LB NUMBER RB		{	check_identifier($1, 1);
							create_number(code, $3, 1);
							ZERO(0)
							STORE(1)
							create_number(code, zmienne[$1].store, 1);
							ADD(1)
							create_number(code, mem_to_save_id, 0);
							STORE(1)
							mem_to_save_id++;				}
							
	;
%%

/****** CHECK *******************************************************************************************/
/********************************************************************************************************/
/*
Sprawdzenie czy zmienna o nazwie 'name' nie zostala zadeklarowana kolejny raz
Jezeli tak sie stalo, zakoncz program z odpowiednia wiadomoscia					
*/
void check_double_declaration(string name){
	if( zmienne.find(name) != zmienne.end() ){
                string err = string("Deklaracja istniejacej zmiennej \"") + string(name) + string("\"");
                yyerror(err.c_str());
        }
}

/* 
Sprawdzamy czy przeczytany identyfikator o nazwie 'name' zostal wczesniej zadeklarowany, oraz
czy jest on tablica (wtedy isArray = 1), czy jest zmienna (isArray = 0).
Jezeli ktorys z tych warunkow zawiedzie konczymy program z odpowiednim komunikatem.		
*/ 
void check_identifier(string name, int isArray){
	if( zmienne.find(name) == zmienne.end() ){
		string err = string("Niezadeklarowana zmienna \"") + string(name) + string("\"");
		yyerror(err.c_str());
	}
	else if( zmienne[name].isArray != isArray ){
		string err = string("Niewlasciwe uzycie identyfikatora \"") + string(name) +string("\"");
		yyerror(err.c_str());
	}
}

/*
Funkcja generujaca asembler ktory dziala na rejestrze 0. Wczytuje on dana z komorki pamieci
'memory' do rejestru 'reg'.
*/
void load_memory_to_register(int memory, int reg){
	create_number(code, memory, 0);
	LOAD(reg)
}

void save_register_to_memory(int reg, int memory){
	create_number(code, memory, 0);
	STORE(reg)
}

void save_number_to_memory(int number, int memory){
	create_number(code, number, 1);
	create_number(code, memory, 0);
	STORE(1)
}

/************************************************************************/
/***** OPERACJE *********************************************************/
/************************************************************************/

void odejmowanie_number_number(int a, int b){
	create_number(code, numbSub(a, b), 1);
}

void odejmowanie_identifier_number(int num){
	save_number_to_memory(num, 0);
	load_memory_to_register(1, 0);		
	LOAD(1)
	ZERO(0)
	SUB(1)
}

void odejmowanie_number_identifier(int num){
	load_memory_to_register(1, 0);
	create_number(code, num, 1);
	SUB(1)
}

/*zmienne a b oznaczaja ktory identifier jest odejmowany od ktorego, czyli:
	a=1, b=2 -> odejmujemy id1 - id2
	a=2, b=1 -> odejmujemy id2 - id1	*/
void odejmowanie_identifier_identifier(int a, int b){
	load_memory_to_register(a,0);
	LOAD(1)
	load_memory_to_register(b,0);
	SUB(1)
}

/************************************************************************/
/***** WARUNKI **********************************************************/
/************************************************************************/
void rowne_number_number(int a, int b){
	EQ_1
	odejmowanie_number_number(a, b);	//odejmowanie
	EQ_2
	odejmowanie_number_number(b, a);	//odejmowanie
	EQ_3
}

void rowne_identifier_number(int num){
	EQ_1
	odejmowanie_identifier_number(num);	//odejmowanie
	EQ_2
	odejmowanie_number_identifier(num);	//odejmowanie
	EQ_3
}

void rowne_identifier_identifier(){
	EQ_1
	odejmowanie_identifier_identifier(1,2);	//odejmowanie
	EQ_2
	odejmowanie_identifier_identifier(2,1);	//odejmowanie
	EQ_3
}


/************************************************************************/
/***** PRZEBIEGI ********************************************************/
/************************************************************************/

void zapamietajPozycjeEtykiet(map<string, string> &ety_pos){
        for(int j=0 ; j<code.size(); j++){
                if(isPrefix("E", code[j])){
                        ostringstream ss;
                        ss << j;
                        ety_pos[code[j]] = ss.str();
                        code.erase(code.begin()+j);
                        j--;
                }
        }
}

void podmienEtykiety(map<string, string> &ety_pos){
       for(int j=0 ; j<code.size() ; j++)
                if(isPrefix("JUMP", code[j]) || isPrefix("JZERO", code[j]) || isPrefix("JODD", code[j]))
                        code[j] = replaceLastWord( code[j], ety_pos[ getLastWord(code[j]) ] );
}

void wypiszAssembler(){
	for(int j=0; j<code.size(); j++)
		cout << code[j] << endl;
	cout << "HALT" << endl;
}

/************************************************************************/
/******** MAIN **********************************************************/
/************************************************************************/

int main()
{
	yyparse();
	map<string, string> ety_pos;
	zapamietajPozycjeEtykiet(ety_pos);
	podmienEtykiety(ety_pos);
	wypiszAssembler();
}


void yyerror(const char *s){
        cout << "Blad. " << s << " w linii " << yylineno << endl;
        exit(0);
}
