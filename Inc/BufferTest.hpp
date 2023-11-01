/*
 * BufferTest.hpp
 *
 *  Created on: Oct 23, 2023
 *      Author: XMF3944
 */

#ifndef SRC_BUFFERTEST_HPP_
#define SRC_BUFFERTEST_HPP_

#include <FwIncludes.hpp>

namespace Test
{

	class BufferTest
	{
		public:

			BufferTest( );
			virtual ~BufferTest( );

			void Overload( ) const;
			void CompareTo( ) const;

			void Operator( ) const;
			void CopyTo( ) const;

			void Resize( ) const;
			void Adds( ) const;

			void Remove( ) const;
			void Read( ) const;

			void SetChar( ) const;
			void SearchChar( ) const;

			void Write( ) const;
			void SubBuffer( ) const;

			void StaticMethods( ) const;

	};

} /* namespace Test */

#endif /* SRC_BUFFERTEST_HPP_ */
