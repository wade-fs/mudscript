 inherit ROOM;

void create()
{
        seteuid(getuid());
	set( "short", "$HIW$逍遙聖境$NOR$" );
	set( "object", ([
		"file2"    : "/open/magic-manor/fire/obj/fire-fan",
		"file8"    : "/open/magic-manor/fire/obj/fire-fan",
		"file1"    : "/open/magic-manor/fire/obj/fire-fan",
		"amount1"  : 1,
		"file9"    : "/open/magic-manor/fire/obj/fire-fan",
		"amount4"  : 1,
		"file4"    : "/open/magic-manor/fire/obj/fire-fan",
		"file3"    : "/open/magic-manor/fire/obj/fire-fan",
		"amount9"  : 1,
		"amount6"  : 1,
		"file10"   : "/open/magic-manor/fire/obj/fire-fan",
		"file6"    : "/open/magic-manor/fire/obj/fire-fan",
		"amount7"  : 1,
		"amount10" : 1,
		"amount2"  : 1,
		"file7"    : "/open/magic-manor/fire/obj/fire-fan",
		"file5"    : "/open/magic-manor/fire/obj/fire-fan",
		"amount3"  : 1,
		"amount8"  : 1,
		"amount5"  : 1,
	]) );
	set( "build", 11025 );
	set( "exits", ([
		"east"      : "/open/clan/free-zone/room/room3.c",
		"south"     : "/open/clan/free-zone/room/room9.c",
		"west"      : "/open/clan/free-zone/room/room4.c",
		"north"     : "/open/clan/free-zone/room/room10.c",
		"up"        : "/open/clan/free-zone/room/room2.c",
		"down"      : "/open/clan/free-zone/room/room19.c",
	]) );
	set( "no_transmit", 1 );
	set( "long", @LONG
$HIC$
               ,;;                           ,;;;;;;;;       
               ;;;;  ;;                    ;;;;; ;;;;;;     
    ,;;;       ;;;; ;;;;,                ;;;;;   ;;;;;;      
    ;;;;; ,;;;; ;;;;;;;;;        ,;;;;;;;;;;;   ;;;;;;        
     ;;;;  ;;;; ;;;;;;;           ;;;;;;;;;;;,,;;;;;         
      ;;;   ;;; ;;;;;;             ;;;;;;;;;;;;;;           
      ;;;   ;;;;;;;;;;;                  ;;;;;;;;;;;;,      
  ,;;;;;;;  ;;;;    ;;;          ,;;;;;; ;;;;;;;;;;;;;      
 ,;;;;;;;;  ;;;;;;;;;;;         ;;;;;;;;;;;;;  ;;;;;;;;;,   
    ;;;;    ;;;;;;;;;;;            ;;;; ;;;;;;;;;;;;;;;;;   
    ;;;;    ;;;;    ;;;            ;;;; ;;;;;;;;;;  ;;;     
     ;;;;   ;;;;;;;;;;;            ;;;;   ;;;  ;;;  ;;;      
      ;;;  ;;;;;;;;;;;;             ;;;   ;;;;;;;;;;;;;     
 ,;;;;;;;; ;;;   ,;;;;;        ,;;;;;;;; ;;;;;;;;;  ;;;     
 ;;;;;;;;;;;;;;;  ;;;;         ;;;;;;;;;;;;;;                
  ;;;    ;;;;;;;;;;;;;;;;;;;;,          ,;;;;;;;;;;;;;;;;;;, 
              ;;;;;;;;;;;;;;;               ;;;;;;;;;;;;;;;  
                 ;;;;;;;;                      ;;;;;;;;;    
                     ,,,                            ,,, 
$NOR$

LONG);
	set( "no_clean_up", 0 );
	setup();
	call_other( "/obj/board/free-zone_b", "???" );
	
	}
