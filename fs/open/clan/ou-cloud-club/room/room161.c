inherit ROOM;
void create() {
	set( "short", "$HIR$藏$NOR$Φ$HIY$妖幻披肩$NOR$" );
	set( "object", ([
		"amount3"  : 1,
		"file1"    : "/open/mon/obj/ghost-cloak",
		"file8"    : "/open/mon/obj/ghost-cloak",
		"amount9"  : 1,
		"amount5"  : 1,
		"file6"    : "/open/mon/obj/ghost-cloak",
		"file5"    : "/open/mon/obj/ghost-cloak",
		"file3"    : "/open/mon/obj/ghost-cloak",
		"amount4"  : 1,
		"file4"    : "/open/mon/obj/ghost-cloak",
		"amount1"  : 1,
		"amount8"  : 1,
		"file9"    : "/open/mon/obj/ghost-cloak",
		"amount6"  : 1,
	]) );
	set( "light_up", 1 );
	set( "build", 23587 );
	set( "exits", ([
		"out"       : "/open/clan/ou-cloud-club/room/room264",
		"east"      : "/open/clan/ou-cloud-club/room/room207.c",
	]) );
	set( "long", @LONG
強烈的腐蝕妖氣朝著你迎面撲來，使你不得不運起全力抵擋這吞噬生命
的驚人殺氣，這裡封印的神器，原本屬於背叛天界，墮落至凡間的千年樹妖
--舞風揚所有，當他於千年前敗於天將之後，遭妖魂遺棄的肉身，被眾神調
製成為十二神器中少數具有妖氣的絕世裝備．

LONG);
	setup();
	replace_program(ROOM);
}
