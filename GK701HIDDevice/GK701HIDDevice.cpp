//
// Copyright © 2020 osy86. All rights reserved.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//

#include "GK701HIDDevice.h"

kern_return_t
IMPL(GK701HIDDevice, Start)
{
    kern_return_t ret;
    if ((ret = Start(provider, SUPERDISPATCH)) != kIOReturnSuccess) {
        Stop(provider, SUPERDISPATCH);
        return ret;
    }
    
    os_log(OS_LOG_DEFAULT, "Patching idle time for MSI GK-701.");
    
    // Fix for stupid keyboard issue
    setIdle(0);
    
    return ret;
}
