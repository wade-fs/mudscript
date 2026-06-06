inherit ROOM;
void create() {
	set( "short", "【秘密花園】" );
	set( "owner", "working" );
	set( "object", ([
		"file4"    : "/open/mogi/dragon/obj/scale",
		"amount1"  : 13450000,
		"amount7"  : 1,
		"amount8"  : 1,
		"file9"    : "/open/mogi/dragon/obj/scale",
		"amount9"  : 1,
		"file2"    : "/open/mogi/dragon/obj/scale",
		"file1"    : "/open/killer/obj/hate_knife",
		"file7"    : "/open/mogi/dragon/obj/scale",
		"amount3"  : 1,
		"file6"    : "/open/mogi/dragon/obj/scale",
		"amount6"  : 1,
		"amount5"  : 1,
		"file3"    : "/open/mogi/dragon/obj/scale",
		"file8"    : "/open/mogi/dragon/obj/scale",
		"file5"    : "/open/mogi/dragon/obj/scale",
		"amount2"  : 1,
		"amount4"  : 1,
	]) );
	set( "build", 10014 );
	set( "exits", ([
		"south"     : "/open/clan/sky-wu-chi/room/room417",
		"west"      : "/open/clan/sky-wu-chi/room/room416.c",
		"north"     : "/open/clan/sky-wu-chi/room/room417",
		"east"      : "/open/clan/sky-wu-chi/room/room418.c",
	]) );
	set( "long", @LONG
 
       此時你正走在一片樹林當中，濃蔭蔽日，枝椏上花朵盛開，萬紫千紅
    ，煞是好看。涼風襲襲，落英繽紛，紅花、白花、黃花、紫花，如一隻隻
    蝴蝶般繞著你身邊飛舞，你覺得彷若置身仙境。但你發現這樹林似乎按照
    某種方位排列成陣，你想起江湖上傳言東邪黃藥師精通天文地理，奇門遁
    甲，想必這樹林就是他依八卦五行所成的桃花陣了。四周的景色似乎沒什
    麼改變，你覺得有些迷失方向了...

LONG);
	setup();
	replace_program(ROOM);
}
