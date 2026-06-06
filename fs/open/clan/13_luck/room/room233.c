inherit ROOM;
void create() {
	set( "short", "娃娃寶殿" );
	set( "owner", "icute" );
	set( "light_up", 1 );
	set( "object", ([
		"amount5"  : 1,
		"amount10" : 987,
		"amount2"  : 1,
		"file7"    : "/open/capital/obj/4-1",
		"file9"    : "/open/fire-hole/obj/r-pill",
		"amount6"  : 1,
		"file1"    : "/open/fire-hole/obj/k-pill",
		"amount8"  : 1,
		"file6"    : "/open/mogi/castle/obj/fire-king-head",
		"file2"    : "/open/capital/obj/4-1",
		"file3"    : "/open/killer/obj/fire-knife",
		"file4"    : "/open/mon/obj/ghost-claw",
		"file10"   : "/open/fire-hole/obj/y-pill",
		"amount9"  : 1934,
		"amount1"  : 557,
		"file8"    : "/open/sky/obj/lucky_grasslink",
		"file5"    : "/open/capital/obj/4-2",
		"amount3"  : 1,
		"amount7"  : 1,
		"amount4"  : 1,
	]) );
	set( "build", 10230 );
	set( "exits", ([
		"east"      : "/open/clan/13_luck/room/room97.c",
	]) );
	set( "long", @LONG
一座雄偉壯觀的寺院映入眼簾，抬頭一看，門頂掛了一塊木造的匾額，
上面藍底紅字寫著「娃娃寶殿」四個大字。此四字寫得甚是蒼勁有力，
看得你懾定入神，心想：「提此四字的人，定是文武全才的大高人。」 
眼前佇立著一塊六人長，二人高的大石碑，碑上刻著五個大字：「天下第一寺」。

LONG);
	setup();
	replace_program(ROOM);
}
