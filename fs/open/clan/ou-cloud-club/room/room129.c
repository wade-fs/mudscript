inherit ROOM;
void create() {
	set( "short", "涼 亭" );
	set( "object", ([
		"file1"    : "/open/mogi/castle/obj/ninepill",
		"file8"    : "/open/magic-manor/obj/magic-sign",
		"file6"    : "/open/fire-hole/obj/p-pill",
		"amount1"  : 17,
		"amount6"  : 5,
		"amount8"  : 1,
		"amount5"  : 5,
		"file4"    : "/open/mogi/dragon/obj/scale",
		"amount4"  : 1,
		"file5"    : "/open/fire-hole/obj/b-pill",
	]) );
	set( "light_up", 1 );
	set( "build", 10306 );
	set( "exits", ([
		"south"     : "/open/clan/ou-cloud-club/room/room448.c",
		"west"      : "/open/clan/ou-cloud-club/room/room322.c",
		"up"        : "/open/clan/ou-cloud-club/room/room182",
		"east"      : "/open/clan/ou-cloud-club/room/room321.c",
	]) );
	set( "long", @LONG
前 無 古 者 ， 後 無 來 者

涼的休息之處，看起來相當整齊乾淨
非常舒服的感覺，也可是涼修煉神功之處
明日的瀧山之星，在這便可感受到她的氣魄
雖然只是女子，但看她精妙的武功，實在不輸男子
從她身上發出的淡淡體香，令人難以想像她是瀧山第一大師姐
LONG);
	setup();
	replace_program(ROOM);
}
