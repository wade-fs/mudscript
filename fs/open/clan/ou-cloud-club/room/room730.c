inherit ROOM;
void create() {
	set( "short", "狗窩" );
	set( "object", ([
		"amount1"  : 50,
		"amount8"  : 1,
		"file5"    : "/open/mogi/dragon/obj/power",
		"amount6"  : 1,
		"amount3"  : 3,
		"file3"    : "/obj/stone/jiao",
		"amount5"  : 15,
		"file8"    : "/open/mogi/dragon/obj/scale",
		"amount2"  : 10,
		"file4"    : "/open/ghost-hole/obj/eq/ghost-king-tooth",
		"file2"    : "/obj/stone/suipian",
		"amount4"  : 1,
		"file1"    : "/obj/stone/powder",
		"file6"    : "/open/mogi/dragon/obj/scale",
	]) );
	set( "build", 10039 );
	set( "light_up", 1 );
	set( "owner", "xman" );
	set( "exits", ([
		"south"     : "/open/clan/ou-cloud-club/room/room729.c",
		"north"     : "/open/clan/ou-cloud-club/room/room731",
	]) );
	set( "long", @LONG
這是百年老不死Xman的龜窩,經過4年的塵封,Xman回到了FS,
現在Xman沒事就會龜在這,這裡的擺飾亂七八糟,整個房間像是被
亂槍掃射過,可見Xman這個死老頭沒事只會顧玩FS,完全沒在整理
房間,真難想像這種房間怎麼可以住人

LONG);
	setup();
	replace_program(ROOM);
}
