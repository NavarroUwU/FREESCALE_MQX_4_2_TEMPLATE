@REM This batch file has been generated by the IAR Embedded Workbench
@REM C-SPY Debugger, as an aid to preparing a command line for running
@REM the cspybat command line utility using the appropriate settings.
@REM
@REM Note that this file is generated every time a new debug session
@REM is initialized, so you may want to move or rename the file before
@REM making changes.
@REM
@REM You can launch cspybat by typing the name of this batch file followed
@REM by the name of the debug file (usually an ELF/DWARF or UBROF file).
@REM
@REM Read about available command line parameters in the C-SPY Debugging
@REM Guide. Hints about additional command line parameters that may be
@REM useful in specific cases:
@REM   --download_only   Downloads a code image without starting a debug
@REM                     session afterwards.
@REM   --silent          Omits the sign-on message.
@REM   --timeout         Limits the maximum allowed execution time.
@REM 


"C:\Program Files (x86)\IAR Systems\Embedded Workbench 7.0\common\bin\cspybat" "C:\Program Files (x86)\IAR Systems\Embedded Workbench 7.0\arm\bin\armproc.dll" "C:\Program Files (x86)\IAR Systems\Embedded Workbench 7.0\arm\bin\armjlink.dll"  %1 --plugin "C:\Program Files (x86)\IAR Systems\Embedded Workbench 7.0\arm\bin\armbat.dll" --macro "C:\Users\b50859\git-wc\mqx-repo\generator_new\gmodules\mqx_project\templates\iar\app_svf522revb_a5\svf522revb_a5_ddr.mac" --backend -B "--endian=little" "--cpu=Cortex-A5" "--fpu=VFPv4Neon" "-p" "C:\Program Files (x86)\IAR Systems\Embedded Workbench 7.0\arm\CONFIG\debugger\Freescale\SVF522R3K1CMK4_A5.ddf" "--semihosting=none" "--device=SVF522R3K1CMK4_A5" "--jlink_device_select=0" "--drv_communication=USB0" "--jlink_speed=auto" "--jlink_initial_speed=32" "--drv_catch_exceptions=0x000" "--jlink_reset_strategy=0,5" 


