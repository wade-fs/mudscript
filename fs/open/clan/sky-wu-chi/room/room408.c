inherit ROOM;
void create() {
	set( "short", "$HIG$NISA的客廳$NOR$" );
	set( "object", ([
		"file5"    : "/open/killer/obj/s_pill",
		"amount5"  : 4010,
		"amount2"  : 1,
		"amount8"  : 1,
		"file8"    : "/open/magic-manor/wood/obj/wood-sword",
		"file3"    : "/open/magic-manor/obj/dark-soul-dagger",
		"file1"    : "/open/magic-manor/wood/obj/wood-sword",
		"amount3"  : 1,
		"amount1"  : 1,
		"file2"    : "/open/magic-manor/wood/obj/wood-sword",
	]) );
	set( "build", 10138 );
	set( "exits", ([
		"north"     : "/open/clan/sky-wu-chi/room/room409.c",
		"chome"     : "/open/clan/sky-wu-chi/room/hall.c",
	]) );
	set( "long", @LONG
火龍王身上取得的精元, 傳說中可暫時獲得烈燄浩氣的威力!!
    白龍身上取得的精元, 傳聞中可暫時增加防禦能力!!
    綠龍身上取得的精元, 傳聞中可暫時增加刀客的能力!!
    黃龍身上取得的精元, 傳聞中可暫時增加劍士與書生的能力!!
    紅龍身上取得的精元, 傳聞中可暫時增加閃躲的能力!!
    藍龍身上取得的精元, 傳說中可暫時增加內力!!
    毒龍身上取得的精元, 傳聞中可暫時增加法術與咒術的能力!!
    由長白山千年靈芝所提煉出來的藥丸, 具有起死回生迅速恢復精氣神的功效!!
    奇異丹藥,可解毒,續命,填補內力。
    逍遙派聖藥,具有神奇無比的療效,幾可起死回生。
LONG);
	setup();
	replace_program(ROOM);
}
