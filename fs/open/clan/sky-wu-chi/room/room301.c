inherit ROOM;
void create() {
	set( "short", "血痕居-刀房" );
	set( "owner", "holeman" );
	set( "object", ([
		"amount8"  : 1,
		"file2"    : "/open/capital/obj/4-1",
		"amount1"  : 1,
		"amount10" : 1,
		"amount6"  : 1,
		"file3"    : "/open/capital/obj/4-4",
		"file6"    : "/open/mogi/dragon/obj/scale",
		"amount2"  : 1,
		"amount4"  : 1,
		"file1"    : "/open/capital/obj/4-1",
		"file9"    : "/open/capital/obj/4-2",
		"amount7"  : 1,
		"file7"    : "/open/capital/obj/4-4",
		"amount5"  : 1,
		"file4"    : "/open/capital/obj/4-3",
		"amount3"  : 1,
		"file8"    : "/open/capital/obj/4-2",
		"file10"   : "/open/capital/obj/4-3",
		"amount9"  : 1,
		"file5"    : "/open/mogi/dragon/obj/scale",
	]) );
	set( "build", 11431 );
	set( "light_up", 1 );
	set( "exits", ([
		"west"      : "/open/clan/sky-wu-chi/room/room305",
	]) );
	set( "long", @LONG

    當你要推開房門時，一道耀眼的光芒從門縫中直射出來
，令你不禁好奇裡面到底有什麼東西，進來此房間後，才明
白原來剛才那道光芒是由收藏在這房間裡的刀所散發出來的
，仔細一看這房間裡的刀每把都是世人夢寐以求的寶刀，雖
然心裡很想取走這些寶刀，但這些刀所散發出的霸氣卻令你
望之怯步。

         〔放眼江湖千百刀　唯有妖刀能稱皇〕


LONG);
	setup();
	replace_program(ROOM);
}
