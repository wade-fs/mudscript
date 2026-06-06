inherit ROOM;
void create() {
	set( "short", "$HIM$十二藏刀房$NOR$" );
	set( "object", ([
		"amount1"  : 1,
		"file2"    : "/open/ghost-hole/obj/light-spirit",
		"amount6"  : 1,
		"file3"    : "/open/ghost-hole/obj/fire-spirit",
		"amount8"  : 1,
		"file6"    : "/open/ghost-hole/obj/fire-spirit",
		"amount10" : 1,
		"file8"    : "/open/ghost-hole/obj/light-spirit",
		"amount9"  : 1,
		"file9"    : "/open/ghost-hole/obj/fire-spirit",
		"file10"   : "/open/ghost-hole/obj/fire-spirit",
		"amount2"  : 1,
		"amount3"  : 1,
		"file1"    : "/open/ghost-hole/obj/light-spirit",
		"file7"    : "/open/ghost-hole/obj/light-spirit",
		"amount4"  : 1,
		"amount7"  : 1,
		"file4"    : "/open/mogi/dragon/obj/scale",
	]) );
	set( "owner", "enter" );
	set( "build", 10844 );
	set( "light_up", 1 );
	set( "exits", ([
		"east"      : "/open/clan/ou-cloud-club/room/room681",
		"south"     : "/open/clan/ou-cloud-club/room/room684",
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
