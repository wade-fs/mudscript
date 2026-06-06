inherit "/open/clan/claneqshop.c";    
void create() {
	set( "short", "武器防具室" );
	set( "object", ([
		"file4"    : "/open/magic-manor/gold/obj/golden-blade",
		"file3"    : "/open/magic-manor/wood/obj/wood-sword",
		"file1"    : "/open/capital/obj/4-2",
		"file5"    : "/open/magic-manor/gold/obj/golden-blade",
		"amount2"  : 1,
		"file10"   : "/open/magic-manor/wood/obj/wood-sword",
		"amount6"  : 1,
		"file6"    : "/open/capital/obj/4-2",
		"amount5"  : 1,
		"amount8"  : 1,
		"amount4"  : 1,
		"file9"    : "/open/magic-manor/gold/obj/golden-blade",
		"amount7"  : 1,
		"file7"    : "/open/capital/guard/gring",
		"amount10" : 1,
		"file2"    : "/open/magic-manor/wood/obj/wood-sword",
		"amount3"  : 1,
		"amount9"  : 1,
		"file8"    : "/open/magic-manor/obj/golden-ball",
		"amount1"  : 1,
	]) );
	set( "item_desc", ([
		"post" : @ITEM

     指令                       說明

     list              查看服務台內有什麼物品
  take xxxx              將物品從服務台取出
   put xxxx              將物品放入服務台內
   put all          將身上的物品全部放務服務台內

ITEM,
	]) );
	set( "build", 10274 );
	set( "light_up", 1 );
	set( "exits", ([
		"enter"     : "/open/clan/13_luck/room/room277",
		"north"     : "/open/clan/13_luck/room/hall.c",
	]) );
	set( "long", @LONG

    這是一間放武器和防具及其它雜物的大房間，在幫派中佔有很重要
的地位。房間中裝璜的非常漂亮，牆上一張蠻有趣的大字報（post），
吸引了你的視線，上頭的ＰＯＰ字寫得很不錯。架子和地板也都十分的
乾淨。但因為是服物台的管理人員相當盡則，所以您存放的物品也都在
架上排列的非常整齊。

LONG);
	setup();
}
