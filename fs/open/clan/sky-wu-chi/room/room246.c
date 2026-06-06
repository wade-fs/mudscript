inherit ROOM;
void create() {
	set( "short", "$HIR$藏劍閣$NOR$" );
	set( "item_desc", ([
		"window" : @ITEM
 在通過密道之後，你眼前出現三座大雕像，地上滿滿的劍痕，隱約可;感覺到一股剛硬之氣；除了三座雕像(statue)之外，還有一個極大的石門，門;上貼了數道古符….似乎在封印著極不祥的東西，門邊有一石碑(stone)，;石碑上好似刻有東西…。
ITEM,
	]) );
	set( "light_up", 1 );
	set( "object", ([
		"amount3"  : 1,
		"amount10" : 1,
		"amount1"  : 1,
		"file5"    : "/open/magic-manor/obj/fire-ball",
		"file8"    : "/open/mon/obj/flower-claw",
		"file10"   : "/open/gsword/obj1/blosword",
		"amount5"  : 1,
		"file3"    : "/open/mon/obj/thousand-nectar",
		"amount6"  : 1,
		"file6"    : "/open/capital/obj/4-1",
		"file1"    : "/open/mogi/castle/obj/fire_book",
		"amount7"  : 1,
		"file7"    : "/open/gsword/npc2/sadsword",
		"amount8"  : 1,
	]) );
	set( "build", 10054 );
	set( "exits", ([
		"west"      : "/open/clan/sky-wu-chi/room/room221.c",
		"east"      : "/open/clan/sky-wu-chi/room/room265.c",
	]) );
	set( "long", @LONG
踏入此處寶劍反映出冰冷的光芒，令人感到不顫而寒，一把把寶劍整齊
的排列在閣中，環視一圈四周的劍皆為罕見之神兵利器，不經讚嘆此人
之收藏，突然間看到一把泛出異樣紅色光芒的長劍立在中央，彷彿劍中
之神凝視天下，莫非這就是傳說中的靈劍====真。連陽劍(Sad Sword)？
LONG);
	setup();
	replace_program(ROOM);
}
