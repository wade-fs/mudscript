inherit ROOM;
void create() {
	set( "short", "首塚" );
	set( "owner", "gever" );
	set( "object", ([
		"file2"    : "/obj/gift/xisuidan",
		"file1"    : "/open/magic-manor/obj/master_snake_head",
		"amount4"  : 1,
		"file4"    : "/open/mogi/dragon/obj/scale",
		"amount2"  : 1,
		"amount1"  : 1,
		"file3"    : "/open/mogi/dragon/obj/scale",
		"amount3"  : 1,
	]) );
	set( "build", 10030 );
	set( "light_up", 1 );
	set( "exits", ([
		"west"      : "/open/clan/13_luck/room/room691",
	]) );
	set( "long", @LONG
踏進此室，忽然一股陰寒之氣襲面而來望著地上東一個西一個
的小土丘土丘之上有的雜草叢生，有的卻疏疏落落，但是從其
中都可以感受到一股血腥之味，你不禁心中納悶，這到底是甚
麼地方？正當你百思不得其解之時，背後傳來一陣冰冷的聲音
        『此地名曰「首塚」，自我成名來，
          刀下亡魂逾萬雖其為仇敵時不能同
          生，但吾亦不忍其死後魂魄飄無所
          蹤，故特立此首塚，使其安息。』
LONG);
	setup();
	replace_program(ROOM);
}
