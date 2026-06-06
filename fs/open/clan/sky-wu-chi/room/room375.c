inherit ROOM;
void create() {
	set( "short", "gk eq-legging" );
	set( "owner", "cong" );
	set( "object", ([
		"amount6"  : 1,
		"amount5"  : 1,
		"amount7"  : 1,
		"amount8"  : 1,
		"amount10" : 1,
		"file2"    : "/open/ghost-hole/obj/eq/ghost-leggings",
		"amount2"  : 1,
		"file5"    : "/open/ghost-hole/obj/eq/ghost-leggings",
		"file10"   : "/open/ghost-hole/obj/eq/ghost-leggings",
		"file7"    : "/open/ghost-hole/obj/eq/ghost-leggings",
		"amount4"  : 1,
		"file1"    : "/open/ghost-hole/obj/eq/ghost-leggings",
		"amount1"  : 1,
		"file4"    : "/open/ghost-hole/obj/eq/ghost-leggings",
		"file6"    : "/open/ghost-hole/obj/eq/ghost-leggings",
		"file8"    : "/open/ghost-hole/obj/eq/ghost-leggings",
	]) );
	set( "light_up", 1 );
	set( "build", 10140 );
	set( "exits", ([
		"north"     : "/open/clan/sky-wu-chi/room/room95",
	]) );
	set( "long", @LONG

湖上風來波浩渺．秋已暮紅稀香少．

水光山色與人親．說不盡．無窮好

蓮子已成荷葉老．青露洗蘋花汀草．

眠沙鷗鷺不回頭．似也恨．人歸早



LONG);
	setup();
	replace_program(ROOM);
}
