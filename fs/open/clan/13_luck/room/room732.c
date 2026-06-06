inherit ROOM;
void create() {
	set( "short", "北極屋" );
	set( "owner", "amdxp" );
	set( "light_up", 1 );
	set( "exits", ([
		"west"      : "/open/clan/13_luck/room/room342",
	]) );
	set( "long", @LONG

    沁芳澆鶴，流雲於上，只見許多異草，或有牽藤的，或有引蔓的，
或穿石腳或依相彼，甚至垂簷繞柱，縈砌珠萃。樺杏雜掩，遮天敝
日，淒沚之水涓涓潺潺攀藤撫樹穿花度葉而過。上則蘿薜倒掛，下
則落華浮蕩，如入武陵桃花，紅塵不染。

LONG);
	setup();
	replace_program(ROOM);
}
