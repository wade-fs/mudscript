inherit ROOM;
void create() {
	set( "short", "EMC 戰鬥教練場" );
	set( "object", ([
		"amount3"  : 1,
		"file6"    : "/open/mogi/dragon/obj/scale",
		"amount2"  : 1,
		"file1"    : "/open/ping/obj/poison_pill",
		"file3"    : "/open/mogi/dragon/obj/scale",
		"amount6"  : 1,
		"amount1"  : 3,
		"file2"    : "/open/mogi/dragon/obj/scale",
	]) );
	set( "owner", "adeyzit" );
	set( "build", 10116 );
	set( "exits", ([
		"south"     : "/open/clan/13_luck/room/room104.c",
		"enter"     : "/open/clan/13_luck/room/room284",
	]) );
	set( "light_up", 1 );
	set( "long", @LONG
這裡有廣闊的紅土高原..都在上面跑 攻防搜警堅..
老是看到班長在比手勢..第x 班注意,朝哪個方向走多少公
尺,以什麼隊形..以什麼方式前進..
在上面跑來跑去..也可以摸魚打混..用錢把小蜜蜂打死..
躺在草叢遙望天空..享受藍天白雲...也是一種滿足
LONG);
	setup();
	replace_program(ROOM);
}
