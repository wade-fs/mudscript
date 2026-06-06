inherit ROOM;
void create() {
	set( "short", "$HIC$欣$HIR$ソ$HIY$防具所$HIB$IV$NOR$" );
	set( "object", ([
		"file2"    : "/obj/gift/lingzhi",
		"amount7"  : 1,
		"file6"    : "/obj/gift/xiandan",
		"file10"   : "/obj/gift/xiandan",
		"amount10" : 1,
		"amount5"  : 1,
		"amount8"  : 1,
		"file5"    : "/obj/gift/unknowdan",
		"file8"    : "/obj/gift/xiandan",
		"amount2"  : 1,
		"file7"    : "/obj/gift/xiandan",
		"amount3"  : 1,
		"amount6"  : 1,
		"amount4"  : 1,
		"file3"    : "/obj/gift/xiandan",
		"file4"    : "/obj/gift/xiandan",
	]) );
	set( "build", 10085 );
	set( "light_up", 1 );
	set( "exits", ([
		"south"     : "/open/clan/sky-wu-chi/room/room187.c",
		"west"      : "/open/clan/sky-wu-chi/room/room108",
	]) );
	set( "long", @LONG
當你到了欣的房間便不自覺的感覺到了一股淡淡的香氣與悠悠的樂音圍;繞在你的四周，天花板上所映射而下的藍色光芒均勻的散佈在房間的每個角落﹞@張;華麗的巨大藍寶石床正擺放在你的北邊，在你的南邊，你看到一座古色古香的檀木製;書櫥，而你的西邊則擺放著一個巨大的古瓷玉瓶，你的東方有一面巨大的藍寶石牆，;你可以透過藍寶石牆看到整個狂想空間完全的呈現在你的面前。

LONG);
	setup();
	replace_program(ROOM);
}
