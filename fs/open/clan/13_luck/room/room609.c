inherit ROOM;
void create() {
	set( "short", "武廟" );
	set( "owner", "mill" );
	set( "light_up", 1 );
	set( "exits", ([
		"east"      : "/open/clan/13_luck/room/room617",
	]) );
	set( "long", @LONG
這裡是武廟的正殿，裡面有岳飛像，金盔銀鎧，英氣勃勃。在那岳飛
像上方懸掛岳飛親筆書寫“還我河山”的橫匾。殿兩側壁上嵌著“盡忠報
國”四個斗大的字。武人到此，都放下手中武器，畢恭畢敬地上香禮拜。
旁邊似乎有一道側門。(step)
LONG);
	setup();
	replace_program(ROOM);
}
