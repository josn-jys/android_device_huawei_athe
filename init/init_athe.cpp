/*
   Copyright (c) 2014, The Linux Foundation. All rights reserved.
   Redistribution and use in source and binary forms, with or without
   modification, are permitted provided that the following conditions are
   met:
    * Redistributions of source code must retain the above copyright
      notice, this list of conditions and the following disclaimer.
    * Redistributions in binary form must reproduce the above
      copyright notice, this list of conditions and the following
      disclaimer in the documentation and/or other materials provided
      with the distribution.
    * Neither the name of The Linux Foundation nor the names of its
      contributors may be used to endorse or promote products derived
      from this software without specific prior written permission.
   THIS SOFTWARE IS PROVIDED "AS IS" AND ANY EXPRESS OR IMPLIED
   WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
   MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT
   ARE DISCLAIMED.  IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS
   BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
   CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
   SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR
   BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
   WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE
   OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN
   IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include <cstdlib>
#include <fstream>
#include <string>

#include "vendor_init.h"
#include "property_service.h"
#include "log.h"
#include "util.h"

void vendor_load_properties()
{
    std::string platform;
    std::ifstream fin;
    std::string buf;
    bool boll;

    platform = property_get("ro.board.platform");
    if (platform != ANDROID_TARGET)
        return;

    fin.open("/proc/app_info");
    while (getline(fin, buf))
        if (buf.find("huawei_fac_product_name") != std::string::npos)
            break;
    fin.close();

    platform = property_get("ro.boot.hwsim");

    if (buf.find("ATH-AL00") != std::string::npos) {
        property_set("ro.product.model", "HUAWEI ATH-AL00");
        property_set("ro.product.device", "hwATH-AL00");
        property_set("ro.build.product", "ATH-AL00");
        property_set("ro.build.description", "ATH-AL00-user 6.0.1 GRJ90 C432B340 release-keys");
        property_set("ro.build.fingerprint", "HUAWEI/ATH-AL00/hwATH-AL00:6.0.1/HuaweiATH-AL00/C432B340:user/release-keys");
    }
    else if (buf.find("ATH-UL00") != std::string::npos) {
        property_set("ro.product.model", "HUAWEI ATH-UL00");
        property_set("ro.product.device", "hwATH-UL00");
        property_set("ro.build.product", "ATH-UL00");
    }
    else if (buf.find("ATH-TL00") != std::string::npos) {
        property_set("ro.product.model", "HUAWEI ATH-TL00");
        property_set("ro.product.device", "hwATH-TL00");
        property_set("ro.build.product", "ATH-TL00");
    }
    else if (buf.find("ATH-TL00H") != std::string::npos) {
        property_set("ro.product.model", "HUAWEI ATH-TL00H");
        property_set("ro.product.device", "hwATH-TL00H");
        property_set("ro.build.product", "ATH-TL00H");
    }
    else if (buf.find("ATH-CL00") != std::string::npos) {
        property_set("ro.product.model", "HUAWEI ATH-CL00");
        property_set("ro.product.device", "hwATH-CL00");
        property_set("ro.build.product", "ATH-CL00");
    }
    else if (buf.find("ATH-UL01") != std::string::npos) {
        property_set("ro.product.model", "HUAWEI ATH-UL01");
        property_set("ro.product.device", "hwATH-UL01");
        property_set("ro.build.product", "ATH-UL01");
    }
    else if (buf.find("ATH-UL06") != std::string::npos) {
        property_set("ro.product.model", "HUAWEI ATH-UL06");
        property_set("ro.product.device", "hwATH-UL06");
        property_set("ro.build.product", "ATH-UL06");
    }

    if (platform == "double") {
	property_set("persist.radio.multisim.config", "dsds");
	property_set("ro.telephony.ril.config", "simactivation,sim2gsmonly");
	property_set("ro.telephony.default_network", "9,9");
    } else {
	property_set("ro.telephony.ril.config", "simactivation");
	property_set("ro.telephony.default_network", "9");
    }
}
