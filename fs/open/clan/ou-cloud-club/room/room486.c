inherit ROOM;
void create() {
	set( "short", "A1-Ring Circuit" );
	set( "object", ([
		"amount8"  : 1,
		"file1"    : "/obj/gift/unknowdan",
		"amount3"  : 1,
		"amount10" : 1,
		"file8"    : "/obj/gift/unknowdan",
		"file4"    : "/obj/gift/unknowdan",
		"amount4"  : 1,
		"amount1"  : 1,
		"file6"    : "/obj/gift/unknowdan",
		"file2"    : "/obj/gift/unknowdan",
		"file10"   : "/obj/gift/unknowdan",
		"amount9"  : 1,
		"amount7"  : 1,
		"file9"    : "/obj/gift/unknowdan",
		"file3"    : "/obj/gift/unknowdan",
		"file5"    : "/obj/gift/unknowdan",
		"amount2"  : 1,
		"amount6"  : 1,
		"amount5"  : 1,
		"file7"    : "/obj/gift/unknowdan",
	]) );
	set( "build", 10060 );
	set( "light_up", 1 );
	set( "exits", ([
		"up"        : "/open/clan/ou-cloud-club/room/room500",
		"north"     : "/open/clan/ou-cloud-club/room/room483.c",
		"south"     : "/open/clan/ou-cloud-club/room/room482.c",
		"down"      : "/open/clan/ou-cloud-club/room/room425.c",
		"east"      : "/open/clan/ou-cloud-club/room/room485.c",
		"west"      : "/open/clan/ou-cloud-club/room/room484.c",
	]) );
	set( "long", @LONG
在這裡,你看到了一個模仿奧地利A1-Ring Circuit賽道所建
造出來的賽車跑道,裡面的彎道有,Castrol彎道,Remus彎道,Goss
er彎道,Lauda彎道,Berger彎道,Rindt彎道,Mobilkom彎道 ,能稱
霸這些彎道的人,就能稱霸A1-Ring Circuit,想要挑戰她嗎?去吧
去接受那方格子旗的揮舞吧。

LONG);
	setup();
	replace_program(ROOM);
}
