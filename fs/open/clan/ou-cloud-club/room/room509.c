inherit ROOM;
void create() {
	set( "short", "魔法學徒-傑瑞" );
	set( "light_up", 1 );
	set( "object", ([
		"file3"    : "/obj/gift/xisuidan",
		"amount2"  : 1,
		"file7"    : "/obj/gift/xisuidan",
		"amount7"  : 1,
		"amount1"  : 1,
		"file9"    : "/obj/gift/xisuidan",
		"amount3"  : 1,
		"file5"    : "/obj/gift/xisuidan",
		"amount8"  : 1,
		"file1"    : "/obj/gift/xisuidan",
		"file4"    : "/obj/gift/xisuidan",
		"file8"    : "/obj/gift/xisuidan",
		"amount9"  : 1,
		"amount5"  : 1,
		"amount4"  : 1,
		"amount6"  : 1,
		"file6"    : "/obj/gift/xisuidan",
		"amount10" : 1,
		"file10"   : "/obj/gift/xisuidan",
		"file2"    : "/obj/gift/xisuidan",
	]) );
	set( "build", 10098 );
	set( "owner", "ctx" );
	set( "exits", ([
		"west"      : "/open/clan/ou-cloud-club/room/room506",
	]) );
	set( "long", @LONG
魔法學徒傑瑞, 商人之子,一開始是4位魔法學徒中實力最強
的, 不過在試練中因為商人的本性反道使得傑瑞沒有學到什麼魔
法,不過也因為商人的本性,使得到最後能夠知人善任的來實現恩
萊科的理想,也算是彌補了到最後有者4人中最弱的實力。

LONG);
	setup();
	replace_program(ROOM);
}
