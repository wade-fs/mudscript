inherit ROOM;
void create() {
	set( "short", "$BRED$時$BGRN$空$BYEL$內$BBLU$力$BMAG$房$BCYN$2$NOR$" );
	set( "owner", "agilent" );
	set( "object", ([
		"file5"    : "/open/firedancer/npc/eq/r_boots",
		"amount1"  : 125,
		"file3"    : "/open/gsword/obj/may_ring",
		"amount4"  : 1,
		"file1"    : "/open/fire-hole/obj/b-pill",
		"file2"    : "/open/poison/obj/armband1",
		"amount2"  : 1,
		"file6"    : "/open/firedancer/npc/eq/r_pants",
		"file7"    : "/open/killer/memory/static",
		"amount5"  : 1,
		"amount6"  : 1,
		"file4"    : "/open/firedancer/npc/eq/r_hands",
		"amount3"  : 1,
		"amount7"  : 1,
	]) );
	set( "build", 10121 );
	set( "exits", ([
		"north"     : "/open/clan/time-limit/room/room99",
	]) );
	set( "long", @LONG
火龍之鱗(Fire-dragon ring) add 10     青蛇護符(Snake amulet) add 10
銀鷹頭盔(Silver-hawk) add 30          古龍紋玉佩(Dragon_gem) add 50(對fighter有效)
朱雀護套(Rose finch's hands) add 4    朱雀羅裙(Rose finch's skirt) add 1
朱雀雲靴(Rose finch's boots) add 3    魔龍睛戒(Mdragon-ring) add 5
淨水光之戒(Light-ring) add 7          藍龍精元(Blue-dragon pill) add 25暫時

LONG);
	setup();
	replace_program(ROOM);
}
