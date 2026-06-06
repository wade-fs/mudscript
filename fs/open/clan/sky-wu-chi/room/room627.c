inherit ROOM;
void create() {
	set( "short", "Ddt-聚靈道倉庫總房" );
	set( "owner", "cong" );
	set( "object", ([
		"amount5"  : 1,
		"file5"    : "/open/magic-manor/fire/obj/fire-fan",
		"file1"    : "/open/magic-manor/fire/obj/fire-fan",
		"file9"    : "/open/magic-manor/fire/obj/fire-fan",
		"file8"    : "/open/magic-manor/water/obj/water-ribbon",
		"file7"    : "/open/magic-manor/water/obj/water-ribbon",
		"amount2"  : 1,
		"amount3"  : 1,
		"amount9"  : 1,
		"amount1"  : 1,
		"amount4"  : 1,
		"amount6"  : 1,
		"file3"    : "/open/magic-manor/fire/obj/fire-fan",
		"file4"    : "/open/magic-manor/fire/obj/fire-fan",
		"file2"    : "/open/magic-manor/water/obj/water-ribbon",
		"file6"    : "/open/magic-manor/fire/obj/fire-fan",
		"amount7"  : 1,
		"amount8"  : 1,
	]) );
	set( "build", 10015 );
	set( "exits", ([
		"gold"      : "/open/clan/sky-wu-chi/room/room632.c",
		"fire"      : "/open/clan/sky-wu-chi/room/room631.c",
		"wood"      : "/open/clan/sky-wu-chi/room/room629.c",
		"water"     : "/open/clan/sky-wu-chi/room/room628",
		"soil"      : "/open/clan/sky-wu-chi/room/room630.c",
		"out"       : "/open/clan/sky-wu-chi/room/hall.c",
	]) );
	set( "long", @LONG
愈至這裏，愈覺得兇險的感覺湧上了心頭，前方入目的是五條不
同的道路，從每條道路的那頭還不時的飄來不同色的靈光，靈光中還
夾帶著些許的殺傷力。
在你前方分別是金靈塔，木靈塔，火靈塔，土靈塔，水靈塔武器分別
放在各塔之內
LONG);
	setup();
	replace_program(ROOM);
}
