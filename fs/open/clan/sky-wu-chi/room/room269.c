inherit ROOM;
void create() {
	set( "short", "ring" );
	set( "owner", "hild" );
	set( "object", ([
		"amount2"  : 1,
		"amount4"  : 1,
		"file4"    : "/open/ghost-hole/obj/eq/ghost-ring",
		"amount7"  : 1,
		"amount5"  : 1,
		"file5"    : "/open/ghost-hole/obj/eq/ghost-ring",
		"file2"    : "/open/ghost-hole/obj/eq/ghost-ring",
		"file6"    : "/open/ghost-hole/obj/eq/ghost-ring",
		"file7"    : "/open/ghost-hole/obj/eq/ghost-ring",
		"amount6"  : 1,
	]) );
	set( "light_up", 1 );
	set( "build", 10004 );
	set( "exits", ([
		"east"      : "/open/clan/sky-wu-chi/room/room153.c",
		"chome"     : "/open/clan/sky-wu-chi/room/hall.c",
	]) );
	set( "long", @LONG
這是婆娑平常發呆的地方，也是他拿來接待朋友的地方，所
以常常會有很多人在這，又因為婆娑嗜茶如命，因此四周的環境
充滿了茶香，以及一些小板凳，不禁讓你覺得好像是老人的茶會
一樣，可是卻又充滿著讓你親近無比的感覺，所以你自然地坐了
起來一起喝杯茶囉，四周得擺設既簡單又樸素，因此四周看起來
又是如此的莊嚴。
LONG);
	setup();
	replace_program(ROOM);
}
