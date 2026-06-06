inherit ROOM;
void create() {
	set( "short", "$HIM$桃花迷陣Ⅶ$NOR$" );
	set( "owner", "borkiller" );
	set( "object", ([
		"file10"   : "/open/ghost-hole/obj/butterfly",
		"file8"    : "/open/killer/obj/s_pill",
		"file7"    : "/open/fire-hole/obj/w-pill",
		"file6"    : "/open/fire-hole/obj/y-pill",
		"amount7"  : 53,
		"file2"    : "/open/fire-hole/obj/b-pill",
		"file5"    : "/open/fire-hole/obj/p-pill",
		"amount10" : 1,
		"amount5"  : 55,
		"amount3"  : 20,
		"amount2"  : 583,
		"file1"    : "/open/ghost-hole/obj/butterfly",
		"amount9"  : 35,
		"amount4"  : 277,
		"file9"    : "/open/fire-hole/obj/g-pill",
		"file3"    : "/open/ping/obj/poison_pill",
		"amount8"  : 889,
		"amount1"  : 1,
		"amount6"  : 95,
		"file4"    : "/open/fire-hole/obj/r-pill",
	]) );
	set( "exits", ([
		"west"      : "/open/clan/orient/room/room27",
	]) );
	set( "build", 19271 );
	set( "light_up", 1 );
	set( "long", @LONG

    此時你正走在一片樹林當中，濃蔭蔽日，枝椏上花朵盛開，萬紫千紅
煞是好看。涼風襲襲，落英繽紛，紅花、白花、黃花、紫花，如一隻隻的
蝴蝶般繞著你身邊飛舞，你覺得彷若置身仙境。但你發現這樹林似乎按照
某種方位排列成陣，你想起江湖上傳言東邪黃藥師精通天文地理，奇門遁
甲，想必這樹林就是他依八卦五行所成的桃花陣了。四周的景色似乎沒什
麼改變，你覺得有些迷失方向了.....

LONG);
	setup();
	replace_program(ROOM);
}
