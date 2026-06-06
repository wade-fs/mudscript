inherit ROOM;
void create() {
	set( "short", "小房間" );
	set( "owner", "sevenll" );
	set( "object", ([
		"amount6"  : 20,
		"file8"    : "/open/mogi/castle/obj/ninepill",
		"amount8"  : 23,
		"file6"    : "/open/mon/obj/mon-pill",
		"amount9"  : 1,
		"file2"    : "/obj/stone/jiao",
		"file3"    : "/open/ghost-hole/obj/eq/ghost-cloak",
		"amount4"  : 1,
		"amount2"  : 1,
		"amount10" : 1,
		"file5"    : "/open/magic-manor/obj/golden-ball",
		"file7"    : "/open/capital/obj/4-2",
		"file9"    : "/open/killer/obj/fire-knife",
		"file4"    : "/open/capital/obj/4-1",
		"amount5"  : 1,
		"amount1"  : 1,
		"amount3"  : 1,
		"file10"   : "/open/magic-manor/obj/maun-shadow-blade",
		"file1"    : "/open/magic-manor/obj/wood-ball",
		"amount7"  : 1,
	]) );
	set( "build", 10035 );
	set( "light_up", 1 );
	set( "exits", ([
		"south"     : "/open/clan/13_luck/room/room675",
	]) );
	set( "long", @LONG
這裡是個奇怪的小房間,裡面什麼都沒有,只有中間地板上
放了一個坐墊,四周的空氣凝結著農中的氣息,你覺得呼吸沉重
了起來,牆壁上還有許多拳印及劍痕,你心中覺得這裡應該是住
在此世外桃源高手的練功房,你只覺得應該快步離開,不趕在逗
留.                            
    

LONG);
	setup();
	replace_program(ROOM);
}
