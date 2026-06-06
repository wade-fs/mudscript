inherit ROOM;
void create() {
	set( "short", "茅坑" );
	set( "owner", "match" );
	set( "object", ([
		"amount10" : 1,
		"file9"    : "/open/main/room/sp/stone",
		"file8"    : "/open/main/room/sp/stone",
		"amount7"  : 1,
		"amount6"  : 1,
		"file1"    : "/open/main/room/sp/stone",
		"file3"    : "/open/main/room/sp/stone",
		"file2"    : "/open/main/room/sp/stone",
		"amount9"  : 1,
		"amount1"  : 1,
		"file7"    : "/open/main/room/sp/stone",
		"amount3"  : 1,
		"amount8"  : 1,
		"file6"    : "/open/main/room/sp/stone",
		"file10"   : "/open/main/room/sp/stone",
		"amount5"  : 1,
		"amount2"  : 1,
		"amount4"  : 1,
		"file5"    : "/open/main/room/sp/stone",
		"file4"    : "/open/main/room/sp/stone",
	]) );
	set( "build", 10050 );
	set( "light_up", 1 );
	set( "exits", ([
		"east"      : "/open/clan/sky-wu-chi/room/room432",
	]) );
	set( "long", @LONG
由於你擅闖草的地盤，所以你被草的守護神----時空大爺送到了
五星級的茅坑，可別小看這茅坑，既然是五星級的，就有他一流之處
，你看看這個便器，所散發出來的芬芳，令你忍不住想要一舔，想不
到你真的舔了！那個味道逐漸在你的舌尖散發出來，好想大聲說棒，
可是你一回神，卻看見自己正在舔著大便。。。
LONG);
	setup();
	replace_program(ROOM);
}
