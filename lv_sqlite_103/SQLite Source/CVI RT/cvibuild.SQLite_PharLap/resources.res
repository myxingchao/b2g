        ��  ��                  �      �� ��     0 	        �4   V S _ V E R S I O N _ I N F O     ���                 ?                            S t r i n g F i l e I n f o   �   0 4 0 9 0 4 b 0   &   C o m p a n y N a m e     N I     D   F i l e D e s c r i p t i o n     s q l i t e w r a p p e r   (   F i l e V e r s i o n     1 . 0   <   I n t e r n a l N a m e   s q l i t e w r a p p e r   L   L e g a l C o p y r i g h t   C o p y r i g h t   �   N I   2 0 0 9   L   O r i g i n a l F i l e n a m e   s q l i t e w r a p p e r . d l l   B   P r o d u c t N a m e     N I   s q l i t e w r a p p e r     ,   P r o d u c t V e r s i o n   1 . 0   D    V a r F i l e I n f o     $    T r a n s l a t i o n     	��  X   C V I D L L P R O T O T Y P E S   C V I D L L E X P O R T S         0 	        int sql_query(const char *database_path, const char *statement, char *result);
int sql_select(const char *database_path, const char *statement, char *result, int *rows, int *cols);
int sqlite3_close(struct sqlite3 *db);
int sqlite3_finalize(struct sqlite3_stmt *pStmt);
int sqlite3_open(const char *zFilename, struct sqlite3 **ppDb);
int sqlite3_prepare(struct sqlite3 *db, const char *zSql, int nBytes, struct sqlite3_stmt **ppStmt, const char **pzTail);
int sqlite3_step(struct sqlite3_stmt *pStmt);
  