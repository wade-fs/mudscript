inherit ROOM;
void create() {
	set( "short", "$HIG$綠色靈劍$NOR$" );
	set( "object", ([
		"file1"    : "/open/magic-manor/wood/obj/wood-sword",
		"file10"   : "/open/magic-manor/wood/obj/wood-sword",
		"amount2"  : 1,
		"amount7"  : 1,
		"amount1"  : 1,
		"file3"    : "/open/magic-manor/wood/obj/wood-sword",
		"file9"    : "/open/magic-manor/wood/obj/wood-sword",
		"amount9"  : 1,
		"file5"    : "/open/magic-manor/wood/obj/wood-sword",
		"amount10" : 1,
		"amount4"  : 1,
		"file7"    : "/open/magic-manor/wood/obj/wood-sword",
		"file2"    : "/open/magic-manor/wood/obj/wood-sword",
		"amount5"  : 1,
		"amount3"  : 1,
		"file4"    : "/open/magic-manor/wood/obj/wood-sword",
		"amount8"  : 1,
		"file8"    : "/open/magic-manor/wood/obj/wood-sword",
	]) );
	set( "build", 10568 );
	set( "light_up", 1 );
	set( "exits", ([
		"west"      : "/open/clan/ou-cloud-club/room/room478.c",
		"east"      : "/open/clan/ou-cloud-club/room/room429",
	]) );
	set( "long", @LONG
$HIG$靈劍綠色靈劍綠色靈劍綠色靈劍綠色靈劍綠色靈劍
$HIG$綠色靈劍綠色靈劍綠色靈劍綠色靈劍綠色靈劍綠色靈劍$NOR$
$HIG$綠色靈劍綠色靈劍綠色靈劍綠色靈劍綠色靈劍綠色靈劍$NOR$
$HIG$綠色靈劍綠色靈劍綠色靈劍綠色靈劍綠色靈劍綠色靈劍$NOR$
$HIG$綠色靈劍綠色靈劍綠色靈劍綠色靈劍綠色靈劍綠色靈劍$NOR$
$HIG$綠色靈劍綠色靈劍綠色靈劍綠色靈劍綠色靈劍綠色靈劍$NOR$

LONG);
	setup();
	replace_program(ROOM);
}
