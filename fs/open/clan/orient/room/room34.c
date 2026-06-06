inherit ROOM;
void create() {
	set( "short", "$HIM$桃花迷陣Ⅸ$NOR$" );
	set( "owner", "borkiller" );
	set( "object", ([
		"amount1"  : 1,
		"file2"    : "/obj/gift/lingzhi",
		"file10"   : "/obj/gift/bingtang",
		"file1"    : "/obj/gift/lingzhi",
		"amount3"  : 1,
		"amount10" : 1,
		"amount6"  : 1,
		"amount8"  : 1,
		"amount4"  : 1,
		"file3"    : "/obj/gift/lingzhi",
		"amount7"  : 1,
		"file9"    : "/obj/gift/bingtang",
		"file5"    : "/obj/gift/bingtang",
		"file4"    : "/obj/gift/lingzhi",
		"amount5"  : 1,
		"file7"    : "/obj/gift/bingtang",
		"amount9"  : 1,
		"amount2"  : 1,
		"file8"    : "/obj/gift/bingtang",
		"file6"    : "/obj/gift/lingzhi",
	]) );
	set( "exits", ([
		"east"      : "/open/clan/orient/room/room28",
	]) );
	set( "build", 10010 );
	set( "light_up", 1 );
	set( "long", @LONG

    此時你正走在一片樹林當中，濃蔭蔽日，枝椏上花朵盛開，萬紫千紅
煞是好看。涼風襲襲，落英繽紛，紅花、白花、黃花、紫花，如一隻隻的
蝴蝶般繞著你身邊飛舞，你覺得彷若置身仙境。但你發現這樹林似乎按照
某種方位排列成陣，你想起江湖上傳言東邪黃藥師精通天文地理，奇門遁
甲，想必這樹林就是他依八卦五行所成的桃花陣了。四周的景色似乎沒什
麼改變，你覺得有些迷失方向了...

LONG);
	setup();
	replace_program(ROOM);
}
