inherit ROOM;
void create() {
	set( "short", "阿婆涼麵" );
	set( "owner", "super" );
	set( "exits", ([
		"west"      : "/open/clan/ou-cloud-club/room/room129",
	]) );
	set( "object", ([
		"file3"    : "/open/mon/obj/ghost-claw",
		"amount6"  : 1,
		"amount1"  : 310,
		"file8"    : "/open/mon/obj/ghost-claw",
		"amount8"  : 1,
		"amount4"  : 1,
		"amount3"  : 1,
		"file4"    : "/open/mon/obj/ghost-legging",
		"file5"    : "/open/mon/obj/ghost-cloak",
		"amount5"  : 1,
		"file7"    : "/u/f/frequency/obj/icer",
		"file6"    : "/open/mon/obj/ghost-helmet",
		"file1"    : "/open/fire-hole/obj/r-pill",
		"amount7"  : 1,
	]) );
	set( "light_up", 1 );
	set( "build", 10034 );
	set( "long", @LONG
蒜味、辣味、原味、綜合涼麵
一眼望去各式的涼麵陳列的琳郎滿目
這邊的特色就是20鑽石吃到飽
還有特製的鮑魚涼麵，更是不吃不可
特地聘請乾隆的御廚來掌廚
如果你來拜訪涼，一定要留在這兒吃飯的
遠遠望去，排隊的人潮已經延伸到隔壁村
遠遠望去，排隊的人潮已經延伸到隔壁村

LONG);
	setup();
	replace_program(ROOM);
}
