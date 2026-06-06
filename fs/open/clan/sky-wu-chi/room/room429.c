inherit ROOM;
void create() {
	set( "short", "【秘密花園】" );
	set( "owner", "working" );
	set( "object", ([
		"amount8"  : 1,
		"file5"    : "/open/magic-manor/obj/hwa-je-icer",
		"file2"    : "/open/magic-manor/obj/evil-gwe-blade",
		"file1"    : "/open/magic-manor/obj/evil-kill-claw",
		"amount2"  : 1,
		"file9"    : "/open/magic-manor/obj/maun-shadow-blade",
		"amount7"  : 3,
		"amount5"  : 1,
		"file7"    : "/open/magic-manor/ghost/obj/trigram-pill",
		"file6"    : "/open/magic-manor/obj/dark-soul-dagger",
		"file8"    : "/open/magic-manor/obj/water-ball",
		"file3"    : "/open/magic-manor/obj/fon-sky-sword",
		"amount1"  : 1,
		"file4"    : "/open/magic-manor/obj/maun-shadow-blade",
		"amount9"  : 1,
		"amount3"  : 1,
		"amount6"  : 1,
		"amount4"  : 1,
	]) );
	set( "build", 10567 );
	set( "light_up", 1 );
	set( "exits", ([
		"north"     : "/open/clan/sky-wu-chi/room/room428.c",
		"south"     : "/open/clan/sky-wu-chi/room/room397",
	]) );
	set( "long", @LONG
    
        此時你正走在一片樹林當中，濃蔭蔽日，枝椏上花朵盛開，萬紫千紅
    ，煞是好看。涼風襲襲，落英繽紛，紅花、白花、黃花、紫花，如一隻隻
    蝴蝶般繞著你身邊飛舞，你覺得彷若置身仙境。但你發現這樹林似乎按照
    某種方位排列成陣，你想起江湖上傳言東邪黃藥師精通天文地理，奇門遁
    甲，想必這樹林就是他依八卦五行所成的桃花陣了。四周的景色似乎沒什
    麼改變，你覺得有些迷失方向了.

LONG);
	setup();
	replace_program(ROOM);
}
