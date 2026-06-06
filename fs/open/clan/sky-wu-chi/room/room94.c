inherit ROOM;
void create() {
	set( "short", "gk eq-belt" );
	set( "object", ([
		"file2"    : "/open/ghost-hole/obj/eq/ghost-belt",
		"amount8"  : 1,
		"amount2"  : 1,
		"file8"    : "/open/ghost-hole/obj/eq/ghost-belt",
	]) );
	set( "light_up", 1 );
	set( "build", 10029 );
	set( "exits", ([
		"east"      : "/open/clan/sky-wu-chi/room/room373.c",
		"west"      : "/open/clan/sky-wu-chi/room/room372",
		"south"     : "/open/clan/sky-wu-chi/room/room67.c",
	]) );
	set( "long", @LONG

尋尋覓覓，冷冷清清，悽悽慘慘戚戚。

乍暖還寒時候，最難將息。

三杯兩盞淡酒，怎敵他，晚來風急。

雁過也，正傷心，卻是舊時相識。

滿地黃花堆積，憔悴損，如今有誰堪摘?

守著窗兒，獨自怎生得黑？

梧桐更兼細雨，到黃昏，點點滴滴。

這次第，怎一箇，愁字了得！



LONG);
	setup();
	replace_program(ROOM);
}
