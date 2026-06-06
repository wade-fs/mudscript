inherit ROOM;
void create() {
	set( "short", "$HIC$快意樓$NOR$" );
	set( "owner", "cong" );
	set( "build", 10050 );
	set( "light_up", 1 );
	set( "exits", ([
		"up"        : "/open/clan/sky-wu-chi/room/room161.c",
		"south"     : "/open/clan/sky-wu-chi/room/room21.c",
	]) );
	set( "long", @LONG
$HIC$
              喜  是  俗  得
              怒  非  世  求
              哀  黑  紅  逍
              樂  白  塵  遙
              但  盡  任  樂
              憑  隨  我  無
              心  意  行  憂$NOR$
                              $HIM$by borbear$NOR$


LONG);
	setup();
	replace_program(ROOM);
}
