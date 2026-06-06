inherit ROOM;
void create() {
	set( "short", "rayk's room" );
	set( "owner", "rayk" );
	set( "exits", ([
		"south"     : "/open/clan/ou-cloud-club/room/room760",
		"east"      : "/open/clan/ou-cloud-club/room/room759.c",
		"up"        : "/open/clan/ou-cloud-club/room/room724.c",
		"north"     : "/open/clan/ou-cloud-club/room/room757.c",
		"west"      : "/open/clan/ou-cloud-club/room/room758.c",
	]) );
	set( "long", @LONG

    看來Ｒａｙｋ似乎真的不是善於整理空間的人，偌大的地下室也
堆疊的亂七八糟、不堪入目，而且上面居然還布滿了厚厚的一堆灰塵
，不禁讓人懷疑這裡真的是Ｒａｙｋ收藏許多神兵利器以及各門各派
武學秘笈的地方嗎？

LONG);
	setup();
	replace_program(ROOM);
}
