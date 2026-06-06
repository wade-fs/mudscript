inherit ROOM;
void create() {
	set( "short", "$HIR$風  $HIM$隨  $HIB$行$NOR$" );
	set( "owner", "ripken" );
	set( "object", ([
		"file8"    : "/daemon/class/fighter/armband",
		"amount5"  : 1,
		"amount7"  : 1,
		"amount3"  : 1,
		"amount2"  : 1,
		"amount6"  : 1,
		"file7"    : "/open/sky/obj/lucky_grasslink",
		"file10"   : "/open/mon/obj/ghost-helmet",
		"file3"    : "/obj/gift/xisuidan",
		"file6"    : "/open/mon/obj/ghost-legging",
		"amount9"  : 1,
		"file5"    : "/open/dancer/obj/yuawaist",
		"file9"    : "/open/mon/obj/ghost-cloak",
		"amount10" : 1,
		"amount8"  : 1,
		"file2"    : "/obj/gift/xisuidan",
	]) );
	set( "build", 10849 );
	set( "light_up", 1 );
	set( "exits", ([
		"east"      : "/open/clan/ou-cloud-club/room/room215.c",
		"west"      : "/open/clan/ou-cloud-club/room/room242",
		"up"        : "/open/clan/ou-cloud-club/room/room256.c",
	]) );
	set( "long", @LONG
一把雪 放於手灼熱 但願不再怕北風深寒刺裂
深深的愛過 永不會泯滅 過度千世百劫都不能間斷
                                                                                
悲傷不要說 太匆匆歲月 現在應與妳相戀的人吻別
分不清季節 這冰冷四月 眼前的世界 景色淒迷決絕
                                                                                
悲傷不要說 太匆匆歲月 現在應與妳相戀的人吻別
分不清季節 這冰冷四月 我們不要說再見 隨世界破滅

LONG);
	setup();
	replace_program(ROOM);
}
