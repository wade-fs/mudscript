inherit ROOM;
void create() {
	set( "short", "鑽石裝備" );
	set( "owner", "amdxp" );
	set( "object", ([
		"amount10" : 1,
		"amount4"  : 1,
		"file9"    : "/obj/gift/xisuidan",
		"file10"   : "/obj/gift/xisuidan",
		"file8"    : "/obj/gift/xiandan",
		"amount9"  : 1,
		"amount5"  : 1,
		"file7"    : "/obj/gift/xiandan",
		"amount1"  : 1,
		"amount8"  : 1,
		"amount6"  : 1,
		"file6"    : "/obj/gift/shenliwan",
		"file2"    : "/obj/gift/shenliwan",
		"file5"    : "/obj/gift/xiandan",
		"file3"    : "/obj/gift/shenliwan",
		"amount2"  : 1,
		"file1"    : "/obj/gift/shenliwan",
		"amount7"  : 1,
		"file4"    : "/obj/gift/shenliwan",
		"amount3"  : 1,
	]) );
	set( "build", 10560 );
	set( "exits", ([
		"west"      : "/open/clan/13_luck/room/room67",
	]) );
	set( "light_up", 1 );
	set( "long", @LONG

    這裡放滿了虹晶的裝備，其原料是用鑽石所提煉的，放入丹爐中
七七四十九天打造出來的最佳防禦裝備，可媲美魔龍裝備跟天界裝備
其配件共有八件，每一部份都會隨著持有者的身材而縮放到最適合主
人的大小，虹晶是一套很有靈性的裝備，並不是任何人都可以擁有。


妳發覺黃色的迷霧圍繞正在妳四周


LONG);
	setup();
	replace_program(ROOM);
}
