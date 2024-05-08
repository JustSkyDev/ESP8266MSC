// =================================================================================
// Copyright (c) 2024 JustSkyDev
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.
// =================================================================================

#ifndef ESP8266MSC_h
#define ESP8266MSC_h

#include <stdint.h>

enum MSC_ROLE
{
  MSC_ROLE_IDLE = 0,
  MSC_ROLE_MASTER,
  MSC_ROLE_SLAVE,
  MSC_ROLE_BOTH,
  MSC_ROLE_MAX,
};

class ESP8266MSC
{
public:
  int init(void);
  int deInit(void);

  int onSendEV(void (*callback)(uint8_t *mac_addr, uint8_t status));
  int delSendEV(void);

  int onReceiveEV(void (*callback)(uint8_t *mac_addr, uint8_t *data, uint8_t length));
  int delReceiveEV(void);

  int send(uint8_t *ba, uint8_t *data, uint8_t length);

  int addPeer(uint8_t *mac_addr, MSC_ROLE role, uint8_t channel, uint8_t *key, uint8_t key_length);
  int delPeer(uint8_t *mac_addr);

  int setRole(MSC_ROLE role);
  int getRole(void);

  int setPeerRole(uint8_t *mac_addr, MSC_ROLE role);
  int getPeerRole(uint8_t *mac_addr);

  int setPeerChannel(uint8_t *mac_addr, uint8_t channel);
  int getPeerChannel(uint8_t *mac_addr);

  int setPeerKey(uint8_t *mac_addr, uint8_t *key, uint8_t key_length);
  int getPeerKey(uint8_t *mac_addr, uint8_t *key, uint8_t *key_length);

  uint8_t *fetchPeer(bool restart);

  int isPeerExist(uint8_t *mac_addr);

  int getCntInfo(uint8_t *all_cnt, uint8_t *encrypt_cnt);

  int setKok(uint8_t *key, uint8_t length);
};

#endif
