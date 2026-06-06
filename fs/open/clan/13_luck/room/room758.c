inherit ROOM;
void create() {
	set( "short", "小小邦的練武房" );
	set( "object", ([
		"amount1"  : 1,
		"file2"    : "/open/mogi/castle/obj/ninepill",
		"amount2"  : 11,
		"file1"    : "/open/mogi/castle/obj/sspill",
	]) );
	set( "build", 13730 );
	set( "owner", "yken" );
	set( "exits", ([
		"east"      : "/open/clan/13_luck/room/room759",
		"out"       : "/open/clan/13_luck/room/room10.c",
		"north"     : "/open/clan/13_luck/room/room762.c",
	]) );
	set( "long", @LONG
妳一打開門就被倒下來的武器給嚇到，還好躲的快，不然又要包紮
了。這房間的每一面牆壁都被深深淺淺的劍痕、刀痕，給刻畫者，看
得出來房間主人一次又一次的練功痕跡，妳找了一張椅子坐了下來，
心裡想，武功的魅力真的是很大，斯斯文文的一個人，都會為了練功
，廢寢忘食，房間也沒心情整理，想者想者，妳開始幫房間主人整理
起來。
LONG);
	setup();
	replace_program(ROOM);
}
