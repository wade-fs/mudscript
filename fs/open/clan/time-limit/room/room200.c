inherit ROOM;
void create() {
	set( "short", "$HIG$天$HIY$地$HIB$門$NOR$" );
	set( "build", 10861 );
	set( "exits", ([
		"west"      : "/open/clan/time-limit/room/room199",
		"out"       : "/open/clan/time-limit/room/room20.c",
		"south"     : "/open/clan/time-limit/room/room257",
		"east"      : "/open/clan/time-limit/room/room164.c",
		"north"     : "/open/clan/time-limit/room/room201.c",
	]) );
	set( "long", @LONG
天地門是武林中最為神秘的地方,傳說是通往異世界的入口,曾經有人進到天地門後
就再也沒有出現過了,而天地門也是龍腦-青陽子的發源地,青陽子原本是合修會的創
辦人,曾經是一方霸主,和素還真及非凡公子鬥志鬥力過,之後與素還真結拜為兄弟後
,便常與素還真聯手對付其他勢力

LONG);
	setup();
	replace_program(ROOM);
}
