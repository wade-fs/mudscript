inherit ROOM;
void create() {
	set( "short", "小豬頭的家" );
	set( "object", ([
		"amount6"  : 1,
		"amount1"  : 1,
		"file4"    : "/open/wind-rain/obj/sun_red_cloth",
		"file8"    : "/daemon/class/blademan/obj/shield",
		"file3"    : "/open/mon/obj/ghost-legging",
		"file5"    : "/daemon/class/fighter/figring",
		"amount5"  : 1,
		"file9"    : "/open/mogi/castle/obj/lochagem",
		"amount3"  : 1,
		"amount2"  : 1,
		"amount7"  : 1,
		"amount9"  : 1,
		"amount4"  : 1,
		"file2"    : "/open/mon/obj/ghost-cloak",
		"amount10" : 1,
		"file1"    : "/open/mon/obj/ghost-helmet",
		"file6"    : "/open/tendo/obj/chaosbelt",
		"file10"   : "/open/sky/obj/lucky_grasslink",
		"amount8"  : 1,
		"file7"    : "/open/gsword/obj/may_ring",
	]) );
	set( "owner", "mysql" );
	set( "light_up", 1 );
	set( "build", 11254 );
	set( "exits", ([
		"south"     : "/open/clan/13_luck/room/room90",
		"enter"     : "/open/clan/13_luck/room/room127",
	]) );
	set( "long", @LONG

    這裡就是傳說中的十三吉祥鎮幫豬頭，可愛小豬頭的家，有於受
到十三吉祥各位前輩的幫忙，小豬頭才能長大成為大豬頭，期待有一
天也能和前輩一樣，闖蕩江湖打遍天下無敵手，並且幫助幫內的夥伴
們，就像前輩當初幫助小豬頭一樣，讓十三吉祥成為第一大幫派。


LONG);
	setup();
	replace_program(ROOM);
}
