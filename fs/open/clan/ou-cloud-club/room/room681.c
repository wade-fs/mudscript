inherit ROOM;
void create() {
	set( "short", "$HIG$十二藏劍室$NOR$" );
	set( "object", ([
		"amount1"  : 1,
		"file2"    : "/open/magic-manor/obj/sun-heart",
		"file4"    : "/open/magic-manor/obj/sun-heart",
		"file1"    : "/open/magic-manor/obj/sun-heart",
		"amount2"  : 1,
		"amount5"  : 1,
		"file5"    : "/open/magic-manor/obj/sun-heart",
		"amount3"  : 1,
		"file3"    : "/open/magic-manor/obj/sun-heart",
		"amount4"  : 1,
	]) );
	set( "owner", "enter" );
	set( "build", 10026 );
	set( "exits", ([
		"out"       : "/open/clan/ou-cloud-club/room/room4.c",
		"west"      : "/open/clan/ou-cloud-club/room/room683.c",
		"south"     : "/open/clan/ou-cloud-club/room/room682",
	]) );
	set( "light_up", 1 );
	set( "long", @LONG

    $HIC$十方無敵天下勢$NOR$    $HIB$二百餘載浮與沉$NOR$
    $HIR$藏鋒一生了塵世$NOR$    $HIY$劍術學究已天人$NOR$

牆上刻滿著短短二十八字正道出了此間主人劍
術無敵於天下故藏劍於此的心情，而此間藏有
天下間十把武林中人聞之喪膽的天兵神劍，但
也因其主人棄劍從武使其被塵封於此了．

LONG);
	setup();
	replace_program(ROOM);
}
