//
// Generated file, do not edit! Created by nedtool 5.2 from N_PDU.msg.
//

#if defined(__clang__)
#  pragma clang diagnostic ignored "-Wreserved-id-macro"
#endif
#ifndef __N_PDU_M_H
#define __N_PDU_M_H

#include <omnetpp.h>

// nedtool version check
#define MSGC_VERSION 0x0502
#if (MSGC_VERSION!=OMNETPP_VERSION)
#    error Version mismatch! Probably this file was generated by an earlier version of nedtool: 'make clean' should help.
#endif



/**
 * Class generated from <tt>N_PDU.msg:20</tt> by nedtool.
 * <pre>
 * //
 * // TODO generated message class
 * //
 * packet N_PDU
 * {
 *     int npduid;
 *     int source;
 *     int destination;
 * }
 * </pre>
 */
class N_PDU : public ::omnetpp::cPacket
{
  protected:
    int npduid;
    int source;
    int destination;

  private:
    void copy(const N_PDU& other);

  protected:
    // protected and unimplemented operator==(), to prevent accidental usage
    bool operator==(const N_PDU&);

  public:
    N_PDU(const char *name=nullptr, short kind=0);
    N_PDU(const N_PDU& other);
    virtual ~N_PDU();
    N_PDU& operator=(const N_PDU& other);
    virtual N_PDU *dup() const override {return new N_PDU(*this);}
    virtual void parsimPack(omnetpp::cCommBuffer *b) const override;
    virtual void parsimUnpack(omnetpp::cCommBuffer *b) override;

    // field getter/setter methods
    virtual int getNpduid() const;
    virtual void setNpduid(int npduid);
    virtual int getSource() const;
    virtual void setSource(int source);
    virtual int getDestination() const;
    virtual void setDestination(int destination);
};

inline void doParsimPacking(omnetpp::cCommBuffer *b, const N_PDU& obj) {obj.parsimPack(b);}
inline void doParsimUnpacking(omnetpp::cCommBuffer *b, N_PDU& obj) {obj.parsimUnpack(b);}


#endif // ifndef __N_PDU_M_H

