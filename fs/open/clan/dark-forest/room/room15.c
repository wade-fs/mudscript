inherit ROOM;
void create() {
	set( "short", "護城樹梢" );
	set( "object", ([
		"file4"    : "/open/magic-manor/soil/obj/soil-claw",
		"amount9"  : 1,
		"amount3"  : 1,
		"file8"    : "/open/magic-manor/gold/obj/golden-blade",
		"amount5"  : 1,
		"file6"    : "/open/magic-manor/soil/obj/soil-claw",
		"file1"    : "/open/magic-manor/soil/obj/soil-claw",
		"amount1"  : 1,
		"amount4"  : 1,
		"file10"   : "/open/magic-manor/fire/obj/fire-fan",
		"file3"    : "/open/magic-manor/soil/obj/soil-claw",
		"file7"    : "/open/magic-manor/wood/obj/wood-sword",
		"amount2"  : 1,
		"file5"    : "/open/magic-manor/water/obj/water-ribbon",
		"file2"    : "/open/magic-manor/soil/obj/soil-claw",
		"file9"    : "/open/magic-manor/fire/obj/fire-fan",
		"amount10" : 1,
		"amount8"  : 1,
		"amount7"  : 1,
		"amount6"  : 1,
	]) );
	set( "build", 10178 );
	set( "exits", ([
		"shoot"     : "/open/clan/dark-forest/room/room11",
		"north"     : "/open/clan/dark-forest/room/room14.c",
	]) );
	set( "long", @LONG
你正走在由樹群的枝葉交錯而成的走道上，眼尖的你發現
到除了一般來往的精靈之外，有一群身穿淡藍色盔甲，手持白
楊長弓的精靈護衛正透過枝葉間的空隙監視下方的幽暗小徑，
以防止對精靈之森懷有惡意的人們接近或是入侵。

LONG);
	setup();
	replace_program(ROOM);
}
