inherit ROOM;
void create() {
	set( "short", "$HIR$禁忌$HIG$森林4$NOR$" );
	set( "owner", "car" );
	set( "build", 10278 );
	set( "exits", ([
		"east"      : "/open/clan/time-limit/room/room67",
	]) );
	set( "long", @LONG
走進這個區域裡,馬上感到不對勁,四周好像有無數對眼睛望著你,
空氣中傳來血腥味,忽然從樹上垂下一隻比牛還大的蜘蛛-阿辣哥,
四周跑出成千上萬的蜘蛛,有大有小對著你流口水,這下完蛋了,
難道今天要葬身在蜘蛛毒牙之下了嗎?趕緊抽身而退吧!

LONG);
	setup();
	replace_program(ROOM);
}
