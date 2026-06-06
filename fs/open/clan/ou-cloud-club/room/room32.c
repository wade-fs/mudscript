inherit ROOM;
void create() {
	set( "short", "$HIR$死靈$HIC$刀$NOR$谷" );
	set( "owner", "moblade" );
	set( "object", ([
		"file9"    : "/obj/gift/hobowdan",
		"amount4"  : 248,
		"file1"    : "/open/mogi/dragon/obj/power",
		"file6"    : "/obj/gift/hobowdan",
		"amount1"  : 4,
		"amount9"  : 1,
		"amount8"  : 1,
		"file4"    : "/open/magic-manor/ghost/obj/trigram-pill",
		"file5"    : "/open/mon/obj/mon-pill",
		"amount6"  : 1,
		"amount3"  : 1,
		"amount5"  : 690,
		"file2"    : "/open/magic-manor/obj/magic-sign",
		"file3"    : "/obj/gift/unknowdan",
		"file8"    : "/open/ghost-hole/obj/butterfly",
		"amount2"  : 1,
		"amount10" : 1,
		"file10"   : "/obj/gift/xiandan",
	]) );
	set( "build", 10019 );
	set( "light_up", 1 );
	set( "exits", ([
		"enter"     : "/open/clan/ou-cloud-club/room/room10",
		"east"      : "/open/clan/ou-cloud-club/room/room107.c",
	]) );
	set( "long", @LONG
刀邪．不二刀練刀之地，自從刀邪不二刀加入魔刀門之後，立
志要奪回失傳已久的妖刀，卻苦於對刀的領悟不夠，無法殺入魔刀
禁地而一舉奪得曾經讓世人聞之色變的妖刀，所以就在此地靜思所
學，當有天破關而出時，也就是妖刀現世了！！

LONG);
	setup();
	replace_program(ROOM);
}
