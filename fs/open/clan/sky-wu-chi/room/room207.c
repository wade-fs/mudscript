inherit ROOM;
void create() {
	set( "short", "白素貞的家" );
	set( "owner", "sasaki" );
	set( "light_up", 1 );
	set( "object", ([
		"file7"    : "/open/quests/snake/npc/obj/helmet",
		"amount3"  : 1,
		"amount8"  : 38,
		"file1"    : "/obj/gift/shenliwan",
		"file4"    : "/open/mon/obj/ghost-cloak",
		"file5"    : "/open/quests/snake/npc/obj/snake_gem",
		"amount6"  : 1,
		"amount1"  : 1,
		"amount9"  : 1,
		"amount7"  : 1,
		"amount2"  : 1,
		"file3"    : "/daemon/class/fighter/ywleg",
		"amount4"  : 1,
		"file6"    : "/obj/stone/suipian",
		"file9"    : "/open/mogi/dragon/obj/scale",
		"file8"    : "/obj/stone/powder",
		"file2"    : "/daemon/class/fighter/ywboots",
		"amount5"  : 1,
	]) );
	set( "build", 10108 );
	set( "exits", ([
		"north"     : "/open/clan/sky-wu-chi/room/room70",
	]) );
	set( "long", @LONG
這是一個屬於$HIW$白素貞$NOR$的天地，每當他累了，都會回到這裡，休息，再出發。這是一個充滿了浪 
漫氣氛，柔和的燭光，好似在訴說她的一切。
你仔細一看，突然覺得有點怪。難道是白素貞回來，正在冬眠嗎？？於是你走到床邊大力一翻開床單突然有一 
團東西衝了出來。你仔細一看，原來是一隻小白貓(Cat)。


LONG);
	setup();
	replace_program(ROOM);
}
