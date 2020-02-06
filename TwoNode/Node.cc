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

#include "Node.h"

Define_Module(Node);

void Node::initialize()
{
    // TODO - Generated method body
    id = par("id");
    in = gate("in");
    out = gate("out");
    if(id==100)
    {
        cMessage *msg = new cMessage("Aka");
        scheduleAt(0, msg);
    }
}

void Node::handleMessage(cMessage *msg)
{
    // TODO - Generated method body
    if(msg->isSelfMessage())
    {
        N_PDU *dpkt = new N_PDU();
        dpkt->setId(1);
        dpkt->setType("Data");
        dpkt->setSource(1);
        dpkt->setDestination(2);
        send(dpkt,out);
    }
    else
    {
        N_PDU* temp = check_and_cast<N_PDU*>(msg);
        int newId = temp->getId();
        N_PDU* npdu = new N_PDU();

        npdu->setId(newId+1);
        npdu->setSource(temp->getDestination());
        npdu->setDestination(temp->getSource());
        if(!opp_strcmp(temp->getType(),"Data"))
            npdu->setType("Acknowledgment");
        else
           npdu->setType("Data");

        if(newId<20)
            send(npdu,out);
    }
}
