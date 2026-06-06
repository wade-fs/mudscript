inherit ROOM;
void create() {
	set( "short", "嘴巴" );
	set( "owner", "saintberii" );
	set( "item_desc", ([
		"舌頭" : @ITEM
一跟蠕動的舌頭，你看著它不斷的蠕動...蠕動....
ITEM,
	]) );
	set( "object", ([
		"amount6"  : 1,
		"amount3"  : 13,
		"file8"    : "/obj/stone/suipian",
		"file5"    : "/open/mogi/castle/obj/leave",
		"amount8"  : 3,
		"file6"    : "/open/mogi/castle/obj/leave",
		"amount7"  : 1,
		"file3"    : "/open/mogi/castle/obj/ninepill",
		"file4"    : "/open/mogi/castle/obj/fire_book",
		"amount10" : 2,
		"amount2"  : 81,
		"file2"    : "/obj/stone/powder",
		"amount5"  : 1,
		"file7"    : "/open/magic-manor/obj/maun-shadow-blade",
		"amount1"  : 161,
		"amount4"  : 1,
		"file10"   : "/obj/stone/jiao",
		"file1"    : "/open/mon/obj/mon-pill",
		"file9"    : "/open/mon/obj/ghost-helmet",
		"amount9"  : 1,
	]) );
	set( "build", 10077 );
	set( "light_up", 1 );
	set( "exits", ([
		"chome"     : "/open/clan/sky-wu-chi/room/hall",
		"north"     : "/open/clan/sky-wu-chi/room/room537",
	]) );
	set( "long", @LONG
這是一個人的嘴巴，是疫病進入人體的門戶。
俗語說：禍從口出，病從口入，口腔對疫病而言正
如同自家大門一般。你眼前的嘴巴擁有一口整齊而
雪白的牙齒及鮮紅而靈動的小舌，每當這精巧的小
舌活動時，都讓你不禁想像擁有它的是怎樣的美女
呢？

LONG);
	setup();
	replace_program(ROOM);
}
