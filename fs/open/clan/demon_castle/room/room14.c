inherit ROOM;
void create() {
	set( "short", "ζ鑽石裝備室ζ" );
	set( "exits", ([
		"west"      : "/open/clan/demon_castle/room/room18",
	]) );
	set( "build", 10648 );
	set( "owner", "son" );
	set( "object", ([
		"file2"    : "/u/d/dhk/questsfan/obj/diamond_belt",
		"amount5"  : 1,
		"file6"    : "/u/d/dhk/questsfan/obj/diamond_legging",
		"amount3"  : 1,
		"file7"    : "/u/d/dhk/questsfan/obj/diamond_hands",
		"file10"   : "/open/mogi/castle/obj/blood-water",
		"amount6"  : 1,
		"amount1"  : 1,
		"file8"    : "/u/d/dhk/questsfan/obj/diamond_hairpin",
		"amount7"  : 1,
		"file4"    : "/u/d/dhk/questsfan/obj/diamond_boots",
		"file5"    : "/u/d/dhk/questsfan/obj/diamond_cloak",
		"amount9"  : 1,
		"amount10" : 1,
		"file9"    : "/open/mogi/castle/obj/blood-water",
		"amount8"  : 1,
		"file3"    : "/u/d/dhk/questsfan/obj/diamond_skirt",
		"file1"    : "/u/d/dhk/questsfan/obj/diamond_armor",
		"amount2"  : 1,
		"amount4"  : 1,
	]) );
	set( "long", @LONG

    這裡放滿了虹晶的裝備，其原料是用鑽石所提煉的，放入丹爐中
七七四十九天打造出來的最佳防禦裝備，可媲美魔龍裝備跟天界裝備
其配件共有八件，每一部份都會隨著持有者的身材而縮放到最適合主
人的大小，虹晶是一套很有靈性的裝備，並不是任何人都可以擁有。


妳發覺黃色的迷霧圍繞正在妳四周

LONG);
	setup();
	replace_program(ROOM);
}
