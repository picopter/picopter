/**
 * Autogenerated by Thrift Compiler (0.9.0)
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */
#include "picopter_types.h"

#include <algorithm>

namespace picopter {

const char* coordDeg::ascii_fingerprint = "EA2086D2BB14222991D7B0497DE7B58B";
const uint8_t coordDeg::binary_fingerprint[16] = {0xEA,0x20,0x86,0xD2,0xBB,0x14,0x22,0x29,0x91,0xD7,0xB0,0x49,0x7D,0xE7,0xB5,0x8B};

uint32_t coordDeg::read(::apache::thrift::protocol::TProtocol* iprot) {

  uint32_t xfer = 0;
  std::string fname;
  ::apache::thrift::protocol::TType ftype;
  int16_t fid;

  xfer += iprot->readStructBegin(fname);

  using ::apache::thrift::protocol::TProtocolException;


  while (true)
  {
    xfer += iprot->readFieldBegin(fname, ftype, fid);
    if (ftype == ::apache::thrift::protocol::T_STOP) {
      break;
    }
    switch (fid)
    {
      case 1:
        if (ftype == ::apache::thrift::protocol::T_DOUBLE) {
          xfer += iprot->readDouble(this->lat);
          this->__isset.lat = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 2:
        if (ftype == ::apache::thrift::protocol::T_DOUBLE) {
          xfer += iprot->readDouble(this->lon);
          this->__isset.lon = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      default:
        xfer += iprot->skip(ftype);
        break;
    }
    xfer += iprot->readFieldEnd();
  }

  xfer += iprot->readStructEnd();

  return xfer;
}

uint32_t coordDeg::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  xfer += oprot->writeStructBegin("coordDeg");

  xfer += oprot->writeFieldBegin("lat", ::apache::thrift::protocol::T_DOUBLE, 1);
  xfer += oprot->writeDouble(this->lat);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("lon", ::apache::thrift::protocol::T_DOUBLE, 2);
  xfer += oprot->writeDouble(this->lon);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}

void swap(coordDeg &a, coordDeg &b) {
  using ::std::swap;
  swap(a.lat, b.lat);
  swap(a.lon, b.lon);
  swap(a.__isset, b.__isset);
}

} // namespace
