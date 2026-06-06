inherit ROOM;
void create() {
	set( "short", "【桃花迷陣】" );
	set( "owner", "working" );
	set( "object", ([
		"file7"    : "/open/killer/obj/hate_knife",
		"amount4"  : 1,
		"amount8"  : 1,
		"file1"    : "/open/gblade/obj/sa-head",
		"file3"    : "/open/fire-hole/obj/r-pill",
		"file2"    : "/open/gblade/obj/sa-head",
		"amount5"  : 151,
		"file4"    : "/open/gblade/obj/sa-head",
		"file5"    : "/open/fire-hole/obj/k-pill",
		"amount2"  : 1,
		"amount7"  : 76896,
		"file8"    : "/open/gblade/obj/sa-head",
		"amount3"  : 143,
		"amount1"  : 1,
	]) );
	set( "light_up", 1 );
	set( "build", 10128 );
	set( "exits", ([
		"down"      : "/open/clan/sky-wu-chi/room/room400",
		"west"      : "/open/clan/sky-wu-chi/room/room397.c",
		"south"     : "/open/clan/sky-wu-chi/room/room400",
		"east"      : "/open/clan/sky-wu-chi/room/room400.c",
		"north"     : "/open/clan/sky-wu-chi/room/room400",
		"up"        : "/open/clan/sky-wu-chi/room/room400",
	]) );
	set( "long", @LONG

        此時你正走在一片樹林當中，濃蔭蔽日，枝椏上花朵盛開，萬紫千紅
    ，煞是好看。涼風襲襲，落英繽紛，紅花、白花、黃花、紫花，如一隻隻
    蝴蝶般繞著你身邊飛舞，你覺得彷若置身仙境。但你發現這樹林似乎按照
    某種方位排列成陣，你想起江湖上傳言東邪黃藥師精通天文地理，奇門遁
    甲，想必這樹林就是他依八卦五行所成的桃花陣了。四周的景色似乎沒什
    麼改變，你覺得有些迷失方向了......。

LONG);
	setup();
	replace_program(ROOM);
}

