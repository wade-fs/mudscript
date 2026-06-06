inherit ROOM;
void create() {
	set( "short", "空瓶子招待所" );
	set( "owner", "ywarter" );
	set( "object", ([
		"file5"    : "/open/mon/obj/ghost-helmet",
		"file4"    : "/daemon/class/bonze/puty_pullium",
		"file10"   : "/daemon/class/fighter/ywhand",
		"amount1"  : 1,
		"amount4"  : 1,
		"amount3"  : 1,
		"amount8"  : 1,
		"file7"    : "/open/mon/obj/ghost-cloak",
		"amount5"  : 1,
		"file9"    : "/open/gsword/obj/yuskirt",
		"amount6"  : 1,
		"file8"    : "/open/sky/obj/lucky_grasslink",
		"file2"    : "/open/gsword/obj/yugem",
		"amount7"  : 1,
		"amount2"  : 1,
		"file1"    : "/daemon/class/blademan/obj/shield",
		"amount9"  : 1,
		"file3"    : "/open/gsword/npc2/sadsword",
		"file6"    : "/open/mon/obj/ghost-legging",
		"amount10" : 1,
	]) );
	set( "light_up", 1 );
	set( "build", 13008 );
	set( "exits", ([
		"east"      : "/open/clan/sky-wu-chi/room/room234.c",
		"enter"     : "/open/clan/sky-wu-chi/room/room133",
		"out"       : "/open/clan/sky-wu-chi/room/room60.c",
	]) );
	set( "long", @LONG
這裡是空瓶子一般在招待貴賓的地方,這裡沒有太豪華的傢俱
這裡有一張太師椅
旁邊有兩排長椅,供貴賓坐,而太師椅則是給空瓶子坐的..所以
你也就知道這裡正是由空瓶子所佔的地盤上,在這裡你不敢
太放肆,否則會遭受到比死還難過的折蘑....
LONG);
	setup();
	replace_program(ROOM);
}
