#ifndef EMUCONTROLLER_H
#define EMUCONTROLLER_H

// #################################
// # Author: Timon Heim
// # Email: timon.heim at cern.ch
// # Project: Yarr
// # Description: Emulator Controller
// # Comment:
// # Date: Feb 2017
// ################################

#include "HwController.h"
#include "EmuTxCore.h"
#include "EmuRxCore.h"
#include "EmuShm.h"
#include "json.hpp"

#include "RingBuffer.h"

using json=nlohmann::basic_json<std::map, std::vector, std::string, bool, std::int32_t, std::uint32_t, float>;

class EmuController : public HwController, public EmuTxCore, public EmuRxCore {
    public:
        EmuController(RingBuffer * rx, RingBuffer * tx);
        void loadConfig(json &j);
};

#endif
