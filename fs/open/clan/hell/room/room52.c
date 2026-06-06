inherit ROOM;
void create() {
	set( "short", "$HIW$黑輪臥房 - $HIC$武器室$NOR$" );
	set( "owner", "radio" );
	set( "object", ([
		"amount9"  : 1,
		"file3"    : "/open/killer/headkill/obj/world_dag",
		"file10"   : "/open/ping/obj/cloud_fan",
		"amount5"  : 1,
		"amount4"  : 1,
		"file4"    : "/daemon/class/fighter/figring",
		"amount1"  : 1,
		"file1"    : "/open/ping/obj/iceger",
		"amount10" : 1,
		"amount6"  : 1,
		"file6"    : "/open/ping/obj/iceger",
		"file9"    : "/open/wind-rain/obj/bird-blade",
		"file5"    : "/open/gsword/obj/dragon-sword",
		"amount3"  : 1,
	]) );
	set( "item_desc", ([
		"dragon_sword" : @ITEM
此劍乃是藏於黃金城內，傳說中拿了便能
使功力增強數倍的神劍，但若是內力不夠，則
無法駕馭此劍，反而會被狂氣所吞噬，看來也
只有劍魔黑輪才夠格拿此劍阿

ITEM,
	]) );
	set( "build", 10760 );
	set( "exits", ([
		"west"      : "/open/clan/hell/room/room48",
		"north"     : "/open/clan/hell/room/room48",
	]) );
	set( "light_up", 1 );
	set( "long", @LONG
這裡是劍魔黑輪放置武器的地方，房間裡
滿是不常見到的武器‧其中更有武林七大奇兵
器中的火龍刀、伏魔花靈劍等，而在這房間中
央放置的正是傳說中黃金城內所藏的

                雷神青龍劍(Dragon_sword)


LONG);
	setup();
	replace_program(ROOM);
}
