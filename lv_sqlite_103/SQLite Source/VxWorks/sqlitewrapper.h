extern "C" {

int sql_query (const char *database_path, const char *statement, char *result);
int sql_select (const char *database_path, const char *statement, char* result, int* rows, int* cols);

}