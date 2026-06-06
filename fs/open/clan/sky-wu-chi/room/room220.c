inherit ROOM;
void create() {
	set( "short", "幽幻小築" );
	set( "owner", "panhermes" );
	set( "object", ([
		"amount7"  : 1,
		"file4"    : "/open/wind-rain/obj/sun_red_cloth",
		"file1"    : "/open/wu/npc/obj/armband",
		"file7"    : "/open/sky/obj/lucky_grasslink",
		"file2"    : "/open/gsword/obj/may_ring",
		"file3"    : "/open/tendo/obj/chaosbelt",
		"amount1"  : 1,
		"amount4"  : 1,
		"amount8"  : 1,
		"file8"    : "/daemon/class/blademan/obj/shield",
		"amount3"  : 1,
		"amount6"  : 1,
		"file6"    : "/open/mogi/castle/obj/lochagem",
		"amount2"  : 1,
	]) );
	set( "build", 10054 );
	set( "light_up", 1 );
	set( "exits", ([
		"west"      : "/open/clan/sky-wu-chi/room/room219",
	]) );
	set( "long", @LONG
你的靈魂飄飄蕩蕩的飄浮了許久，等你醒來卻發現自己毫髮無傷
是迴廊未寒的屍骨所殘留的痛苦的回憶?你定眼一看，你下意識
的走出了迴廊，來到了一座典雅的小屋，四周的楓林伴著那不搭
調的殺氣，當你想在往前時，四周捲起了一陣旋風，凜冽的殺氣，
環繞在你的四周，多踏一步，似乎就要了你的性命，你----還敢
向前嗎??
LONG);
	setup();
	replace_program(ROOM);
}
