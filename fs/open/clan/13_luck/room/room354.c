inherit ROOM;
void create() {
	set( "short", "蒼月軒" );
	set( "owner", "superblade" );
	set( "object", ([
		"file8"    : "/open/mon/obj/thousand-nectar",
		"file7"    : "/open/fire-hole/obj/r-pill",
		"file1"    : "/open/mogi/castle/obj/ninepill",
		"amount8"  : 26,
		"file3"    : "/open/mon/obj/mon-pill",
		"amount1"  : 50,
		"amount9"  : 58,
		"amount4"  : 161,
		"file5"    : "/open/mogi/castle/obj/sspill",
		"file4"    : "/open/ping/obj/poison_pill",
		"amount6"  : 1,
		"amount7"  : 55,
		"file2"    : "/open/fire-hole/obj/w-pill",
		"amount2"  : 467,
		"file6"    : "/obj/gift/unknowdan",
		"file9"    : "/open/fire-hole/obj/g-pill",
		"amount3"  : 491,
		"amount5"  : 300,
	]) );
	set( "build", 10257 );
	set( "exits", ([
		"down"      : "/open/clan/13_luck/room/room539",
		"up"        : "/open/clan/13_luck/room/room485.c",
		"west"      : "/open/clan/13_luck/room/room71.c",
		"east"      : "/open/clan/13_luck/room/room541.c",
	]) );
	set( "light_up", 1 );
	set( "long", @LONG

    在這小小的天地,可以看到許多的稀奇古怪的玩意,陳列四周的櫃子,
像一些造型奇特的人偶,你拿起來仔細一看,發現人偶竟然對你瞪了一眼,
還跟你說小朋友這樣不行喔!怎麼可以亂拿別人的東西!!你只好摸摸自己
的鼻子大嘆一聲,人偶敢這麼囂張,真是狗丈人勢QQ.......
人偶大笑道是主人教的好ㄚ^^

LONG);
	setup();
	replace_program(ROOM);
}
