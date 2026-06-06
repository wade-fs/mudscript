inherit ROOM;
void create() {
	set( "short", "星際大冒險2" );
	set( "object", ([
		"amount5"  : 2,
		"file3"    : "/open/ghost-hole/obj/eq/ghost-boots",
		"amount1"  : 1,
		"file1"    : "/open/ghost-hole/obj/eq/ghost-gloves",
		"amount2"  : 1,
		"amount4"  : 1,
		"file5"    : "/open/fire-hole/obj/g-pill",
		"file4"    : "/open/mon/obj/mon-pill",
		"file2"    : "/open/ghost-hole/obj/eq/ghost-king-tooth",
		"amount3"  : 1,
	]) );
	set( "build", 10014 );
	set( "owner", "sulamark" );
	set( "exits", ([
		"south"     : "/open/clan/time-limit/room/room254.c",
		"north"     : "/open/clan/time-limit/room/room252",
	]) );
	set( "long", @LONG
  踏上和式地板，淡淡柚木地板氣味在空氣中飄盪，妳的腳掌輕輕的
趴在地板上，服貼的想馬上躺下去睡著，可惜這裡終究是小小邦的房間
，妳想休息，最好跟主人講一聲。窗台的風鈴不時傳來悅耳的鈴聲，和
煦的晚風不冷不熱，剛剛好幫妳輕解了煩惱桌上擺了一壺溫好的清酒
，妳一飲而盡，完全不想再離開這裡了。
LONG);
	setup();
	replace_program(ROOM);
}
