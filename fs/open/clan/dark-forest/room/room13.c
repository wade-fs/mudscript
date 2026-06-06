inherit ROOM;
void create() {
	set( "short", "護城樹梢" );
	set( "owner", "really" );
	set( "object", ([
		"file6"    : "/obj/gift/lingzhi",
		"file10"   : "/open/magic-manor/wood/obj/wood-sword",
		"amount9"  : 1,
		"file3"    : "/open/magic-manor/gold/obj/golden-blade",
		"amount1"  : 1,
		"amount6"  : 1,
		"amount8"  : 1,
		"amount5"  : 1,
		"file4"    : "/open/magic-manor/gold/obj/golden-blade",
		"amount2"  : 1,
		"file2"    : "/open/magic-manor/gold/obj/golden-blade",
		"amount4"  : 1,
		"amount7"  : 1,
		"file8"    : "/open/magic-manor/wood/obj/wood-sword",
		"amount3"  : 1,
		"file9"    : "/open/magic-manor/wood/obj/wood-sword",
		"file7"    : "/open/magic-manor/wood/obj/wood-sword",
		"file5"    : "/open/magic-manor/gold/obj/golden-blade",
		"amount10" : 1,
		"file1"    : "/open/magic-manor/gold/obj/golden-blade",
	]) );
	set( "build", 11185 );
	set( "exits", ([
		"shoot"     : "/open/clan/dark-forest/room/room9.c",
		"north"     : "/open/clan/dark-forest/room/room12.c",
		"southeast" : "/open/clan/dark-forest/room/room14",
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
