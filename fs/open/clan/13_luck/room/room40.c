inherit ROOM;
void create() {
	set( "short", "客棧正廳" );
	set( "object", ([
		"amount3"  : 1,
		"file1"    : "/open/mogi/dragon/obj/scale",
		"amount9"  : 1,
		"amount5"  : 1,
		"amount1"  : 1,
		"file6"    : "/open/mogi/dragon/obj/scale",
		"file5"    : "/open/mon/obj/ghost-helmet",
		"file8"    : "/open/mogi/dragon/obj/scale",
		"file3"    : "/daemon/class/blademan/obj/ublade",
		"file2"    : "/open/capital/obj/blade2",
		"amount4"  : 1,
		"amount8"  : 1,
		"file4"    : "/open/mogi/dragon/obj/scale",
		"amount2"  : 1,
		"file9"    : "/open/mogi/dragon/obj/scale",
		"amount7"  : 1,
		"amount6"  : 1,
		"file7"    : "/open/snow/obj/figring",
	]) );
	set( "build", 11037 );
	set( "exits", ([
		"煙雨樓"    : "/open/clan/13_luck/room/room43.c",
		"紅塵閣"    : "/open/clan/13_luck/room/room96",
		"west"      : "/open/clan/13_luck/room/room41.c",
		"down"      : "/open/clan/13_luck/room/room9.c",
		"east"      : "/open/clan/13_luck/room/room42.c",
	]) );
	set( "light_up", 1 );
	set( "long", @LONG

    歡迎您來到十三吉祥的客棧正廳，請先向櫃檯的店小二CHECK IN
辦理好手續後，您就可以回到妳的廂房休息了，如有需要任何服務請
直撥CT頻道將有專人為您服務～～
                                               謝謝光臨 ！！

             從正廳往前走，即是『煙雨樓』。
             從左廳往前走，即是『鳳凰樓』。
             從右聽往前走，即是『望月樓』。

LONG);
	setup();
	replace_program(ROOM);
}
