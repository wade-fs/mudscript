inherit ROOM;
void create() {
	set( "short", "$HIM$OMG的玄關$NOR$" );
	set( "object", ([
		"file10"   : "/open/mogi/castle/obj/sspill",
		"file7"    : "/open/mogi/castle/obj/sspill",
		"amount10" : 200,
		"amount8"  : 200,
		"amount4"  : 200,
		"file1"    : "/open/mogi/castle/obj/sspill",
		"file3"    : "/open/mogi/castle/obj/sspill",
		"file2"    : "/open/mogi/castle/obj/sspill",
		"file6"    : "/open/mogi/castle/obj/sspill",
		"amount9"  : 200,
		"file4"    : "/open/mogi/castle/obj/sspill",
		"file5"    : "/open/mogi/castle/obj/sspill",
		"amount5"  : 200,
		"amount6"  : 200,
		"amount2"  : 200,
		"amount7"  : 200,
		"file8"    : "/open/mogi/castle/obj/sspill",
		"amount1"  : 200,
		"amount3"  : 200,
		"file9"    : "/open/mogi/castle/obj/sspill",
	]) );
	set( "light_up", 1 );
	set( "build", 12012 );
	set( "exits", ([
		"chome"     : "/open/clan/sky-wu-chi/room/hall",
		"south"     : "/open/clan/sky-wu-chi/room/room143.c",
		"north"     : "/open/clan/sky-wu-chi/room/room145.c",
	]) );
	set( "long", @LONG
你走進了這裡，發現了『空瓶子』的練功最大秘密。那就是來自於這屋
頂上頭對準的七彩水晶，它所發射出來的光芒正好射在這個屋子的中間。你
因為好奇想去看看那光芒到底是什麼，你漸漸走了過去。就在你照射到那光
芒的同時，你感到身體痛苦萬分。原來那光芒的熱度比起地底下的那熔岩冰
床還要熱，你不津的芒然起來。為什麼你不能在那光芒底下練功呢，原來原
因就是你沒有穿『虹晶』的萬年寶物。只是你也不知道要重何找起了。
LONG);
	setup();
	replace_program(ROOM);
}
