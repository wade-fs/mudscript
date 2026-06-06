inherit ROOM;
void create() {
	set( "short", "霧之林入口" );
	set( "owner", "amdmp" );
	set( "object", ([
		"amount1"  : 1,
		"amount9"  : 1,
		"amount6"  : 1,
		"amount7"  : 1,
		"file10"   : "/open/magic-manor/obj/master_snake_head",
		"file9"    : "/open/magic-manor/obj/master_snake_head",
		"file5"    : "/open/magic-manor/ghost/obj/trigram-pill",
		"file1"    : "/open/capital/obj/blade2",
		"file4"    : "/open/magic-manor/obj/master_snake_head",
		"amount3"  : 1,
		"amount10" : 1,
		"file6"    : "/open/capital/obj/blade2",
		"file8"    : "/open/magic-manor/obj/master_snake_head",
		"file7"    : "/open/capital/obj/force_book",
		"amount8"  : 1,
		"amount4"  : 1,
		"amount5"  : 4,
		"file3"    : "/open/magic-manor/obj/master_snake_head",
	]) );
	set( "build", 10608 );
	set( "light_up", 1 );
	set( "exits", ([
		"enter"     : "/open/clan/13_luck/room/room157",
		"west"      : "/open/clan/13_luck/room/room153.c",
	]) );
	set( "long", @LONG

　　你已來到了霧之林的入口處了，旁邊插著一塊警告牌，上頭寫著
『霧之林，終年濃霧不散，越往裡去，霧氣越是濃密，沒事者，切忽
擅闖，以免迷失在其中』。看到這在往裡頭望去，果真是白茫茫的一
片濃霧籠罩著一切，令你心有餘悸。

LONG);
	setup();
	replace_program(ROOM);
}
