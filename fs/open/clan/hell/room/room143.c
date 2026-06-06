inherit ROOM;
void create() {
	set( "short", "裝備室" );
	set( "object", ([
		"file6"    : "/open/dancer/obj/yuawaist",
		"file9"    : "/open/mon/obj/ghost-cloak",
		"file7"    : "/open/wu/npc/obj/armband",
		"file10"   : "/open/killer/headkill/obj/world_dag",
		"file3"    : "/open/ping/obj/ring-2",
		"amount4"  : 1,
		"amount1"  : 1,
		"amount3"  : 1,
		"amount8"  : 1,
		"amount5"  : 1,
		"file8"    : "/open/ping/obj/chilin_legging",
		"file4"    : "/daemon/class/bonze/puty_pullium",
		"amount7"  : 1,
		"amount9"  : 1,
		"file2"    : "/open/gsword/obj1/bbladeball",
		"amount10" : 1,
		"file1"    : "/open/killer/obj/k_ring",
		"file5"    : "/open/ping/obj/gold_hand",
		"amount6"  : 1,
		"amount2"  : 1,
	]) );
	set( "light_up", 1 );
	set( "build", 12984 );
	set( "exits", ([
		"east"      : "/open/clan/hell/room/room140",
		"west"      : "/open/clan/hell/room/room13.c",
	]) );
	set( "long", @LONG
這裡是嘿嘿呵呵放裝備ㄉ地方,處處擺放著嘿嘿呵呵平時練工時所穿ㄉ裝備,雖然不是上等貨,但卻夠讓嘿嘿呵呵練功ㄌ,裡面放著寒冰,妖幻之爪,寶蓮靴,天蠶絲帶.魔法盾,金之手套.妖行甲,...............等等,如果你絕ㄉ有更適合嘿嘿呵呵川ㄉ裝備請指教
LONG);
	setup();
	replace_program(ROOM);
}
