inherit ROOM;
void create() {
	set( "short", "鎖綠橋" );
	set( "owner", "rue" );
	set( "light_up", 1 );
	set( "object", ([
		"file7"    : "/daemon/class/blademan/obj/shield",
		"amount6"  : 1,
		"amount3"  : 1,
		"amount5"  : 1,
		"file4"    : "/open/mon/obj/ghost-cloak",
		"file3"    : "/obj/stone/jiao",
		"file1"    : "/obj/stone/powder",
		"amount1"  : 46,
		"amount9"  : 1,
		"file2"    : "/open/mon/obj/ghost-legging",
		"file9"    : "/daemon/class/bonze/puty_pullium",
		"amount2"  : 1,
		"amount7"  : 1,
		"file6"    : "/daemon/class/blademan/obj/shield",
		"amount8"  : 1,
		"file8"    : "/open/mon/obj/ghost-helmet",
		"file5"    : "/open/quests/snake/npc/obj/snake-key-2",
		"amount4"  : 1,
		"amount10" : 1,
		"file10"   : "/open/dancer/obj/yuawaist",
	]) );
	set( "build", 10070 );
	set( "exits", ([
		"out"       : "/open/clan/sky-wu-chi/room/room37.c",
		"west"      : "/open/clan/sky-wu-chi/room/room288.c",
		"east"      : "/open/clan/sky-wu-chi/room/room40",
		"chome"     : "/open/clan/sky-wu-chi/room/hall.c",
		"south"     : "/open/clan/sky-wu-chi/room/room61.c",
	]) );
	set( "long", @LONG
單孔的石木拱橋跨於流水之上，橋首柱上雕『鎖綠橋』
三字，倒影於水中化為珠鏈般的圓環，又如一輪明月扶搖水
中；橋下三三兩兩的魚兒漂游嬉戲著，自在快活無憂無慮的
模樣，直教人厭起這副終日案牘勞形的臭皮囊，願化此身水
中相隨逍遙游。
LONG);
	setup();
	replace_program(ROOM);
}
