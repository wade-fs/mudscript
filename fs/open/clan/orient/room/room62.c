inherit ROOM;
void create() {
	set( "short", "$HIG$= 綠色靈劍 =$NOR$" );
	set( "owner", "fivewp" );
	set( "object", ([
		"amount5"  : 1,
		"file1"    : "/open/magic-manor/wood/obj/wood-sword",
		"file7"    : "/open/magic-manor/wood/obj/wood-sword",
		"amount7"  : 1,
		"amount6"  : 1,
		"file2"    : "/open/magic-manor/wood/obj/wood-sword",
		"amount9"  : 1,
		"amount1"  : 1,
		"amount3"  : 1,
		"file3"    : "/open/magic-manor/wood/obj/wood-sword",
		"amount8"  : 1,
		"amount2"  : 1,
		"file9"    : "/open/magic-manor/wood/obj/wood-sword",
		"file8"    : "/open/magic-manor/wood/obj/wood-sword",
		"amount10" : 1,
		"file6"    : "/open/magic-manor/wood/obj/wood-sword",
		"file5"    : "/open/magic-manor/wood/obj/wood-sword",
		"file10"   : "/open/magic-manor/wood/obj/wood-sword",
	]) );
	set( "build", 10031 );
	set( "exits", ([
		"west"      : "/open/clan/orient/room/room63.c",
		"east"      : "/open/clan/orient/room/room61",
	]) );
	set( "long", @LONG
$HIG$綠色靈劍綠色靈劍綠色靈劍綠色靈劍綠色靈劍綠色靈劍綠色靈劍
    綠色靈劍綠色靈劍綠色靈劍綠色靈劍綠色靈劍綠色靈劍綠色靈劍
    綠色靈劍綠色靈劍綠色靈劍綠色靈劍綠色靈劍綠色靈劍綠色靈劍
    綠色靈劍綠色靈劍綠色靈劍綠色靈劍綠色靈劍綠色靈劍綠色靈劍$NOR$
LONG);
	setup();
	replace_program(ROOM);
}
