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

#include "NetworkLayer.h"

Define_Module(NetworkLayer);

void NetworkLayer::initialize()
{
    // TODO - Generated method body
    Nid = par("Nid");
    state = par("state");
    fromDLL = gate("fromDLL");
    toDLL = gate("toDLL");

    if(Nid==1)
    {
        cMessage *msg = new cMessage("Aka");
        scheduleAt(0, msg);
    }
}

void NetworkLayer::handleMessage(cMessage *msg)
{
    // TODO - Generated method body
    if(msg->isSelfMessage())
    {
        if(state<10)
        {
            N_PDU* npdu = new N_PDU();
            npdu->setNpduid(state);
            npdu->setSource(1);
            npdu->setDestination(2);
            send(npdu,toDLL);

            cMessage *temp = new cMessage();
            scheduleAt(simTime()+200, temp);
            state++;
        }
    }
    else
    {
        delete(msg);
    }

}
