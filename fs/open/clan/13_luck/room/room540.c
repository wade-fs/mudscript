inherit ROOM;
void create() {
	set( "short", "活水池" );
	set( "exits", ([
		"south"     : "/open/clan/13_luck/room/room126",
	]) );
	set( "owner", "biob" );
	set( "object", ([
		"file10"   : "/open/mogi/castle/obj/fire-king-head",
		"amount10" : 1,
		"file9"    : "/obj/gift/shenliwan",
		"amount8"  : 37,
		"file3"    : "/open/center/obj/clan-master-head",
		"amount4"  : 1,
		"file6"    : "/obj/gift/shenliwan",
		"amount5"  : 1,
		"amount7"  : 3,
		"amount3"  : 1,
		"file5"    : "/open/mogi/castle/obj/fire-king-head",
		"amount1"  : 2,
		"file8"    : "/open/mogi/dragon/obj/power",
		"file1"    : "/open/mogi/mountain/obj/frog-pill",
		"file2"    : "/open/wu/obj/ya-head",
		"amount2"  : 1,
		"file7"    : "/open/magic-manor/ghost/obj/trigram-pill",
		"amount9"  : 1,
		"amount6"  : 1,
		"file4"    : "/open/ghost-hole/obj/eq/ghost-leggings",
	]) );
	set( "build", 10076 );
	set( "light_up", 1 );
	set( "long", @LONG

    你發現有水滴搭搭的作響,往裡面走去,發現有一個用寒玉冰石所砌成的大浴池,水的顏色是
淡淡的藍色,還冒這白白煙,你伸手去觸碰發現水是寒到你的骨子裡,不知道是怎樣的高手才能使
用這個池子,相信在這個池子浸泡過,會使自己的功力更上一層,也不會使自己有走火入魔的危機
存在.

LONG);
	setup();
	replace_program(ROOM);
}
