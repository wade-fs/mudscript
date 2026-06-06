inherit ROOM;
void create() {
	set( "short", "$HIG$十二藏劍室$NOR$" );
	set( "owner", "enter" );
	set( "object", ([
		"amount5"  : 1,
		"file3"    : "/obj/gift/xiandan",
		"file10"   : "/open/magic-manor/ghost/obj/five-turn-ball",
		"file8"    : "/open/magic-manor/ghost/obj/five-turn-ball",
		"amount9"  : 1,
		"file4"    : "/obj/gift/unknowdan",
		"file6"    : "/obj/gift/xiandan",
		"amount10" : 1,
		"file9"    : "/obj/gift/xiandan",
		"amount4"  : 1,
		"file7"    : "/open/ping/obj/poison_pill",
		"file1"    : "/open/ping/obj/poison_pill",
		"amount7"  : 1000,
		"amount1"  : 1000,
		"amount2"  : 1,
		"amount8"  : 1,
		"file5"    : "/obj/gift/xisuidan",
		"amount6"  : 1,
		"file2"    : "/obj/gift/hobowdan",
		"amount3"  : 1,
	]) );
	set( "build", 10952 );
	set( "light_up", 1 );
	set( "exits", ([
		"south"     : "/open/clan/ou-cloud-club/room/room180",
		"up"        : "/open/clan/ou-cloud-club/room/room145",
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
