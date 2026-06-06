inherit ROOM;
void create() {
	set( "short", "魔界之路" );
	set( "item_desc", ([
		"map" : @ITEM

                  天邪峰(north)
                        o
                        o       
   炎龍谷(west)---魔界村(old man)---古堡(east)
                        o
                        o
                  魔森林(south)

ITEM,
	]) );
	set( "object", ([
		"amount1"  : 1,
		"amount3"  : 1,
		"file1"    : "/open/magic-manor/wood/obj/wood-sword",
		"amount5"  : 1,
		"file8"    : "/open/magic-manor/fire/obj/fire-fan",
		"file9"    : "/open/magic-manor/fire/obj/fire-fan",
		"amount7"  : 1,
		"file5"    : "/open/magic-manor/water/obj/water-ribbon",
		"file7"    : "/open/magic-manor/fire/obj/fire-fan",
		"file2"    : "/open/mogi/castle/obj/blood-water",
		"file3"    : "/open/magic-manor/water/obj/water-ribbon",
		"file10"   : "/obj/gift/xisuidan",
		"amount6"  : 1,
		"amount9"  : 1,
		"amount10" : 1,
		"amount2"  : 1,
		"file6"    : "/open/magic-manor/water/obj/water-ribbon",
		"amount8"  : 1,
		"file4"    : "/open/magic-manor/water/obj/water-ribbon",
		"amount4"  : 1,
	]) );
	set( "build", 10561 );
	set( "light_up", 1 );
	set( "exits", ([
		"west"      : "/open/clan/13_luck/room/room241.c",
		"east"      : "/open/clan/13_luck/room/room176.c",
		"south"     : "/open/clan/13_luck/room/room177",
		"out"       : "/open/clan/13_luck/room/room136.c",
		"north"     : "/open/clan/13_luck/room/room178",
	]) );
	set( "long", @LONG

    這裡就是傳說中的魔界之路，是由十三吉祥的前輩們用血所堆成
的路，回想起當年，前輩們腳踏七星塔，血濺魔森林，費盡千辛萬苦
才到達，這裡以魔界村為中心，四方分別是，西炎龍谷，北天邪峰，
南魔森林，東古堡，此處有前人留下的魔界地圖，十三的後人們，要
謹記前人的教誨，一定要血刃魔界的統治者焚天魔王，讓人間恢復正
常，讓十三吉祥永遠留名於世。

仔細的搜索後 發現路旁不起眼的牌子上就是傳說中的魔界地圖(map)


LONG);
	setup();
	replace_program(ROOM);
}
