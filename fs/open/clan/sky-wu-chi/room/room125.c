inherit ROOM;
void create() {
	set( "short", "空瓶子武器室1" );
	set( "object", ([
		"amount10" : 1,
		"amount4"  : 1,
		"file2"    : "/open/fire-hole/obj/r-pill",
		"amount9"  : 1,
		"amount1"  : 1,
		"amount7"  : 1,
		"file7"    : "/open/magic-manor/obj/fire-color-ribbon",
		"amount3"  : 1,
		"file4"    : "/open/mogi/castle/obj/fire-king-head",
		"amount2"  : 10,
		"file3"    : "/open/magic-manor/obj/soil-ball",
		"file1"    : "/open/magic-manor/obj/wood-ball",
		"file9"    : "/obj/gift/hobowdan",
		"amount5"  : 1,
		"file5"    : "/open/gblade/obj/sa-head",
		"file10"   : "/open/magic-manor/obj/evil-kill-claw",
	]) );
	set( "build", 10072 );
	set( "light_up", 1 );
	set( "exits", ([
		"west"      : "/open/clan/sky-wu-chi/room/room124.c",
		"east"      : "/open/clan/sky-wu-chi/room/room126",
	]) );
	set( "long", @LONG
這裡的武器是屬於比較平凡的,但也已經是非常不錯的一些武器
如 狂龍翔天破(crazy dragon)寒冰(icefan)天誅筆(ten pen)
尚方寶劍(god sword)金鋼指環(figring)穿龍劍(dragon sword)
雪影(iceblade)金鱗蟒邪(snake sword)日月神刀(sun-moon blade)
冰雪寒絲針(cold needle)

LONG);
	setup();
	replace_program(ROOM);
}
