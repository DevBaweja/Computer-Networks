//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
// 
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Lesser General Public License for more details.
// 
// You should have received a copy of the GNU Lesser General Public License
// along with this program.  If not, see http://www.gnu.org/licenses/.
// 

network TwoNode
{
    submodules:
        N1:Node
        	{id=1;
        	@display("i=,gold");}
        N2:Node
        	{id=2;
        	@display("i=,cyan");}
//       	N3:Node
//       		{id=3;}
//       	N4:Node
//       		{id=4;}
   connections:
       N1.out --> {delay=100ms;} --> N2.in;  
       N2.out --> {delay=100ms;}--> N1.in;
//       N1.out --> N3.in;
//       N1.out --> N4.in;
//       N2.out --> N3.in;
//       N2.out --> N4.in;
//       
//       N3.out --> N1.in;
//       N3.out --> N2.in;
//       N3.out --> N4.in;
//       
//       N4.out --> N1.in;
//       N4.out --> N2.in;
//       N4.out --> N3.in;
       
}
