inherit ROOM;
void create() {
	set( "short", "$HIC$冰雪神戒$NOR$存放區" );
	set( "object", ([
		"amount2"  : 1,
		"file2"    : "/open/ping/obj/ring-2",
		"file1"    : "/open/ping/obj/ring-2",
		"amount1"  : 1,
	]) );
	set( "build", 11208 );
	set( "exits", ([
		"out"       : "/open/clan/hell/room/room39",
	]) );
	set( "light_up", 1 );
	set( "long", @LONG
加入地府的幫眾相信都有一定程度的水準,拿到冰雪神戒都沒有啥問題了
然而為了應付幫中許多隻大米蟲,ect.$HIR$kalin,blur,nirvana$NOR$這些懶的快爆炸的
幫眾,小敏幫主還是做了一間房間存放冰雪神戒,如果想放機器人又懶的去打的
話,可以來這裡拿,當然新手幫眾更可以來此取用

LONG);
	setup();
	replace_program(ROOM);
}
