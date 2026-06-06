inherit ROOM;
void create() {
	set( "short", "華陽湖畔" );
	set( "object", ([
		"amount1"  : 1,
		"file5"    : "/open/ghost-hole/obj/eq/ghost-ring",
		"file6"    : "/open/ghost-hole/obj/eq/ghost-belt",
		"amount6"  : 1,
		"amount5"  : 1,
		"amount3"  : 1,
		"amount10" : 610,
		"file8"    : "/open/ghost-hole/obj/eq/ghost-pants",
		"file7"    : "/open/ping/obj/poison_pill",
		"file3"    : "/open/ghost-hole/obj/eq/ghost-ring",
		"file9"    : "/open/ghost-hole/obj/eq/ghost-gloves",
		"amount4"  : 1,
		"file4"    : "/open/ghost-hole/obj/eq/ghost-gloves",
		"file1"    : "/open/ghost-hole/obj/eq/ghost-gloves",
		"amount2"  : 686,
		"file2"    : "/open/ping/obj/poison_pill",
		"file10"   : "/open/ping/obj/poison_pill",
		"amount8"  : 1,
		"amount7"  : 737,
		"amount9"  : 1,
	]) );
	set( "owner", "zmud" );
	set( "build", 10006 );
	set( "light_up", 1 );
	set( "exits", ([
		"south"     : "/open/clan/13_luck/room/room483.c",
		"north"     : "/open/clan/13_luck/room/room478",
		"east"      : "/open/clan/13_luck/room/room480.c",
		"west"      : "/open/clan/13_luck/room/room481.c",
	]) );
	set( "long", @LONG

    這裡是華陽湖畔的一條小衚衕，衚衕靠著湖上的這邊種著整排的楊
柳，樹下有官府專程放置的桌椅讓人休憩之用。話說：晚風拂柳曳生姿
，伴霞映水畫綺粲，是這邑陽城的一大景色，多少騷人墨客遊城之時，
不無來此尋找詩詞靈感。

LONG);
	setup();
	replace_program(ROOM);
}
