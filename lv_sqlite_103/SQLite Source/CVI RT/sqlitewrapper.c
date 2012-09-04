// sqlitewrapper.cpp : Defines the entry point for the DLL application.
//

#include "sqlite3.h"
#include "string.h"


//extern "C" 
__declspec(dllexport) int sql_query (const char *database_path, const char *statement, char * result) {

	int a,b;
	

	sqlite3 *database;
	sqlite3_stmt *sql_stmt;
	const unsigned char * temp_result;

	b=0;
	a=sqlite3_open(database_path,&database);
    if (a!=0)
		b=1;

    a=sqlite3_prepare(database,statement,-1,&sql_stmt,NULL);
	if (a!=0)
		b=1;

	a=sqlite3_step(sql_stmt);
	if (a==100) {
		temp_result=(sqlite3_column_text(sql_stmt,0));
		strcpy(result,(char *)temp_result);
	}
	else
	{
		b=1;
		result=NULL;
	}
	a=sqlite3_finalize(sql_stmt);
	if (a!=0)
		b=1;

	a=sqlite3_close(database);
	if (a!=0)
		b=1;
	return(b);
}

//extern "C" 
__declspec(dllexport) int sql_select (const char *database_path, const char *statement, char* result, int* rows, int* cols) {

	int a,b;

	sqlite3 *database;

	b=0;
	a=sqlite3_open(database_path,&database);
	if (a!=0)
		b=11;

	char** err_ret;
	char*** tmp_result;
	
	err_ret=(char**)sqlite3_malloc(sizeof(char**));
	tmp_result=(char***)sqlite3_malloc(sizeof(char***));
	
	long i;

	sqlite3_get_table(database,statement,tmp_result,rows,cols,err_ret);
	
	
	
	strcpy(result,"");
	
	if (*rows!=0) {
		for (i=0;i<(*rows * *cols)+*cols;i++)
		{
			strcat(result,tmp_result[0][i]);
			strcat(result,"|");
		};
	}

	sqlite3_free_table(*tmp_result);
	sqlite3_free(err_ret);
	

	a=sqlite3_close(database);
	if (a!=0)
		b=10;
	return(b);

}
