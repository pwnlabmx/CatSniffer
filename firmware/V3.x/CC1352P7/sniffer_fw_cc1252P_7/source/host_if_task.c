/******************************************************************************
*  Filename:       host_if_task.c
*
*  Description:    Source file for the Host IF Task. 
*
* Copyright (C) 2017-2018 Texas Instruments Incorporated - http://www.ti.com/
*
*
*  Redistribution and use in source and binary forms, with or without
*  modification, are permitted provided that the following conditions
*  are met:
*
*    Redistributions of source code must retain the above copyright
*    notice, this list of conditions and the following disclaimer.
*
*    Redistributions in binary form must reproduce the above copyright
*    notice, this list of conditions and the following disclaimer in the
*    documentation and/or other materials provided with the
*    distribution.
*
*    Neither the name of Texas Instruments Incorporated nor the names of
*    its contributors may be used to endorse or promote products derived
*    from this software without specific prior written permission.
*
*  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
*  "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
*  LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
*  A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
*  OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
*  SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
*  LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
*  DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
*  THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
*  (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
*  OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*
******************************************************************************/

#include <ti/sysbios/knl/Task.h>
#include "packet_queue.h"
#include "host_if.h"


//! \brief Host IF task function
//!        The arguments are not used.
//!
//!        This task takes packets from the Host interface queue and sends the packets
//!        out on the Host interface. 
//!
void hostIfTask(UArg a0, UArg a1)
{
    DataPacket_Obj* dataPacket;
    uint16_t packetLength;
  
    while(1)
    {
        PacketQueue_dequeue(&dataPacket, &packetLength);
        HostIF_writeBuffer((uint8_t*)dataPacket, packetLength);
        // HostIF_writeBuffer blocks until the packet is written. 
        // The buffer slot can now be freed. 
        PacketQueue_freeBufferSlot(dataPacket);
    }
}

