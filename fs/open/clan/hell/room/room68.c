inherit ROOM;
void create() {
	set( "short", "$HIG$綠龍$NOR$區" );
	set( "object", ([
		"file1"    : "/open/fire-hole/obj/g-pill",
		"amount1"  : 60,
	]) );
	set( "owner", "blur" );
	set( "build", 10441 );
	set( "light_up", 1 );
	set( "exits", ([
		"out"       : "/open/clan/hell/room/room27",
	]) );
	set( "long", @LONG

綠龍精元..是刀克夢寐以求的良藥...
因為刀克服用它之後,馬上生龍活虎...全身的血液都在沸騰

你此時一定又有疑惑了
為何綠龍精元有如此神效...??

哎呀! 早教你多唸點書了..
這也是食物鏈的關係...
因為綠龍只是簡稱...其實它真正的全名是 戴綠帽的龍...
你想想..戴綠帽...一定很火爆囉..
所以你吃了綠龍精元後...一定更火爆 @@?

LONG);
	setup();
	replace_program(ROOM);
}
