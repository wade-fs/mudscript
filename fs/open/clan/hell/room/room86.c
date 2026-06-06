inherit ROOM;
void create() {
	set( "short", "$HIY$靈珠封印區$NOR$" );
	set( "light_up", 1 );
	set( "build", 10195 );
	set( "exits", ([
		"fire"      : "/open/clan/hell/room/room82.c",
		"soil"      : "/open/clan/hell/room/room85.c",
		"out"       : "/open/clan/hell/room/room28",
		"wood"      : "/open/clan/hell/room/room83.c",
		"golden"    : "/open/clan/hell/room/room84.c",
		"water"     : "/open/clan/hell/room/room79.c",
	]) );
	set( "long", @LONG
地府的精兵戰將們當年闖進聚靈山莊後,收集了不少聚靈八傑手中之物由於
其得來不易,地府的大飛哥提議將之分類封印起來,滿足他變態收集慾望這裡
是專門收藏八傑之中段家守護者所持武器的地方,有興趣的人可以拿去試用,
不過用畢請記得歸還,不然大飛哥會請你吃鼻屎的 :D

LONG);
	setup();
	replace_program(ROOM);
}
