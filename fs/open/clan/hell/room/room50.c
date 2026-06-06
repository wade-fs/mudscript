inherit ROOM;
void create() {
	set( "short", "$YEL$in utero$NOR$" );
	set( "object", ([
		"file1"    : "/open/marksman/obj/arrow-3",
		"amount3"  : 1,
		"file3"    : "/open/marksman/obj/dragon_bow",
		"amount2"  : 1,
		"amount1"  : 2598959,
		"file2"    : "/open/marksman/obj/bow-5",
	]) );
	set( "owner", "blur" );
	set( "build", 10500 );
	set( "exits", ([
		"west"      : "/open/clan/hell/room/room55",
		"south"     : "/open/clan/hell/room/room46.c",
	]) );
	set( "light_up", 1 );
	set( "long", @LONG
kalin大二時....漸漸迷上pink floyed..
其實在高三時kalin就在聽他們了....
只是這時特別對他們有感覺....
也開始收集60 70年代的其他專輯....
除此之...kalin對英國樂團也特別有興趣....
對音樂的態度也有所改觀了...
這好像又是一個轉折點....
雖然花了許多錢跟心血....
kalin仍津津樂道在此........
LONG);
	setup();
	replace_program(ROOM);
}
