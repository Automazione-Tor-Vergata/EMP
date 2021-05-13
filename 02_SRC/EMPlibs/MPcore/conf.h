//
// Created by alfy on 04/05/21.
//

#ifndef EMP_LIB_CONF_H
#define EMP_LIB_CONF_H
//#include <cstdint>
#include <stdint.h>

/* This structure are use to describe the behaviour of EMP classes, not have to be use in the Concrete Class
 * CRC8_enable  := True to enable CRC8 Calculation and Verification, add 1 byte to all pack
 * cbPackStore  := Capacity (in term of pIn items) of the Circular Buffer use to store the correctly handle pIn
 * cdBinStore   := Capacity (in term of pIn items) of the Circular Buffer use to store the byte not yet analyze/sended
 * RT_THREAD    := If True, the priority of the readerThread are move to FIFO
 * N.B. True HAVE TO BE 1 and False 0, other wise, the logic will fail
 */
typedef struct MPConf_ {
  // Compatibility features
  bool CRC8_enable;

  // local storage configuration
  uint16_t cbPackStore;
  uint16_t cdBinStore;

  // Thread configuration
  bool RT_THREAD;
} MPConf;

#if __cplusplus > 201703L // superiore al C++17
#define configDeclare(name, CRC8_enable, cbPackStore, cdBinStore, RT_THREAD)                                           \
  constexpr MPConf name { CRC8_enable, cbPackStore, cdBinStore, RT_THREAD }
#else
#define configDeclare(CRC8_enable, cbPackStore, cdBinStore) CRC8_enable, cbPackStore, cdBinStore

#define ArduinoMP_template(crcEn) configDeclare(crcEn, 8, 4)
#define ArduinoMP_templateDefault() configDeclare(true, 8, 4)

#endif

#define LinuxMP_ConfBig(name, crcEn) configDeclare(name, crcEn, 256, 32, true)
#define LinuxMP_ConfMed(name, crcEn) configDeclare(name, crcEn, 64, 16, true)
#define LinuxMP_ConfSmall(name, crcEn) configDeclare(name, crcEn, 16, 8, true)

// MPConf test = ArduinoMP_ConfDefault();
#endif // EMP_LIB_CONF_H
