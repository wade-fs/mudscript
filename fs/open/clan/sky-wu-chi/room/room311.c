inherit ROOM;
void create() {
	set( "short", "$HIC$【舞蹈服裝專櫃】$NOR$" );
	set( "owner", "peiyi" );
	set( "object", ([
		"amount6"  : 1,
		"file4"    : "/open/magic-manor/obj/dark-soul-dagger",
		"amount9"  : 1,
		"file3"    : "/open/killer/obj/k_ring",
		"file10"   : "/open/gsword/obj/may_ring",
		"file8"    : "/open/magic-manor/obj/hwa-je-icer",
		"amount5"  : 1,
		"file5"    : "/open/magic-manor/obj/hwa-je-icer",
		"amount4"  : 1,
		"file1"    : "/open/killer/obj/k_ring",
		"amount8"  : 1,
		"file9"    : "/open/mogi/castle/obj/fire-king-head",
		"file2"    : "/open/magic-manor/obj/evil-kill-claw",
		"amount1"  : 1,
		"file7"    : "/open/poison/obj/pearl",
		"amount10" : 1,
		"amount7"  : 1,
		"amount3"  : 1,
		"file6"    : "/open/mon/obj/ghost-claw",
		"amount2"  : 1,
	]) );
	set( "build", 10869 );
	set( "light_up", 1 );
	set( "exits", ([
		"west"      : "/open/clan/sky-wu-chi/room/room226",
	]) );
	set( "long", @LONG
    打開東邊的小櫃子，你可以發現許多漂亮的衣服，有紅的、藍的、
黃的、紫的、還有花樣的衣服，看的你是眼花撩亂，又讚嘆不已。在一
堆炫麗的服裝下面，也有幾件素色的衣服，有白色的洋裝，黑色的晚禮
服，有傳統中國服飾的旗袍，也有開高叉的裙子，還有短短的迷你裙，
看來小佩佩是個愛打扮的小女生。

LONG);
	setup();
	replace_program(ROOM);
}
