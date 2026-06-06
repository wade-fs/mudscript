inherit ROOM;
void create() {
	set( "short", "Silverstone Circuit" );
	set( "owner", "clair" );
	set( "object", ([
		"file7"    : "/obj/gift/xisuidan",
		"file5"    : "/obj/gift/xisuidan",
		"amount8"  : 1,
		"amount6"  : 1,
		"amount1"  : 1,
		"amount7"  : 1,
		"amount2"  : 1,
		"file6"    : "/obj/gift/xisuidan",
		"file2"    : "/obj/gift/xisuidan",
		"amount5"  : 1,
		"file1"    : "/obj/gift/xisuidan",
		"amount4"  : 1,
		"amount3"  : 1,
		"file4"    : "/obj/gift/xisuidan",
		"amount9"  : 1,
		"amount10" : 1,
		"file10"   : "/obj/gift/xisuidan",
		"file9"    : "/obj/gift/xisuidan",
		"file8"    : "/obj/gift/xisuidan",
		"file3"    : "/obj/gift/xisuidan",
	]) );
	set( "build", 10037 );
	set( "light_up", 1 );
	set( "exits", ([
		"north"     : "/open/clan/ou-cloud-club/room/room486",
	]) );
	set( "long", @LONG
銀石賽道,沒錯,這就是仿照英國銀石賽道建造而成的賽車跑
道,這名字相當亮眼吧,現在這賽道的擁有者就相當喜歡這賽道的
名稱,在這賽到中的彎道和有名的直路有,Copse彎道, Maggots彎
道,Becketts彎道,Chapel彎道,Hangar直線路段,Stowe彎道, The
Vale直線路段,Club彎道,Abbey彎道,Bridge彎道,Priory彎道,Lu
ffield彎道,以及最後的Woodcote彎道。

LONG);
	setup();
	replace_program(ROOM);
}
