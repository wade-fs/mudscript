inherit ROOM;
void create() {
	set( "short", "$HIM$十二藏刀房$NOR$" );
	set( "object", ([
		"amount10" : 1,
		"amount7"  : 1,
		"amount3"  : 1,
		"file5"    : "/open/mogi/dragon/obj/scale",
		"file7"    : "/open/magic-manor/obj/evil-gwe-blade",
		"file2"    : "/open/magic-manor/obj/lin-cloud-fan",
		"amount2"  : 1,
		"file1"    : "/open/magic-manor/obj/hwa-je-icer",
		"amount6"  : 1,
		"file8"    : "/open/mogi/dragon/obj/scale",
		"file4"    : "/open/mogi/dragon/obj/scale",
		"file6"    : "/open/magic-manor/obj/evil-kill-claw",
		"amount9"  : 1,
		"file3"    : "/open/magic-manor/ghost/obj/five-turn-ball",
		"amount8"  : 1,
		"amount1"  : 1,
		"file10"   : "/open/magic-manor/obj/fon-sky-sword",
		"file9"    : "/open/magic-manor/obj/maun-shadow-blade",
		"amount5"  : 1,
		"amount4"  : 1,
	]) );
	set( "owner", "enter" );
	set( "build", 11612 );
	set( "light_up", 1 );
	set( "exits", ([
		"east"      : "/open/clan/ou-cloud-club/room/room682",
		"north"     : "/open/clan/ou-cloud-club/room/room683",
	]) );
	set( "long", @LONG

    $HIC$十方無敵天下勢$NOR$    $HIB$二百餘載浮與沉$NOR$
    $HIR$藏鋒一生了塵世$NOR$    $HIY$刀術學究已天人$NOR$

牆上刻滿著短短二十八字正道出了此間主人刀
術無敵於天下故藏刀於此的心情，而此間藏有
天下間十把武林中人聞之喪膽的天兵神刀，但
也因其主人棄刀從武使其被塵封於此了．

LONG);
	setup();
	replace_program(ROOM);
}
