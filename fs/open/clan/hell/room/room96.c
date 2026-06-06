inherit ROOM;
void create() {
	set( "short", "$HIY$$HBRED$重搖滾實驗$NOR$" );
	set( "object", ([
		"file1"    : "/open/mon/obj/ghost-claw",
		"file6"    : "/open/mon/obj/ghost-claw",
		"amount7"  : 1,
		"amount10" : 1,
		"file10"   : "/open/mon/obj/ghost-claw",
		"file7"    : "/open/mon/obj/ghost-claw",
		"file3"    : "/open/mon/obj/ghost-claw",
		"amount6"  : 1,
		"amount2"  : 1,
		"file2"    : "/open/mon/obj/ghost-claw",
		"amount4"  : 1,
		"file5"    : "/open/mon/obj/ghost-claw",
		"amount5"  : 1,
		"amount8"  : 1,
		"amount9"  : 1,
		"amount1"  : 1,
		"file9"    : "/open/mon/obj/ghost-claw",
		"file4"    : "/open/mon/obj/ghost-claw",
		"file8"    : "/open/mon/obj/ghost-claw",
		"amount3"  : 1,
	]) );
	set( "owner", "blur" );
	set( "exits", ([
		"west"      : "/open/clan/hell/room/room47.c",
		"east"      : "/open/clan/hell/room/room43",
		"south"     : "/open/clan/hell/room/room93.c",
	]) );
	set( "light_up", 1 );
	set( "build", 10395 );
	set( "long", @LONG
$WHT$      HUH-HUH  HUH-HUH  HUH-HUH  
                HUH-HUH  HUH-HUH  HUH-HUH  
$HIM$                   huh
$WHT$  HUH-HUH  HUH-HUH  HUH-HUH  
$WHT$             HUH-HUH  HUH-HUH  HUH-HUH  
$WHT$                     HUH-HUH  HUH-HUH  HUH-HUH  
$WHT$               HUH-HUH  HUH-HUH  HUH-HUH  
$HIM$          huh
$WHT$ HUH-HUH  HUH-HUH  HUH-HUH  
$WHT$  HUH-HUH  HUH-HUH  HUH-HUH  
$WHT$       HUH-HUH  HUH-HUH  HUH-HUH  

$HIC$$HBRED$Jose'y Hetor ????      $HIG$凸 $HIW$-,-$NOR$

LONG);
	setup();
	replace_program(ROOM);
}
