inherit ROOM;
void create() {
	set( "short", "LEON 御用房" );
	set( "owner", "adeyzit" );
	set( "object", ([
		"amount10" : 8,
		"amount7"  : 10,
		"amount8"  : 8,
		"amount3"  : 85,
		"amount1"  : 51,
		"amount4"  : 1,
		"file5"    : "/open/mogi/castle/obj/ninepill",
		"amount5"  : 265,
		"amount6"  : 4215,
		"amount2"  : 1,
		"file9"    : "/open/mogi/castle/obj/sspill",
		"file3"    : "/obj/stone/powder",
		"file2"    : "/open/capital/obj/book",
		"file4"    : "/obj/stone/jiao",
		"amount9"  : 175,
		"file6"    : "/open/killer/obj/atman_pill",
		"file8"    : "/open/fire-hole/obj/r-pill",
		"file7"    : "/obj/stone/suipian",
		"file10"   : "/open/fire-hole/obj/k-pill",
		"file1"    : "/open/mon/obj/mon-pill",
	]) );
	set( "build", 10033 );
	set( "exits", ([
		"west"      : "/open/clan/13_luck/room/room749.c",
		"north"     : "/open/clan/13_luck/room/room580.c",
		"east"      : "/open/clan/13_luck/room/room745.c",
		"south"     : "/open/clan/13_luck/room/room763.c",
	]) );
	set( "light_up", 1 );
	set( "long", @LONG
   
    ㄧ走進房間, 就看到大大的LEON四個字, 這是LEON的個人專
屬房間, 裡面到處都是垃圾, 可見LEON真是一個相當懶惰的人, 
不過, 無論何時都可以看到LEON在房間裡TIN FORCE 可見他真的
是把時間都花在練功上面, 頓時之間又覺得情有可原

                      閒人勿進喔

LONG);
	setup();
	replace_program(ROOM);
}
