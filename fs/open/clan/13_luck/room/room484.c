inherit ROOM;
void create() {
	set( "short", "aaaaa7" );
	set( "owner", "mill" );
	set( "object", ([
		"amount4"  : 5,
		"file3"    : "/open/fire-hole/obj/g-pill",
		"amount1"  : 5,
		"file1"    : "/open/fire-hole/obj/b-pill",
		"file2"    : "/open/fire-hole/obj/r-pill",
		"amount3"  : 65,
		"file4"    : "/open/fire-hole/obj/b-pill",
		"amount2"  : 70,
	]) );
	set( "build", 10006 );
	set( "light_up", 1 );
	set( "exits", ([
		"west"      : "/open/clan/13_luck/room/room404",
	]) );
	set( "long", @LONG

    碩大的琉璃建築，紅漆大門加上兩根龍形大石柱，整個寺廟看起來
是何等的雄偉。慈航寺供奉的是如來、無金爐張火，只有鮮花素果、紅
蠋沉香，還有頌經的僧人。肅穆莊嚴的佛像，伴隨清心悅耳的梵樂，整
間寺廟氣氛是如此的神聖。

LONG);
	setup();
	replace_program(ROOM);
}
