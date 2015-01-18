source names.tcl

proc doit {} {
   # RESET + Hold CPU reset after release
   set mdmApControl [rcreg  $::MDM_AP_Control]
   set mdmApControl [expr $mdmApControl|$::MDM_AP_C_CORE_HOLD|$::MDM_AP_C_SYSTEM_RESET]
   wcreg $::MDM_AP_Control $mdmApControl
   after 50
   # Release reset (core stays reset)
   set mdmApControl [expr $mdmApControl & ~$::MDM_AP_C_SYSTEM_RESET]
   wcreg $::MDM_AP_Control $mdmApControl
   after 50
   
   wl $::DEMCR [expr $::DEMCR_VC_CORERESET|$::DEMCR_VC_HARDERR]
   wl $::DHCSR [expr $::DHCSR_DBGKEY|$::DHCSR_C_HALT|$::DHCSR_C_DEBUGEN]

   # Release core reset
   set mdmApControl [expr $mdmApControl & ~$::MDM_AP_C_CORE_HOLD]
   wcreg $::MDM_AP_Control $mdmApControl
   after 50

   gs
   gs
}

proc doit2 {} {
   # hold in RESET
   pinSet rst=0
   after 50
   
   wl $::DEMCR [expr $::DEMCR_VC_CORERESET|$::DEMCR_VC_HARDERR]
   wl $::DHCSR [expr $::DHCSR_DBGKEY|$::DHCSR_C_HALT|$::DHCSR_C_DEBUGEN]

   pinSet
   after 50
   
   gs
   gs
return   
}

proc doit3 {} {

   ;# Reset device
   wl $::DEMCR [expr $::DEMCR_VC_CORERESET|$::DEMCR_VC_HARDERR]
   wl $::DHCSR [expr $::DHCSR_DBGKEY|$::DHCSR_C_HALT|$::DHCSR_C_DEBUGEN]
   wl $::AIRCR [expr $::AIRCR_VECTKEY|$::AIRCR_SYSRESETREQ]
   
   gs
   gs
return   
}
