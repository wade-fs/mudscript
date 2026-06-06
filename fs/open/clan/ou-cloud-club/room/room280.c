inherit ROOM;
void create() {
	set( "short", "$HIR$藏$NOR$Φ$HIY$幻紋妖爪$NOR$" );
	set( "object", ([
		"amount8"  : 1,
		"amount4"  : 1,
		"amount1"  : 1,
		"file6"    : "/open/mon/obj/ghost-claw",
		"amount7"  : 1,
		"file8"    : "/open/mon/obj/ghost-claw",
		"amount2"  : 1,
		"file7"    : "/open/mon/obj/ghost-claw",
		"amount10" : 1,
		"file2"    : "/open/mon/obj/ghost-claw",
		"file3"    : "/open/mon/obj/ghost-claw",
		"amount9"  : 1,
		"file1"    : "/open/mon/obj/ghost-claw",
		"file10"   : "/open/mon/obj/ghost-claw",
		"amount6"  : 1,
		"file4"    : "/open/mon/obj/ghost-claw",
		"amount3"  : 1,
		"file5"    : "/open/mon/obj/ghost-claw",
		"amount5"  : 1,
		"file9"    : "/open/mon/obj/ghost-claw",
	]) );
	set( "build", 10030 );
	set( "light_up", 1 );
	set( "exits", ([
		"east"      : "/open/clan/ou-cloud-club/room/room279",
		"west"      : "/open/clan/ou-cloud-club/room/room206.c",
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
