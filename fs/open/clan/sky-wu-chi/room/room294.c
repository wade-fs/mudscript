inherit ROOM;
void create() {
	set( "short", "血痕居-主臥房" );
	set( "owner", "holeman" );
	set( "object", ([
		"amount1"  : 1,
		"amount3"  : 1,
		"file1"    : "/open/mon/obj/ghost-cloak",
		"file8"    : "/open/wind-rain/obj/sun_red_cloth",
		"amount5"  : 1,
		"file9"    : "/open/sky/obj/lucky_grasslink",
		"file5"    : "/open/wu/obj/figring",
		"amount7"  : 1,
		"file2"    : "/open/mon/obj/ghost-legging",
		"file7"    : "/open/wu/npc/obj/armband",
		"file3"    : "/open/mon/obj/ghost-helmet",
		"file10"   : "/open/tendo/obj/chaosbelt",
		"amount6"  : 1,
		"amount10" : 1,
		"file6"    : "/daemon/class/blademan/obj/shield",
		"amount2"  : 1,
		"amount9"  : 1,
		"amount8"  : 1,
		"amount4"  : 1,
		"file4"    : "/open/mogi/castle/obj/lochagem",
	]) );
	set( "light_up", 1 );
	set( "build", 11886 );
	set( "exits", ([
		"west"      : "/open/clan/sky-wu-chi/room/room298",
	]) );
	set( "long", @LONG

    當你在門外鼓起十二萬分的勇氣準備要去敲門的時候，突
然從房間裡面傳來一聲：「門沒鎖，請進吧」，這時候你心裡
就決定這次就豁出去了，而當你推開門的時候，映入你眼簾的
是明亮的環境以及簡單的裝潢，而這間房子的主人就坐在你的
面前。當你戰戰兢兢坐下來的時候，沒想到主人卻出乎意料的
十分歡迎你的到來，而接下來的時間，你與主人聊了許多的話
題，尤其是在武學方面更是令你受益不少，而在過的一段很長
的時間，你感覺到你的修為又更上一層樓了


LONG);
	setup();
	replace_program(ROOM);
}
