inherit ROOM;
void create() {
	set( "short", "十三刀堂" );
	set( "owner", "roar" );
	set( "object", ([
		"amount8"  : 1,
		"amount7"  : 1,
		"file2"    : "/open/ghost-hole/obj/eq/ghost-ring",
		"file5"    : "/open/ghost-hole/obj/eq/ghost-ring",
		"amount1"  : 1,
		"file1"    : "/open/ghost-hole/obj/eq/ghost-ring",
		"file7"    : "/open/ghost-hole/obj/eq/ghost-ring",
		"amount6"  : 1,
		"amount5"  : 1,
		"file8"    : "/open/ghost-hole/obj/eq/ghost-ring",
		"amount2"  : 1,
		"file6"    : "/open/ghost-hole/obj/eq/ghost-ring",
	]) );
	set( "build", 12633 );
	set( "light_up", 1 );
	set( "exits", ([
		"west"      : "/open/clan/13_luck/room/room391",
		"east"      : "/open/clan/13_luck/room/room393",
	]) );
	set( "long", @LONG

    一扇桃紅色的木門豎立在你的眼前，和十三吉祥詭異的氣氛有點不大
相襯，不過仔細一想，十三吉祥內似乎蠻多以桃木為材質的裝飾，難道跟
太歲的武功會有關係嗎??這十三刀堂也是由浪子搜羅回來的高手所掌理的
，傳說中這裡的堂主以前是個名滿天下的高手，不知為何落魄到此，不過
他所掌理的刀堂門眾各個武功不弱，深受太歲信賴。

LONG);
	setup();
	replace_program(ROOM);
}
