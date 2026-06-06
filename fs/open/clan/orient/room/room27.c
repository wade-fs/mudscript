inherit ROOM;
void create() {
	set( "short", "$HIM$桃花迷陣Ⅰ$NOR$" );
	set( "owner", "borkiller" );
	set( "object", ([
		"file6"    : "/open/magic-manor/water/obj/water-ribbon",
		"file7"    : "/open/mogi/castle/obj/fire-king-head",
		"file8"    : "/open/capital/obj/blade2",
		"file10"   : "/open/killer/memory/static",
		"file5"    : "/open/ghost-hole/obj/butterfly",
		"amount7"  : 1,
		"file2"    : "/open/magic-manor/water/obj/water-ribbon",
		"amount10" : 1,
		"amount5"  : 1,
		"amount3"  : 1,
		"file1"    : "/open/magic-manor/water/obj/water-ribbon",
		"amount2"  : 1,
		"amount9"  : 1,
		"amount4"  : 1,
		"file9"    : "/open/killer/memory/static",
		"file3"    : "/open/ghost-hole/obj/butterfly",
		"amount1"  : 1,
		"amount8"  : 1,
		"amount6"  : 1,
		"file4"    : "/open/ghost-hole/obj/butterfly",
	]) );
	set( "light_up", 1 );
	set( "build", 10003 );
	set( "exits", ([
		"south"     : "/open/clan/orient/room/room3.c",
		"north"     : "/open/clan/orient/room/room28.c",
		"east"      : "/open/clan/orient/room/room36",
		"west"      : "/open/clan/orient/room/room32.c",
	]) );
	set( "long", @LONG

    此時你正走在一片樹林當中，濃蔭蔽日，枝椏上花朵盛開，萬紫千紅
煞是好看。涼風襲襲，落英繽紛，紅花、白花、黃花、紫花，如一隻隻的
蝴蝶般繞著你身邊飛舞，你覺得彷若置身仙境。但你發現這樹林似乎按照
某種方位排列成陣，你想起江湖上傳言東邪黃藥師精通天文地理，奇門遁
甲，想必這樹林就是他依八卦五行所成的桃花陣了。四周的景色似乎沒什
麼改變，你覺得有些迷失方向了.

LONG);
	setup();
	replace_program(ROOM);
}
