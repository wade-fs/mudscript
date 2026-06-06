inherit ROOM;
void create() {
	set( "short", "$HIY$十三$HIR$聖殿$NOR$" );
	set( "exits", ([
		"south"     : "/open/clan/time-limit/room/room201.c",
		"west"      : "/open/clan/time-limit/room/room202",
	]) );
	set( "long", @LONG
十三聖殿仿照聖鬥士一般,建立了13個行宮,前方的12行宮可以有效阻礙敵人的進攻,為後
面的防線爭取時間,後方的主殿是金陽聖帝關足天住所,同時也是十三聖殿裡兵力最多的
地方,而金陽聖帝早就對中原虎視眈眈,經過幾年的養精蓄銳之後,已是一股不可小覷的勢
力,看來隨時有發兵的可能

LONG);
	setup();
	replace_program(ROOM);
}
