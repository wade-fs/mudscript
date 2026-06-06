inherit ROOM;
void create() {
	set( "short", "臨綜合醫院" );
	set( "owner", "wecs" );
	set( "light_up", 1 );
	set( "object", ([
		"amount6"  : 1,
		"file1"    : "/open/magic-manor/ghost/obj/five-turn-ball",
		"file8"    : "/open/marksman/obj/dragon_bow",
		"amount1"  : 1,
		"file2"    : "/open/magic-manor/ghost/obj/five-turn-ball",
		"amount4"  : 1,
		"amount5"  : 1,
		"file5"    : "/open/magic-manor/ghost/obj/five-turn-ball",
		"file6"    : "/open/magic-manor/ghost/obj/five-turn-ball",
		"amount2"  : 1,
		"file4"    : "/open/magic-manor/ghost/obj/five-turn-ball",
		"amount8"  : 1,
	]) );
	set( "build", 12409 );
	set( "exits", ([
		"south"     : "/open/clan/ou-cloud-club/room/room536",
	]) );
	set( "long", @LONG

臨臨臨臨臨臨臨臨臨臨臨臨臨臨臨臨臨臨
兵兵兵兵兵兵兵兵兵兵兵兵兵兵兵兵兵兵
鬥鬥鬥鬥鬥鬥鬥鬥鬥鬥鬥鬥鬥鬥鬥鬥鬥鬥
者者者者者者者者者者者者者者者者者者
皆皆皆皆皆皆皆皆皆皆皆皆皆皆皆皆皆皆
陣陣陣陣陣陣陣陣陣陣陣陣陣陣陣陣陣陣
列列列列列列列列列列列列列列列列列列
在在在在在在在在在在在在在在在在在在
前前前前前前前前前前前前前前前前前前
LONG);
	setup();
	replace_program(ROOM);
}
