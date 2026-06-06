inherit ROOM;
void create() {
	set( "short", "種族及國家2" );
	set( "owner", "dfyw" );
	set( "object", ([
		"file4"    : "/obj/gift/unknowdan",
		"file2"    : "/obj/gift/unknowdan",
		"file3"    : "/obj/gift/unknowdan",
		"amount8"  : 1,
		"file1"    : "/obj/gift/unknowdan",
		"file10"   : "/obj/gift/unknowdan",
		"amount9"  : 1,
		"file5"    : "/obj/gift/unknowdan",
		"amount2"  : 1,
		"file9"    : "/obj/gift/unknowdan",
		"file6"    : "/obj/gift/unknowdan",
		"amount7"  : 1,
		"file7"    : "/obj/gift/unknowdan",
		"amount6"  : 1,
		"amount1"  : 1,
		"file8"    : "/obj/gift/unknowdan",
		"amount5"  : 1,
		"amount4"  : 1,
		"amount10" : 1,
		"amount3"  : 1,
	]) );
	set( "build", 10019 );
	set( "light_up", 1 );
	set( "exits", ([
		"south"     : "/open/clan/13_luck/room/room440",
	]) );
	set( "long", @LONG

妖精
妖精是大陸上長壽的種族，過著自然且與世無爭的生活。理性的面對生命中的一
切，可以說是大陸上最有智慧的種族。

法魯西翁
擁有高度魔法文明的西方大國，國家意識鬆散，無排外傾向，能接納外族成員定
居。為應付人類王國的侵略，在邊界建造了巨潼城要塞。妖精族普遍，不把人類
的野心當成一回事。現任領導者為妖精王葛雷芬特。

LONG);
	setup();
	replace_program(ROOM);
}
