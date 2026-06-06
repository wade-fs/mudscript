inherit ROOM;
void create() {
	set( "short", "$HIR$北銀河系$NOR$" );
	set( "owner", "cong" );
	set( "object", ([
		"amount3"  : 1,
		"file3"    : "/open/killer/obj/fire-knife",
	]) );
	set( "light_up", 1 );
	set( "build", 10115 );
	set( "exits", ([
		"south"     : "/open/clan/sky-wu-chi/room/room239",
	]) );
	set( "long", @LONG
這裡是傳說中 神秘的幻境 北銀河系

$HIR$這裡是一個佈滿整整齊齊的書櫃的地方，每一個書櫃上面
都貼有一張張看不懂的符咒，看起來像是防止別人偷偷拿
走裡面東西的樣子。四周古色古香的佈置、而且還瀰漫一
股濃濃的桂花香氣，另人心況神怡。$NOR$
LONG);
	setup();
	replace_program(ROOM);
}
