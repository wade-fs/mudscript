inherit ROOM;
void create() {
	set( "short", "傑克小屋" );
	set( "owner", "biom" );
	set( "exits", ([
		"enter"     : "/open/clan/13_luck/room/room108.c",
		"west"      : "/open/clan/13_luck/room/room90.c",
	]) );
	set( "object", ([
		"file1"    : "/open/capital/obj/blade2",
		"amount9"  : 1,
		"amount1"  : 1,
		"file10"   : "/open/tendo/obj/chaosbelt",
		"file2"    : "/open/sky/obj/lucky_grasslink",
		"file9"    : "/open/mon/obj/ghost-helmet",
		"amount3"  : 1,
		"amount8"  : 1,
		"amount4"  : 1,
		"amount2"  : 1,
		"amount10" : 1,
		"file8"    : "/obj/gift/xisuidan",
		"file4"    : "/open/mogi/dragon/obj/scale",
		"file7"    : "/open/capital/obj/blade2",
		"amount5"  : 1,
		"file5"    : "/open/mogi/dragon/obj/dragon-head",
		"file3"    : "/open/mogi/dragon/obj/scale",
		"amount7"  : 1,
	]) );
	set( "build", 10023 );
	set( "light_up", 1 );
	set( "long", @LONG
哇! 
你一踏進房間的驚訝表情, 差點嚇壞歹勇的可愛小寵物--BABY
雖然如此, 但擺滿人頭的屋子, 仍然令你覺得很不安, 焚天魔
王, 不可一世的魔王人頭, 竟然也在此列, 更有那萬惡不赦的
蛇郎君, 甚至七魔將, 黃金甲龍, 以及打敗黃金甲龍得來的魔
界異寶--魔龍鱗! 此物乃是可以自由進出魔界的寶物, 可惜用
一次就消失了, 能不好好珍惜嗎? 也許改天我也應該來跟歹勇
仔要一下裝備, 節省我進七星塔, 打魔界森林甚至看守魔界入
口網中人的時間......
LONG);
	setup();
	replace_program(ROOM);
}
