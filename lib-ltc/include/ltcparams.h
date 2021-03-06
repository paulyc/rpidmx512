/**
 * @file ltcparams.h
 */
/* Copyright (C) 2019 by Arjan van Vught mailto:info@raspberrypi-dmx.nl
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

#ifndef LTCPARAMS_H_
#define LTCPARAMS_H_

#include <stdint.h>

#include "displaymax7219.h"

enum TLtcReaderSource {
	LTC_READER_SOURCE_LTC,
	LTC_READER_SOURCE_ARTNET,
	LTC_READER_SOURCE_MIDI
};

struct TLtcParams {
	uint32_t bSetList;
	uint8_t tSource;
	uint8_t tMax7219Type;
	uint8_t nMax7219Intensity;
};

class LtcParamsStore {
public:
	virtual ~LtcParamsStore(void);

	virtual void Update(const struct TLtcParams *pTLtcParams)=0;
	virtual void Copy(struct TLtcParams *pTLtcParams)=0;

private:

};

class LtcParams {
public:
	LtcParams(LtcParamsStore *pLtcParamsStore = 0);
	~LtcParams(void);

	bool Load(void);

	 TLtcReaderSource GetSource(void) {
		return (TLtcReaderSource) m_tLtcParams.tSource;
	}

	 uint8_t GetMax7219Intensity(void) {
		return m_tLtcParams.nMax7219Intensity;
	}

	 tMax7219Types GetMax7219Type(void) {
		return (tMax7219Types) m_tLtcParams.tMax7219Type;
	}

	void Dump(void);

private:
	bool isMaskSet(uint32_t nMask) const;

public:
    static void staticCallbackFunction(void *p, const char *s);

private:
    void callbackFunction(const char *pLine);

private:
    LtcParamsStore 	*m_pLTcParamsStore;
    struct TLtcParams	m_tLtcParams;
};

#endif /* LTCPARAMS_H_ */
