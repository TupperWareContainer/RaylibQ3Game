#pragma once
#include <raylib.h>
#include "BaseUnit.h"
#include <raymath.h>
using namespace std; 
class Connection {
	public:
		Connection(); 
		Connection(Vector2, Vector2);
		void setEnd(Vector2); 
		/// <summary>
		/// Gets the base units attatched to this connection
		/// </summary>
		/// <param name="connection:"> the number of the connection within a array of size 2 (0,1) </param>
		/// <returns></returns>
		BaseUnit getConnection(int connection); 
		/// <summary>
		/// Sets the base units attatched to this connection
		/// </summary>
		/// <param name="connection">the number of the connection within a array of size 2 (0,1)</param>
		/// <param name="baseUnit">the base unit to attatch</param>
		void setConnection(int connection, BaseUnit baseUnit); 
		void PartialRender(); 
		void FullRender(); 
		void CheckCollison(BaseUnit*,int);
		~Connection();

	private:
		Rectangle c1;
		Rectangle c2;
		BaseUnit connectedTo[2]; 
		Vector2 startPos; 
		Vector2 endPos; 

};
