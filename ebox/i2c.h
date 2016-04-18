/*
file   : i2c.h
author : shentq
version: V1.1
date   : 2016/4/6

Copyright 2015 shentq. All Rights Reserved.

Copyright Notice
No part of this software may be used for any commercial activities by any form or means, without the prior written consent of shentq.

Disclaimer
This specification is preliminary and is subject to change at any time without notice. shentq assumes no responsibility for any errors contained herein.
*/
#ifndef __I2C_H
#define __I2C_H

#include "common.h"

/*
	1.֧��I2C1��I2C2
	2.��ʱ��֧��remap�������ܿ�����
*/

class I2C
{

public:
    I2C(I2C_TypeDef *I2Cx, GPIO *scl_pin, GPIO *sda_pin);
    void		begin(uint32_t speed);
    void        config(uint32_t speed);
    uint32_t    read_config();

    int8_t	write_byte(uint8_t slave_address, uint8_t reg_address, uint8_t data);
    int8_t	write_byte(uint8_t slave_address, uint8_t reg_address, uint8_t *data, uint16_t num_to_write);
    int8_t	read_byte (uint8_t slave_address, uint8_t reg_address, uint8_t *data);
    int8_t	read_byte (uint8_t slave_address, uint8_t reg_address, uint8_t *data, uint16_t num_to_read);
    int8_t	wait_dev_busy(uint8_t slave_address);
public:
    int8_t take_i2c_right(uint32_t speed);
    int8_t release_i2c_right(void);

private:
    int8_t start();
    int8_t stop();
    int8_t send_no_ack();
    int8_t send_ack();

    int8_t send_byte(uint8_t regData);
    int8_t send_7bits_address(uint8_t slave_address);
    int8_t receive_byte(uint8_t *data);

private:
    I2C_TypeDef *I2Cx;
    GPIO        *sda_pin;
    GPIO        *scl_pin;
    uint32_t    speed;
    uint8_t     busy;
};


/*
	1.֧���κ�IO���ţ�
	2.�����ӿں�Ӳ��I2C��ȫһ�����Ի������
	ע�⣺
				1.�����speed����delay_us��ʱ�������ơ����в�׼
				2.speed����ֻ��Ϊ100000��200000,300k,400k��������Ǵ�ֵ����Ὣspeed��ֱֵ�Ӵ��ݸ�delay_us.��delay_us(speed);
				3.���ڵ���I2C�豸����ʹ��100k�����ߴ���10��ֵ
*/
class SOFTI2C
{
public:
    SOFTI2C(GPIO *scl, GPIO *sda);
    void 		begin(uint32_t speed);
    int8_t 		config(uint32_t speed);
    uint32_t	read_config();
    int8_t		write_byte(uint8_t slave_address, uint8_t reg_address, uint8_t data);
    int8_t 		write_byte(uint8_t slave_address, uint8_t reg_address, uint8_t *data, uint16_t num_to_write);
    int8_t 		read_byte (uint8_t slave_address, uint8_t reg_address, uint8_t *data);
    int8_t 		read_byte (uint8_t slave_address, uint8_t reg_address, uint8_t *data, uint16_t num_to_read);
    int8_t		wait_dev_busy (uint8_t slave_address);
public:
    int8_t      take_i2c_right(uint32_t speed);
    int8_t      release_i2c_right(void);

private:
    void 	start();
    void 	stop();
    int8_t 	send_ack();
    int8_t 	send_no_ack();

    int8_t 	send_byte(uint8_t Byte);
    int8_t	send_7bits_address(uint8_t slave_address);
    uint8_t receive_byte();

    int8_t	wait_ack();

private:
    GPIO        *sda_pin;
    GPIO        *scl_pin;
    uint32_t	speed;
    uint16_t	delay_times;
    uint8_t 	busy;
};

#endif