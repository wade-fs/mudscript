inherit ROOM;
void create() {
	set( "short", "$HIY$≡冥魔甲冑Ⅱ≡$NOR$" );
	set( "light_up", 1 );
	set( "object", ([
		"amount8"  : 1,
		"amount1"  : 1,
		"file3"    : "/open/ghost-hole/obj/eq/ghost-armor",
		"file6"    : "/open/ghost-hole/obj/eq/ghost-armor",
		"amount5"  : 1,
		"amount3"  : 1,
		"amount4"  : 1,
		"amount6"  : 1,
		"amount7"  : 1,
		"file10"   : "/open/ghost-hole/obj/eq/ghost-armor",
		"file5"    : "/open/ghost-hole/obj/eq/ghost-armor",
		"file2"    : "/open/ghost-hole/obj/eq/ghost-armor",
		"file1"    : "/open/ghost-hole/obj/eq/ghost-armor",
		"amount2"  : 1,
		"file4"    : "/open/ghost-hole/obj/eq/ghost-armor",
		"file9"    : "/open/ghost-hole/obj/eq/ghost-armor",
		"amount9"  : 1,
		"amount10" : 1,
		"file8"    : "/open/ghost-hole/obj/eq/ghost-armor",
		"file7"    : "/open/ghost-hole/obj/eq/ghost-armor",
	]) );
	set( "build", 10831 );
	set( "exits", ([
		"down"      : "/open/clan/ou-cloud-club/room/room365",
	]) );
	set( "long", @LONG
    甲冑冥魔甲冑冥魔甲冑冥魔甲冑冥魔甲冑冥魔甲冑
冥魔甲冑冥魔甲冑冥魔甲冑冥魔甲冑冥魔甲冑冥魔甲冑
冥魔甲冑冥魔甲冑冥魔甲冑冥魔甲冑冥魔甲冑冥魔甲冑
冥魔甲冑冥魔甲冑冥魔甲冑冥魔甲冑冥魔甲冑冥魔甲冑
冥魔甲冑冥魔甲冑冥魔甲冑冥魔甲冑冥魔甲冑冥魔甲冑
冥魔甲冑冥魔甲冑冥魔甲冑冥魔甲冑冥魔甲冑冥魔甲冑
冥魔甲冑冥魔甲冑冥魔甲冑冥魔甲冑冥魔甲冑冥魔甲冑
LONG);
	setup();
	replace_program(ROOM);
}
