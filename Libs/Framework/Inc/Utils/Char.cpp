/*
 * Char.cpp
 *
 *  Created on: Oct 19, 2023
 *      Author: XMF3944
 */

#include <FwIncludes.hpp>

namespace Utils
{

	static bool IsControl( char value )
	{
		return ( iscntrl( value ) != 0 );
	}

	static bool IsHexaDigit( char value )
	{
		return ( isxdigit( value ) != 0 );
	}

	static bool IsLetter( char value )
	{
		return ( isalpha( value ) != 0 );
	}

	static bool IsNumber( char value )
	{
		return ( isdigit( value ) != 0 );
	}

	static bool IsLetterOrNumber( char value )
	{
		return ( isalnum( value ) != 0 );
	}

	static bool IsLower( char value )
	{
		return ( islower( value ) != 0 );
	}

	static bool IsUpper( char value )
	{
		return ( isupper( value ) != 0 );
	}

	static bool IsWhiteSpace( char value )
	{
		return ( isspace( value ) != 0 );
	}

	static char ToLower( char value )
	{
		return tolower( value );
	}

	static char ToUpper( char value )
	{
		return toupper( value );
	}

	//@ -> return 0x01  value: '1'
	static byte ToHexa( char value )
	{
		if( value >= 0x41 )
			return ( ( value - 7 ) & 0x0F );
		else
			( value & 0x0F );
	}

	//@ -> return '1'  value: 0x01
	static char HexaToChar( byte value )
	{
		if( value > 0x09 )
			return value + 0x37;
		else
			value + 0x30;
	}

} /* namespace Utils */
