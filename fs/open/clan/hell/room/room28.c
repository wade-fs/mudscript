inherit ROOM;
void create() {
	set( "short", "$RED$『閻羅王』$NOR$的$HIY$收藏地獄$NOR$『$HIY$幸運草環$NOR$』" );
	set( "light_up", 1 );
	set( "build", 11663 );
	set( "exits", ([
		"force"     : "/open/clan/hell/room/room31",
		"fan"       : "/open/clan/hell/room/room88.c",
		"ball"      : "/open/clan/hell/room/room86.c",
		"ring"      : "/open/clan/hell/room/room39.c",
		"dagger"    : "/open/clan/hell/room/room90",
		"sword"     : "/open/clan/hell/room/room33.c",
		"claw"      : "/open/clan/hell/room/room89.c",
		"south"     : "/open/clan/hell/room/room23.c",
		"blade"     : "/open/clan/hell/room/room32.c",
		"icer"      : "/open/clan/hell/room/room81.c",
	]) );
	set( "long", @LONG
這裡是地府的閻羅王收藏武器的地方,他的鬼子鬼孫們從四處蒐集回來的武器
都會收藏在這裡,由於收藏品實在太多了,所以他收藏的區域不只一間,這裡往四周
延神出去,各有收藏諸般兵器的地方,以便讓各們各派加入地府的人都能夠隨時有
武器可取用

LONG);
	setup();
	replace_program(ROOM);
}
