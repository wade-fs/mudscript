inherit ROOM;
void create() {
	set( "short", "CDROM的丹藥房" );
	set( "owner", "cdrom" );
	set( "object", ([
		"amount8"  : 938,
		"file4"    : "/open/fire-hole/obj/k-pill",
		"amount4"  : 317,
		"file6"    : "/open/fire-hole/obj/y-pill",
		"amount7"  : 1322,
		"file3"    : "/open/fire-hole/obj/r-pill",
		"amount10" : 281,
		"amount1"  : 925,
		"amount2"  : 1239,
		"file7"    : "/open/fire-hole/obj/p-pill",
		"amount3"  : 1330,
		"file8"    : "/open/mon/obj/mon-pill",
		"amount5"  : 745,
		"file10"   : "/open/mogi/castle/obj/sspill",
		"file1"    : "/open/fire-hole/obj/b-pill",
		"file9"    : "/open/mogi/castle/obj/ninepill",
		"amount9"  : 442,
		"file5"    : "/open/fire-hole/obj/w-pill",
		"file2"    : "/open/fire-hole/obj/g-pill",
		"amount6"  : 420,
	]) );
	set( "build", 11358 );
	set( "light_up", 1 );
	set( "exits", ([
		"south"     : "/open/clan/sky-wu-chi/room/room402.c",
		"ghost"     : "/open/clan/sky-wu-chi/room/room106.c",
		"west"      : "/open/clan/sky-wu-chi/room/room297.c",
		"down"      : "/open/clan/sky-wu-chi/room/room643",
		"east"      : "/open/clan/sky-wu-chi/room/room296.c",
		"chome"     : "/open/clan/sky-wu-chi/room/hall.c",
	]) );
	set( "long", @LONG
目前已儲存：
   ( 1) 白龍精元(white-dragon pill)
   ( 2) 藍龍精元(blue-dragon pill)
   ( 3) 綠龍精元(green-dragon pill)
   ( 4) 千年靈芝仙丹(thousand pill)
   ( 5) 紅龍精元(red-dragon pill)
   ( 6) 生生造化丹(sen sen pill)
   ( 7) 黃龍精元(yellow-dragon pill)
   ( 8) 龍王精元(dragon-king pill)
   ( 9) 毒龍精元(poison-dragon pill)
   (10) 九轉熊蛇丸(snake pill)
LONG);
	setup();
	replace_program(ROOM);
}
