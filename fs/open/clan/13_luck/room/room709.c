inherit ROOM;
void create() {
	set( "short", "三樓south" );
	set( "owner", "zmud" );
	set( "object", ([
		"file3"    : "/open/capital/obj/4-4",
		"file2"    : "/open/capital/obj/4-4",
		"amount2"  : 1,
		"file1"    : "/open/capital/obj/4-2",
		"amount3"  : 1,
		"amount1"  : 1,
	]) );
	set( "build", 10017 );
	set( "exits", ([
		"east"      : "/open/clan/13_luck/room/room713",
		"north"     : "/open/clan/13_luck/room/room661.c",
		"west"      : "/open/clan/13_luck/room/room712.c",
	]) );
	set( "long", @LONG

   ┌───   _.,-*~'`^`'~*-,._ _.,-*~'`^`'~*- 江美琪‧想起 -*~'`^`'~*-,._      
   │剛剛風無 意吹起  花瓣隨著風落地  我看見多麼美的一場櫻花雨  聞一聞茶的      
   │    香氣 哼一段舊時旋律  要是你   一定歡天喜地 你曾經坐在這裡談吐的那      
   │麼闊氣就 像是所有幸福都能被預期│ 你打開我的手心 一切都突然安靜  你要      
   │我承接你的真心   花季雖然會過去   今年 明年  有一樣的風情  相愛  以為      
       是你給的美麗│ 讓我驚喜  讓我慶幸  我有一生的風景  命運  插手的太急      
           我來不及│ 全都要還回去 從此 是一段長長的距離 偶而想起 總是欷噓      
     如果當初懂珍惜│ 我知道眼淚多餘 笑變的好不容易 特別是只能面對回憶和空      
             ───┘ 氣 多半的自言自語  是用來安慰自己 也許你字字句句傾聽      
                *~'`^`'~*- -*~'`^`'~*- -*~'`^`'~*-,.,.-*~'`vcloudy`'~*-,.-      

LONG);
	setup();
	replace_program(ROOM);
}
