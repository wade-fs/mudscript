inherit ROOM;
void create() {
	set( "short", "gk eq-gem" );
	set( "owner", "cong" );
	set( "object", ([
		"amount6"  : 1,
		"amount5"  : 1,
		"amount8"  : 1,
		"file1"    : "/open/ghost-hole/obj/eq/ghost-gem",
		"amount1"  : 1,
		"file2"    : "/open/ghost-hole/obj/eq/ghost-gem",
		"amount2"  : 1,
		"file6"    : "/open/ghost-hole/obj/eq/ghost-gem",
		"file5"    : "/open/ghost-hole/obj/eq/ghost-gem",
		"file8"    : "/open/ghost-hole/obj/eq/ghost-gem",
	]) );
	set( "build", 10392 );
	set( "light_up", 1 );
	set( "exits", ([
		"north"     : "/open/clan/sky-wu-chi/room/room97",
	]) );
	set( "long", @LONG

黃金榜上。偶夫龍頭望。

明代暫遺賢。如何向。

未遂風雲便。爭不恣狂蕩。

何須論得喪。才子詞人自是白衣卿相

煙花巷陌。依約丹青屏障。

幸有意中人。堪尋訪。

且恁偎紅翠。風流事平生暢。

青春都一餉。忍把浮名。換了淺斟低唱



LONG);
	setup();
	replace_program(ROOM);
}
