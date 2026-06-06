inherit ROOM;
void create() {
	set( "short", "往空瓶子兵器室入口" );
	set( "light_up", 1 );
	set( "object", ([
		"amount3"  : 1,
		"amount1"  : 1,
		"file3"    : "/open/mogi/dragon/obj/scale",
		"file6"    : "/open/mogi/dragon/obj/scale",
		"amount6"  : 1,
		"file1"    : "/open/ping/questsfan/obj/diamond_hairpin",
	]) );
	set( "build", 10017 );
	set( "exits", ([
		"enter"     : "/open/clan/sky-wu-chi/room/room124",
		"south"     : "/open/clan/sky-wu-chi/room/room137.c",
	]) );
	set( "long", @LONG
這裡是往空瓶子兵器室的通道..當你還沒進去入口之前你已經看到
一些不是頂好的兵器,但也是有名的武器被丟在一旁了...你不禁的想到
要是裡面的武器沒有比現在的更好才怪..但是到底是什麼武器才算是
可以放進這兵器室裡面呢..你又不禁的想著..嗯..看來還是要一探究竟
才會知道裡面到底是有些什麼樣的好兵器

LONG);
	setup();
	replace_program(ROOM);
}
