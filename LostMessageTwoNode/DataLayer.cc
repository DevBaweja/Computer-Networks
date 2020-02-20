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

#include "DataLayer.h"

Define_Module(DataLayer);

void DataLayer::initialize()
{
    // TODO - Generated method body
    Did = par("Did");
    fromNL = gate("fromNL");
    toNL = gate("toNL");
    fromNode = gate("fromNode");
    toNode = gate("toNode");
    isLost = par("isLost");
    timeoutEvent = new cMessage("timeoutEvent");
    copy = new cMessage("copy");

}

void DataLayer::handleMessage(cMessage *msg)
{
    // TODO - Generated method body

    if(msg->isSelfMessage())
    {
        DL_PDU* dpcopy = check_and_cast<DL_PDU*>(copy);
        send(dpcopy,toNode);
    }

    if(msg->getArrivalGate()==fromNL)
    {
        // It is to be transmitted to channel
        N_PDU *temp = check_and_cast<N_PDU*>(msg);
        DL_PDU* dpdu = new DL_PDU();
        int id = temp->getNpduid()%2;
        dpdu->setDpduid(id);
        dpdu->setType("Data");
        dpdu->setSource(temp->getSource());
        dpdu->setDestination(temp->getDestination());

        dpdu->encapsulate(temp);

        copy = (cMessage*)dpdu->dup();
        send(dpdu,toNode);

        scheduleAt(simTime()+200, timeoutEvent);
    }

    if(msg->getArrivalGate()==fromNode)
    {
        // It is to be transmitted to NL and acknowledgment to Node
        DL_PDU *temp = check_and_cast<DL_PDU*>(msg);
        if(!opp_strcmp(temp->getType(),"Data"))
        {
            // We need to send Acknowledgment and decapsulate to NL
            if(isLost%3==0)
            {
                bubble("Message Lost");
            }
            else
            {
                cancelEvent(timeoutEvent);
                DL_PDU* dpdu = new DL_PDU();
                dpdu->setDpduid(temp->getDpduid());
                dpdu->setType("Acknowledge");
                dpdu->setSource(temp->getDestination());
                dpdu->setDestination(temp->getSource());
                send(dpdu,toNode);

                send(temp->decapsulate(),toNL);
            }

            isLost++;
        }
    }
}
