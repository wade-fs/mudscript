inherit ROOM;
void create() {
	set( "short", "$HIG$十二藏劍室$NOR$" );
	set( "owner", "enter" );
	set( "object", ([
		"amount10" : 1,
		"file5"    : "/open/magic-manor/obj/lunar-heart",
		"amount7"  : 1,
		"file2"    : "/open/magic-manor/obj/lunar-heart",
		"file7"    : "/open/magic-manor/obj/lunar-heart",
		"amount2"  : 1,
		"file1"    : "/open/magic-manor/obj/lunar-heart",
		"amount6"  : 1,
		"file6"    : "/open/magic-manor/obj/lunar-heart",
		"file4"    : "/open/magic-manor/obj/lunar-heart",
		"file8"    : "/open/magic-manor/obj/lunar-heart",
		"amount9"  : 1,
		"amount8"  : 1,
		"amount1"  : 1,
		"file10"   : "/open/magic-manor/obj/lunar-heart",
		"file9"    : "/open/magic-manor/obj/lunar-heart",
		"amount5"  : 1,
		"amount4"  : 1,
	]) );
	set( "build", 12075 );
	set( "light_up", 1 );
	set( "exits", ([
		"west"      : "/open/clan/ou-cloud-club/room/room684",
		"north"     : "/open/clan/ou-cloud-club/room/room681",
	]) );
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
