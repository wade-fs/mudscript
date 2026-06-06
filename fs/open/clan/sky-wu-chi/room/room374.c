inherit ROOM;
void create() {
	set( "short", "gk eq-armband" );
	set( "owner", "cong" );
	set( "light_up", 1 );
	set( "object", ([
		"amount3"  : 1,
		"file2"    : "/open/ghost-hole/obj/eq/ghost-armband",
		"file3"    : "/open/ghost-hole/obj/eq/ghost-armband",
		"amount2"  : 1,
	]) );
	set( "build", 10641 );
	set( "exits", ([
		"east"      : "/open/clan/sky-wu-chi/room/room97",
	]) );
	set( "long", @LONG

長命無絕衰

山無陵

江水為竭

冬雷震震夏雨雪

天地合

乃敢與君絕

LONG);
	setup();
	replace_program(ROOM);
}
