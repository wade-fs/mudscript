inherit ROOM;
void create() {
	set( "short", "忘塵居" );
	set( "owner", "amdxp" );
	set( "object", ([
		"amount4"  : 1,
		"amount2"  : 1,
		"amount8"  : 1,
		"amount3"  : 1,
		"file2"    : "/open/main/obj/dragon-moon",
		"amount6"  : 1,
		"file4"    : "/obj/gift/xiandan",
		"amount7"  : 1,
		"file6"    : "/obj/gift/unknowdan",
		"file1"    : "/obj/gift/xiandan",
		"amount5"  : 1,
		"file9"    : "/open/mogi/castle/obj/fire-king-head",
		"file7"    : "/obj/gift/unknowdan",
		"amount10" : 1,
		"file10"   : "/open/main/obj/present-f",
		"file3"    : "/obj/gift/xisuidan",
		"amount9"  : 1,
		"amount1"  : 1,
		"file5"    : "/obj/gift/shenliwan",
		"file8"    : "/open/mogi/castle/obj/fire-king-head",
	]) );
	set( "build", 10060 );
	set( "exits", ([
		"north"     : "/open/clan/13_luck/room/room53",
	]) );
	set( "light_up", 1 );
	set( "long", @LONG

    這裡是殘心靜修之處，房中的陳設相當的簡單，角落一個石頭盆
景，另一邊擺著一架紗照屏，案上有個墨凍石鼎。牆上掛著一幅主人
的畫像，畫裡還題著一首詩。

     「 自古多情空餘恨 ， 凡夫俗子總無愁 
        殘風曉月不知處 ， 忘情天涯不染塵 」

LONG);
	setup();
	replace_program(ROOM);
}
