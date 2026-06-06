inherit ROOM;
void create() {
	set( "short", "小廖休息房" );
	set( "owner", "poll" );
	set( "object", ([
		"file3"    : "/open/port/obj/wolf_ring",
		"amount5"  : 1,
		"file10"   : "/open/gsword/obj/yugem",
		"amount9"  : 1,
		"file6"    : "/open/capital/obj/force_book",
		"file8"    : "/open/quests/snake/npc/obj/snake_gem",
		"amount3"  : 1,
		"file4"    : "/open/gsword/obj/ring-1",
		"file2"    : "/open/capital/obj/book",
		"file7"    : "/open/ping/obj/ring-2",
		"amount6"  : 1,
		"amount8"  : 1,
		"amount4"  : 1,
		"amount2"  : 1,
		"file1"    : "/open/killer/memory/static",
		"file5"    : "/open/gsword/obj/yugem",
		"amount7"  : 1,
		"amount10" : 1,
		"amount1"  : 1,
		"file9"    : "/open/port/obj/wolf_ring",
	]) );
	set( "build", 10434 );
	set( "light_up", 1 );
	set( "exits", ([
		"up"        : "/open/clan/13_luck/room/room474.c",
		"out"       : "/open/clan/13_luck/room/room89.c",
		"west"      : "/open/clan/13_luck/room/room78.c",
		"down"      : "/open/clan/13_luck/room/room618.c",
	]) );
	set( "long", @LONG
$HIW$這裡是一間寬敞舒適的休息室，一張圓桌上正擺著剛沏好的茶，
和煦的陽光從窗口映射到地板上，看這多麼舒適的環境，尤其中間有
一張大床，看了就讓人忍不住想上去躺一躺，陣陣茶香味正溢滿四周
，的確是一間相當適合給忙碌一整天的廖官人休息的房間。$NOR$
LONG);
	setup();
	replace_program(ROOM);
}
