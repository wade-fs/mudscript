inherit ROOM;
void create() {
	set( "short", "小小邦的和式房" );
	set( "object", ([
		"file3"    : "/open/mon/obj/ghost-cloak",
		"amount3"  : 1,
		"file4"    : "/open/magic-manor/obj/fon-sky-sword",
		"amount6"  : 165,
		"amount4"  : 1,
		"amount1"  : 1,
		"file1"    : "/open/scholar/obj/icefan",
		"file6"    : "/open/killer/obj/atman_pill",
		"amount5"  : 1,
		"file2"    : "/open/mon/obj/ghost-helmet",
		"file5"    : "/open/gsword/obj/dragon-sword",
		"amount2"  : 1,
	]) );
	set( "build", 11081 );
	set( "owner", "yken" );
	set( "exits", ([
		"south"     : "/open/clan/13_luck/room/room758",
	]) );
	set( "long", @LONG
踏上和式地板，淡淡柚木地板氣味在空氣中飄盪，妳的腳掌輕輕的
趴在地板上，服貼的想馬上躺下去睡著，可惜這裡終究是小小邦的房間
，妳想休息，最好跟主人講一聲。窗台的風鈴不時傳來悅耳的鈴聲，和
煦的晚風不冷不熱，剛剛好幫妳輕解了煩愁桌上擺了一壺溫好的清酒
，妳一飲而盡，完全不想再離開這裡了。
LONG);
	setup();
	replace_program(ROOM);
}
