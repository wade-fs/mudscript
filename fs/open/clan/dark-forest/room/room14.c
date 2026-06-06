inherit ROOM;
void create() {
	set( "short", "護城樹梢" );
	set( "owner", "really" );
	set( "object", ([
		"file4"    : "/open/magic-manor/fire/obj/fire-fan",
		"amount9"  : 1,
		"amount3"  : 1,
		"file8"    : "/open/magic-manor/wood/obj/wood-sword",
		"amount5"  : 1,
		"file6"    : "/open/magic-manor/fire/obj/fire-fan",
		"file1"    : "/open/magic-manor/fire/obj/fire-fan",
		"amount1"  : 1,
		"amount4"  : 1,
		"file10"   : "/open/magic-manor/soil/obj/soil-claw",
		"file3"    : "/open/magic-manor/fire/obj/fire-fan",
		"file7"    : "/open/magic-manor/wood/obj/wood-sword",
		"amount2"  : 1,
		"file5"    : "/open/magic-manor/fire/obj/fire-fan",
		"file2"    : "/open/magic-manor/fire/obj/fire-fan",
		"file9"    : "/open/magic-manor/soil/obj/soil-claw",
		"amount10" : 1,
		"amount8"  : 1,
		"amount7"  : 1,
		"amount6"  : 1,
	]) );
	set( "build", 10084 );
	set( "exits", ([
		"northwest" : "/open/clan/dark-forest/room/room13",
		"south"     : "/open/clan/dark-forest/room/room15.c",
		"shoot"     : "/open/clan/dark-forest/room/room10.c",
	]) );
	set( "long", @LONG
你正走在由樹群的枝葉交錯而成的走道上，眼尖的你發現
到除了一般來往的精靈之外，有一群身穿淡藍色盔甲，手持白
楊長弓的精靈護衛正透過枝葉間的空隙監視下方的幽暗小徑，
以防止對精靈之森懷有惡意的人們接近或是入侵。

  $HIG$精靈護衛長$NOR$ 提爾(Till)
LONG);
	setup();
	replace_program(ROOM);
}
