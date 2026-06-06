inherit ROOM;
void create() {
	set( "short", "$HIR$藏$NOR$Φ$HIY$妖幻護膝$NOR$" );
	set( "object", ([
		"amount10" : 1,
		"amount8"  : 1,
		"amount7"  : 1,
		"amount5"  : 1,
		"amount9"  : 1,
		"file8"    : "/open/mon/obj/ghost-legging",
		"amount3"  : 1,
		"file6"    : "/open/mon/obj/ghost-legging",
		"amount1"  : 1,
		"file1"    : "/open/mon/obj/ghost-legging",
		"file2"    : "/open/mon/obj/ghost-legging",
		"amount6"  : 1,
		"file7"    : "/open/mon/obj/ghost-legging",
		"file5"    : "/open/mon/obj/ghost-legging",
		"file4"    : "/open/mon/obj/ghost-legging",
		"amount2"  : 1,
		"amount4"  : 1,
		"file9"    : "/open/mon/obj/ghost-legging",
		"file3"    : "/open/mon/obj/ghost-legging",
		"file10"   : "/open/mon/obj/ghost-legging",
	]) );
	set( "build", 13474 );
	set( "light_up", 1 );
	set( "exits", ([
		"west"      : "/open/clan/ou-cloud-club/room/room205",
		"east"      : "/open/clan/ou-cloud-club/room/room271",
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
