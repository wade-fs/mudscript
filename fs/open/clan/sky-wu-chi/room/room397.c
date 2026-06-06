inherit ROOM;
void create() {
	set( "short", "【桃花迷陣】" );
	set( "owner", "working" );
	set( "object", ([
		"file10"   : "/open/ghost-hole/obj/life-ghost-head",
		"amount10" : 1,
		"file4"    : "/open/killer/obj/bellstar",
		"amount4"  : 90713,
		"amount8"  : 1,
		"file8"    : "/open/ghost-hole/obj/death-ghost-head",
		"amount1"  : 1,
		"file1"    : "/open/capital/guard/gring",
	]) );
	set( "light_up", 1 );
	set( "build", 10281 );
	set( "exits", ([
		"north"     : "/open/clan/sky-wu-chi/room/room429",
		"up"        : "/open/clan/sky-wu-chi/room/room414",
		"down"      : "/open/clan/sky-wu-chi/room/room398.c",
		"south"     : "/open/clan/sky-wu-chi/room/room397",
		"west"      : "/open/clan/sky-wu-chi/room/room419",
		"east"      : "/open/clan/sky-wu-chi/room/room400.c",
	]) );
	set( "long", @LONG

        此時你正走在一片樹林當中，濃蔭蔽日，枝椏上花朵盛開，萬紫千紅
    ，煞是好看。涼風襲襲，落英繽紛，紅花、白花、黃花、紫花，如一隻隻
    蝴蝶般繞著你身邊飛舞，你覺得彷若置身仙境。但你發現這樹林似乎按照
    某種方位排列成陣，你想起江湖上傳言東邪黃藥師精通天文地理，奇門遁
    甲，想必這樹林就是他依八卦五行所成的桃花陣了。四周的景色似乎沒什
    麼改變，你覺得有些迷失方向了......

LONG);
	setup();
	replace_program(ROOM);
}

