inherit ROOM;
void create() {
	set( "short", "$HIY$【平南書院】 $HIC$聖賢學堂$NOR$" );
	set( "owner", "working" );
	set( "object", ([
		"amount6"  : 1,
		"file10"   : "/open/tendo/obj/chaosbelt",
		"file7"    : "/open/mon/obj/ghost-legging",
		"file8"    : "/daemon/class/blademan/obj/shield",
		"amount1"  : 1,
		"file2"    : "/daemon/class/fighter/figring",
		"file1"    : "/open/mon/obj/ghost-cloak",
		"amount5"  : 1,
		"file6"    : "/open/wind-rain/obj/sun_red_cloth",
		"file5"    : "/open/mogi/castle/obj/lochagem",
		"file3"    : "/open/mon/obj/ghost-helmet",
		"amount3"  : 1,
		"amount4"  : 1,
		"amount8"  : 1,
		"amount10" : 1,
		"amount2"  : 1,
		"file4"    : "/open/wu/npc/obj/armband",
		"amount7"  : 1,
	]) );
	set( "light_up", 1 );
	set( "build", 10300 );
	set( "exits", ([
		"west"      : "/open/clan/sky-wu-chi/room/room139",
	]) );
	set( "long", @LONG
走進聖賢學堂，馬上就可以感受到一股讀書人的氣質，彷彿只要從這裡出去的
學生，都能成為當代的文學大師，事實上也是如此，平南書院的聖賢學堂就是專門
訓練文人學士作學問的最高殿堂，在這裡任教的老師們也都是當代的大儒，這裡要
求也比一般的書院來的嚴格，不但想進來要接受考試，在裡面跟不上別人程度的學
生，也多如過江之鯽，不過就算因為跟不上進度被開除的學生，在外面一樣能獨當
一面的研究學問。在學堂的兩側各有一排櫃子，是在這裡上課的學生專用的，而講
堂前方的小書櫃裡面放的是老師的私人物品。

LONG);
	setup();
	replace_program(ROOM);
}
