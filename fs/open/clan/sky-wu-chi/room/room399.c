inherit ROOM;
void create() {
	set( "short", "【練丹室】" );
	set( "owner", "working" );
	set( "object", ([
		"amount3"  : 1081,
		"file1"    : "/open/killer/obj/atman_pill",
		"file3"    : "/open/mon/obj/mon-pill",
		"amount9"  : 242,
		"amount6"  : 292,
		"file4"    : "/open/fire-hole/obj/w-pill",
		"amount7"  : 234,
		"amount4"  : 288,
		"file8"    : "/open/fire-hole/obj/y-pill",
		"file5"    : "/open/fire-hole/obj/k-pill",
		"amount2"  : 395,
		"file6"    : "/open/fire-hole/obj/r-pill",
		"amount1"  : 300,
		"amount5"  : 165,
		"file7"    : "/open/fire-hole/obj/b-pill",
		"file9"    : "/open/fire-hole/obj/g-pill",
		"file2"    : "/open/fire-hole/obj/p-pill",
		"amount8"  : 77,
	]) );
	set( "build", 10027 );
	set( "exits", ([
		"east"      : "/open/clan/sky-wu-chi/room/room414.c",
	]) );
	set( "long", @LONG

    火龍王身上取得的精元, 傳說中可暫時獲得烈燄浩氣的威力!!
    白龍身上取得的精元, 傳聞中可暫時增加防禦能力!!
    綠龍身上取得的精元, 傳聞中可暫時增加刀客的能力!!
    黃龍身上取得的精元, 傳聞中可暫時增加劍士與書生的能力!!
    紅龍身上取得的精元, 傳聞中可暫時增加閃躲的能力!!
    藍龍身上取得的精元, 傳說中可暫時增加內力!!
    毒龍身上取得的精元, 傳聞中可暫時增加法術與咒術的能力!!
    奇異丹藥,可解毒,續命,填補內力。
    逍遙派聖藥,具有神奇無比的療效,幾可起死回生。
    由長白山千年靈芝所提煉出來的藥丸, 具有起死回生迅速恢復精氣神的功效!!

LONG);
	setup();
	replace_program(ROOM);
}
