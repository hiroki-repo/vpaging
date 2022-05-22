#uselib "vpaging.dll"
#cfunc gettypemask "gettypemask"
#cfunc m68kgetnfc "m68kgetnfc"
#func m68knfccallback "m68knfccallback" int
#func m68ksetcb4getpriv "m68ksetcb4getpriv" int
#cfunc memaccessmod "memaccessmod" int,int,int
#func memaccessptrset "memaccessptrset" int,int
#func setmemaccess4nonmac "setmemaccess4nonmac" int
#func setpagehandler "setpagehandler" int
#func settypemask "settypemask" int
