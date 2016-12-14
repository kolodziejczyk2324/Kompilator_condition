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

using namespace std;

void yyerror(const char *s);
void check_identifier(string name, int isArray);
void check_double_declaration(string name);
void load_memory_to_register(int memory, int reg);
void save_register_to_memory(int reg, int memory);
void save_number_to_memory(int number, int memory);

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
%token GT LT EQ GOET LOET
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
							STORE(1)					}								
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
	|	NUMBER MINUS NUMBER		{	create_number(code, numbSub($1, $3), 1);	}
	|	identifier MINUS NUMBER		{	save_number_to_memory($3, 0);
							load_memory_to_register(1, 0);		
							LOAD(1)
							ZERO(0)
							SUB(1)						}
	|	NUMBER MINUS identifier		{	load_memory_to_register(1, 0);
							create_number(code, $1, 1);
							SUB(1)						}
	|	identifier MINUS identifier	{	load_memory_to_register(1,0);
							LOAD(1)
							load_memory_to_register(2,0);
							SUB(1)						}
	;
	/***********************************************************************************************/
	/********** WARUNKI ****************************************************************************/
	/***********************************************************************************************/
	/**********    >    ****************************************************************************/
	/***********************************************************************************************/
condition:	NUMBER GT NUMBER		{	create_number(code, numbSub($1, $3), 1);	}
        |       identifier GT NUMBER		{       save_number_to_memory($3, 0);
                                                        load_memory_to_register(1, 0);
                                                        LOAD(1)
                                                        ZERO(0)
                                                        SUB(1)                                          }
        |       NUMBER GT identifier         	{       load_memory_to_register(1, 0);
                                                        create_number(code, $1, 1);
                                                        SUB(1)                                          }
        |       identifier GT identifier     	{       load_memory_to_register(1,0);
                                                        LOAD(1)
                                                        load_memory_to_register(2,0);
                                                        SUB(1)                                          }
	/***********************************************************************************************/
	/*********    <     ****************************************************************************/
	/***********************************************************************************************/
	/* robimy X LT Y to r1 <- Y-X */
	|	NUMBER LT NUMBER		{	create_number(code, numbSub($3, $1), 1);	}
	|	identifier LT NUMBER		{	load_memory_to_register(1,0);
							create_number(code, $3, 1);
							SUB(1)						}
	|	NUMBER LT identifier		{	save_number_to_memory($1, 0);
							load_memory_to_register(1, 0);
							LOAD(1)
							ZERO(0)
							SUB(1)						}
	|	identifier LT identifier	{	load_memory_to_register(2,0);
							LOAD(1)
							load_memory_to_register(1,0);
							SUB(1)						}
	/***********************************************************************************************/
	/*********    =    *****************************************************************************/
	/***********************************************************************************************/
	/* robimy X LT Y to X-Y = 0 = Y-X */
	|	NUMBER EQ NUMBER		{	PUSH_ETYK(ety+1) PUSH_ETYK(ety+2) PUSH_ETYK(ety+1)
							PUSH_ETYK(ety+2) PUSH_ETYK(ety) PUSH_ETYK(ety+1)
							PUSH_ETYK(ety) ety+=3;
							create_number(code, numbSub($1,$3), 1);
							JZERO(1, etykiety.pop())
							create_number(code, 0, 1);
							JUMP(etykiety.pop())
							POP_AND_WRITE_ETYK
							create_number(code, numbSub($3,$1), 1);
							JZERO(1, etykiety.pop())
							create_number(code, 0, 1);
							JUMP(etykiety.pop())
							POP_AND_WRITE_ETYK
							create_number(code, 1, 1);
							POP_AND_WRITE_ETYK			}
	|	identifier EQ NUMBER		{	PUSH_ETYK(ety+1) PUSH_ETYK(ety+2) PUSH_ETYK(ety+1)
                                                        PUSH_ETYK(ety+2) PUSH_ETYK(ety) PUSH_ETYK(ety+1)
                                                        PUSH_ETYK(ety) ety+=3;
							save_number_to_memory($3, 0);	//odejmowanie
                                                        load_memory_to_register(1, 0);	//odejmowanie
                                                        LOAD(1)				//odejmowanie
                                                        ZERO(0)				//odejmowanie
                                                        SUB(1)				//odejmowanie
							JZERO(1, etykiety.pop())
                                                        create_number(code, 0, 1);
                                                        JUMP(etykiety.pop())
                                                        POP_AND_WRITE_ETYK
							load_memory_to_register(1,0);	//odejmowanie
                                                        create_number(code, $3, 1);	//odejmowanie
                                                        SUB(1)				//odejmowanie
							JZERO(1, etykiety.pop())
                                                        create_number(code, 0, 1);
                                                        JUMP(etykiety.pop())
                                                        POP_AND_WRITE_ETYK
                                                        create_number(code, 1, 1);
                                                        POP_AND_WRITE_ETYK				}
	|	NUMBER EQ identifier		{	PUSH_ETYK(ety+1) PUSH_ETYK(ety+2) PUSH_ETYK(ety+1)
                                                        PUSH_ETYK(ety+2) PUSH_ETYK(ety) PUSH_ETYK(ety+1)
                                                        PUSH_ETYK(ety) ety+=3;
							load_memory_to_register(1, 0);	//odejmowanie
                                                        create_number(code, $1, 1);	//odejmowanie
                                                        SUB(1)				//odejmowanie
							JZERO(1, etykiety.pop())
                                                        create_number(code, 0, 1);
                                                        JUMP(etykiety.pop())
                                                        POP_AND_WRITE_ETYK
							save_number_to_memory($1, 0);	//odejmowanie
                                                        load_memory_to_register(1, 0);	//odejmowanie
                                                        LOAD(1)				//odejmowanie
                                                        ZERO(0)				//odejmowanie
                                                        SUB(1)				//odejmowanie
							JZERO(1, etykiety.pop())
                                                        create_number(code, 0, 1);
                                                        JUMP(etykiety.pop())
                                                        POP_AND_WRITE_ETYK
                                                        create_number(code, 1, 1);
                                                        POP_AND_WRITE_ETYK				}
	|	identifier EQ identifier	{	PUSH_ETYK(ety+1) PUSH_ETYK(ety+2) PUSH_ETYK(ety+1)
                                                        PUSH_ETYK(ety+2) PUSH_ETYK(ety) PUSH_ETYK(ety+1)
                                                        PUSH_ETYK(ety) ety+=3;
							load_memory_to_register(1,0);	//odejmowanie
                                                        LOAD(1)				//odejmowanie
                                                        load_memory_to_register(2,0);	//odejmowanie
                                                        SUB(1)				//odejmowanie
							JZERO(1, etykiety.pop())
                                                        create_number(code, 0, 1);
                                                        JUMP(etykiety.pop())
                                                        POP_AND_WRITE_ETYK
							load_memory_to_register(2,0);	//odejmowanie
                                                        LOAD(1)				//odejmowanie
                                                        load_memory_to_register(1,0);	//odejmowanie
                                                        SUB(1)				//odejmowanie
							JZERO(1, etykiety.pop())
                                                        create_number(code, 0, 1);
                                                        JUMP(etykiety.pop())
                                                        POP_AND_WRITE_ETYK
                                                        create_number(code, 1, 1);
                                                        POP_AND_WRITE_ETYK				}
	/***********************************************************************************************/
	/*********** >= ********************************************************************************/
	/***********************************************************************************************/
	/* robimy X GOET Y wtedy
			{ tak : wyskocz
		X>Y = 	{
			{ nie : sprawdz X=Y	*/
	|	NUMBER	GOET NUMBER		{	PUSH_ETYK(ety+1) PUSH_ETYK(ety) PUSH_ETYK(ety+1)
							PUSH_ETYK(ety) ety+=2;
							create_number(code, numbSub($1, $3), 1); //odejmowanie
							JZERO(1, etykiety.pop())
							JUMP(etykiety.pop())
							POP_AND_WRITE_ETYK
							PUSH_ETYK(ety+1) PUSH_ETYK(ety+2) PUSH_ETYK(ety+1)	//rowne
                                                        PUSH_ETYK(ety+2) PUSH_ETYK(ety) PUSH_ETYK(ety+1)	//rowne
                                                        PUSH_ETYK(ety) ety+=3;					//rowne
                                                        create_number(code, numbSub($1,$3), 1);			//rowne
                                                        JZERO(1, etykiety.pop())				//rowne
                                                        create_number(code, 0, 1);				//rowne
                                                        JUMP(etykiety.pop())					//rowne
                                                        POP_AND_WRITE_ETYK					//rowne
                                                        create_number(code, numbSub($3,$1), 1); //odejmowanie	  rowne
                                                        JZERO(1, etykiety.pop())				//rowne
                                                        create_number(code, 0, 1);				//rowne
                                                        JUMP(etykiety.pop())					//rowne
                                                        POP_AND_WRITE_ETYK					//rowne
                                                        create_number(code, 1, 1);				//rowne
                                                        POP_AND_WRITE_ETYK					//rowne
							POP_AND_WRITE_ETYK				}
	|	identifier GOET NUMBER		{	PUSH_ETYK(ety+1) PUSH_ETYK(ety) PUSH_ETYK(ety+1)
                                                        PUSH_ETYK(ety) ety+=2;
							save_number_to_memory($3, 0);	//wieksze
                                                        load_memory_to_register(1, 0);	//wieksze
                                                        LOAD(1)				//wieksze
                                                        ZERO(0)				//wieksze
                                                        SUB(1)				//wieksze
							JZERO(1, etykiety.pop())
                                                        JUMP(etykiety.pop())
                                                        POP_AND_WRITE_ETYK
							PUSH_ETYK(ety+1) PUSH_ETYK(ety+2) PUSH_ETYK(ety+1)	//rowne
                                                        PUSH_ETYK(ety+2) PUSH_ETYK(ety) PUSH_ETYK(ety+1)	//rowne
                                                        PUSH_ETYK(ety) ety+=3;					//rowne
                                                        save_number_to_memory($3, 0);   //odejmowanie		  rowne
                                                        load_memory_to_register(1, 0);  //odejmowanie		  rowne
                                                        LOAD(1)                         //odejmowanie		  rowne
                                                        ZERO(0)                         //odejmowanie		  rowne
                                                        SUB(1)                          //odejmowanie		  rowne
                                                        JZERO(1, etykiety.pop())				//rowne
                                                        create_number(code, 0, 1);				//rowne
                                                        JUMP(etykiety.pop())					//rowne
                                                        POP_AND_WRITE_ETYK					//rowne
                                                        load_memory_to_register(1,0);   //odejmowanie		  rowne
                                                        create_number(code, $3, 1);     //odejmowanie		  rowne
                                                        SUB(1)                          //odejmowanie		  rowne
                                                        JZERO(1, etykiety.pop())				//rowne
                                                        create_number(code, 0, 1);				//rowne
                                                        JUMP(etykiety.pop())					//rowne
                                                        POP_AND_WRITE_ETYK					//rowne
                                                        create_number(code, 1, 1);				//rowne
                                                        POP_AND_WRITE_ETYK					//rowne
							POP_AND_WRITE_ETYK				}
	|	NUMBER GOET identifier		{	PUSH_ETYK(ety+1) PUSH_ETYK(ety) PUSH_ETYK(ety+1)
                                                        PUSH_ETYK(ety) ety+=2;
							load_memory_to_register(1, 0);	//wieksze
                                                        create_number(code, $1, 1);	//wieksze
                                                        SUB(1) 				//wieksze
							JZERO(1, etykiety.pop())
                                                        JUMP(etykiety.pop())
                                                        POP_AND_WRITE_ETYK
							PUSH_ETYK(ety+1) PUSH_ETYK(ety+2) PUSH_ETYK(ety+1)	//rowne
                                                        PUSH_ETYK(ety+2) PUSH_ETYK(ety) PUSH_ETYK(ety+1)	//rowne
                                                        PUSH_ETYK(ety) ety+=3;					//rowne
                                                        load_memory_to_register(1, 0);  //odejmowanie		  rowne
                                                        create_number(code, $1, 1);     //odejmowanie		  rowne
                                                        SUB(1)                          //odejmowanie		  rowne
                                                        JZERO(1, etykiety.pop())				//rowne
                                                        create_number(code, 0, 1);				//rowne
                                                        JUMP(etykiety.pop())					//rowne
                                                        POP_AND_WRITE_ETYK					//rowne
                                                        save_number_to_memory($1, 0);   //odejmowanie		  rowne
                                                        load_memory_to_register(1, 0);  //odejmowanie		  rowne
                                                        LOAD(1)                         //odejmowanie		  rowne
                                                        ZERO(0)                         //odejmowanie		  rowne
                                                        SUB(1)                          //odejmowanie		  rowne
                                                        JZERO(1, etykiety.pop())				//rowne
                                                        create_number(code, 0, 1);				//rowne
                                                        JUMP(etykiety.pop())					//rowne
                                                        POP_AND_WRITE_ETYK					//rowne
                                                        create_number(code, 1, 1);				//rowne
                                                        POP_AND_WRITE_ETYK					//rowne
							POP_AND_WRITE_ETYK				}
	|	identifier GOET identifier	{	PUSH_ETYK(ety+1) PUSH_ETYK(ety) PUSH_ETYK(ety+1)
                                                        PUSH_ETYK(ety) ety+=2;
							load_memory_to_register(1,0);	//wieksze
                                                        LOAD(1)				//wieksze
                                                        load_memory_to_register(2,0);	//wieksze
                                                        SUB(1)				//wieksze
							JZERO(1, etykiety.pop())
                                                        JUMP(etykiety.pop())
                                                        POP_AND_WRITE_ETYK
							PUSH_ETYK(ety+1) PUSH_ETYK(ety+2) PUSH_ETYK(ety+1)	//rowne
                                                        PUSH_ETYK(ety+2) PUSH_ETYK(ety) PUSH_ETYK(ety+1)	//rowne
                                                        PUSH_ETYK(ety) ety+=3;					//rowne
                                                        load_memory_to_register(1,0);   //odejmowanie		  rowne
                                                        LOAD(1)                         //odejmowanie		  rowne
                                                        load_memory_to_register(2,0);   //odejmowanie		  rowne
                                                        SUB(1)                          //odejmowanie		  rowne
                                                        JZERO(1, etykiety.pop())				//rowne
                                                        create_number(code, 0, 1);				//rowne
                                                        JUMP(etykiety.pop())					//rowne
                                                        POP_AND_WRITE_ETYK					//rowne
                                                        load_memory_to_register(2,0);   //odejmowanie		  rowne
                                                        LOAD(1)                         //odejmowanie		  rowne
                                                        load_memory_to_register(1,0);   //odejmowanie		  rowne
                                                        SUB(1)                          //odejmowanie		  rowne
                                                        JZERO(1, etykiety.pop())				//rowne
                                                        create_number(code, 0, 1);				//rowne
                                                        JUMP(etykiety.pop())					//rowne
                                                        POP_AND_WRITE_ETYK					//rowne
                                                        create_number(code, 1, 1);				//rowne
                                                        POP_AND_WRITE_ETYK					//rowne
							POP_AND_WRITE_ETYK				}
	/***********************************************************************************************/
        /*********** >= ********************************************************************************/
        /***********************************************************************************************/
        /* robimy X LOET Y wtedy
                        { tak : wyskocz
                X<Y =   {
                        { nie : sprawdz X=Y     */
	|	NUMBER LOET NUMBER		{	PUSH_ETYK(ety+1) PUSH_ETYK(ety) PUSH_ETYK(ety+1)
                                                        PUSH_ETYK(ety) ety+=2;
							create_number(code, numbSub($3, $1), 1); //mniejsze
							JZERO(1, etykiety.pop())
                                                        JUMP(etykiety.pop())
                                                        POP_AND_WRITE_ETYK
							PUSH_ETYK(ety+1) PUSH_ETYK(ety+2) PUSH_ETYK(ety+1)
                                                        PUSH_ETYK(ety+2) PUSH_ETYK(ety) PUSH_ETYK(ety+1)
                                                        PUSH_ETYK(ety) ety+=3;
                                                        create_number(code, numbSub($1,$3), 1);
                                                        JZERO(1, etykiety.pop())
                                                        create_number(code, 0, 1);
                                                        JUMP(etykiety.pop())
                                                        POP_AND_WRITE_ETYK
                                                        create_number(code, numbSub($3,$1), 1);
                                                        JZERO(1, etykiety.pop())
                                                        create_number(code, 0, 1);
                                                        JUMP(etykiety.pop())
                                                        POP_AND_WRITE_ETYK
                                                        create_number(code, 1, 1);
                                                        POP_AND_WRITE_ETYK
							POP_AND_WRITE_ETYK				}

								
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

void generate_greater_number_number(){

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
