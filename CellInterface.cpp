/* CellularInterface
 * Copyright (c) 2015 ARM Limited
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include "CellInterface.h"
//#include "mbed.h"

static MDMSerial mdm;


int CellInterface::connect(const char *apn /* = 0 */,
		const char *username /* = 0 */,
		const char *password /* = 0 */)
{
    if (!mdm.connect(NULL, apn, username, password) ){
    	return 0;
    }
    return 1;
}

int CellInterface::disconnect()
{
	mdm.disconnect();
    return 0;
}

const char *CellInterface::get_ip_address()
{
	char textToWrite[ 16 ];
	uint32_t ip;
	ip = mdm.getIpAddress();
	sprintf(textToWrite,"%lu", ip);
    return textToWrite;
}

const char *CellInterface::get_mac_address()
{
	char *ret = "mac";
    return ret;
}

NetworkStack *CellInterface::get_stack()
{
	//return nsapi_create_stack(&mdm);
	return NULL;
}
