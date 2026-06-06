inherit ROOM;
void create() {
	set( "short", "小笨蛋的客廳" );
	set( "object", ([
		"amount5"  : 1,
		"file9"    : "/open/mon/obj/ghost-legging",
		"amount8"  : 1,
		"file7"    : "/open/sky/obj/lucky_grasslink",
		"file3"    : "/open/main/obj/firesword",
		"file10"   : "/open/mon/obj/ghost-helmet",
		"amount3"  : 1,
		"amount10" : 1,
		"file5"    : "/open/mon/obj/ghost-cloak",
		"file2"    : "/open/mon/obj/ghost-legging",
		"file8"    : "/open/mon/obj/ghost-cloak",
		"amount4"  : 1,
		"amount2"  : 1,
		"amount1"  : 377,
		"file4"    : "/open/mon/obj/ghost-helmet",
		"amount7"  : 1,
		"amount9"  : 1,
		"file6"    : "/open/magic-manor/obj/magic-sign",
		"amount6"  : 1,
		"file1"    : "/open/killer/obj/s_pill",
	]) );
	set( "owner", "acelan" );
	set( "build", 11029 );
	set( "item_desc", ([
		"叮叮" : @ITEM
一隻白色帶有點金毛的波斯和金吉拉混種的可愛喵咪
最愛趴在角落睡覺，醒來時愛追著用紙揉成的球跑來跑去
是一隻超級可愛的小貓咪喔 ^_^
ITEM,
	]) );
	set( "light_up", 1 );
	set( "exits", ([
		"east"      : "/open/clan/hell/room/room127",
		"west"      : "/open/clan/hell/room/room125",
	]) );
	set( "long", @LONG
小笨蛋的客廳看來不像房間，倒像是個橢圓廣場，周圍環繞著異
常而強烈的氣流，將在廣場內的所有物品都托了起來。不過四周都空
盪盪的，看起來好荒涼的樣子，真看不出來著個客廳要如何來接待客
人。在角落趴著一隻貓咪，是小笨蛋的愛貓(叮叮)...
LONG);
	setup();
	replace_program(ROOM);
}
