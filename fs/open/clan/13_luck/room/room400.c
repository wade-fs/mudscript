inherit ROOM;
void create() {
	set( "short", "練刀房" );
	set( "object", ([
		"file2"    : "/open/ghost-hole/obj/eq/ghost-cloak",
		"file5"    : "/open/ghost-hole/obj/eq/ghost-cloak",
		"amount1"  : 1,
		"file1"    : "/open/ghost-hole/obj/eq/ghost-cloak",
		"amount5"  : 1,
		"amount2"  : 1,
	]) );
	set( "owner", "roar" );
	set( "build", 12162 );
	set( "light_up", 1 );
	set( "exits", ([
		"north"     : "/open/clan/13_luck/room/room391",
	]) );
	set( "long", @LONG

    在這裡的牆壁上刻著大大小小的人像圖形，將十三刀堂的刀招一一
記錄在此地，故大部份十三刀堂的弟子入門時均會到此習練最基本的刀
招，當然此地就是絕對的禁地，在這裡的弟子若是看到不是羅剎的人出
現在此，可是會毫不猶豫的動手砍人的，西邊的石壁上好像刻著幾行字
，據說是當初殺出十三吉祥的飛驚走之前所留下的

LONG);
	setup();
	replace_program(ROOM);
}
