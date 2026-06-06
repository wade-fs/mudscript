inherit ROOM;
void create() {
	set( "short", "維修零件室" );
	set( "owner", "icute" );
	set( "light_up", 1 );
	set( "object", ([
		"amount5"  : 1,
		"amount10" : 1,
		"amount2"  : 1,
		"file7"    : "/open/mogi/castle/obj/fire-king-head",
		"amount6"  : 1,
		"amount8"  : 835,
		"file1"    : "/open/beggar/obj/hat",
		"file6"    : "/open/mon/obj/ghost-cloak",
		"file2"    : "/open/mogi/dragon/obj/scale",
		"file3"    : "/open/mon/obj/ghost-legging",
		"file4"    : "/open/fire-hole/obj/w-pill",
		"file10"   : "/open/mon/obj/ghost-helmet",
		"file8"    : "/open/fire-hole/obj/b-pill",
		"amount1"  : 1,
		"file5"    : "/open/mon/obj/ghost-helmet",
		"amount3"  : 1,
		"amount7"  : 1,
		"amount4"  : 1017,
	]) );
	set( "build", 10278 );
	set( "exits", ([
		"west"      : "/open/clan/13_luck/room/room97.c",
	]) );
	set( "long", @LONG
   走進此間石室，數道耀眼的光茫閃爍不定，原來此地便是收藏著
   主要武器裝備的EQ室，只見武器櫃上擺滿了許多稀世利器，無
  論是劍、刀、棍、暗器、可謂是十八般武器樣樣齊全，可見幫主初創
  時亦花費了許多心血在於武器裝備的收集
LONG);
	setup();
	replace_program(ROOM);
}
