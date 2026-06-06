inherit ROOM;
void create() {
	set( "short", "$HIC$忘臺$NOR$" );
	set( "owner", "spicy" );
	set( "object", ([
		"amount8"  : 1,
		"file6"    : "/open/ghost-hole/obj/light-spirit",
		"file1"    : "/open/ghost-hole/obj/light-spirit",
		"amount6"  : 1,
		"file8"    : "/open/ghost-hole/obj/fire-spirit",
		"amount5"  : 1,
		"amount1"  : 1,
		"file7"    : "/open/mogi/castle/obj/ninepill",
		"file5"    : "/open/ghost-hole/obj/fire-spirit",
		"amount4"  : 200,
		"file3"    : "/open/mogi/castle/obj/ninepill",
		"file10"   : "/open/mogi/castle/obj/ninepill",
		"amount3"  : 200,
		"amount7"  : 200,
		"file4"    : "/open/mogi/castle/obj/ninepill",
		"amount10" : 200,
	]) );
	set( "build", 13271 );
	set( "item_desc", ([
		"monpo" : @ITEM
你想喝喝孟婆湯嗎???        
ITEM,
	]) );
	set( "light_up", 1 );
	set( "exits", ([
		"east"      : "/open/clan/orient/room/room49",
	]) );
	set( "long", @LONG
                 ╔═════════════════╗
                     ║╒═══╤═══╤═══╤═══╕║
                     ║│  口  │  欲  │  再  │  為  │║
                     ║│  與  │  生  │  要  │  人  │║
                     ║│  心  │  福  │  為  │  容  │║
                     ║│  同  │  地  │  人  │  易  │║
                     ║│  卻  │  無  │  恐  │  做  │║
                     ║│  不  │  難  │  更  │  人  │║
                     ║│  難  │  處  │  難  │  難  │║
                     ║│  。  │  ；  │  。  │  ；  │║
                     ║╘═══╧═══╧═══╧═══╛║
                     ╚═════════════════╝

這裡就是俗稱孟婆亭的醧忘臺。所有的鬼魂在轉世前，都要喝下醧忘湯(孟婆湯)。
你看到專門灌準備投胎陰魂迷湯的孟婆神MonPo，對你親切的笑著。

LONG);
	setup();
	replace_program(ROOM);
}
