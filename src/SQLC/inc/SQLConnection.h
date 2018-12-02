#pragma once
#include "SQLpch.h"
#include "SQLmacros.h"

_SQLC_START
#define DISPLAY_MAX 50          // Arbitrary limit on column width to display
#define DISPLAY_FORMAT_EXTRA 3  // Per column extra display bytes (| <data> )
#define DISPLAY_FORMAT      L"%c %*.*s "
#define DISPLAY_FORMAT_C    L"%c %-*.*s "
#define NULL_SIZE           6   // <NULL>
#define SQL_QUERY_SIZE      1000 // Max. Num characters for SQL Query passed in.

#define PIPE                L'|'

typedef struct STR_BINDING
{
	SQLSMALLINT         cDisplaySize;           /* size to display  */
	WCHAR               *wszBuffer;             /* display buffer   */
	SQLLEN              indPtr;                 /* size or null     */
	BOOL                fChar;                  /* character col?   */
	struct STR_BINDING  *sNext;                 /* linked list      */
} BINDING;

class SQLC_API SQLConnection
{
public:
	SQLConnection(SQLWCHAR* pwszConnStr);
	~SQLConnection();

	bool Connect();

	void Run();

protected:
	void HandleDiagnosticRecord(SQLHANDLE      hHandle,
								SQLSMALLINT    hType,
								RETCODE        RetCode);

	void DisplayResults(HSTMT       hStmt,
						SQLSMALLINT cCols);		

	void AllocateBindings(HSTMT         hStmt,
						  SQLSMALLINT   cCols,
						  BINDING**     ppBinding,
						  SQLSMALLINT*  pDisplay);


	void DisplayTitles(HSTMT    hStmt,
					   DWORD    cDisplaySize,
					   BINDING* pBinding);

	void SetConsole(DWORD   cDisplaySize,
					BOOL    fInvert);

private:
	SQLHENV     m_hEnv;
	SQLHDBC     m_hDbc;
	SQLHSTMT    m_hStmt;

	SQLWCHAR*   m_pwszConnStr;

	SHORT	    m_Height = 80;       // Users screen height
	WCHAR       wszInput[SQL_QUERY_SIZE];
};
_SQLC_END