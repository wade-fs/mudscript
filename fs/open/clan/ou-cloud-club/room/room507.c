inherit ROOM;
void create() {
	set( "short", "魔法學徒-凱特" );
	set( "light_up", 1 );
	set( "object", ([
		"file4"    : "/obj/gift/unknowdan",
		"amount4"  : 1,
		"amount1"  : 1,
		"file7"    : "/obj/gift/unknowdan",
		"file10"   : "/obj/gift/unknowdan",
		"amount9"  : 1,
		"amount8"  : 1,
		"file3"    : "/obj/gift/unknowdan",
		"amount6"  : 1,
		"file1"    : "/obj/gift/unknowdan",
		"file5"    : "/obj/gift/unknowdan",
		"amount10" : 1,
		"file6"    : "/obj/gift/unknowdan",
		"amount2"  : 1,
		"amount7"  : 1,
		"file9"    : "/obj/gift/unknowdan",
		"file2"    : "/obj/gift/unknowdan",
		"amount5"  : 1,
		"amount3"  : 1,
		"file8"    : "/obj/gift/unknowdan",
	]) );
	set( "build", 10135 );
	set( "owner", "ctx" );
	set( "exits", ([
		"south"     : "/open/clan/ou-cloud-club/room/room506",
	]) );
	set( "long", @LONG
魔法學徒凱特, 於魔法學徒試練中和恩萊科一行人相遇而成
為同伴,出身於騎士家族,再試練中成為一個相當利害的魔法騎士
而本人也愛慕者索菲恩王國的公主, 但是因為了解到公主所背負
者王國的命運及興衰,所以並不敢表明心跡,而是守護在公主的背
後,默默者支持的公主的決定。

LONG);
	setup();
	replace_program(ROOM);
}
