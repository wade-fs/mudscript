inherit ROOM;
void create() {
	set( "short", "Yuki的秘密閨房" );
	set( "object", ([
		"file2"    : "/obj/gift/hobowdan",
		"amount1"  : 1,
		"amount2"  : 1,
		"file1"    : "/obj/gift/lingzhi",
	]) );
	set( "owner", "yuki" );
	set( "light_up", 1 );
	set( "build", 10521 );
	set( "exits", ([
		"west"      : "/open/clan/sky-wu-chi/room/room420",
		"east"      : "/open/clan/sky-wu-chi/room/room205.c",
	]) );
	set( "long", @LONG
這裡是一間擺滿各式武器的房間，但是房間的角落卻擺著一
張布丁狗的彈簧床，形成非常奇特的景觀，令你不經想看看
這個房間的主人會是誰，剛走進去發現三個巨大的機械人，
擋在門口你剛想突破進去，她們就把你一腳踢飛像一到流星
飛逝而去，不見蹤影！！
LONG);
	setup();
	replace_program(ROOM);
}
