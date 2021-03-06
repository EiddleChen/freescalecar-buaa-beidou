;#<![CDATA[
;#
;######################################################################################
;#  This file defines the following flash functions
;#  
;#  massEraseTarget - Entirely erases the target.
;#                    The target should be left in an unsecured state.
;#
;#  isUnsecure - indicates if the target is secured in some fashion (read/write protected)
;#               Returns TCL_OK if NOT secured
;#
;#  initFlash - initialises the target for flash programing (if needed)
;#
;#  initTarget - initialises the target for general use
;#
;#  In addition the script may do any once-only initialisation such as setting global symbols
;#  when initially loaded into the TCL environment.
;#

;#####################################################################################
;#  History
;#
;#  V4.10.4 - Changed return code handling
;# 

;######################################################################################
;#
;#
proc loadSymbols {} {
   # LittleEndian format for writing numbers to memory
   setbytesex  littleEndian
   defaultMemorySpace X

   set ::DSC_FSEC_SEC_MASK     0x03   ;# Security bits
   set ::DSC_FSEC_SEC_UNSEC    0x02   ;# Security bits for unsecured device
   set ::DSC_FSEC_SEC_KEYEN    0x80   ;# Backdoor Key enable
   set ::DSC_FSEC_SEC_FNORED   0x40   ;# Vector redirection disable
   set ::DSC_FSEC_UNSEC_VALUE  0xFFFE ;# Value to use when unsecuring (0xFF:NVSEC value)
      
;#   set ::OCCS_OSCTL            x:0xF2D5
   
   set ::HFM_FCLKD             x:0xF400
   set ::HFM_CR                x:0xF401
   set ::HFM_SECH              x:0xF403
   set ::HFM_SECL              x:0xF404
   set ::HFM_PROT              x:0xF410
   set ::HFM_PROTB             x:0xF411
   set ::HFM_USTAT             x:0xF413
   set ::HFM_CMD               x:0xF414
   set ::HFM_OPT0              x:0xF41A
   set ::HFM_OPT1              x:0xF41B
   set ::HFM_OPT2              x:0xF41C

   set ::HFM_USTAT_CBEIF       0x80
   set ::HFM_USTAT_CCIF        0x40
   set ::HFM_USTAT_PVIOL       0x20
   set ::HFM_USTAT_ACCERR      0x10
   set ::HFM_USTAT_BLANK       0x04

   set ::HFM_CMD_ERASE_VER     0x05
   set ::HFM_CMD_WORD_PROG     0x20
   set ::HFM_CMD_SECTOR_ERASE  0x40
   set ::HFM_CMD_MASS_ERASE    0x41

   set ::DSC_PRDIV8            0x40
     
   set ::BUS_FREQUENCY         4000
   
   return
}

;######################################################################################
;#
;#
proc initTarget { args } {
   ;#  puts "initTarget {}"
   return
     
   ;# Trim the clock from internal value
   set clockTrim [rw $::HFM_OPT1] 
   set osctl     [rw $::OCCS_OSCTL] 
   set osctl     [expr ($osctl & 0xFFFFFC00) | ($clockTrim & 0x000003FF)] 
   ww $::OCCS_OSCTL $osctl
   
   return
}

;######################################################################################
;#
;#  busFrequency - Target bus busFrequency in kHz
;#
proc initFlash { busFrequency } {
   ;#  puts "initFlash {}"
   
   set ::BUS_FREQUENCY $busFrequency

   ;# Set up Flash
   set cfmclkd [calculateFlashDivider $busFrequency]
   ;# set cfmclkd 10 ;# Fixed value based on value used by Codewarrior 
   ww $::HFM_FCLKD $cfmclkd   ;# Flash divider
   ww $::HFM_CR    0x0001     ;# select flash bank 1 => Data
   ww $::HFM_PROT  0x0000     ;# unprotect Flash
   ww $::HFM_CR    0x0000     ;# select flash bank 0 => Program/Boot
   ww $::HFM_PROT  0x0000     ;# unprotect Flash
   ww $::HFM_PROTB 0x0000
   
   return
}

;######################################################################################
;#
;#  busFrequency - Target bus busFrequency in kHz
;#
proc calculateFlashDivider { busFrequency } {
;# NOTES:
;# According to data sheets the Flash uses the sysclock
;#
;# This code assumes that busFrequency = sysclock = oscclk/2
;#
   ;#  puts "calculateFlashDivider {}"
   if { [expr $busFrequency < 1000] } {
      error "Clock too low for flash programming"
   }
   set sysclk [expr 2*$busFrequency]
   if { [expr $sysclk > 12800] } {
      set cfmclkd $::DSC_PRDIV8 
      set inFrequency [expr $sysclk/8]
   } else {
      set cfmclkd 0
      set inFrequency $sysclk 
   }
   set minPeriod [expr (1/200.0)]
   set cfmclkd [expr $cfmclkd + round(floor(($inFrequency*$minPeriod)))] 
   set flashClk [expr $inFrequency / (($cfmclkd&0x3F)+1)]
   ;#  puts "inFrequency = $inFrequency cfmclkd = $cfmclkd, flashClk = $flashClk"
   if { [expr ($flashClk<150)] } {
      error "Not possible to find suitable flash clock divider"
   }      
   return $cfmclkd
}

;######################################################################################
;#  Target is erased & unsecured
proc massEraseTarget { } {
   error "Mass erase is not supported"
   
   return
}

;######################################################################################
;#
proc isUnsecure { } {
   return
   ;#  puts "Checking if unsecured"
   set securityValue [rb $::DSC_FSEC]

   if [ expr ( $securityValue & $::DSC_FSEC_SEC_MASK ) != $::DSC_FSEC_SEC_UNSEC ] {
      error "Target is secured"
   }
   
   return
}

;######################################################################################
;# Actions on initial load
;#
loadSymbols

;#]]>