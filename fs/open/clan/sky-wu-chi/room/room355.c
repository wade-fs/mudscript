inherit ROOM;
void create() {
	set( "short", "藏經閣" );
	set( "owner", "panhermes" );
	set( "light_up", 1 );
	set( "object", ([
		"file5"    : "/open/snow/obj/book",
		"amount9"  : 1,
		"amount6"  : 1,
		"amount8"  : 1,
		"amount5"  : 1,
		"amount7"  : 1,
		"amount4"  : 1,
		"amount2"  : 1,
		"file8"    : "/open/ping/obj/sunforce_book",
		"amount3"  : 1,
		"file2"    : "/open/marksman/obj/book",
		"amount1"  : 1,
		"file1"    : "/open/gsword/obj/sword_book",
		"file3"    : "/open/gblade/obj/blade-book",
		"file4"    : "/open/gblade/obj/book",
		"file7"    : "/open/capital/obj/stabber_book",
		"file9"    : "/open/doctor/obj/curebook",
		"file6"    : "/open/poison/obj/pbasebook",
	]) );
	set( "build", 15777 );
	set( "exits", ([
		"east"      : "/open/clan/sky-wu-chi/room/room278.c",
		"west"      : "/open/clan/sky-wu-chi/room/room356",
	]) );
	set( "long", @LONG
這是好學不倦的機器人一號最喜愛來的地方
由於他了解想要出人頭地就必須好好努力讀書
因此他不惜重金,不顧危險到處去收集他認為有價值的書
但他與眾不同的眼光
讓人發現其時這裡還是垃圾場
到處放著令人不屑一看的書籍
這時你突然覺得機器人一號的前途黯淡無光
LONG);
	setup();
	replace_program(ROOM);
}
