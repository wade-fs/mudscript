inherit ROOM;
void create() {
	set( "short", "$HIG$硬的劍$NOR$" );
	set( "owner", "robo" );
	set( "object", ([
		"amount7"  : 1,
		"amount8"  : 1,
		"amount2"  : 1,
		"file2"    : "/open/magic-manor/wood/obj/wood-sword",
		"file8"    : "/open/magic-manor/wood/obj/wood-sword",
		"file7"    : "/open/magic-manor/wood/obj/wood-sword",
	]) );
	set( "build", 10062 );
	set( "light_up", 1 );
	set( "exits", ([
		"east"      : "/open/clan/dark-forest/room/room29",
	]) );
	set( "long", @LONG

劍劍劍劍劍　　霸霸霸霸霸　　天天天天天　　下下下下下
劍劍劍劍劍　　霸霸霸霸霸　　天天天天天　　下下下下下
劍劍劍劍劍　　霸霸霸霸霸　　天天天天天　　下下下下下
劍劍劍劍劍　　霸霸霸霸霸　　天天天天天　　下下下下下
劍劍劍劍劍　　霸霸霸霸霸　　天天天天天　　下下下下下

LONG);
	setup();
	replace_program(ROOM);
}
