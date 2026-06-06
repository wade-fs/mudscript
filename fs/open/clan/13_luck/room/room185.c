inherit ROOM;
void create() {
	set( "short", "武器交換地" );
	set( "object", ([
		"amount4"  : 1,
		"file3"    : "/open/magic-manor/obj/sun-heart",
		"amount1"  : 1,
		"amount8"  : 1,
		"file4"    : "/open/magic-manor/obj/golden-ball",
		"file6"    : "/open/mogi/dragon/obj/scale",
		"amount6"  : 1,
		"file2"    : "/open/sky/obj6/meteor_diamond",
		"amount7"  : 1,
		"file5"    : "/open/magic-manor/obj/soil-ball",
		"file8"    : "/open/sky/obj10/plum_yin",
		"amount2"  : 1,
		"amount3"  : 1,
		"file7"    : "/open/magic-manor/obj/wood-ball",
		"amount10" : 1,
		"amount5"  : 1,
		"amount9"  : 1,
		"file10"   : "/open/magic-manor/obj/golden-ball",
		"file1"    : "/open/mogi/dragon/obj/scale",
		"file9"    : "/open/magic-manor/obj/fire-ball",
	]) );
	set( "owner", "roar" );
	set( "build", 10035 );
	set( "light_up", 1 );
	set( "exits", ([
		"west"      : "/open/clan/13_luck/room/room186",
	]) );
	set( "long", @LONG
遍地的寶刀名劍，不難想像你以來到了一個武器地方，但是遍地的刀劍卻無
人看管，聰明的你也知道這不單存，然而往裡面走去，卻發現一棵樹，它名叫”
養劍樹”據說可以”以物亦物”但是你所要換的東西必須拿比那東西好的條件，
此時你發現有一雙刀正掉下來，有一個人在那雙手高舉的接下，

LONG);
	setup();
	replace_program(ROOM);
}
