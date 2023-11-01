/*
 * BufferTest.cpp
 *
 *  Created on: Oct 23, 2023
 *      Author: XMF3944
 */

#include "BufferTest.hpp"
#include <FwIncludes.hpp>

namespace Test
{

	static const cstr cstrValue = "Hola Mundo!";
	static const Buffer bufferValue( cstrValue, Utils::Str::GetLength( cstrValue ) );

	BufferTest::BufferTest( )
	{
	}

	BufferTest::~BufferTest( )
	{
	}

	void BufferTest::Overload( ) const
	{

		//@Comments Buffer creado de 1024
		Buffer buffer1( Defines::KbSize );
		//@Comments a  este Buffer se le pueden agregar nuevos valores hasta el tamaño del Buffer
		//@ -> return: Hola Mundo!   source: "Hola Mundo!" -> SizeBuffer: 1024
		buffer1.Add( cstrValue );
		Telium_Printf( "Buffer 1 [%s] -> Length [%d]", buffer1, buffer1.GetLength( ) );

		//@Commnets Se crea el Buffer con el tamaño justo al valor imgresado
		//@ -> return: Hola Mundo!   source: "Hola Mundo!"
		Buffer buffer2( cstrValue, Utils::Str::GetLength( cstrValue ) );
		Telium_Printf( "Buffer 2 [%s] -> Length [%d]", buffer2, buffer2.GetLength( ) );
		/*Hacer un Add  ya no es válido ya que el buffer creado es de 11 y si se intenta agrega un valor
		 * más este ya no es permitido y saldra una Exception. Se recomienda usar esta creación
		 * de Buffers solo para manipular el datos y destruir el buffer

		 buffer.Add('!');
		 */

		//@Comments Este constructor ayuda a crear el buffer apartir de otro Buffer y se le indica
		//cuantos valos va agregar a partir del indice 0
		//@ -> return: Hola  source: "Hola Mundo!"
		Buffer buffer3( bufferValue, 4 );
		uint32 length3 = buffer3.GetLength( );
		Telium_Printf( "Buffer 3 [%s] -> Length [%d]", buffer3, length3 );

		//@Comments Este constructor ayuda a crear el buffer de otro Buffer a partir del indice
		//que se le indique

		//@ -> return: Mundo!   source: "Hola Mundo!"
		Buffer buffer4( 4, bufferValue );
		uint32 length4 = buffer4.GetLength( );
		Telium_Printf( "Buffer 4 [%s] -> Length [%d]", buffer4, length4 );

		//@Comments Este constructor te permite crear el buffer apartir de otro buffer sel indica
		//el indice que va empezar y cuando valores va copiar/escribir en el nuevo buffer

		//@ -> return: Mu   source: "Hola Mundo!"
		Buffer buffer5( 5, bufferValue, 2 );
		uint32 length5 = buffer5.GetLength( );
		Telium_Printf( "Buffer 5 [%s] -> Length [%d]", buffer5, length5 );
	}

	void BufferTest::CompareTo( ) const
	{
		//@Commenst El CompareTo regresa un valo 0 si son iguales y in valor diferente de 0 si son diferentes
		Buffer valueA( bufferValue );
		Buffer valueB( "Hola Mundo", 10 );
		Buffer valueC( bufferValue );

		uint32 result1 = valueA.CompareTo( valueB );
		Telium_Printf( "Compare valueA To valueB -> result [%d]", result1 );

		uint32 result2 = valueA.CompareTo( valueC );
		Telium_Printf( "Compare valueA To valueC -> result [%d]", result2 );

	}

	void BufferTest::Operator( ) const
	{
		//@Creación de variables.
		cstr value = "Comparar Hola Mundo";
		Buffer valueA( bufferValue );
		Buffer valueB( value, Str::GetLength( value ) );
		Buffer equals( '!' );

		//@Comments Los operadores "+ y +=" nos ayudan a concatenar dos buffer diferentes y
		//retornar un nuevo Buffer

		//@ -> return: Hola Mundo!Comparar Hola Mundo  source: valueA -> Hola Mundo! valueB -> Comparar Hola Mundo
		Buffer resultPlus = valueA + valueB;
		//@ -> return: Hola Mundo! source: valueA -> Hola Mundo! valueB -> Comparar Hola Mundo
		Buffer resultEquals = valueA += equals;

		//@Comments Los siguinetes operadores nos ayudan a saber si a nivel Buffer son "==, !=, >, >=, <, <="
		//y regresan un valor Booleano (true o false).
		bool equal = valueA == valueB;
		if( equal )
			Telium_Printf( "ValueA == ValueB" );

		bool different = valueA != valueB;
		if( different )
			Telium_Printf( "ValueA != ValueB" );

		bool high = valueA > valueB;
		if( high )
			Telium_Printf( "ValueA > ValueB" );

		bool highEquals = valueA >= valueB;
		if( highEquals )
			Telium_Printf( "ValueA >= ValueB" );

		bool less = valueA < valueB;
		if( less )
			Telium_Printf( "ValueA < ValueB" );

		bool lessEquals = valueA <= valueB;
		if( lessEquals )
			Telium_Printf( "ValueA <= ValueB" );
	}

	void BufferTest::CopyTo( ) const
	{
		Buffer helloWord( Defines::KbSize );
		const Buffer DefaultValue( "Hello Word!", 11 );

		Buffer valueA( Defines::KbSize );
		valueA.Add( "Value A" );

		Buffer valueB( Defines::KbSize );
		valueB.Add( "Value B" );

		//@Comment el CopyTo nos apoya a hacer una copia del objeto Buffer al objeto
		//que se le pasa por parametro.

		//@ -> return: valueB -> ValueA source: valueA -> Value A - valueB -> Value B
		uint32 result = DefaultValue.CopyTo( valueB );
		Telium_Printf( "Copy To [%d]", result );

		//@Comment el CopyTo nos apoya a hacer una copia del objeto Buffer al objeto
		//que se le pasa por parametro y se le indica cuantos bytes va a tomar.

		//@ -> return: helloWord -> "Hel" source: helloWord -> "" - valueB -> "Hello Word!"
		helloWord.Clean( );
		valueB.CopyTo( helloWord, 3 );

		//@Comment el CopyTo nos apoya a hacer una copia del objeto Buffer al objeto
		//que se le pasa por parametro y se le indica apartur de que byte o index va iniciar la copia del objeto.

		//@ -> return: helloWord -> "lo Word!" source: helloWord -> "" - DefaultValue -> "Hello Word!"
		helloWord.Clean( );
		DefaultValue.CopyTo( 3, helloWord );

		//@Comment el CopyTo nos apoya a hacer una copia del objeto Buffer al objeto
		//que se le pasa por parametro y se le indica apartir de que index va empezar y cuantos
		//bytes va tomar.
		//@ -> return: helloWord -> " Wor" source: helloWord -> "" - DefaultValue -> "Hello Word!"
		helloWord.Clean( );
		DefaultValue.CopyTo( 5, helloWord, 4 );
	}

	void BufferTest::Resize( ) const
	{
		//@Comment Permite ajustar el tamaño(size) del buffer para poder agregar nuevos valores
		//en caso del que el buffer creado no cuente con el tamaño requerido.

		//El buffer nace con un tamaño de 11
		Buffer value( bufferValue );

		//Se ajusta el tamaño(size) a 1024 kb y recordar que se elimina el contenido que contenga
		value.Resize( Defines::KbSize );

		//Se agrega nuevos valores ya que le tamaño del buffer ahora lo permite, en caso de no ajustar
		//se valida y mostrara una Exception
		value.Add( " ahora permite agregar un nuevo valor mayor al que se creo el buffer" );
	}

	void BufferTest::Adds( ) const
	{
		Buffer value( Defines::KbSize );

		//@Comments Nos permite agregar valores al buffer siempre y cuando el tamaño(size) del buffer lo permita
		value.Add( '1' );
		//@ -> repite el número de carcteres que se le indique en el parametro coun
		//@ -> return: "122" source: "1"
		value.Add( '2', 2 );

		//@ -> Agrega un buffer completo
		//@ -> return: "122Hola Mundo!" source: "122"
		value.Add( bufferValue );

		//@ -> Se agrega los bytes indicados en el contador este empieza desde el indice 0
		//@ -> return: "Hola " source: "Hola Mundo!"
		value.Clean( );
		value.Add( bufferValue, 5 );

		//@ -> Se toma el valor apartir el index de inicio indicado en este caso es apartir del 5
		//@ -> return: "Mundo!" source: "Hola Mundo!"
		value.Clean( );
		value.Add( 5, bufferValue );

		//@ -> Se agrega el valor apartir del start index y toma el numero de bytes que se le indica en el contador
		//@ -> return: "undo" source: "Hola Mundo!"
		value.Clean( );
		value.Add( 6, bufferValue, 4 );

	}

	void BufferTest::Remove( ) const
	{
		Buffer value( bufferValue );

		//@Comment Permite Remover los caractares que continuan del contador que
		//se le indica en el contador que se le pasa por parametro.

		//@ -> return: "Hola " 		source: "Hola Mundo!"
		value.Remove( 5 );
		Telium_Printf( "Value[%s]", value );

	}

	void BufferTest::Read( ) const
	{
		//@Comment Permite leer un numero de carcateres del buffer y retornar el valor
		//al buffer que se pasa por parametro

		Buffer value( bufferValue );
		Buffer readValue( Defines::KbSize );

		//@ -> return: "M" 		source: "Hola Mundo!"
		char ch = value.Read( 5 );
		//@ -> return: "la Mu" 		source: "Hola Mundo!"
		uint32 countRead = value.Read( 2, readValue, 5 );
		Telium_Printf( "Char value[%c]  -> Counter value [%d]", ch, countRead );

		//@ -> return: "la Mu" 		source: "Hola Mundo!"
		readValue.Clean( );
		countRead = value.Read( 1, 2, readValue, 5 );

		//@ -> return: ASCII -> 72	Hex -> 48 Symbol -> "H"	source: "Hola Mundo!"
		uint32 code;
		value.Read( 0, str( &code ), 1 );

		//@ -> return: ASCII -> 72	Hex -> 48 Symbol -> "H"	source: "Hola Mundo!"
		uint32 symbol;
		value.Read( 0, str( &symbol ), sizeof( code ), sizeof( code ) );
	}

	void BufferTest::SetChar( ) const
	{
		//@Comment Permite hacer un Set de un caracter a todo un Buffer o tambien
		//se le puede indicar cuantos caracteres se requieren setear
		Buffer value( bufferValue );

		//@ -> return: "xxxxxxxxxxx"	source: "Hola Mundo!"
		value.SetChar( 'x' );

		//@ -> return: "ZZZZZxxxxxx"	source: "xxxxxxxxxxx"
		value.SetChar( 'Z', 5 );
	}

	void BufferTest::SearchChar( ) const
	{
		Buffer value( bufferValue );

		//@Comments Permite buscar un o varios caracteres en un buffer y retoran -1
		//si no encuentra el dato y mayor a 0, este valor mayor a 0 es en la posición
		// donde fuen ecnontrado

		uint32 counter = value.SearchChar( 'M' );
		counter = value.SearchChar( 'u', 8 );
		counter = value.SearchChar( 2, 'a' );
		counter = value.SearchChar( 0, 'n', 9 );

		Buffer word( "Mun", 5 );
		counter = value.SearchAnyChar( word );
		counter = value.SearchAnyChar( word, value.GetLength( ) );
		counter = value.SearchAnyChar( 4, word );
		counter = value.SearchAnyChar( 4, word, 5 );

	}

	void BufferTest::Write( ) const
	{
		//@Comment Permite insertar un caracter dentro del Buffer en index indicado
		Buffer value( bufferValue );
		//@ -> return: "HoXa Mundo!"	source: "Hola Mundo!"
		value.Write( 2, 'X' );

		//@Comment Permite insertar un caracter dentro del Buffer en index indicado
		//este caracter es repetido con respecto al contador ingresado.
		//@ -> return: "HoZZZMundo!"	source: "HoXa Mundo!"
		value.Write( 2, 'Z', 3 );

		//@Comment Permite insertar un caracter dentro del Buffer apartir del index indicado
		//@ -> return: "HoZInserto!"	source: "HoZZZMundo!"
		Buffer newValue( "MyValue", 7 );
		value.Write( 3, newValue );

		//@Comment Permite insertar un caracter dentro del Buffer, se le indica el startIndex
		//y cuantos caracteres va tomar del buffer a insertar
		//@ -> return: "MyVem ipsum dolor" source: "Lorem ipsum dolor"

		Buffer lorem( "Lorem ipsum dolor", 17 );
		lorem.Write( 0, newValue, 3 );

		//@ offset -> Apartir de donde se insertara el nuevo buffer
		//@ startIndex -> Indica el index/inicio del byte a tomar del buffer a escribir
		//@ value -> Valor a escribir
		//@ -> return:  "MyVem Value dolor" source: "MyVem ipsum dolor"
		lorem.Write( 6, 2, newValue );

		//@ offset -> Apartir de donde se insertara el nuevo buffer
		//@ startIndex -> Indica el index/inicio del byte a tomar del buffer a escribir
		//@ value -> Valor a escribir
		//@ count -> número de valores a tomar del buffer (se toma el tamaño del buffer - starIndex para que no se desborde el buffer)

		//@ -> return:  "lueem Value dolor" source: " "MyVem Value dolor""
		lorem.Write( 0, 4, newValue, newValue.GetLength( ) - 4 );

		//@ -> return:  "Lorem ipsum dolor"  source: "lueem Value dolor"
		Buffer format( "Lorem ipsum dolor", 17 );
		lorem.WriteFormat( 0, "%s", format.GetBytes( 0 ) );
	}

	void BufferTest::SubBuffer( ) const
	{
		Buffer value = bufferValue.SubBuffer( 5 );
		Buffer aux = bufferValue.SubBuffer( 0, 5 );
	}

	void BufferTest::StaticMethods( ) const
	{
		Buffer valueA( "Hola", 4 );
		Buffer valueB( "Mundo", 5 );
		Buffer valueC( bufferValue );

		Buffer value( Defines::KbSize );

		//@ -> return : "HolaMundo"		Source: valueA -> "Hola"  valueB -> "Mundo"
		value = Buffer::Concat( valueA, valueB );

		//@ -> return : "Hola Mundo!. Este es un Format"		Source: "Hola Mundo!"
		value.Clean( );
		value = Buffer::Format( "%s. Este es un Format", bufferValue.GetBytes( 0 ) );

		if( Buffer::Compare( valueA, valueB ) )
			Telium_Printf( "value A == valueB" );

		if( Buffer::Compare( valueA, valueB, true ) )
			Telium_Printf( "value A == valueB" );

		if( Buffer::Compare( valueA, valueC, uint32(4) ) )
			Telium_Printf( "valueA == valueC" );

		if( Buffer::Compare( valueA, valueC, 4, true ) )
			Telium_Printf( "valueA == valueC" );

		if( Buffer::Compare( valueB, 0, valueC, 5, 5 ) )
			Telium_Printf( "valueB == valueC" );

		if( Buffer::Compare( valueB, 0, valueC, 5, 5, false ) )
			Telium_Printf( "valueB == valueC" );

		//@Comment Numeric Methods
		value.Clean( );
		value = Buffer::NumericToBuffer( byte('A') );

		//@ -> return : "16"		Source: 16
		Buffer value16 = Buffer::NumericToBuffer( uint16( 16 ) );
		//@ -> return : 32 " "		Source: 32
		Buffer value32 = Buffer::NumericToBuffer( uint32( 32 ) );
		//@ -> return : 64 '@'		Source: 64
		Buffer value64 = Buffer::NumericToBuffer( uint64( 64 ) );
		//@ -> return : 182 '¶'		Source: 1.234
		Buffer valueSingle = Buffer::NumericToBuffer( single( 1.234 ) );
		//@ -> return :  "z"		Source: 3.141592
		Buffer valueDoble = Buffer::NumericToBuffer( 3.141592 );

		//@ -> return : 16		Source: "16"
		uint16 v16 = Buffer::ToNumeric16( value16 );
		//@ -> return : 32		Source: "32"
		uint32 v32 = Buffer::ToNumeric32( value32 );
		//@ -> return : 64		Source: "64"
		uint64 v64 = Buffer::ToNumeric64( value64 );
		//@ -> return : 1.23399997		Source: ""
		single vSingle = Buffer::ToNumericSingle( valueSingle );
		//@ -> return : "3.1415920000000002"		Source: "z"
		double vDoble = Buffer::ToNumericDouble( valueDoble );

		//TODO aun falta revisar XOR
		Buffer color1( "9C", 2 );
		Buffer color2( "5A", 2 );
		value.Clean( );

		//@ -> return : '\f'
		value = Buffer::XOR( color1, color2 );
		cstr hex = value.GetBytes(0);
		//@ -> return : ""		Source: ""
		value = Buffer::XOR( color1, color2, 1 );
		//@ -> return : ""		Source: ""
		value = Buffer::XOR( 1, color1, 1, color2, 1 );
	}
} /* namespace Test */

