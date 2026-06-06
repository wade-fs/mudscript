inherit ROOM;
void create() {
	set( "short", "天邪峰" );
	set( "object", ([
		"file5"    : "/daemon/class/fighter/armband",
		"amount9"  : 1,
		"amount8"  : 1,
		"file4"    : "/open/mon/obj/ghost-helmet",
		"amount10" : 1,
		"amount6"  : 1,
		"file9"    : "/daemon/class/bonze/puty_pullium",
		"amount4"  : 1,
		"file6"    : "/open/gsword/obj/yuskirt",
		"amount7"  : 1,
		"file7"    : "/open/capital/guard/gring",
		"amount5"  : 1,
		"file8"    : "/open/ping/obj/gold_hand",
		"file10"   : "/open/mon/obj/ghost-legging",
	]) );
	set( "build", 10473 );
	set( "exits", ([
		"south"     : "/open/clan/13_luck/room/room179",
	]) );
	set( "light_up", 1 );
	set( "long", @LONG

    從魔界村往北方直走，便可以到達此處，有別於魔森林的詭異氣
氛，讓你感覺這裡似乎沒那麼危險，但是眼尖的你發現遠方好像有類
似雕像的物品，瞬間你腦中閃過一念頭，不會又要再來一次吧？想起
在魔森林的恐怖經驗，你決定收起你的好奇心，遠離這些雕像。記得
魔界村的人說過，傳聞這裡有三隻妖狐千萬不能見，因為見到的人從
來沒回來過。


LONG);
	setup();
	replace_program(ROOM);
}
