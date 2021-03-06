/**
 * @file oscserverparams.h
 *
 */
/* Copyright (C) 2018-2019 by Arjan van Vught mailto:info@raspberrypi-dmx.nl
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:

 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.

 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */

#ifndef OSCSERVERPARAMS_H_
#define OSCSERVERPARAMS_H_

#include <stdint.h>

#include "oscserver.h"

enum TOscOutputType {
	OSC_OUTPUT_TYPE_DMX,
	OSC_OUTPUT_TYPE_SPI,
	OSC_OUTPUT_TYPE_MONITOR
};

struct TOSCServerParams {
    uint32_t nSetList;
	uint16_t nIncomingPort;
	uint16_t nOutgoingPort;
	TOscOutputType tOutputType;
	bool bPartialTransmission;
	char aPath[OSCSERVER_PATH_LENGTH_MAX];
	char aPathInfo[OSCSERVER_PATH_LENGTH_MAX];
	char aPathBlackOut[OSCSERVER_PATH_LENGTH_MAX];
};

class OSCServerParamsStore {
public:
	virtual ~OSCServerParamsStore(void);

	virtual void Update(const struct TOSCServerParams *pOSCServerParams)=0;
	virtual void Copy(struct TOSCServerParams *pOSCServerParams)=0;
};

class OSCServerParams {
public:
	OSCServerParams(OSCServerParamsStore *m_pOSCServerParamsStore=0);
	~OSCServerParams(void);

	bool Load(void);
	void Set(OscServer *pOscServer);
	void Dump(void);

	 uint16_t GetIncomingPort(void) {
		return m_tOSCServerParams.nIncomingPort;
	}

	 uint16_t GetOutgoingPort(void) {
		return m_tOSCServerParams.nOutgoingPort;
	}

	 bool GetPartialTransmission(void) {
		return m_tOSCServerParams.bPartialTransmission;
	}

	 TOscOutputType GetOutputType(void) {
		return m_tOSCServerParams.tOutputType;
	}

public:
    static void staticCallbackFunction(void *p, const char *s);

private:
    void callbackFunction(const char *s);
	bool isMaskSet(uint16_t) const;

private:
	OSCServerParamsStore *m_pOSCServerParamsStore;
    struct TOSCServerParams m_tOSCServerParams;
};

#endif /* OSCSERVERPARAMS_H_ */
