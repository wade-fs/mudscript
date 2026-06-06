inherit ROOM;
void create() {
	set( "short", "奇門八陣" );
	set( "owner", "herozero" );
	set( "exits", ([
		"east"      : "/open/clan/sky-wu-chi/room/room148",
		"west"      : "/open/clan/sky-wu-chi/room/room18.c",
		"south"     : "/open/clan/sky-wu-chi/room/room97",
	]) );
	set( "object", ([
		"amount10" : 1,
		"file8"    : "/open/mogi/castle/obj/ninepill",
		"file6"    : "/obj/stone/suipian",
		"file10"   : "/open/magic-manor/obj/wood-ball",
		"file4"    : "/open/ping/obj/poison_pill",
		"amount1"  : 148,
		"amount8"  : 127,
		"amount2"  : 13,
		"file9"    : "/open/magic-manor/obj/fire-ball",
		"amount7"  : 1,
		"amount4"  : 10,
		"amount6"  : 150,
		"file7"    : "/obj/gift/xisuidan",
		"file2"    : "/obj/stone/jiao",
		"amount3"  : 1,
		"file1"    : "/obj/stone/powder",
		"amount9"  : 1,
		"amount5"  : 49,
		"file5"    : "/open/mon/obj/mon-pill",
		"file3"    : "/open/magic-manor/obj/water-ball",
	]) );
	set( "light_up", 1 );
	set( "build", 10095 );
	set( "long", @LONG
逃出了結界，不遠處似乎有間小屋，在這種雞不生蛋的地方有人
住，真是太神奇了，你不禁加快了腳步，想過去一探究竟，走著走著
，四周的景像突然間起了大變化，看著瞬息萬變的環境，你不禁冷汗
直流，完了，運氣怎麼這麼背，離開了結界，卻踩進了傳說中的奇門
八陣。
LONG);
	setup();
	replace_program(ROOM);
}
