inherit ROOM;
void create() {
	set( "short", "瀑瀉古岳雲眉棧" );
	set( "object", ([
		"file6"    : "/open/capital/obj/blade2",
		"amount5"  : 303,
		"amount2"  : 68,
		"file5"    : "/open/fire-hole/obj/r-pill",
		"file2"    : "/open/fire-hole/obj/b-pill",
		"amount8"  : 1,
		"amount3"  : 165,
		"file1"    : "/open/mogi/castle/obj/ninepill",
		"file9"    : "/obj/gift/bingtang",
		"amount7"  : 69,
		"amount9"  : 1,
		"file10"   : "/open/ping/obj/poison_pill",
		"file8"    : "/obj/gift/shenliwan",
		"amount4"  : 198,
		"file4"    : "/open/fire-hole/obj/w-pill",
		"file3"    : "/open/fire-hole/obj/g-pill",
		"amount10" : 11,
		"amount1"  : 330,
		"amount6"  : 1,
		"file7"    : "/open/mogi/castle/obj/sspill",
	]) );
	set( "build", 10001 );
	set( "item_desc", ([
		"saku" : @ITEM
Dreamedyln專用戴瑞斯保險套
ITEM,
	]) );
	set( "owner", "dreamedyln" );
	set( "light_up", 1 );
	set( "exits", ([
		"north"     : "/open/clan/13_luck/room/room94",
	]) );
	set( "long", @LONG
你在一次因緣巧合的機會下，來到了這座高聳的山岳上，四周都被白茫茫
的雲霧遮住了。突然間你的眼睛似乎看到了前方隱約有個草屋，往前一看竟然
是座草屋，還有個牌子寫著『雲眉棧』。正在遲疑是否該進去拜訪主人時，一
陣響亮的詩號自屋內傳出：『  

     身藏風雲心無塵，古今聖賢誰為鄰，
     一笑橫江挂書劍，九重天外臥龍深。
     
歡迎貴客光臨。』心想：主人既然以開口相邀，自己也不好意思拒絕... 

一打保險套(saku)

LONG);
	setup();
	replace_program(ROOM);
}
