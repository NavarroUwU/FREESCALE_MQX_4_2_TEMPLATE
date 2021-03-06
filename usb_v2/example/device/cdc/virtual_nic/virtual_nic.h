/**HEADER********************************************************************
*
* Copyright (c) 2008, 2013 Freescale Semiconductor;
* All Rights Reserved
*
* Copyright (c) 1989-2008 ARC International;
* All Rights Reserved
*
***************************************************************************
*
* THIS SOFTWARE IS PROVIDED BY FREESCALE "AS IS" AND ANY EXPRESSED OR
* IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
* OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
* IN NO EVENT SHALL FREESCALE OR ITS CONTRIBUTORS BE LIABLE FOR ANY DIRECT,
* INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
* (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
* SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
* HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,
* STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING
* IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF
* THE POSSIBILITY OF SUCH DAMAGE.
*
**************************************************************************
*
* $FileName: virtual_nic.h$
* $Version :
* $Date    :
*
* Comments:
*
* @brief The file contains Macro's and functions needed by the Virtual Network
*        Interface Application
*
*****************************************************************************/


#ifndef _VIRTUAL_NIC_H
#define _VIRTUAL_NIC_H  1

#include "usb_descriptor.h"
#include "virtual_nic_enet.h"
#include "usb_cdc_config.h"
#include "pcb.h"

/******************************************************************************
 * Constants - None
 *****************************************************************************/

/******************************************************************************
 * Macro's
 *****************************************************************************/
#if HIGH_SPEED
#define CONTROLLER_ID         USB_CONTROLLER_EHCI_0
#else
#define CONTROLLER_ID         USB_CONTROLLER_KHCI_0
#endif

#define DATA_BUFF_SIZE                  (DIC_BULK_OUT_ENDP_PACKET_SIZE)
/* Implementation Specific Macros */
#define LINE_CODING_SIZE              (0x07)
#define COMM_FEATURE_DATA_SIZE        (0x02)

#define LINE_CODE_DTERATE_IFACE      (115200) /*e.g 9600 is 0x00002580 */
#define LINE_CODE_CHARFORMAT_IFACE   (0x00)   /* 1 stop bit */
#define LINE_CODE_PARITYTYPE_IFACE   (0x00)  /* No Parity */
#define LINE_CODE_DATABITS_IFACE     (0x08)  /* Data Bits Format */

#define STATUS_ABSTRACT_STATE_IFACE  (0x0000) /* Disable Multiplexing ENDP in
                                                  this interface will continue
                                                  to accept/offer data*/
#define COUNTRY_SETTING_IFACE        (0x0000) /* Country Code in the format as 
                                                  defined in [ISO3166]- 
                                                  - PLEASE CHECK THESE VALUES*/
/*****************************************************************************
 * Global variables
 *****************************************************************************/

/******************************************************************************
 * Types
 *****************************************************************************/
typedef struct _rndis_packet_msg_format
{
    /*Specifies the Remote NDIS message type.
      This is set to REMOTE_NDIS_PACKET_MSG = 0x1.*/
    uint32_t message_type;
    /*Message length in bytes, including appended packet data, out-of-band
      data, per-packet-info data, and both internal and external padding*/
    uint32_t message_len;
    /*Specifies the offset in bytes from the start of the DataOffset field of
      this message to the start of the data. This is an integer multiple of 4*/
    uint32_t data_offset;
    /*Specifies the number of bytes in the data content of this message.*/
    uint32_t data_len;
    /*Specifies the offset in bytes of the first out of band data record from
      the start of the DataOffset field of this message.  Set to 0 if there is
      no out-of-band data. Otherwise this is an integer multiple of 4*/
    uint32_t oob_data_offset;
    /*Specifies in bytes the total length of the out of band data.*/
    uint32_t oob_data_len;
    /*Specifies the number of out of band records in this message*/
    uint32_t num_oob_data_elems;
    /*Specifies in bytes the offset from the beginning of the DataOffset field
      in the REMOTE_NDIS_PACKET_MSG data message to the start of the first per
      packet info data record.  Set to 0 if there is no per-packet data.
      Otherwise this is an integer multiple of 4*/
    uint32_t per_pkt_info_offset;
    /*Specifies in bytes the total length of the per packet information
      contained in this message*/
    uint32_t per_pkt_info_len;
    /*Reserved for connection-oriented devices.  Set to 0.*/
    uint32_t vc_handle;
    /*Reserved. Set to 0.*/
    uint32_t reserved;
} RNDIS_PKT_MSG_STRUCT, * PTR_RNDIS_PKT_MSG_STRUCT;

/*****************************************************************************
 * Global Functions
 *****************************************************************************/
extern void TestApp_Init(void);
extern void VNIC_USB_Send(uint8_t * nic_data_ptr, uint32_t length, PCB_PTR  enet_pcb);

#endif


/* EOF */
