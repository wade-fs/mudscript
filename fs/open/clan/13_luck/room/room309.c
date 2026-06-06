inherit ROOM;
void create() {
	set( "short", "絕世匕首室" );
	set( "owner", "zmud" );
	set( "object", ([
		"amount8"  : 1,
		"file7"    : "/open/ghost-hole/obj/eq/ghost-shield",
		"amount9"  : 1,
		"amount6"  : 1,
		"amount1"  : 1,
		"file2"    : "/open/ghost-hole/obj/eq/ghost-shield",
		"amount7"  : 1,
		"file8"    : "/open/ghost-hole/obj/eq/ghost-shield",
		"file3"    : "/open/ghost-hole/obj/eq/ghost-shield",
		"amount3"  : 1,
		"file9"    : "/open/ghost-hole/obj/eq/ghost-shield",
		"amount2"  : 1,
		"amount5"  : 1,
		"file1"    : "/open/ghost-hole/obj/eq/ghost-shield",
		"file6"    : "/open/ghost-hole/obj/eq/ghost-shield",
		"file5"    : "/open/ghost-hole/obj/eq/ghost-shield",
	]) );
	set( "build", 10284 );
	set( "light_up", 1 );
	set( "exits", ([
		"south"     : "/open/clan/13_luck/room/room266",
	]) );
	set( "long", @LONG

    殺手，又是那可怕的殺手，一身魔氣殺定人無數，使出玄武，白虎
，青龍，朱雀，就等著去見黑白伯伯了，可見這武器的來處不易，尤其
是看到笨殺手飛燕，一身殺氣無窮，見到他走過來大家一定要危恐避之
，不然下一個死亡的就是你。

LONG);
	setup();
	replace_program(ROOM);
}
