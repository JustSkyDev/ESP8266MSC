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

#include <ESP8266MSC.h>
#include <COMMUNICATION.h>

#include <stdint.h>

int ESP8266MSC::init(void)
{
    return esp_now_init();
}

int ESP8266MSC::deInit(void)
{
    return esp_now_deinit();
}

int ESP8266MSC::onReceiveEV(void (*callback)(uint8_t *mac_addr, uint8_t *data, uint8_t length))
{
    return esp_now_register_recv_cb(callback);
}

int ESP8266MSC::delReceiveEV(void)
{
    return esp_now_unregister_recv_cb();
}

int ESP8266MSC::onSendEV(void (*callback)(uint8_t *mac_addr, uint8_t status))
{
    return esp_now_register_send_cb(callback);
}

int ESP8266MSC::delSendEV(void)
{
    return esp_now_unregister_send_cb();
}

int ESP8266MSC::send(uint8_t *ba, uint8_t *data, uint8_t length)
{
    return esp_now_send(ba, data, length);
}

int ESP8266MSC::addPeer(uint8_t *mac_addr, MSC_ROLE role, uint8_t channel, uint8_t *key, uint8_t key_length)
{
    return esp_now_add_peer(mac_addr, role, channel, key, key_length);
}

int ESP8266MSC::delPeer(uint8_t *mac_addr)
{
    return esp_now_del_peer(mac_addr);
}

int ESP8266MSC::setRole(MSC_ROLE role)
{
    return esp_now_set_self_role(role);
}

int ESP8266MSC::getRole(void)
{
    return esp_now_get_self_role();
}

int ESP8266MSC::setPeerRole(uint8_t *mac_addr, MSC_ROLE role)
{
    return esp_now_set_peer_role(mac_addr, role);
}

int ESP8266MSC::getPeerRole(uint8_t *mac_addr)
{
    return esp_now_get_peer_role(mac_addr);
}

int ESP8266MSC::setPeerChannel(uint8_t *mac_addr, uint8_t channel)
{
    return esp_now_set_peer_channel(mac_addr, channel);
}

int ESP8266MSC::getPeerChannel(uint8_t *mac_addr)
{
    return esp_now_get_peer_channel(mac_addr);
}

int ESP8266MSC::setPeerKey(uint8_t *mac_addr, uint8_t *key, uint8_t key_length)
{
    return esp_now_set_peer_key(mac_addr, key, key_length);
}

int ESP8266MSC::getPeerKey(uint8_t *mac_addr, uint8_t *key, uint8_t *key_length)
{
    return esp_now_get_peer_key(mac_addr, key, key_length);
}

uint8_t *ESP8266MSC::fetchPeer(bool restart)
{
    return esp_now_fetch_peer(restart);
}

int ESP8266MSC::isPeerExist(uint8_t *mac_addr)
{
    return esp_now_is_peer_exist(mac_addr);
}

int ESP8266MSC::getCntInfo(uint8_t *all_cnt, uint8_t *encrypt_cnt)
{
    return esp_now_get_cnt_info(all_cnt, encrypt_cnt);
}

int ESP8266MSC::setKok(uint8_t *key, uint8_t length)
{
    return esp_now_set_kok(key, length);
}
