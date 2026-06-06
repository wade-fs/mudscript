inherit ROOM;
void create() {
	set( "short", "天樞堂大廳" );
	set( "build", 10086 );
	set( "owner", "fireer" );
	set( "light_up", 1 );
	set( "exits", ([
		"out"       : "/open/clan/13_luck/room/room518.c",
		"north"     : "/open/clan/13_luck/room/room507",
	]) );
	set( "long", @LONG
你冒著必死的決心來到了天樞堂，你看到廳內有數個人影，一個坐
在廳內的大椅上，其他人則是站在一旁，你提神一看，坐在椅子上的是
他們的頭頭常默衣，其他那些人分別是神祕劍客、一字劍、雙龍背、三
霜刃、六分刀、秋聲飛羽、三無命，看來天樞堂的重要人物都到齊了，
於是你自己靜靜的離開了此地，不想生命就此結束了。
LONG);
	setup();
	replace_program(ROOM);
}
