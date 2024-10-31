#pragma once
#ifndef _AFX
#include <windows.h>
#endif
#include <string>
#include <stdint.h>

#ifdef ODBCAT_EXPORTS
#define ODBCAT_API extern "C" __declspec(dllexport)
#else
#define ODBCAT_API extern "C" __declspec(dllimport)
#endif

class CatBase
{
public:
	virtual ~CatBase()
	{

	}
};

enum CatTransactionIsolationLevel
{
	/**
	 * Indicates that any phenomena such as dirty reads, non-repeatable reads
	 * and phantoms can occur.
	 */
	READ_UNCOMMITTED,
	/**
	 * Prevents from dirty reads, but non-repeatable reads and phantoms can
	 * occur.
	 */
	READ_COMMITTED,
	/**
	 * Prevents from dirty and non-repeatable reads, but phantoms can occur.
	 */
	REPEATABLE_READ,
	/**
	 * Prevents from any phenomena such as dirty reads, non-repeatable reads and
	 * phantoms.
	 */
	SERIALIZABLE,
	/**
	 * Indicates that transactions are not supported by a database.
	 */
	NONE
};

enum CatIndexType
{
	/**
	 * All indexes are returned.
	 */
	ALL,
	/**
	 * Only unique indexes are returned.
	 */
	UNIQUE
};

enum CatStatisticsAccuracy
{
	/**
	 * Requests that the driver unconditionally retrieves the statistics.
	 */
	ENSURE,
	/**
	 * Requests that the driver retrieves the CARDINALITY and PAGES only if they
	 * are readily available from the server.
	 */
	QUICK
};

enum CatRowIdentifierScope
{
	/**
	 * The rowid is guaranteed to be valid only while positioned on that row.
	 * A later reselect using rowid may not return a row if the row was updated
	 * or deleted by another transaction.
	 */
	CURRENT_ROW,
	/**
	 * The rowid is guaranteed to be valid for the duration of the session
	 * (across transaction boundaries).
	 */
	SESSION,
	/**
	 * The rowid is guaranteed to be valid for the duration of the current
	 * transaction.
	 */
	TRANSACTION
};

enum CatColumnNullableValue
{
	/**
	 * Column does not allow NULL values.
	 */
	NO_NULLS,
	/**
	 * Column allows NULL values.
	 */
	NULLABLE
};

enum CatRowIdentifierType
{
	/**
	 * Returns the optimal column or set of columns that, by retrieving values
	 * from the column or columns, allows any row in the specified table to be
	 * uniquely identified. A column can be either a pseudo - column
	 * specifically designed for this purpose (as in Oracle ROWID or Ingres TID)
	 * or the column or columns of any unique index for the table.
	 */
	BEST_ROWID,
	/**
	 * Returns the column or columns in the specified table, if any, that are
	 * automatically updated by the data source when any value in the row is
	 * updated by any transaction (as in SQLBase ROWID or Sybase TIMESTAMP).
	 */
	ROWVER
};

/**
 *  Specifies the type of an ODBC DSN.
 */
enum CatDSNType
{
	/**
	 * Indicates that both user and system DSNs will be returned.
	 */
	ALL_DSN,
	/**
	 * Indicates that only system DSNs will be returned.
	 */
	SYSTEM_DSN,
	/**
	 * Indicates that only user DSNs will be returned.
	 */
	USER_DSN
};

class CatDataSourceInformations
{
public:
	/**
	 * count informations
	 */
	virtual int count() = 0;

	/**
	 * The data source name.
	 *
	 * For example, dBASE Files or SQL Server.
	 */
	virtual const char* name(int idx) = 0;

	/**
	 * The description of the driver associated with the data source.
	 *
	 * For example, Microsoft Access dBASE Driver (*.dbf, *.ndx, *.mdx).
	 */
	virtual const char* description(int idx) = 0;
};

class CatDriverInformationAttributes
{
public:
	/**
	 * count Attributes
	 */
	virtual int count() = 0;

	/**
	 * The attribute's name.
	 */
	virtual const char* name(int idx) = 0;

	/**
	 * The attribute's value.
	 */
	virtual const char* value(int idx) = 0;
};

class CatDriverInformations
{
public:
	/**
	 * count informations
	 */
	virtual int count() = 0;

	/**
	 * The driver description.
	 *
	 * For example, PostgreSQL Unicode(x64) or SQL Server.
	 */
	virtual const char* description(int idx) = 0;

	/**
	 * The list of driver attributes.
	 */
	virtual CatDriverInformationAttributes* attributes(int idx) = 0;
};

enum CatColumnType
{
	CT_UNKNOWN_TYPE    =0 ,
	CT_CHAR            =1 ,
	CT_NUMERIC         =2 ,
	CT_DECIMAL         =3 ,
	CT_INTEGER         =4 ,
	CT_SMALLINT        =5 ,
	CT_FLOAT           =6 ,
	CT_REAL            =7 ,
	CT_DOUBLE          =8 ,
	CT_DATETIME        =9 ,
	CT_VARCHAR         =12,
	CT_TYPE_DATE       =91,
	CT_TYPE_TIME       =92,
	CT_TYPE_TIMESTAMP  =93,
};

class CatResultSetMetaData
{
public:
	/**
	 * Returns the number of columns in the result set.
	 *
	 * @return  Returns the number of columns in the result set.
	 */
	virtual unsigned short getColumnCount() = 0;

	/**
	 * Returns a column's data type.
	 *
	 * See SQLDataTypes for a list of data type constants.
	 *
	 * @param columnIndex  The column index starting from 1.
	 * @return             Returns the column's data type.
	 */
	virtual CatColumnType getColumnType(unsigned short columnIndex) = 0;

	/**
	 * Returns a column's length.
	 *
	 * This is usually the maximum length of a value measured in characters for
	 * strings and measured in bytes for binary data.
	 *
	 * @param columnIndex  The column index starting from 1.
	 * @return             Returns the column's length.
	 */
	virtual size_t getColumnLength(unsigned short columnIndex) = 0;

	/**
	 * Returns a column's octet length.
	 *
	 * This is usually the maximum length of a value measured in bytes.
	 *
	 * @param columnIndex  The column index starting from 1.
	 * @return             Returns the column's octet length.
	 */
	virtual size_t getColumnOctetLength(unsigned short columnIndex) = 0;

	/**
	 * Returns a column's display size.
	 *
	 * This is the maximum number of characters to display a value.
	 *
	 * @param columnIndex  The column index starting from 1.
	 * @return             Returns the column's display size.
	 */
	virtual size_t getColumnDisplaySize(unsigned short columnIndex) = 0;

	/**
	 * Returns a column's precision in case of decimal types.
	 *
	 * @param columnIndex  The column index starting from 1.
	 * @return             Returns the column's precision in case of decimal
	 *                     types.
	 */
	virtual unsigned short getPrecision(unsigned short columnIndex) = 0;

	/**
	 * Returns a column's scale in case of decimal types.
	 *
	 * @param columnIndex  The column index starting from 1.
	 * @return             Returns the column's scale in case of decimal
	 *                     types.
	 */
	virtual unsigned short getScale(unsigned short columnIndex) = 0;

	/**
	 * Checks whether a column is auto-incrementing.
	 *
	 * @param columnIndex  The column index starting from 1.
	 * @return             Returns true if the column is auto-incrementing,
	 *                     false otherwise.
	 */
	virtual bool isAutoIncrement(unsigned short columnIndex) = 0;

	/**
	 * Checks whether a column is case sensitive.
	 *
	 * @param columnIndex  The column index starting from 1.
	 * @return             Returns true if the column is case-sensitive, false
	 *                     otherwise.
	 */
	virtual bool isCaseSensitive(unsigned short columnIndex) = 0;

	/**
	 * Checks whether a column is named.
	 *
	 * If a column is named, its name can be retrieved with the getColumnName()
	 * function.
	 *
	 * @param columnIndex  The column index starting from 1.
	 * @return             Returns true if the column is named, false otherwise.
	 */
	virtual bool isNamed(unsigned short columnIndex) = 0;

	/**
	 * Checks whether a column can contain NULL values.
	 *
	 * @param columnIndex  The column index starting from 1.
	 * @return             Returns true if the column can contain NULL values,
	 *                     false otherwise.
	 */
	virtual bool isNullable(unsigned short columnIndex) = 0;

	/**
	 * Checks whether a column in a result set is read-only.
	 *
	 * @param columnIndex  The column index starting from 1.
	 * @return             Returns true if the column is read-only, false
	 *                     otherwise.
	 */
	virtual bool isReadOnly(unsigned short columnIndex) = 0;

	/**
	 * Checks whether a column can be used in WHERE-clauses with any comparison
	 * operator.
	 *
	 * @param columnIndex  The column index starting from 1.
	 * @return             Returns true if the column is searchable, false
	 *                     otherwise.
	 */
	virtual bool isSearchable(unsigned short columnIndex) = 0;

	/**
	 * Checks whether a column can contain signed numbers.
	 *
	 * @param columnIndex  The column index starting from 1.
	 * @return             Returns true if the column can contain signed
	 *                     numbers, false otherwise.
	 */
	virtual bool isSigned(unsigned short columnIndex) = 0;

	/**
	 * Returns a column's catalog name.
	 *
	 * @param columnIndex  The column index starting from 1.
	 * @return             Returns the column's catalog name.
	 */
	virtual const char* getCatalogName(unsigned short columnIndex) = 0;

	/**
	 * Returns a column's schema name.
	 *
	 * @param columnIndex  The column index starting from 1.
	 * @return             Returns the column's schema name.
	 */
	virtual const char* getSchemaName(unsigned short columnIndex) = 0;

	/**
	 * Returns a column's table name.
	 *
	 * @param columnIndex  The column index starting from 1.
	 * @return             Returns the column's table name.
	 */
	virtual const char* getTableName(unsigned short columnIndex) = 0;

	/**
	 * Returns the name of the base table that contains the column.
	 *
	 * @param columnIndex  The column index starting from 1.
	 * @return             Returns the base table name.
	 */
	virtual const char* getBaseTableName(unsigned short columnIndex) = 0;

	/**
	 * Returns the base column name for the result set column.
	 *
	 * @param columnIndex  The column index starting from 1.
	 * @return             Returns the base column name.
	 */
	virtual const char* getBaseColumnName(unsigned short columnIndex) = 0;

	/**
	 * Returns a column's label.
	 *
	 * @param columnIndex  The column index starting from 1.
	 * @return             Returns the column's label.
	 */
	virtual const char* getColumnLabel(unsigned short columnIndex) = 0;

	/**
	 * Returns a column's name.
	 *
	 * @param columnIndex  The column index starting from 1.
	 * @return             Returns the column's name.
	 */
	virtual const char* getColumnName(unsigned short columnIndex) = 0;

	/**
	 * Returns a column's type name.
	 *
	 * @param columnIndex  The column index starting from 1.
	 * @return             Returns the column's type name.
	 */
	virtual const char* getColumnTypeName(unsigned short columnIndex) = 0;
};

class CatResultSetMetaDataUnicode
{
public:
	/**
	 * Returns the number of columns in the result set.
	 *
	 * @return  Returns the number of columns in the result set.
	 */
	virtual unsigned short getColumnCount() = 0;

	/**
	 * Returns a column's data type.
	 *
	 * See SQLDataTypes for a list of data type constants.
	 *
	 * @param columnIndex  The column index starting from 1.
	 * @return             Returns the column's data type.
	 */
	virtual CatColumnType getColumnType(unsigned short columnIndex) = 0;

	/**
	 * Returns a column's length.
	 *
	 * This is usually the maximum length of a value measured in characters for
	 * strings and measured in bytes for binary data.
	 *
	 * @param columnIndex  The column index starting from 1.
	 * @return             Returns the column's length.
	 */
	virtual size_t getColumnLength(unsigned short columnIndex) = 0;

	/**
	 * Returns a column's octet length.
	 *
	 * This is usually the maximum length of a value measured in bytes.
	 *
	 * @param columnIndex  The column index starting from 1.
	 * @return             Returns the column's octet length.
	 */
	virtual size_t getColumnOctetLength(unsigned short columnIndex) = 0;

	/**
	 * Returns a column's display size.
	 *
	 * This is the maximum number of characters to display a value.
	 *
	 * @param columnIndex  The column index starting from 1.
	 * @return             Returns the column's display size.
	 */
	virtual size_t getColumnDisplaySize(unsigned short columnIndex) = 0;

	/**
	 * Returns a column's precision in case of decimal types.
	 *
	 * @param columnIndex  The column index starting from 1.
	 * @return             Returns the column's precision in case of decimal
	 *                     types.
	 */
	virtual unsigned short getPrecision(unsigned short columnIndex) = 0;

	/**
	 * Returns a column's scale in case of decimal types.
	 *
	 * @param columnIndex  The column index starting from 1.
	 * @return             Returns the column's scale in case of decimal
	 *                     types.
	 */
	virtual unsigned short getScale(unsigned short columnIndex) = 0;

	/**
	 * Checks whether a column is auto-incrementing.
	 *
	 * @param columnIndex  The column index starting from 1.
	 * @return             Returns true if the column is auto-incrementing,
	 *                     false otherwise.
	 */
	virtual bool isAutoIncrement(unsigned short columnIndex) = 0;

	/**
	 * Checks whether a column is case sensitive.
	 *
	 * @param columnIndex  The column index starting from 1.
	 * @return             Returns true if the column is case-sensitive, false
	 *                     otherwise.
	 */
	virtual bool isCaseSensitive(unsigned short columnIndex) = 0;

	/**
	 * Checks whether a column is named.
	 *
	 * If a column is named, its name can be retrieved with the getColumnName()
	 * function.
	 *
	 * @param columnIndex  The column index starting from 1.
	 * @return             Returns true if the column is named, false otherwise.
	 */
	virtual bool isNamed(unsigned short columnIndex) = 0;

	/**
	 * Checks whether a column can contain NULL values.
	 *
	 * @param columnIndex  The column index starting from 1.
	 * @return             Returns true if the column can contain NULL values,
	 *                     false otherwise.
	 */
	virtual bool isNullable(unsigned short columnIndex) = 0;

	/**
	 * Checks whether a column in a result set is read-only.
	 *
	 * @param columnIndex  The column index starting from 1.
	 * @return             Returns true if the column is read-only, false
	 *                     otherwise.
	 */
	virtual bool isReadOnly(unsigned short columnIndex) = 0;

	/**
	 * Checks whether a column can be used in WHERE-clauses with any comparison
	 * operator.
	 *
	 * @param columnIndex  The column index starting from 1.
	 * @return             Returns true if the column is searchable, false
	 *                     otherwise.
	 */
	virtual bool isSearchable(unsigned short columnIndex) = 0;

	/**
	 * Checks whether a column can contain signed numbers.
	 *
	 * @param columnIndex  The column index starting from 1.
	 * @return             Returns true if the column can contain signed
	 *                     numbers, false otherwise.
	 */
	virtual bool isSigned(unsigned short columnIndex) = 0;

	/**
	 * Returns a column's catalog name.
	 *
	 * @param columnIndex  The column index starting from 1.
	 * @return             Returns the column's catalog name.
	 */
	virtual const char16_t* getCatalogName(unsigned short columnIndex) = 0;

	/**
	 * Returns a column's schema name.
	 *
	 * @param columnIndex  The column index starting from 1.
	 * @return             Returns the column's schema name.
	 */
	virtual const char16_t* getSchemaName(unsigned short columnIndex) = 0;

	/**
	 * Returns a column's table name.
	 *
	 * @param columnIndex  The column index starting from 1.
	 * @return             Returns the column's table name.
	 */
	virtual const char16_t* getTableName(unsigned short columnIndex) = 0;

	/**
	 * Returns the name of the base table that contains the column.
	 *
	 * @param columnIndex  The column index starting from 1.
	 * @return             Returns the base table name.
	 */
	virtual const char16_t* getBaseTableName(unsigned short columnIndex) = 0;

	/**
	 * Returns the base column name for the result set column.
	 *
	 * @param columnIndex  The column index starting from 1.
	 * @return             Returns the base column name.
	 */
	virtual const char16_t* getBaseColumnName(unsigned short columnIndex) = 0;

	/**
	 * Returns a column's label.
	 *
	 * @param columnIndex  The column index starting from 1.
	 * @return             Returns the column's label.
	 */
	virtual const char16_t* getColumnLabel(unsigned short columnIndex) = 0;

	/**
	 * Returns a column's name.
	 *
	 * @param columnIndex  The column index starting from 1.
	 * @return             Returns the column's name.
	 */
	virtual const char16_t* getColumnName(unsigned short columnIndex) = 0;

	/**
	 * Returns a column's type name.
	 *
	 * @param columnIndex  The column index starting from 1.
	 * @return             Returns the column's type name.
	 */
	virtual const char16_t* getColumnTypeName(unsigned short columnIndex) = 0;
};

class CatResultSet
{
public:
	/**
	 * Advances the cursor to the next row of the ResultSet object and fetches
	 * data for all bound columns.
	 *
	 * @return  Returns true if the current row is valid, false otherwise.
	 */
	virtual bool next() = 0;

	/**
	 * Closes the cursor associated with the current Statement object and
	 * discards all pending results.
	 */
	virtual void close() = 0;

	/**
	 * Retrieves a ResultSetMetaData object that contains information about the
	 * number, types and properties of the columns in this ResultSet object.
	 *
	 * @return  Returns a ResultSetMetaData object.
	 */
	virtual CatResultSetMetaData* getMetaData() = 0;

	/**
	 * Retrieves a ResultSetMetaDataUnicode object that contains information
	 * about the number, types and properties of the columns in this ResultSet
	 * object.
	 *
	 * @return  Returns a ResultSetMetaDataUnicode object.
	 */
	virtual CatResultSetMetaDataUnicode* getMetaDataUnicode() = 0;

	/**
	 * Retrieves the value of the specified column in the current row as
	 * a boolean.
	 *
	 * @param columnIndex  The column index starting from 1.
	 * @return             Returns the column value.
	 */
	virtual bool getBoolean(unsigned short columnIndex, bool* outIsNull = NULL) = 0;

	/**
	 * Retrieves the value of the specified column in the current row as
	 * a signed byte.
	 *
	 * @param columnIndex  The column index starting from 1.
	 * @return             Returns the column value.
	 */
	virtual std::int8_t getByte(unsigned short columnIndex, bool* outIsNull = NULL) = 0;

	/**
	 * Retrieves the value of the specified column in the current row as
	 * an unsigned byte.
	 *
	 * @param columnIndex  The column index starting from 1.
	 * @return             Returns the column value.
	 */
	virtual std::uint8_t getUByte(unsigned short columnIndex, bool* outIsNull = NULL) = 0;

	/**
	 * Retrieves the value of the specified column in the current row as
	 * a signed short integer.
	 *
	 * @param columnIndex  The column index starting from 1.
	 * @return             Returns the column value.
	 */
	virtual short getShort(unsigned short columnIndex, bool* outIsNull = NULL) = 0;

	/**
	 * Retrieves the value of the specified column in the current row as
	 * an unsigned short integer.
	 *
	 * @param columnIndex  The column index starting from 1.
	 * @return             Returns the column value.
	 */
	virtual unsigned short getUShort(unsigned short columnIndex, bool* outIsNull = NULL) = 0;

	/**
	 * Retrieves the value of the specified column in the current row as
	 * a signed integer.
	 *
	 * @param columnIndex  The column index starting from 1.
	 * @return             Returns the column value.
	 */
	virtual int getInt(unsigned short columnIndex, bool* outIsNull = NULL) = 0;

	/**
	 * Retrieves the value of the specified column in the current row as
	 * an unsigned integer.
	 *
	 * @param columnIndex  The column index starting from 1.
	 * @return             Returns the column value.
	 */
	virtual unsigned int getUInt(unsigned short columnIndex, bool* outIsNull = NULL) = 0;

	/**
	 * Retrieves the value of the specified column in the current row as
	 * a signed long integer.
	 *
	 * @param columnIndex  The column index starting from 1.
	 * @return             Returns the column value.
	 */
	virtual long long getLong(unsigned short columnIndex, bool* outIsNull = NULL) = 0;

	/**
	 * Retrieves the value of the specified column in the current row as
	 * an unsigned long integer.
	 *
	 * @param columnIndex  The column index starting from 1.
	 * @return             Returns the column value.
	 */
	virtual unsigned long long getULong(unsigned short columnIndex, bool* outIsNull = NULL) = 0;

	/**
	 * Retrieves the value of the specified column in the current row as
	 * a floating point type with single precision.
	 *
	 * @param columnIndex  The column index starting from 1.
	 * @return             Returns the column value.
	 */
	virtual float getFloat(unsigned short columnIndex, bool* outIsNull = NULL) = 0;

	/**
	 * Retrieves the value of the specified column in the current row as
	 * a floating point type with double precision.
	 *
	 * @param columnIndex  The column index starting from 1.
	 * @return             Returns the column value.
	 */
	virtual double getDouble(unsigned short columnIndex, bool* outIsNull = NULL) = 0;

	/**
	 * Retrieves the value of the specified column in the current row as
	 * a date object.
	 *
	 * @param columnIndex  The column index starting from 1.
	 * @return             Returns the column value.
	 */
	virtual bool getDate(unsigned short columnIndex, int* year, int* month, int* day, bool* outIsNull = NULL) = 0;

	/**
	 * Retrieves the value of the specified column in the current row as
	 * a time object.
	 *
	 * @param columnIndex  The column index starting from 1.
	 * @return             Returns the column value.
	 */
	virtual bool getTime(unsigned short columnIndex, int* hour, int* minute, int* second, bool* outIsNull = NULL) = 0;

	/**
	 * Retrieves the value of the specified column in the current row as
	 * a timestamp object.
	 *
	 * @param columnIndex  The column index starting from 1.
	 * @return             Returns the column value.
	 */
	virtual bool getTimestamp(unsigned short columnIndex,
		int* year, int* month, int* day,
		int* hour, int* minute, int* second, int* milliseconds, 
		bool* outIsNull = NULL) = 0;


	/**
	 * Retrieves the length of the binary data stored in the specified column of
	 * the current row.
	 *
	 * If the binary data is NULL, the constant NULL_DATA is returned. If the
	 * database cannot determine the length, the constant UNKNOWN_LENGTH is
	 * returned.
	 *
	 * @param columnIndex  The column index starting from 1.
	 * @return             Returns the length of binary data, NULL_DATA or
	 *                     UNKNOWN_LENGTH.
	 */
	virtual size_t getBinaryLength(unsigned short columnIndex, bool* outIsNull = NULL) = 0;

	/**
	 * Retrieves the binary data stored in the specified column of the current
	 * row.
	 *
	 * The total length of the binary data can be found by calling
	 * the getBinaryLength() function.
	 *
	 * @param columnIndex  The column index starting from 1.
	 * @param data         The pointer to a buffer where the read data will be
	 *                     stored.
	 * @param size  The maximum number of bytes to be read.
	 */
	virtual void getBinaryData(unsigned short columnIndex, void* outData, size_t size) = 0;

	/**
	 * Retrieves the lengh of the string stored in the specified column of
	 * the current row.
	 *
	 * If the string is NULL, the constant NULL_DATA is returned. If the
	 * database cannot determine the length, the constant UNKNOWN_LENGTH is
	 * returned.
	 *
	 * @param columnIndex  The column index starting from 1.
	 * @return             The length of a string in characters, NULL_DATA or
	 *                     UNKNOWN_LENGTH.
	 */
	virtual size_t getStringLength(unsigned short columnIndex, bool* outIsNull = NULL) = 0;

	/**
	 * Retrieves the string data stored in the specified column of the current
	 * row.
	 *
	 * The total length of the string can be found by calling the
	 * getStringLength() function.
	 *
	 * @param columnIndex  The column index starting from 1.
	 * @param[out] data  The pointer to a buffer where the read data will be
	 *                   stored.
	 * @param size  The maximum number of bytes to be read.
	 */
	virtual void getStringData(unsigned short columnIndex, void* outData, size_t size) = 0;

	/**
	 * Retrieves the length of the string with 16-bit characters stored in the
	 * specified column of the current row.
	 *
	 * If the string is NULL, the constant NULL_DATA is returned. If the
	 * database cannot determine the length, the constant UNKNOWN_LENGTH is
	 * returned.
	 *
	 * @param columnIndex  The column index starting from 1.
	 * @return             The length of a string in characters, NULL_DATA or
	 *                     UNKNOWN_LENGTH.
	 */
	virtual size_t getNStringLength(unsigned short columnIndex, bool* outIsNull = NULL) = 0;

	/**
	 * Retrieves the 16-bit character string data stored in the specified column
	 * of the current row.
	 *
	 * The total length of the string can be found by calling the
	 * getNStringLength() function.
	 *
	 * @param columnIndex  The column index starting from 1.
	 * @param data         The pointer to a buffer where read data will be
						   stored.
	 * @param size         The maximum number of 16-bit characters to be read.
	 */
	virtual void getNStringData(unsigned short columnIndex, void* outData, size_t size) = 0;
};

class CatStatement
{
public:
	/**
	 * Gets the maximum number of rows that any ResultSet object created by the
	 * current instance can contain.
	 *
	 * If the returned value equals 0, the driver returns all rows.
	 *
	 * @return  Returns the maximum number of rows in a ResultSet object.
	 */
	virtual unsigned long getMaxRows() = 0;

	/**
	 * Sets the maximum number of rows that any ResultSet object created by the
	 * current instance can contain.
	 *
	 * If the value is set to 0, the driver returns all rows.
	 *
	 * @param maxRows  The the maximum number of rows in a ResultSet object.
	 */
	virtual void setMaxRows(unsigned long maxRows) = 0;

	/**
	 * Retrieves the number of seconds that the Statement object has at its
	 * disposal to finish query execution.
	 *
	 * If the returned value equals 0, there is no limit.
	 *
	 * @return  Returns the query timeout.
	 */
	virtual unsigned long getQueryTimeout() = 0;

	/**
	 * Sets the numer of seconds that the Statement object has at its
	 * disposal to finish query execution.
	 *
	 * If the value is set to 0, there is no limit.
	 *
	 * @param seconds  The query timeout in seconds.
	 */
	virtual void setQueryTimeout(unsigned long seconds) = 0;

	/**
	 * Executes the given SQL statement.
	 *
	 * @param sql  The SQL statement.
	 */
	virtual bool execute(const char* sql) = 0;

	/**
	 * Executes the given SQL statement.
	 *
	 * @param sql  The SQL statement.
	 */
	virtual bool execute(const char16_t* sql) = 0;

	/**
	 * Executes the given SQL statement and returns a ResultSet object.
	 *
	 * @param sql  The SQL statement.
	 * @return     Returns a ResultSet object that contains the data produced
	 *             by the given SQL statement.
	 */
	virtual CatResultSet* executeQuery(const char* sql) = 0;

	/**
	 * Executes the given SQL statement and returns a ResultSet object.
	 *
	 * @param sql  The SQL statement.
	 * @return     Returns a ResultSet object that contains the data produced
	 *             by the given SQL statement.
	 */
	virtual CatResultSet* executeQuery(const char16_t* sql) = 0;
};

class CatParameterMetaData
{
public:
	/**
	 * Retrieves the number of parameters in the associated PreparedStatement
	 * object.
	 *
	 * @return  The number of parameters.
	 */
	virtual unsigned short getParameterCount() = 0;

	/**
	 * Retrieves the SQL type of the specified parameter.
	 *
	 * @param paramIndex  The parameter index starting from 1.
	 * @return            The SQL type.
	 */
	virtual short getParameterType(unsigned short paramIndex) = 0;

	/**
	 * Retrieves the size of the column or expression measured in characters.
	 *
	 * @param paramIndex  The parameter index starting from 1.
	 * @return            The size in characters.
	 */
	virtual size_t getParameterSize(unsigned short paramIndex) = 0;

	/**
	 * Retrieves the precision of the type assigned to the parameter.
	 *
	 * For numeric data, the returned value denotes the maximum number of digits
	 * in a number. For character data, this is the length of a character
	 * sequence. For date, time and timestamp types, this is the length of their
	 * string representation.
	 *
	 * @param paramIndex  The parameter index starting from 1.
	 * @return            The precision value.
	 */
	virtual unsigned short getPrecision(unsigned short paramIndex) = 0;

	/**
	 * Retrieves the scale of numeric data, which is the maximum number of
	 * decimal digits.
	 *
	 * The function returns 0 for non-numeric data.
	 *
	 * @param paramIndex  The parameter index starting from 1.
	 * @return            The scale value.
	 */
	virtual unsigned short getScale(unsigned short paramIndex) = 0;

	/**
	 * Determines whether the corresponding column accepts null values or not.
	 *
	 * @param paramIndex  The parameter index starting from 1.
	 * @return            True if the parameter accepts nulls, false otherwise.
	 */
	virtual bool isNullable(unsigned short paramIndex) = 0;
};

class CatPreparedStatement
{
public:
	/**
	 * Gets the maximum number of rows that any ResultSet object created by the
	 * current instance can contain.
	 *
	 * If the returned value equals 0, the driver returns all rows.
	 *
	 * @return  Returns the maximum number of rows in a ResultSet object.
	 */
	virtual unsigned long getMaxRows() = 0;

	/**
	 * Sets the maximum number of rows that any ResultSet object created by the
	 * current instance can contain.
	 *
	 * If the value is set to 0, the driver returns all rows.
	 *
	 * @param maxRows  The the maximum number of rows in a ResultSet object.
	 */
	virtual void setMaxRows(unsigned long maxRows) = 0;

	/**
	 * Retrieves the number of seconds that the Statement object has at its
	 * disposal to finish query execution.
	 *
	 * If the returned value equals 0, there is no limit.
	 *
	 * @return  Returns the query timeout.
	 */
	virtual unsigned long getQueryTimeout() = 0;

	/**
	 * Sets the numer of seconds that the Statement object has at its
	 * disposal to finish query execution.
	 *
	 * If the value is set to 0, there is no limit.
	 *
	 * @param seconds  The query timeout in seconds.
	 */
	virtual void setQueryTimeout(unsigned long seconds) = 0;

	/**
	 * Retrieves the number, types and properties of the parameters.
	 *
	 * @return  Returns a ParameterMetaData object that contains information
	 *          about the number, types and properties for each parameter.
	 */
	virtual CatParameterMetaData* getParameterMetaData() = 0;

	/**
	 * Sets the specified parameter to the given boolean value.
	 *
	 * @param paramIndex  The parameter index starting from 1.
	 * @param value       The parameter value.
	 */
	virtual void setBoolean(unsigned short paramIndex, bool value) = 0;

	/**
	 * Sets the specified parameter to the given signed byte value.
	 *
	 * @param paramIndex  The parameter index starting from 1.
	 * @param value       The parameter value.
	 */
	virtual void setByte(unsigned short paramIndex, INT8 value) = 0;
	/**
	 * Sets the specified parameter to the given unsigned byte value.
	 *
	 * @param paramIndex  The parameter index starting from 1.
	 * @param value       The parameter value.
	 */
	virtual void setUByte(unsigned short paramIndex, UINT8 value) = 0;
	/**
	 * Sets the specified parameter to the given signed short integer value.
	 *
	 * @param paramIndex  The parameter index starting from 1.
	 * @param value       The parameter value.
	 */
	virtual void setShort(unsigned short paramIndex, INT16 value) = 0;
	/**
	 * Sets the specified parameter to the given unsigned short integer value.
	 *
	 * @param paramIndex  The parameter index starting from 1.
	 * @param value       The parameter value.
	 */
	virtual void setUShort(unsigned short paramIndex, UINT16 value) = 0;
	/**
	 * Sets the specified parameter to the given signed integer value.
	 *
	 * @param paramIndex  The parameter index starting from 1.
	 * @param value       The parameter value.
	 */
	virtual void setInt(unsigned short paramIndex, int value) = 0;
	/**
	 * Sets the specified parameter to the given unsigned integer value.
	 *
	 * @param paramIndex  The parameter index starting from 1.
	 * @param value       The parameter value.
	 */
	virtual void setUInt(unsigned short paramIndex, UINT value) = 0;
	/**
	 * Sets the specified parameter to the given signed long integer value.
	 *
	 * @param paramIndex  The parameter index starting from 1.
	 * @param value       The parameter value.
	 */
	virtual void setLong(unsigned short paramIndex, long long value) = 0;
	/**
	 * Sets the specified parameter to the given unsigned long integer value.
	 *
	 * @param paramIndex  The parameter index starting from 1.
	 * @param value       The parameter value.
	 */
	virtual void setULong(unsigned short paramIndex, unsigned long long value) = 0;

	///**
	// * Sets the specified parameter to the given decimal value.
	// *
	// * @param paramIndex  The parameter index starting from 1.
	// * @param value       The parameter value.
	// */
	//void setDecimal(unsigned short paramIndex, const Decimal& value) = 0;

	/**
	 * Sets the specified parameter to the given float value.
	 *
	 * @param paramIndex  The parameter index starting from 1.
	 * @param value       The parameter value.
	 */
	virtual void setFloat(unsigned short paramIndex, float value) = 0;
	/**
	 * Sets the specified parameter to the given double value.
	 *
	 * @param paramIndex  The parameter index starting from 1.
	 * @param value       The parameter value.
	 */
	virtual void setDouble(unsigned short paramIndex, double value) = 0;
	/**
	 * Sets the specified parameter to the given null-terminated character
	 * sequence (C-String).
	 *
	 * @param paramIndex  The parameter index starting from 1.
	 * @param s           The null-terminated character sequence.
	 */
	virtual void setCString(unsigned short paramIndex, const char* s) = 0;
	/**
	 * Sets the specified parameter to the given character sequence of the
	 * desired length.
	 *
	 * @param paramIndex  The parameter index starting from 1.
	 * @param s           The sequence of characters.
	 * @param len         The length of the sequence.
	 */
	virtual void setCString(unsigned short paramIndex, const char* s, size_t len) = 0;
	/**
	 * Sets the specified parameter to the given null-terminated 16-bit
	 * character sequence (C-String).
	 *
	 * @param paramIndex  The parameter index starting from 1.
	 * @param s           The null-terminated character sequence.
	 */
	virtual void setNCString(unsigned short paramIndex, const char16_t* s) = 0;
	/**
	 * Sets the specified parameter to the given 16-bit character sequence of
	 * the desired length.
	 *
	 * @param paramIndex  The parameter index starting from 1.
	 * @param s           The sequence of characters.
	 * @param len         The length of the sequence.
	 */
	virtual void setNCString(unsigned short paramIndex, const char16_t* s, size_t len) = 0;
	/**
	 * Sets the specified parameter to the given byte sequence of the desired
	 * length.
	 *
	 * @param paramIndex  The parameter index starting from 1.
	 * @param data        The sequence of bytes.
	 * @param size        The length of the sequence.
	 */
	virtual void setBytes(unsigned short paramIndex, const void* data, size_t size) = 0;

	/**
	 * Sets the specified parameter to the given Date value.
	 *
	 * @param paramIndex  The parameter index starting from 1.
	 * @param value       The parameter value.
	 */
	virtual void setDate(unsigned short paramIndex, int year, int month, int day) = 0;
	/**
	 * Sets the specified parameter to the given Time value.
	 *
	 * @param paramIndex  The parameter index starting from 1.
	 * @param value       The parameter value.
	 */
	virtual void setTime(unsigned short paramIndex, int hour, int minute, int second) = 0;
	/**
	 * Sets the specified parameter to the given Timestamp value.
	 *
	 * @param paramIndex  The parameter index starting from 1.
	 * @param value       The parameter value.
	 */
	virtual void setTimestamp(unsigned short paramIndex,
		int year, int month, int day,
		int hour, int minute, int second, int milliseconds) = 0;

	/**
	 * Clears the parameter values.
	 */
	virtual void clearParameters() = 0;

	/**
	 * Retrieves a ResultSetMetaData object that contains information about a
	 * ResultSet object returned by executeQuery method.
	 *
	 * @return  Returns a ResultSetMetaData object.
	 */
	virtual CatResultSetMetaData* getMetaData() = 0;

	/**
	 * Retrieves a ResultSetMetaDataUnicode object that contains information
	 * about a ResultSet object returned by executeQuery method.
	 *
	 * @return  Returns a ResultSetMetaDataUnicode object.
	 */
	virtual CatResultSetMetaDataUnicode* getMetaDataUnicode() = 0;

	/**
	 * Executes the SQL query of this PreparedStatement object and returns a
	 * ResultSet object.
	 *
	 * @return  Returns a ResultSet object that contains the data produced
	 *          by the given SQL statement.
	 */
	virtual CatResultSet* executeQuery() = 0;

	/**
	 * Executes the SQL query of this PreparedStatement object and returns
	 * the number of rows affected by an UPDATE, INSERT, or DELETE statement.
	 *
	 * @return  Returns the number of rows affected by an UPDATE, INSERT, or
	 *          DELETE statement.
	 */
	virtual size_t executeUpdate() = 0;

	/**
	 * Add the current set of parameters to the batch of commands.
	 */
	virtual bool addBatch() = 0;
	/**
	 * Executes the batch of commands.
	 */
	virtual bool executeBatch() = 0;
	/**
	 * Clears the batch of commands.
	 */
	virtual void clearBatch() = 0;

	/**
	 * Retrieves the number of bytes required by the batch of commands.
	 *
	 * @return  Returns the number of bytes required by the batch of commands.
	 */
	virtual size_t getBatchDataSize() = 0;
};

class CatDatabaseMetaData
{
public:
	/**
	 * Retrieves the maximum number of active connections the driver can
	 * support.
	 *
	 * @return  Returns the maximum number of active connections the driver can
	 *          support. If there is no limit or if the limit is not known,
	 *          the function returns 0.
	 */
	virtual unsigned short getMaxConnections() = 0;

	/**
	 * Retrieves the maximum length of a statement string.
	 *
	 * @return  Returns the maximum length of a statement string. If there is no
	 *          limit or if the limit is not known, the function returns 0.
	 */
	virtual unsigned long getMaxStatementLength() = 0;

	/**
	 * Checks whether the database is in read-only mode.
	 *
	 * @return  Returns true if the database is in read-only mode, false
	 *          otherwise.
	 */
	virtual bool isReadOnly() = 0;

	/**
	 * Checks whether the database supports adding columns to existing tables.
	 *
	 * @returns  Returns true if the database supports adding columns to
	 *           existing tables, false otherwise.
	 */
	virtual bool supportsAlterTableWithAddColumn() = 0;

	/**
	 * Checks whether the database supports dropping columns from existing
	 * tables.
	 *
	 * @returns  Returns true if the database supports dropping columns to
	 *           existing tables, false otherwise.
	 */
	virtual bool supportsAlterTableWithDropColumn() = 0;

	/**
	 * Retrieves the default transaction isolation level of the database.
	 *
	 * @return   Returns the default transaction isolation level.
	 */
	virtual CatTransactionIsolationLevel getDefaultTransactionIsolation() = 0;

	/**
	 * Checks whether the database supports the given transaction isolation
	 * level or not.
	 *
	 * @return   Returns true if the given transaction isolation level is
	 *           supported, otherwise false.
	 */
	virtual bool supportsTransactionIsolation(CatTransactionIsolationLevel level) = 0;

	/**
	 * Retrieves a list of columns in specified tables.
	 *
	 * The list of columns is returned as a ResultSet object, in which each
	 * returned row has the following columns:
	 *     1. Catalog name
	 *     2. Schema name
	 *     3. Table name
	 *     4. Column name
	 *     5. Data type
	 *     6. Type name
	 *     7. Column size
	 *     8. Buffer length
	 *     9. Decimal digits
	 *     10. Numeric radix
	 *     11. Nullability
	 *     12. Remarks
	 *     13. Default value (ODBC 3.0)
	 *     14. SQL data type (ODBC 3.0)
	 *     15. Subtype code for date, time and interval data types (ODBC 3.0)
	 *     16. Maximum length of bytes in a character or binary column type
	 *         (ODBC 3.0)
	 *     17. The ordinal position of the column in the table (1-based)
	 *         (ODBC 3.0)
	 *     18. Nullability as "NO" or "YES" string (ODBC 3.0)
	 *
	 * This function uses the ODBC function SQLColumns. Refer to its
	 * documentation for further details on the data in the ResultSet object.
	 *
	 * @param catalogName  A string indicating the catalog name.
	 * @param schemaName   A string search pattern for schema names.
	 * @param tableName    A string search pattern for table names.
	 * @param columnName   A string search pattern for column names.
	 * @return             Returns a ResultSet object containing the requested
	 *                     table description.
	 */
	virtual CatResultSet* getColumns(
		const char* catalogName,
		const char* schemaName,
		const char* tableName,
		const char* columnName) = 0;

	/**
	 * Retrieves a list of columns and associated privileges for the specified
	 * table.
	 *
	 * The list of columns is returned as a ResultSet object, in which each
	 * returned row has the following columns:
	 *     1. Catalog name
	 *     2. Schema name
	 *     3. Table name
	 *     4. Column name
	 *     5. Grantor
	 *     6. Grantee
	 *     7. Privilege
	 *     8. Grantable
	 *
	 * This function uses the ODBC function SQLColumnPrivileges. Refer to its
	 * documentation for further details on the data in the ResultSet object.
	 *
	 * @param catalogName  A string indicating the catalog name.
	 * @param schemaName   A string indicating the schema name.
	 * @param tableName    A string indicating the table name.
	 * @param columnName   A string search pattern for column names.
	 * @return             Returns a ResultSet object containing the requested
	 *                     information about privileges.
	 */
	virtual CatResultSet* getColumnPrivileges(
		const char* catalogName,
		const char* schemaName,
		const char* tableName,
		const char* columnName) = 0;

	/**
	 * Retrieves a list of primary keys in the specified table.
	 *
	 * The list of primary keys is returned as a ResultSet object, in which
	 * each returned row has the following columns:
	 *     1. Table catalog name
	 *     2. Table schema name
	 *     3. Table name
	 *     4. Primary key column name
	 *     5. Primary column sequence number in key (1-based)
	 *     6. Primary key name
	 *
	 * This function uses the ODBC function SQLPrimaryKeys. Refer to its
	 * documentation for further details on the data in the ResultSet object.
	 *
	 * @param catalogName  A string indicating the catalog name.
	 * @param schemaName   A string indicating the schema name.
	 * @param tableName    A string indicating the table name.
	 * @return             Returns a ResultSet object containing the requested
	 *                     table description.
	 */
	virtual CatResultSet* getPrimaryKeys(
		const char* catalogName,
		const char* schemaName,
		const char* tableName) = 0;

	/**
	 * Retrieves information about the unique row identifier of a table.
	 *
	 * The list of columns is returned as a ResultSet object, in which each
	 * returned row has the following columns:
	 *     1. Actual scope of the rowid
	 *     2. Column name
	 *     3. SQL data type
	 *     4. Data source-dependent data type name
	 *     5. The size of the column on the data source
	 *     6. The length in bytes of data transferred
	 *     7. The decimal digits of the column on the data source
	 *     8. Indicates whether the column is a pseudo-column
	 *
	 * This function uses the ODBC function SQLSpecialColumns. Refer to its
	 * documentation for further details on the data in the ResultSet object.
	 *
	 * @param identifierType  Type of unique row identifier to return.
	 * @param catalogName     A string indicating the catalog name.
	 * @param schemaName      A string indicating the schema name.
	 * @param tableName       A string indicating the table name.
	 * @param scope           Minimum required scope of the rowid.
	 * @param nullable        Determines whether to return special columns that
	 *                        can have a NULL value.
	 * @return                Returns a ResultSet object containing the
	 *                        unique row identifier information.
	 */
	virtual CatResultSet* getSpecialColumns(
		CatRowIdentifierType identifierType,
		const char* catalogName,
		const char* schemaName,
		const char* tableName,
		CatRowIdentifierScope scope,
		CatColumnNullableValue nullable) = 0;

	/**
	 * Retrieves the statistics about the specified table and its indexes.
	 *
	 * The list of columns is returned as a ResultSet object, in which each
	 * returned row has the following columns:
	 *     1. Catalog name of the table
	 *     2. Schema name of the table
	 *     3. Table name of the table
	 *     4. Indicates whether the index does not allow duplicate values
	 *     5. The identifier that is used to qualify the index name doing a
	 *        DROP INDEX
	 *     6. Index name
	 *     7. Type of information being returned
	 *     8. Column sequence number in index (starting with 1)
	 *     9. Column name
	 *     10. Sort sequence for the column: "A" for ascending; "D" for
	 *         descending
	 *     11. Cardinality of table or index
	 *     12. Number of pages used to store the index or table
	 *     13. If the index is a filtered index
	 *
	 * This function uses the ODBC function SQLStatistics. Refer to its
	 * documentation for further details on the data in the ResultSet object.
	 *
	 * @param catalogName  A string indicating the catalog name.
	 * @param schemaName   A string indicating the schema name.
	 * @param tableName    A string indicating the table name.
	 * @param indexType    Type of index.
	 * @param accuracy     Indicates the accuracy of the returned statistics.
	 * @return             Returns a ResultSet object containing the statistics
	 *                     about the specified table and its indexes.
	 */
	virtual CatResultSet* getStatistics(
		const char* catalogName,
		const char* schemaName,
		const char* tableName,
		CatIndexType indexType,
		CatStatisticsAccuracy accuracy) = 0;

	/**
	 * Retrieves a description of the tables that are available in the connected
	 * database.
	 *
	 * The list of tables is returned as a ResultSet object, in which each
	 * returned row has the following columns:
	 *     1. Catalog name
	 *     2. Schema name
	 *     3. Table name
	 *     4. Table type
	 *     5. Remarks
	 *
	 * This function uses the ODBC function SQLTables. Refer to its
	 * documentation for further details on the data in the ResultSet object.
	 *
	 * @param catalogName  A string indicating the catalog name.
	 * @param schemaName   A string search pattern for schema names.
	 * @param tableName    A string search pattern for table names.
	 * @param tableType    A list of table types to be searched. The list must
	 *                     be empty or must contain a list of a comma-separated
	 *                     values. These values are "TABLE", "VIEW",
	 *                     "SYSTEM TABLE", "GLOBAL TEMPORARY",
	 *                     "LOCAL TEMPORARY", "ALIAS", "SYNONYM", or a data
	 *                     source-specific type name.
	 * @return             Returns a ResultSet object containing the requested
	 *                     table description.
	 */
	virtual CatResultSet* getTables(
		const char* catalogName,
		const char* schemaName,
		const char* tableName,
		const char* tableType) = 0;

	/**
	 * Retrieves information about all data types.
	 *
	 * The information is returned as a ResultSet object, in which each returned
	 * row has the following columns:
	 *     1. Type name
	 *     2. Data type
	 *     3. Maximum column size for the data type.
	 *     4. Characters used to prefix a literal of that data type.
	 *     5. Characters used to suffix a literal of that data type.
	 *     6. A list of keywords, separated by commas, corresponding to each
	 *        parameter that the application may specify in parentheses when
	 *        using the name that is returned in field 1.
	 *     7. Nullability of the type.
	 *     8. Case-sensitiveness.
	 *     9. Searchability.
	 *     10. Unsignedness.
	 *     11. Flag indicating if the type has a predefined fixed precision and
	 *         scale.
	 *     12. Auto-incrementing flag.
	 *     13. Localized type name.
	 *     14. Minimum scale.
	 *     15. Maximum scale.
	 *     16. SQL data type code.
	 *     17. Date/time subcode.
	 *     18. The radix used by a numeric type.
	 *     19. Interval leading precision.
	 *
	 * This function uses the ODBC function SQLGetTypeInfo. Refer to its
	 * documentation for further details on the data in the ResultSet object.
	 *
	 * @return      Returns a ResultSet object containing the requested data
	 *              type information.
	 */
	virtual CatResultSet* getTypeInfo() = 0;

	/**
	 * Retrieves information about a specific data type.
	 *
	 * See the documentation of getTypeInfo() for further details.
	 *
	 * @param type  The data type to retrieve the type information of.
	 * @return      Returns a ResultSet object containing the requested data
	 *              type information.
	 */
	virtual CatResultSet* getTypeInfo(int type) = 0;

	/**
	 * Retrieves the name of the data source.
	 *
	 * @return  Returns the name of the data source.
	 */
	virtual const char* getDataSourceName() = 0;

	/**
	 * Retrieves the current database in use.
	 *
	 * @return  Returns the current database in use.
	 */
	virtual const char* getDatabaseName() = 0;

	/**
	 * Retrieves the name of the DBMS system.
	 *
	 * @return  Returns the name of the DBMS system.
	 */
	virtual const char* getDBMSName() = 0;

	/**
	 * Retrieves the version of the DBMS system.
	 *
	 * @return  Returns the version of the DBMS system.
	 */
	virtual const char* getDBMSVersion() = 0;

	/**
	 * Retrieves the name of the ODBC driver.
	 *
	 * @return  Returns the name of the ODBC driver.
	 */
	virtual const char* getDriverName() = 0;

	/**
	 * Retrieves the version of the ODBC driver.
	 *
	 * @return  Returns the version of the ODBC driver.
	 */
	virtual const char* getDriverVersion() = 0;

	/**
	 * Retrieves the server name.
	 *
	 * @return  Returns the server name.
	 */
	virtual const char* getServerName() = 0;

	/**
	 * Retrieves the name used in the database.
	 *
	 * @return  Returns the name used in the database.
	 */
	virtual const char* getUserName() = 0;
};

class CatDatabaseMetaDataUnicode
{
public:
	/**
	 * Retrieves the maximum number of active connections the driver can
	 * support.
	 *
	 * @return  Returns the maximum number of active connections the driver can
	 *          support. If there is no limit or if the limit is not known,
	 *          the function returns 0.
	 */
	virtual unsigned short getMaxConnections() = 0;

	/**
	 * Retrieves the maximum length of a statement string.
	 *
	 * @return  Returns the maximum length of a statement string. If there is no
	 *          limit or if the limit is not known, the function returns 0.
	 */
	virtual unsigned long getMaxStatementLength() = 0;

	/**
	 * Checks whether the database is in read-only mode.
	 *
	 * @return  Returns true if the database is in read-only mode, false
	 *          otherwise.
	 */
	virtual bool isReadOnly() = 0;

	/**
	 * Checks whether the database supports adding columns to existing tables.
	 *
	 * @returns  Returns true if the database supports adding columns to
	 *           existing tables, false otherwise.
	 */
	virtual bool supportsAlterTableWithAddColumn() = 0;

	/**
	 * Checks whether the database supports dropping columns from existing
	 * tables.
	 *
	 * @returns  Returns true if the database supports dropping columns to
	 *           existing tables, false otherwise.
	 */
	virtual bool supportsAlterTableWithDropColumn() = 0;

	/**
	 * Retrieves the default transaction isolation level of the database.
	 *
	 * @return   Returns the default transaction isolation level.
	 */
	virtual CatTransactionIsolationLevel getDefaultTransactionIsolation() = 0;

	/**
	 * Checks whether the database supports the given transaction isolation
	 * level or not.
	 *
	 * @return   Returns true if the given transaction isolation level is
	 *           supported, otherwise false.
	 */
	virtual bool supportsTransactionIsolation(CatTransactionIsolationLevel level) = 0;

	/**
	 * Retrieves a list of columns in specified tables.
	 *
	 * The list of columns is returned as a ResultSet object, in which each
	 * returned row has the following columns:
	 *     1. Catalog name
	 *     2. Schema name
	 *     3. Table name
	 *     4. Column name
	 *     5. Data type
	 *     6. Type name
	 *     7. Column size
	 *     8. Buffer length
	 *     9. Decimal digits
	 *     10. Numeric radix
	 *     11. Nullability
	 *     12. Remarks
	 *     13. Default value (ODBC 3.0)
	 *     14. SQL data type (ODBC 3.0)
	 *     15. Subtype code for date, time and interval data types (ODBC 3.0)
	 *     16. Maximum length of bytes in a character or binary column type
	 *         (ODBC 3.0)
	 *     17. The ordinal position of the column in the table (1-based)
	 *         (ODBC 3.0)
	 *     18. Nullability as "NO" or "YES" string (ODBC 3.0)
	 *
	 * This function uses the ODBC function SQLColumns. Refer to its
	 * documentation for further details on the data in the ResultSet object.
	 *
	 * @param catalogName  A string indicating the catalog name.
	 * @param schemaName   A string search pattern for schema names.
	 * @param tableName    A string search pattern for table names.
	 * @param columnName   A string search pattern for column names.
	 * @return             Returns a ResultSet object containing the requested
	 *                     table description.
	 */
	virtual CatResultSet* getColumns(
		const char16_t* catalogName,
		const char16_t* schemaName,
		const char16_t* tableName,
		const char16_t* columnName) = 0;

	/**
	 * Retrieves a list of columns and associated privileges for the specified
	 * table.
	 *
	 * The list of columns is returned as a ResultSet object, in which each
	 * returned row has the following columns:
	 *     1. Catalog name
	 *     2. Schema name
	 *     3. Table name
	 *     4. Column name
	 *     5. Grantor
	 *     6. Grantee
	 *     7. Privilege
	 *     8. Grantable
	 *
	 * This function uses the ODBC function SQLColumnPrivileges. Refer to its
	 * documentation for further details on the data in the ResultSet object.
	 *
	 * @param catalogName  A string indicating the catalog name.
	 * @param schemaName   A string indicating the schema name.
	 * @param tableName    A string indicating the table name.
	 * @param columnName   A string search pattern for column names.
	 * @return             Returns a ResultSet object containing the requested
	 *                     information about privileges.
	 */
	virtual CatResultSet* getColumnPrivileges(
		const char16_t* catalogName,
		const char16_t* schemaName,
		const char16_t* tableName,
		const char16_t* columnName) = 0;

	/**
	 * Retrieves a list of primary keys in the specified table.
	 *
	 * The list of primary keys is returned as a ResultSet object, in which
	 * each returned row has the following columns:
	 *     1. Table catalog name
	 *     2. Table schema name
	 *     3. Table name
	 *     4. Primary key column name
	 *     5. Primary column sequence number in key (1-based)
	 *     6. Primary key name
	 *
	 * This functions uses the ODBC function SQLPrimaryKeys. Refer to its
	 * documentation for further details on the data in the ResultSet object.
	 *
	 * @param catalogName  A string indicating the catalog name.
	 * @param schemaName   A string indicating the schema name.
	 * @param tableName    A string indicating the table name.
	 * @return             Returns a ResultSet object containing the requested
	 *                     table description.
	 */
	virtual CatResultSet* getPrimaryKeys(
		const char16_t* catalogName,
		const char16_t* schemaName,
		const char16_t* tableName) = 0;

	/**
	 * Retrieves information about the unique row identifier of a table.
	 *
	 * The list of columns is returned as a ResultSet object, in which each
	 * returned row has the following columns:
	 *     1. Actual scope of the rowid
	 *     2. Column name
	 *     3. SQL data type
	 *     4. Data source-dependent data type name
	 *     5. The size of the column on the data source
	 *     6. The length in bytes of data transferred
	 *     7. The decimal digits of the column on the data source
	 *     8. Indicates whether the column is a pseudo-column
	 *
	 * This function uses the ODBC function SQLSpecialColumns. Refer to its
	 * documentation for further details on the data in the ResultSet object.
	 *
	 * @param identifierType  Type of unique row identifier to return.
	 * @param catalogName     A string indicating the catalog name.
	 * @param schemaName      A string indicating the schema name.
	 * @param tableName       A string indicating the table name.
	 * @param scope           Minimum required scope of the rowid.
	 * @param nullable        Determines whether to return special columns that
	 *                        can have a NULL value.
	 * @return                Returns a ResultSet object containing the
	 *                        unique row identifier information.
	 */
	virtual CatResultSet* getSpecialColumns(
		CatRowIdentifierType identifierType,
		const char16_t* catalogName,
		const char16_t* schemaName,
		const char16_t* tableName,
		CatRowIdentifierScope scope,
		CatColumnNullableValue nullable) = 0;

	/**
	  * Retrieves the statistics about the specified table and its indexes.
	  *
	  * The list of columns is returned as a ResultSet object, in which each
	  * returned row has the following columns:
	  *     1. Catalog name of the table
	  *     2. Schema name of the table
	  *     3. Table name of the table
	  *     4. Indicates whether the index does not allow duplicate values
	  *     5. The identifier that is used to qualify the index name doing a
	  *        DROP INDEX
	  *     6. Index name
	  *     7. Type of information being returned
	  *     8. Column sequence number in index (starting with 1)
	  *     9. Column name
	  *     10. Sort sequence for the column: "A" for ascending; "D" for
	  *         descending
	  *     11. Cardinality of table or index
	  *     12. Number of pages used to store the index or table
	  *     13. If the index is a filtered index
	  *
	  * This function uses the ODBC function SQLStatistics. Refer to its
	  * documentation for further details on the data in the ResultSet object.
	  *
	  * @param catalogName  A string indicating the catalog name.
	  * @param schemaName   A string indicating the schema name.
	  * @param tableName    A string indicating the table name.
	  * @param indexType    Type of index.
	  * @param accuracy     Indicates the type of the returned statistics.
	  * @return             Returns a ResultSet object containing the statistics
	  *                     about the specified table and its indexes.
	  */
	virtual CatResultSet* getStatistics(
		const char16_t* catalogName,
		const char16_t* schemaName,
		const char16_t* tableName,
		CatIndexType indexType,
		CatStatisticsAccuracy accuracy) = 0;

	/**
	 * Retrieves a description of the tables that are available in the connected
	 * database.
	 *
	 * The list of tables is returned as a ResultSet object, in which each
	 * returned row has the following columns:
	 *     1. Catalog name
	 *     2. Schema name
	 *     3. Table name
	 *     4. Table type
	 *     5. Remarks
	 *
	 * This function uses the ODBC function SQLTables. Refer to its
	 * documentation for further details on the data in the ResultSet object.
	 *
	 * @param catalogName  A string indicating the catalog name.
	 * @param schemaName   A string search pattern for schema names.
	 * @param tableName    A string search pattern for table names.
	 * @param tableType    A list of table types to be searched. The list must
	 *                     be empty or must contain a list of a comma-separated
	 *                     values. These values are "TABLE", "VIEW",
	 *                     "SYSTEM TABLE", "GLOBAL TEMPORARY",
	 *                     "LOCAL TEMPORARY", "ALIAS", "SYNONYM", or a data
	 *                     source-specific type name.
	 * @return             Returns a ResultSet object containing the requested
	 *                     table description.
	 */
	virtual CatResultSet* getTables(
		const char16_t* catalogName,
		const char16_t* schemaName,
		const char16_t* tableName,
		const char16_t* tableType) = 0;

	/**
	 * Retrieves information about all data types.
	 *
	 * The information is returned as a ResultSet object, in which each returned
	 * row has the following columns:
	 *     1. Type name
	 *     2. Data type
	 *     3. Maximum column size for the data type.
	 *     4. Characters used to prefix a literal of that data type.
	 *     5. Characters used to suffix a literal of that data type.
	 *     6. A list of keywords, separated by commas, corresponding to each
	 *        parameter that the application may specify in parentheses when
	 *        using the name that is returned in field 1.
	 *     7. Nullability of the type.
	 *     8. Case-sensitiveness.
	 *     9. Searchability.
	 *     10. Unsignedness.
	 *     11. Flag indicating if the type has a predefined fixed precision and
	 *         scale.
	 *     12. Auto-incrementing flag.
	 *     13. Localized type name.
	 *     14. Minimum scale.
	 *     15. Maximum scale.
	 *     16. SQL data type code.
	 *     17. Date/time subcode.
	 *     18. The radix used by a numeric type.
	 *     19. Interval leading precision.
	 *
	 * This function uses the ODBC function SQLGetTypeInfo. Refer to its
	 * documentation for further details on the data in the ResultSet object.
	 *
	 * @return      Returns a ResultSet object containing the requested data
	 *              type information.
	 */
	virtual CatResultSet* getTypeInfo() = 0;

	/**
	 * Retrieves information about a specific data type.
	 *
	 * See the documentation of getTypeInfo() for further details.
	 *
	 * @param type  The data type to retrieve the type information of.
	 * @return      Returns a ResultSet object containing the requested data
	 *              type information.
	 */
	virtual CatResultSet* getTypeInfo(int type) = 0;

	/**
	 * Retrieves the name of the data source.
	 *
	 * @return  Returns the name of the data source.
	 */
	virtual const char16_t* getDataSourceName() = 0;

	/**
	 * Retrieves the current database in use.
	 *
	 * @return  Returns the current database in use.
	 */
	virtual const char16_t* getDatabaseName() = 0;

	/**
	 * Retrieves the name of the DBMS system.
	 *
	 * @return  Returns the name of the DBMS system.
	 */
	virtual const char16_t* getDBMSName() = 0;

	/**
	 * Retrieves the version of the DBMS system.
	 *
	 * @return  Returns the version of the DBMS system.
	 */
	virtual const char16_t* getDBMSVersion() = 0;

	/**
	 * Retrieves the name of the ODBC driver.
	 *
	 * @return  Returns the name of the ODBC driver.
	 */
	virtual const char16_t* getDriverName() = 0;

	/**
	 * Retrieves the version of the ODBC driver.
	 *
	 * @return  Returns the version of the ODBC driver.
	 */
	virtual const char16_t* getDriverVersion() = 0;

	/**
	 * Retrieves the server name.
	 *
	 * @return  Returns the server name.
	 */
	virtual const char16_t* getServerName() = 0;

	/**
	 * Retrieves the name used in the database.
	 *
	 * @return  Returns the name used in the database.
	 */
	virtual const char16_t* getUserName() = 0;
};

class CatConnection
{
public:
	/**
	 * Attempts to establish a database connection using a data source name.
	 *
	 * The method will throw an exception if a connection could not be
	 * established.
	 *
	 * @param dsn       The data source name.
	 * @param user      The user name to use.
	 * @param password  The password to use.
	 */
	virtual bool connectByDSNName(const char* dsn, const char* user = NULL, const char* password = NULL) = 0;

	/**
	 * Attempts to establish a database connection using an ODBC driver-specific
	 * connection string.
	 *
	 * Refer to the documentation of your ODBC driver for details on the
	 * connection string.
	 *
	 * The method will throw an exception if a connection could not be
	 * established.
	 *
	 * @param connString  The driver-specific connection string.
	 */
	virtual bool connect(const char* connString) = 0;

	/**
	 * Disconnects from the database.
	 */
	virtual void disconnect() = 0;

	/**
	 * Checks whether this Connection object is currently connected to the
	 * database.
	 *
	 * This method checks only whether a successful connection has been made in
	 * the past and has not been actively disconnected by the client. It will
	 * not check if the connection is still alive. Use function isValid() to
	 * check if a connection is still alive.
	 *
	 * @return  Returns true if the Connection object is connected to the
	 *          database, false otherwise.
	 */
	virtual bool connected() = 0;

	/**
	 * Checks whether the connection is still alive or not.
	 *
	 * @return  Returns true if the connection is alive, false otherwise.
	 */
	virtual bool isValid() = 0;

	/**
	 * Gets the number of seconds that a driver can wait for any connection
	 * request to complete.
	 *
	 * If the returned value equals 0, the driver will wait infinitely. The
	 * default value is driver-specific.
	 *
	 * @return  Returns the connection timeout.
	 */
	virtual unsigned long getConnectionTimeout() = 0;

	/**
	 * Sets the numer of seconds that a driver will wait for a connection
	 * request to complete.
	 *
	 * If the value is set to 0, the driver can wait infinitely.
	 *
	 * @param seconds  The connection timeout.
	 */
	virtual void setConnectionTimeout(unsigned long seconds) = 0;

	/**
	 * Gets the number of seconds that a driver can wait for a login attempt to
	 * complete.
	 *
	 * If the returned value equals 0, the driver will wait infinitely. The
	 * default value is driver-specific.
	 *
	 * @return  Returns the login timeout.
	 */
	virtual unsigned long getLoginTimeout() = 0;

	/**
	 * Sets the numer of seconds that a driver will wait for a login attempt to
	 * complete.
	 *
	 * If the value is set to 0, the driver can wait infinitely.
	 *
	 * @param seconds  The login timeout.
	 */
	virtual void setLoginTimeout(unsigned long seconds) = 0;

	/**
	 * Sets a connection attribute of type integer.
	 *
	 * This method is intended for setting driver-specific connection
	 * attributes. Generic connection attributes like the auto-commit attribute
	 * should be set via the corresponding member function. Refer to your ODBC
	 * driver documentation for a list of available attributes.
	 *
	 * Some connection attributes can only be set before a connection has been
	 * made, others can only be set after a connection has been made. Refer
	 * to the documentation of the attribute to find out if it must been set
	 * before or after making a connection.
	 *
	 * @param attr   The attribute to set.
	 * @param value  The value to set.
	 */
	virtual void setAttribute(int attr, int value) = 0;

	/**
	 * Sets a connection attribute of type unsigned integer.
	 *
	 * This method is intended for setting driver-specific connection
	 * attributes. Generic connection attributes like the auto-commit attribute
	 * should be set via the corresponding member function. Refer to your ODBC
	 * driver documentation for a list of available attributes.
	 *
	 * Some connection attributes can only be set before a connection has been
	 * made, others can only be set after a connection has been made. Refer
	 * to the documentation of the attribute to find out if it must been set
	 * before or after making a connection.
	 *
	 * @param attr   The attribute to set.
	 * @param value  The value to set.
	 */
	virtual void setAttribute(int attr, unsigned int value) = 0;

	/**
	 * Sets a connection attribute of type string.
	 *
	 * This method is intended for setting driver-specific connection
	 * attributes. Generic connection attributes like the auto-commit attribute
	 * should be set via the corresponding member function. Refer to your ODBC
	 * driver documentation for a list of available attributes.
	 *
	 * Some connection attributes can only be set before a connection has been
	 * made, others can only be set after a connection has been made. Refer
	 * to the documentation of the attribute to find out if it must been set
	 * before or after making a connection.
	 *
	 * @param attr   The attribute to set.
	 * @param value  The value to set.
	 */
	virtual void setAttribute(int attr, const char* value) = 0;

	/**
	 * Sets a connection attribute of type string.
	 *
	 * This method is intended for setting driver-specific connection
	 * attributes. Generic connection attributes like the auto-commit attribute
	 * should be set via the corresponding member function. Refer to your ODBC
	 * driver documentation for a list of available attributes.
	 *
	 * Some connection attributes can only be set before a connection has been
	 * made, others can only be set after a connection has been made. Refer
	 * to the documentation of the attribute to find out if it must been set
	 * before or after making a connection.
	 *
	 * @param attr    The attribute to set.
	 * @param value   The value to set.
	 * @param length  The length of the string.
	 */
	virtual void setAttribute(int attr, const char* value, size_t length) = 0;

	/**
	 * Sets a connection attribute of type binary.
	 *
	 * This method is intended for setting driver-specific connection
	 * attributes. Generic connection attributes like the auto-commit attribute
	 * should be set via the corresponding member function. Refer to your ODBC
	 * driver documentation for a list of available attributes.
	 *
	 * Some connection attributes can only be set before a connection has been
	 * made, others can only be set after a connection has been made. Refer
	 * to the documentation of the attribute to find out if it must been set
	 * before or after making a connection.
	 *
	 * @param attr   The attribute to set.
	 * @param value  The value to set.
	 * @param size   The size of the binary data in bytes.
	 */
	virtual void setAttribute(int attr, const void* value, size_t size) = 0;

	/**
	 * Checks whether auto-commit mode is enabled.
	 *
	 * @return  Returns true if auto-commit is enabled, false otherwise.
	 */
	virtual bool getAutoCommit() = 0;

	/**
	 * Enables or disables auto-commit mode for this connection.
	 *
	 * @param autoCommit  Set to true to enable auto-commit, set to false to
	 *                    disable auto-commit.
	 */
	virtual void setAutoCommit(bool autoCommit) = 0;

	/**
	 * Commits all changes made since the previous commit or rollback.
	 */
	virtual void commit() = 0;

	/**
	 * Undoes all changes made since the previous commit or rollback.
	 */
	virtual void rollback() = 0;

	/**
	 * Checks whether the Connection object allows statements performing any
	 * updates on data.
	 *
	 * @return  Returns true if the Connection is in read only mode.
	 */
	virtual bool isReadOnly() = 0;

	/**
	 * Sets the Connection object either in read-only or read-write mode.
	 *
	 * By default, the read-only mode is set to false.
	 *
	 * @param readOnly  The value indicating read-only mode.
	 */
	virtual void setReadOnly(bool readOnly) = 0;

	/**
	 * Retrieves the transaction isolation level of this Connection object.
	 *
	 * @return   Returns the transaction isolation level.
	 */
	virtual CatTransactionIsolationLevel getTransactionIsolation() = 0;

	/**
	 * Attempts to set the isolation level on which the transactions should be
	 * executed.
	 *
	 * This method can be called only if there are no open transactions on the
	 * current Connection object.
	 *
	 * @param level   The transaction isolation level.
	 */
	virtual void setTransactionIsolation(CatTransactionIsolationLevel level) = 0;

	/**
	 * Creates a new Statement object.
	 *
	 * @return  Returns a reference to the newly created Statement object.
	 */
	virtual CatStatement* createStatement() = 0;

	/**
	 * Creates a new PreparedStatement object.
	 *
	 * @param sql  The SQL statement to prepare. Use '?' for placeholders.
	 * @return     Returns a reference to the newly created PreparedStatement
	 *             object.
	 */
	virtual CatPreparedStatement* prepareStatement(const char* sql) = 0;

	/**
	 * Creates a new PreparedStatement object.
	 *
	 * @param sql  The SQL statement to prepare. Use '?' for placeholders.
	 * @return     Returns a reference to the newly created PreparedStatement
	 *             object.
	 */
	virtual CatPreparedStatement* prepareStatement(const char16_t* sql) = 0;

	/**
	 * Retrieves metadata information of the database.
	 *
	 * @return  Returns a reference to the DatabaseMetaData object.
	 */
	virtual CatDatabaseMetaData* getDatabaseMetaData() = 0;

	/**
	 * Retrieves metadata information of the database.
	 *
	 * @return  Returns a reference to the DatabaseMetaDataUnicode object.
	 */
	virtual CatDatabaseMetaDataUnicode* getDatabaseMetaDataUnicode() = 0;
};

class CatEnvironment
{
public:
	enum ConfigDsnAction
	{
		AddDSN,
		ConfigDSN,
		RemoveDSN,

		AddSysDSN,
		ConfigSysDSN,
		RemoveSysDSN,
	};
	/**
	 * Creates a new Connection object.
	 *
	 * @return  Returns a reference to the newly created Connection object.
	 */
	virtual CatConnection* createConnection() = 0;

	/**
	 * Create a DSN
	 * @param driver driver name. example:Microsoft Access Driver (*.mdb, *.accdb)
	 * @param attributesString split with "\0" and end with two "\0". example:
			L"DSN=MyDSN\0"
			L"DRIVER=Microsoft Access Driver (*.mdb, *.accdb)\0"
			L"UID=\0"
			L"PWD=\0"
			L"UserCommitSync=Yes\0"
			L"Threads=3\0"
			L"SafeTransactions=0\0"
			L"PageTimeout=5\0"
			L"MaxScanRows=8\0"
			L"MaxBufferSize=2048\0"
			L"FIL=MS Access\0"
			L"DriverId=25\0"
			L"DefaultDir=E:\\\0"
			L"DBQ=E:\\Database1.mdb\0"
			L"\0"
	 */
	virtual bool configDSN(const wchar_t* attributesString,
		const wchar_t* driver = NULL, ConfigDsnAction action = AddDSN) = 0;

	/**
	 * Create a DSN
	 * @param driver driver name. example:Microsoft Access Driver (*.mdb, *.accdb)
	 * @param dsnFile dsn file create by C:\Windows\System32\odbcad32.exe (64bit) C:\Windows\SysWOW64\odbcad32.exe(32bit)
	 * @param DSNName set DSN attribute
	 */
	virtual bool configDSNByFile(const wchar_t* dsnFile, const wchar_t* DSNName,
		const wchar_t* driver = NULL, ConfigDsnAction action = AddDSN) = 0;

	/**
	 * Retrieves information about available data sources.
	 *
	 * @return  Returns a full list of DataSourceInformation objects.
	 */
	virtual CatDataSourceInformations* getDataSources() = 0;

	/**
	 * Retrieves information about available data sources of the specified type.
	 *
	 * @param dsnType  Specifies the type of the returned ODBC DSNs.
	 * @return         Returns a list of DataSourceInformation objects.
	 */
	virtual CatDataSourceInformations* getDataSources(CatDSNType dsnType) = 0;

	/**
	 * Retrieves information about available drivers.
	 *
	 * @return  Returns a list of DriverInformation objects.
	 */
	virtual CatDriverInformations* getDrivers() = 0;

	/**
	* Gets a value indicating whether the given driver is installed or not.
	*
	* @param name  The driver name.
	* @return      Returns true if the driver is installed, otherwise false.
	*/
	virtual bool isDriverInstalled(const char* driver) = 0;
};

ODBCAT_API CatEnvironment* CreateEnvironment();
ODBCAT_API void CatFree(CatBase** pp);

ODBCAT_API bool HasError();
ODBCAT_API const char* GetError();

class odbcat
{
#define DEF_PROC(name) \
	decltype(::name)* name

#define SET_PROC(hDll, name) \
	this->name = (decltype(::name)*)::GetProcAddress(hDll, #name)

public:
	DEF_PROC(CreateEnvironment);
	DEF_PROC(CatFree);
	DEF_PROC(HasError);
	DEF_PROC(GetError);

	odbcat()
	{
		hDll = LoadLibraryFromCurrentDir("odbcat.dll");
		if (!hDll)
			return;

		SET_PROC(hDll, CreateEnvironment);
		SET_PROC(hDll, CatFree);
		SET_PROC(hDll, HasError);
		SET_PROC(hDll, GetError);
	}

	template<class T>
	void CatFreeT(T** pp)
	{
		CatBase* ppb = dynamic_cast<CatBase*>(*pp);
		if (ppb)
		{
			CatFree(&ppb);
		}
	}

public:
	inline static odbcat& Ins()
	{
		static odbcat s_ins;
		return s_ins;
	}

	static HMODULE LoadLibraryFromCurrentDir(const char* dllName)
	{
		char selfPath[MAX_PATH];
		MEMORY_BASIC_INFORMATION mbi;
		HMODULE hModule = ((::VirtualQuery(
			LoadLibraryFromCurrentDir, &mbi, sizeof(mbi)) != 0) ? (HMODULE)mbi.AllocationBase : NULL);
		::GetModuleFileNameA(hModule, selfPath, MAX_PATH);
		std::string moduleDir(selfPath);
		size_t idx = moduleDir.find_last_of('\\');
		moduleDir = moduleDir.substr(0, idx);
		std::string modulePath = moduleDir + "\\" + dllName;
		char curDir[MAX_PATH];
		::GetCurrentDirectoryA(MAX_PATH, curDir);
		::SetCurrentDirectoryA(moduleDir.c_str());
		HMODULE hDll = LoadLibraryA(modulePath.c_str());
		::SetCurrentDirectoryA(curDir);
		if (!hDll)
		{
			DWORD err = ::GetLastError();
			char buf[10];
			sprintf_s(buf, "%u", err);
			::MessageBoxA(NULL, ("找不到" + modulePath + "模块:" + buf).c_str(),
				"找不到模块", MB_OK | MB_ICONERROR);
		}
		return hDll;
	}
	~odbcat()
	{
		if (hDll)
		{
			FreeLibrary(hDll);
			hDll = NULL;
		}
	}

private:
	HMODULE hDll;

public:
	class Scope
	{
	public:
		Scope(CatBase* pp)
			: m_pp(pp)
		{
		}
		~Scope()
		{
			if (m_pp)
				odbcat::Ins().CatFree(&m_pp);
		}

		CatBase* m_pp;
	};

#define CATSCOPE(p) odbcat::Scope _scope_ ## p (dynamic_cast<CatBase*>(p))
};

