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

module Node
{
    parameters:
        int id;
    gates:
        input in;
        output out;
    submodules:
        NL : NetworkLayer
        	{ Nid=id; count=0;}
        DL : DataLayer
        	{ Did=id; }
    connections:
        NL.toDLL --> DL.fromNL;
        DL.toNL --> NL.fromDLL;
        // These connection are out-out and in-in
        DL.toNode --> out;
        in --> DL.fromNode;
}
