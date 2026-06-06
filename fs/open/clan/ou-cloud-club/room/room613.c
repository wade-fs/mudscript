inherit ROOM;
void create() {
	set( "short", "茯苓之家" );
	set( "object", ([
		"amount9"  : 1,
		"file2"    : "/open/killer/obj/atman_pill",
		"file8"    : "/open/mogi/castle/obj/fire-king-head",
		"file9"    : "/open/mogi/dragon/obj/scale",
		"file3"    : "/open/mogi/dragon/obj/scale",
		"amount4"  : 1,
		"amount3"  : 1,
		"amount1"  : 1200,
		"file7"    : "/open/mon/obj/mon-pill",
		"amount5"  : 1,
		"amount8"  : 1,
		"amount10" : 1,
		"file1"    : "/open/killer/obj/s_pill",
		"amount7"  : 75,
		"file4"    : "/open/mogi/dragon/obj/scale",
		"file5"    : "/obj/gift/lingzhi",
		"file6"    : "/open/mon/obj/thousand-nectar",
		"amount2"  : 210,
		"file10"   : "/open/killer/obj/kill_yar_head",
		"amount6"  : 9,
	]) );
	set( "build", 10197 );
	set( "light_up", 1 );
	set( "owner", "fulling" );
	set( "exits", ([
		"south"     : "/open/clan/ou-cloud-club/room/room450",
	]) );
	set( "long", @LONG
茯苓為多孔菌科寄生於松樹根部的菌核。味甘、淡。性平無毒，歸心、脾、腎經。
具有利水滲濕、健脾、安神等功效。適用於小便不順暢、水腫、痰飲脾氣虛弱及心
悸、失眠等症狀。除去外皮之後外層呈淡紅色者稱赤茯苓、內層白色者稱白茯苓、
中間有細松根穿過者稱茯神。是四神湯的食材之一。
LONG);
	setup();
	replace_program(ROOM);
}
