inherit ROOM;
void create() {
	set( "short", "--聖地--" );
	set( "light_up", 1 );
	set( "object", ([
		"amount5"  : 1,
		"file1"    : "/open/capital/obj/4-3",
		"amount1"  : 1,
		"file5"    : "/open/marksman/obj/dragon_bow",
		"amount2"  : 1,
		"file2"    : "/obj/gift/xiandan",
	]) );
	set( "build", 11094 );
	set( "exits", ([
		"chome"     : "/open/clan/sky-wu-chi/room/hall",
	]) );
	set( "long", @LONG
這裡不知道是從那邊生出來的聖地，有著很多的荒老建築物在此地，旁邊
還有許許多多的遺跡掉在地上和埋在土裡，你看到有好幾種的神像以及埃及的
人面獅身物品在此地，你有股衝到想要拿起來看一下到底是真假，可惜當你一
走過去時，所有東西都消失了。
LONG);
	setup();
	replace_program(ROOM);
}
