/*HEADER**********************************************************************
*
* Copyright 2008 Freescale Semiconductor, Inc.
*
* This software is owned or controlled by Freescale Semiconductor.
* Use of this software is governed by the Freescale MQX RTOS License
* distributed with this Material.
* See the MQX_RTOS_LICENSE file distributed for more details.
*
* Brief License Summary:
* This software is provided in source form for you to use free of charge,
* but it is not open source software. You are allowed to use this software
* but you cannot redistribute it or derivative works of it in source form.
* The software may be used only in connection with a product containing
* a Freescale microprocessor, microcontroller, or digital signal processor.
* See license agreement file for full license terms including other
* restrictions.
*****************************************************************************
*
* Comments:
*
*   This include file is used to provide information needed by
*   applications using the SAI I/O functions.
*
*
*END************************************************************************/

#include <mqx.h>
#include <bsp.h>
#include <fio.h>
#include <mfs.h>
#include <sh_mfs.h>
#include <shell.h>
#include <sdcard.h>
#include <part_mgr.h>
#include "main.h"
#include "log_messages.h"
#include "sgtl5000.h"
#include "sh_audio.h"

#if !BSPCFG_ENABLE_IO_SUBSYSTEM
#error This application requires BSPCFG_ENABLE_IO_SUBSYSTEM defined non-zero in user_config.h. Please recompile BSP with this option.
#endif

#ifndef BSP_DEFAULT_IO_CHANNEL_DEFINED
#error This application requires BSP_DEFAULT_IO_CHANNEL to be not NULL. Please set corresponding BSPCFG_ENABLE_TTYx to non-zero in user_config.h and recompile BSP with this option.
#endif

#if ! SHELLCFG_USES_MFS
#error This application requires SHELLCFG_USES_MFS defined non-zero in user_config.h. Please recompile libraries with this option.
#endif

#if defined BSP_SDCARD_ESDHC_CHANNEL
#if ! BSPCFG_ENABLE_ESDHC
#error This application requires BSPCFG_ENABLE_ESDHC defined non-zero in user_config.h. Please recompile libraries with this option.
#endif

#elif defined BSP_SDCARD_SDHC_CHANNEL

#if ! BSPCFG_ENABLE_SDHC
#error This application requires BSPCFG_ENABLE_SDHC defined non-zero in user_config.h. Please recompile libraries with this option.
#endif

#elif defined (BSP_TWRMCF51CN) || defined (BSP_TWRPXS20) || defined (BSP_TWR_K20D72M) || defined (BSP_TWR_K22F120M) || defined (BSP_TWR_K24F120M)

#if ! BSPCFG_ENABLE_SPI1
#error This application requires BSPCFG_ENABLE_SPI1 defined non-zero in user_config.h. Please recompile libraries with this option.
#endif

#else
#if ! BSPCFG_ENABLE_SPI0
#error This application requires BSPCFG_ENABLE_SPI0 defined non-zero in user_config.h. Please recompile libraries with this option.
#endif

#endif

#if defined (BSP_SDCARD_SPI_CHANNEL)
#define SDCARD_COM_CHANNEL BSP_SDCARD_SPI_CHANNEL
#elif defined (BSP_SDCARD_ESDHC_CHANNEL)
#define SDCARD_COM_CHANNEL BSP_SDCARD_ESDHC_CHANNEL
#elif defined (BSP_SDCARD_SDHC_CHANNEL)
#define SDCARD_COM_CHANNEL BSP_SDCARD_SDHC_CHANNEL
#else
#error "SDCARD low level communication device not defined!"
#endif


TASK_TEMPLATE_STRUCT MQX_template_list[] =
{
    /*  Task number, Entry point, Stack, Pri, String,   Auto? */
    { SDCARD_WRITE_TASK, Sdcard_write_task, 2000,  12, "sdwrite", 0 },
    { SHELL_TASK,        Shell_task,        2000,  11,   "shell", 0 },
    { SDCARD_TASK,       Sdcard_task,       2000,  10,  "sdcard", 0 },
    { INIT_TASK,         Init_task,         1000,   9,    "init", MQX_AUTO_START_TASK },
    { 0, 0, 0, 0, 0, 0 }
};

const SHELL_COMMAND_STRUCT Shell_commands[] = {
    { "cd",        Shell_cd },
    { "del",       Shell_del },
    { "dir",       Shell_dir },
    { "exit",      Shell_exit },
    { "help",      Shell_help },
    { "mkdir",     Shell_mkdir },
    { "ren",       Shell_rename },
    { "rmdir",     Shell_rmdir },
    { "play",      Shell_play },
    { "record",    Shell_record},
    { "?",         Shell_command_list },
    { NULL,        NULL }
};

/*TASK*-----------------------------------------------------------------
*
* Function Name  : Shell_task
* Returned Value : void
* Comments       :
*
*END------------------------------------------------------------------*/

void Shell_task
(
    uint32_t temp
)
{
    /* Run the shell on the serial port */
    printf("Audio driver demo application\n");
    Shell(Shell_commands, NULL);
    for(;;)
    {
	printf("Shell exited, restarting...\n");
	Shell(Shell_commands, NULL);
    }

}

/*TASK*-----------------------------------------------------------------
*
* Function Name  : Init_task
* Returned Value : void
* Comments       :
*
*END------------------------------------------------------------------*/
void Init_task
(
    uint32_t temp
)
{

    MQX_TICK_STRUCT time;
    _mqx_int errcode = 0;
    /* Install MQX default unexpected ISR routines */
    _int_install_unexpected_isr();
    /* Setup time */
    printf("Setting up time......................");
    time.TICKS[0] = 0L;
    time.TICKS[1] = 0L;
    time.HW_TICKS = 0;
    _time_set_ticks(&time);
    printf("[OK]\n");

    /* Initialize audio codec */
    printf("Initializing audio codec.............");
    errcode = InitCodec();
    if (errcode != 0)
    {
        printf("[FAIL]\n");
        printf("  Error 0x%X\n", errcode);
    }
    else
    {
        printf("[OK]\n");
    }

    /* Create tasks */
    printf("Creating shell task..................");
    errcode = _task_create(0, SHELL_TASK, 0);
    if (errcode == MQX_NULL_TASK_ID)
    {
        printf("[FAIL]\n");
        printf("  Error 0x%X.\n");
    }
    else
    {
        printf("[OK]\n");
    }
    errcode = _task_create(0, SDCARD_TASK, 0);
    printf("Creating SD card task................");
    if (errcode == MQX_NULL_TASK_ID)
    {
        printf("[FAIL]\n");
        printf("  Error 0x%X.\n");
    }
    else
    {
        printf("[OK]\n");
    }
    printf("\n\n");
    _task_abort(MQX_NULL_TASK_ID);
}

/*TASK*-----------------------------------------------------------------
*
* Function Name  : Sdcard_task
* Returned Value : void
* Comments       :
*
*END------------------------------------------------------------------*/
void Sdcard_task(uint32_t temp)
{
    bool      inserted = TRUE, readonly = FALSE, last = FALSE;
    _mqx_int     error_code;
    _mqx_uint    param;
    MQX_FILE_PTR com_handle = NULL, sdcard_handle = NULL, filesystem_handle = NULL, partition_handle = NULL;
    char         filesystem_name[] = "a:";
    char         partman_name[] = "pm:";
    char         partition_name[] = "pm:1";
#if defined BSP_SDCARD_GPIO_DETECT
    LWGPIO_STRUCT      sd_detect;
#endif
#if defined BSP_SDCARD_GPIO_PROTECT
    LWGPIO_STRUCT      sd_protect;
#endif
#ifdef BSP_SDCARD_GPIO_CS

    LWGPIO_STRUCT          sd_cs;
    SPI_CS_CALLBACK_STRUCT callback;

#endif

    /* Open low level communication device */
    com_handle = fopen(SDCARD_COM_CHANNEL, (void *)(SPI_FLAG_FULL_DUPLEX));

    if (NULL == com_handle)
    {
        printf("Error opening communication handle %s, check your user_config.h.\n", SDCARD_COM_CHANNEL);
        _task_block();
    }

#ifdef BSP_SDCARD_GPIO_CS

    /* Open GPIO file for SPI CS signal emulation */
    error_code = lwgpio_init(&sd_cs, BSP_SDCARD_GPIO_CS, LWGPIO_DIR_OUTPUT, LWGPIO_VALUE_NOCHANGE);
    if (!error_code)
       {
           printf("Initializing GPIO with associated pins failed.\n");
           _task_block();
       }
    lwgpio_set_functionality(&sd_cs,BSP_SDCARD_CS_MUX_GPIO);
    lwgpio_set_attribute(&sd_cs, LWGPIO_ATTR_PULL_UP, LWGPIO_AVAL_ENABLE);
    /* Set CS callback */
    callback.MASK = BSP_SDCARD_SPI_CS;
    callback.CALLBACK = set_CS;
    callback.USERDATA = &sd_cs;
    if (SPI_OK != ioctl(com_handle, IO_IOCTL_SPI_SET_CS_CALLBACK, &callback))
    {
        printf ("Setting CS callback failed.\n");
        _task_block();
    }

#endif

#if defined BSP_SDCARD_GPIO_DETECT
    /* Init GPIO pins for other SD card signals */
    error_code = lwgpio_init(&sd_detect, BSP_SDCARD_GPIO_DETECT, LWGPIO_DIR_INPUT, LWGPIO_VALUE_NOCHANGE);
       if (!error_code)
       {
           printf("Initializing GPIO with sdcard detect pin failed.\n");
           _task_block();
       }
       /*Set detect and protect pins as GPIO Function */
       lwgpio_set_functionality(&sd_detect,BSP_SDCARD_DETECT_MUX_GPIO);
#if defined(BSP_SDCARD_DETECT_ACTIVE_LOW)
       lwgpio_set_attribute(&sd_detect, LWGPIO_ATTR_PULL_DOWN, LWGPIO_AVAL_ENABLE);
#else
       lwgpio_set_attribute(&sd_detect, LWGPIO_ATTR_PULL_UP, LWGPIO_AVAL_ENABLE);
#endif
#endif /* BSP_SDCARD_GPIO_DETECT */

#if defined BSP_SDCARD_GPIO_PROTECT
    /* Init GPIO pins for other SD card signals */
    error_code = lwgpio_init(&sd_protect, BSP_SDCARD_GPIO_PROTECT, LWGPIO_DIR_INPUT, LWGPIO_VALUE_NOCHANGE);
       if (!error_code)
       {
           printf("Initializing GPIO with sdcard protect pin failed.\n");
           _task_block();
       }
       /*Set detect and protect pins as GPIO Function */
       lwgpio_set_functionality(&sd_protect,BSP_SDCARD_PROTECT_MUX_GPIO);
       lwgpio_set_attribute(&sd_protect, LWGPIO_ATTR_PULL_UP, LWGPIO_AVAL_ENABLE);
#endif

    /* Install SD card device */
    error_code = _io_sdcard_install("sdcard:", (void *)&_bsp_sdcard0_init, com_handle);
    if ( error_code != MQX_OK )
    {
        printf("Error installing SD card device (0x%x)\n", error_code);
        _task_block();
    }

    for (;;)
    {

#if defined BSP_SDCARD_GPIO_DETECT
        #ifdef BSP_MPC8308RDB
        /* Set function as GPIO to detect sdcard */
        lwgpio_set_functionality(&sd_detect,BSP_SDCARD_DETECT_MUX_GPIO);
        lwgpio_set_attribute(&sd_detect, LWGPIO_ATTR_PULL_UP, LWGPIO_AVAL_ENABLE);
        #endif
#if defined(BSP_SDCARD_DETECT_ACTIVE_LOW)
        inserted = lwgpio_get_value(&sd_detect);
#else
        inserted = !lwgpio_get_value(&sd_detect);
#endif /* BSP_SDCARD_DETECT_ACTIVE_LOW */
#endif /* BSP_SDCARD_GPIO_DETECT */

#if defined BSP_SDCARD_GPIO_PROTECT
        /* Get value of protect pin */
        readonly = lwgpio_get_value(&sd_protect);
#endif
#ifdef BSP_MPC8308RDB
        /* Set function as SD_CD which indicate that card is present in Present State Register */
        lwgpio_set_functionality(&sd_detect,BSP_SDCARD_DETECT_MUX_SD_CD);
        lwgpio_set_attribute(&sd_detect, LWGPIO_ATTR_PULL_UP, LWGPIO_AVAL_ENABLE);
#endif
        if (last != inserted)
        {
            last = inserted;

            if (inserted)
            {
                _time_delay (200);
                /* Open the device which MFS will be installed on */
                sdcard_handle = fopen("sdcard:", 0);
                if (sdcard_handle == NULL)
                {
                    printf("Unable to open SD card device.\n");
                    continue;
                }

                /* Set read only flag as needed */
                param = 0;
                if (readonly)
                {
                    param = IO_O_RDONLY;
                }
                if (IO_OK != ioctl(sdcard_handle, IO_IOCTL_SET_FLAGS, (char *) &param))
                {
                    printf("Setting device read only failed.\n");
                    continue;
                }

                /* Install partition manager over SD card driver */
                error_code = _io_part_mgr_install(sdcard_handle, partman_name, 0);
                if (error_code != MFS_NO_ERROR)
                {
                    printf("Error installing partition manager: %s\n", MFS_Error_text((uint32_t)error_code));
                    continue;
                }

                /* Open partition */
                partition_handle = fopen(partition_name, NULL);
                if (partition_handle != NULL)
                {
                    printf("Installing MFS over partition...\n");

                    /* Validate partition */
                    error_code = _io_ioctl(partition_handle, IO_IOCTL_VAL_PART, NULL);
                    if (error_code != MFS_NO_ERROR)
                    {
                        printf("Error validating partition: %s\n", MFS_Error_text((uint32_t)error_code));
                        printf("Not installing MFS.\n");
                        continue;
                    }

                    /* Install MFS over partition */
                    error_code = _io_mfs_install(partition_handle, filesystem_name, 0);
                    if (error_code != MFS_NO_ERROR)
                    {
                        printf("Error initializing MFS over partition: %s\n", MFS_Error_text((uint32_t)error_code));
                    }

                } else {

                    printf("Installing MFS over SD card driver...\n");

                    /* Install MFS over SD card driver */
                    error_code = _io_mfs_install(sdcard_handle, filesystem_name, (_file_size)0);
                    if (error_code != MFS_NO_ERROR)
                    {
                        printf("Error initializing MFS: %s\n", MFS_Error_text((uint32_t)error_code));
                    }
                }

                /* Open file system */
                if (error_code == MFS_NO_ERROR) {
                    filesystem_handle = fopen(filesystem_name, NULL);
                    error_code = ferror(filesystem_handle);
                    if (error_code == MFS_NOT_A_DOS_DISK)
                    {
                        printf("NOT A DOS DISK! You must format to continue.\n");
                    }
                    else if (error_code != MFS_NO_ERROR)
                    {
                        printf("Error opening filesystem: %s\n", MFS_Error_text((uint32_t)error_code));
                        continue;
                    }

                    printf ("SD card installed to %s\n", filesystem_name);
                    if (readonly)
                    {
                        printf ("SD card is locked (read only).\n");
                    }
                }
            }
            else
            {
                /* Close the filesystem */
            	if ((filesystem_handle != NULL) && (MQX_OK != fclose(filesystem_handle)))
                {
                    printf("Error closing filesystem.\n");
                }
            	filesystem_handle = NULL;

                /* Uninstall MFS  */
                error_code = _io_dev_uninstall(filesystem_name);
                if (error_code != MFS_NO_ERROR)
                {
                    printf("Error uninstalling filesystem.\n");
                }

                /* Close partition */
                if ((partition_handle != NULL) && (MQX_OK != fclose(partition_handle)))
                {
                    printf("Error closing partition.\n");
                }
                partition_handle = NULL;

                /* Uninstall partition manager  */
                error_code = _io_dev_uninstall(partman_name);
                if (error_code != MFS_NO_ERROR)
                {
                    printf("Error uninstalling partition manager.\n");
                }

                /* Close the SD card device */
                if ((sdcard_handle != NULL) && (MQX_OK != fclose(sdcard_handle)))
                {
                    printf("Unable to close SD card device.\n");
                }
                sdcard_handle = NULL;

                printf ("SD card uninstalled.\n");
            }
        }

        _time_delay (200);
    }
}


/*TASK*-----------------------------------------------------------------
*
* Function Name  : Sdcard_write_task
* Returned Value : void
* Comments       : Task that write recorded data to SD card
*
*END------------------------------------------------------------------*/
void Sdcard_write_task
(
    uint32_t temp
)
{
    SD_WRITE_PARAM_STRUCT* param = (SD_WRITE_PARAM_STRUCT*) temp;
    uint32_t i = 0;
    uint32_t ret = 0;
    for(i = 0; i < param->requests - 1; i++)
    {
        _lwsem_wait(&param->buffer_full);
        ret = fwrite(param->address, param->size, 1, param->file_ptr);
        if(i & 0x1)
        {
            param->address = param->start_address;
        }
        else
        {
            param->address += param->size;
        }
    }
    /* The last block */
    _lwsem_wait(&param->buffer_full);
    ret = fwrite(param->address, param->last_size, 1, param->file_ptr);
    _lwsem_post(&param->sdwrite_sem);
    MQX_UNUSED_ARGUMENT(ret);
}

/* EOF */

