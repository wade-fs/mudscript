inherit ROOM;
void create() {
	set( "short", "$HIG$綠色靈劍$NOR$" );
	set( "object", ([
		"amount7"  : 1,
		"file1"    : "/open/magic-manor/wood/obj/wood-sword",
		"amount1"  : 1,
		"file9"    : "/open/magic-manor/wood/obj/wood-sword",
		"amount2"  : 1,
		"amount9"  : 1,
		"file4"    : "/open/magic-manor/wood/obj/wood-sword",
		"file7"    : "/open/magic-manor/wood/obj/wood-sword",
		"file2"    : "/open/magic-manor/wood/obj/wood-sword",
		"amount4"  : 1,
	]) );
	set( "owner", "cowboy" );
	set( "build", 12225 );
	set( "light_up", 1 );
	set( "exits", ([
		"east"      : "/open/clan/ou-cloud-club/room/room696",
		"west"      : "/open/clan/ou-cloud-club/room/room694.c",
	]) );
	set( "long", @LONG

$HIG$綠色靈劍綠色靈劍綠色靈劍綠色靈劍綠色靈劍$NOR$
$HIG$綠色靈劍綠色靈劍綠色靈劍綠色靈劍綠色靈劍$NOR$
$HIG$綠色靈劍綠色靈劍綠色靈劍綠色靈劍綠色靈劍$NOR$
$HIG$綠色靈劍綠色靈劍綠色靈劍綠色靈劍綠色靈劍$NOR$

LONG);
	setup();
	replace_program(ROOM);
}
