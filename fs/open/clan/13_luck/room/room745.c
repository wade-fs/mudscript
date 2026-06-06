inherit ROOM;
void create() {
	set( "short", "LEON丹藥庫" );
	set( "object", ([
		"amount9"  : 3,
		"amount4"  : 1,
		"file10"   : "/open/ghost-hole/obj/eq/ghost-armband",
		"file6"    : "/obj/gift/shenliwan",
		"amount10" : 1,
		"file9"    : "/open/mon/obj/mon-pill",
		"file3"    : "/obj/stone/suipian",
		"amount8"  : 2,
		"amount5"  : 1,
		"file1"    : "/obj/stone/powder",
		"amount6"  : 1,
		"amount7"  : 2,
		"file2"    : "/open/mogi/dragon/obj/dragon-head",
		"amount2"  : 1,
		"file4"    : "/open/mogi/castle/obj/black-ghost-head",
		"amount1"  : 368,
		"file7"    : "/obj/stone/jiao",
		"file5"    : "/open/mogi/castle/obj/white-ghost-head",
		"file8"    : "/open/mon/obj/thousand-nectar",
		"amount3"  : 19,
	]) );
	set( "owner", "adeyzit" );
	set( "build", 10040 );
	set( "exits", ([
		"south"     : "/open/clan/13_luck/room/room748",
		"enter"     : "/open/clan/13_luck/room/room582",
		"west"      : "/open/clan/13_luck/room/room733.c",
		"north"     : "/open/clan/13_luck/room/room746.c",
		"east"      : "/open/clan/13_luck/room/room747.c",
	]) );
	set( "long", @LONG
一進來就聞到濃濃的藥味 不用懷疑 這就是LEON的丹藥庫
不過仔細一看 這只是丹藥庫的一部份 後面還有許多間存
放各種不同丹藥的丹藥庫 在這邊似乎只能找到生生造化丹
想不到多年來都未曾見過的生生造化丹居然會在這個地方出
現 而且還是這麼大量的生生造化丹 讓你感到嘆為觀止 你心
中想 莫非這些是假冒的丹藥?

LONG);
	setup();
	replace_program(ROOM);
}
