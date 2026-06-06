inherit ROOM;
void create() {
	set( "short", "010-Diamond中心大樓" );
	set( "object", ([
		"amount5"  : 1,
		"amount1"  : 1,
		"file10"   : "/obj/gift/unknowdan",
		"file7"    : "/obj/gift/unknowdan",
		"file8"    : "/obj/gift/unknowdan",
		"file4"    : "/obj/gift/unknowdan",
		"amount7"  : 1,
		"amount3"  : 1,
		"file5"    : "/obj/gift/unknowdan",
		"amount8"  : 1,
		"amount2"  : 1,
		"file6"    : "/obj/gift/unknowdan",
		"amount10" : 1,
		"file2"    : "/obj/gift/unknowdan",
		"amount9"  : 1,
		"amount4"  : 1,
		"file9"    : "/obj/gift/unknowdan",
		"amount6"  : 1,
		"file1"    : "/obj/gift/unknowdan",
		"file3"    : "/obj/gift/unknowdan",
	]) );
	set( "owner", "ctx" );
	set( "build", 20400 );
	set( "light_up", 1 );
	set( "exits", ([
		"north"     : "/open/clan/ou-cloud-club/room/room500",
	]) );
	set( "long", @LONG
全FS最高的大樓建立完成了, 雖然建立過程中有不少事故發
生,像是恐怖攻擊汽車炸彈等等,不過這些危機通通過去了,現在0
10-Diamond中心大樓可以說是全FS中最高的大樓了,樓高508公尺
大概在短時間內我想不可能會有人可以超越的,這真是FS之光阿

LONG);
	setup();
	replace_program(ROOM);
}
