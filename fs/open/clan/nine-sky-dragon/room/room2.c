inherit ROOM;
void create() {
	set( "short", "裝備室" );
	set( "object", ([
		"file5"    : "/open/capital/obj/blade2",
		"amount4"  : 1,
		"file10"   : "/open/start/obj/ten_pen",
		"file8"    : "/open/mon/obj/ghost-legging",
		"file4"    : "/open/mogi/dragon/obj/scale",
		"amount7"  : 1,
		"amount5"  : 1,
		"file3"    : "/open/sky/obj/lucky_grasslink",
		"amount3"  : 1,
		"file1"    : "/open/magic-manor/ghost/obj/five-turn-ball",
		"amount1"  : 1,
		"amount2"  : 1,
		"file2"    : "/open/magic-manor/obj/evil-gwe-blade",
		"amount9"  : 1,
		"file7"    : "/open/mon/obj/ghost-helmet",
		"file9"    : "/open/mon/obj/ghost-cloak",
		"amount10" : 1,
		"amount8"  : 1,
	]) );
	set( "build", 10066 );
	set( "item_desc", ([
		"post" : @ITEM
     指令                       說明

     list              查看櫃台內有什麼裝備
   take xxxx              將裝備從櫃台領出
   put xxxx              將物品存入櫃台內
   put all          將身上的物品全部放至櫃台內

ITEM,
	]) );
	set( "light_up", 1 );
	set( "exits", ([
		"up"        : "/open/clan/nine-sky-dragon/room/room3.c",
		"down"      : "/open/clan/nine-sky-dragon/room/room5.c",
		"out"       : "/open/clan/nine-sky-dragon/room/hall.c",
	]) );
	set( "long", @LONG

　　這裡是「九天蒼龍」裝備室，牆上到處都掛滿了各式各樣的武器
以及裝備，多到令人感到眼花瞭亂，在這裡相信一定可以找到自己想
要的裝備，正中央的牆壁上有一張製作精美的大字報（post）。櫃台
那站著一位可愛的女孩，面帶微笑地準備為您服務，如果有任何問題
可以請她幫忙解決。

LONG);
	setup();
	replace_program(ROOM);
}
