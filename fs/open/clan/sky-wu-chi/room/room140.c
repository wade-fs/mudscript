inherit ROOM;
void create() {
	set( "short", "$HIY$寒風山莊$NOR$--$GRN$道館旁小徑$NOR$ " );
	set( "owner", "lonsan" );
	set( "object", ([
		"file6"    : "/open/ping/obj/poison_pill",
		"file7"    : "/open/killer/obj/k_ring",
		"amount10" : 1,
		"amount3"  : 1,
		"amount6"  : 81,
		"file10"   : "/open/mogi/dragon/obj/scale",
		"file2"    : "/open/mon/obj/ghost-legging",
		"file5"    : "/open/killer/headkill/obj/world_dag",
		"file3"    : "/open/mon/obj/ghost-cloak",
		"file1"    : "/open/mon/obj/ghost-helmet",
		"amount7"  : 1,
		"amount1"  : 1,
		"amount5"  : 1,
		"amount8"  : 1,
		"amount2"  : 1,
		"file8"    : "/open/killer/headkill/obj/world_dag",
		"file9"    : "/open/killer/headkill/obj/world_dag",
		"amount9"  : 1,
	]) );
	set( "light_up", 1 );
	set( "build", 11066 );
	set( "exits", ([
		"chome"     : "/open/clan/sky-wu-chi/room/hall.c",
		"north"     : "/open/clan/sky-wu-chi/room/room141.c",
		"out"       : "/open/clan/sky-wu-chi/room/room55",
	]) );
	set( "long", @LONG
從$HIG$綠蔭大道$NOR$轉到小路上，四周的環境逐漸趨於寧靜，猛烈的練武氣勢也不在逼
人，許多不知名的鳥類和麻雀，在兩旁樹蔭遮天的大樹上飛跳嘻鬧著，走在路上，
心裡也平靜許多，慢慢升起祥和之氣。在蒼蓊濃郁的大樹下，長著許多不知名的花
草，五顏六色，爭相奪艷，還有一些奇怪的草藥，散發出獨特的氣味，讓人聞了有
恢復體力的感覺。道路向北延伸，走靠近一些似乎還能隱隱約約聽的到朗朗的讀書
聲，看來北邊是一個書院。

LONG);
	setup();
	replace_program(ROOM);
}
