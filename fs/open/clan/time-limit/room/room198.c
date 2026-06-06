inherit ROOM;
void create() {
	set( "short", "$HIG$翠$HIM$環$HIC$山$NOR$" );
	set( "build", 10647 );
	set( "exits", ([
		"west"      : "/open/clan/time-limit/room/room245",
		"south"     : "/open/clan/time-limit/room/room199.c",
		"east"      : "/open/clan/time-limit/room/room249.c",
		"north"     : "/open/clan/time-limit/room/room250.c",
	]) );
	set( "long", @LONG
翠環山是清香白蓮素還真的住所之一,雄偉的拱門加上長長的石階筆直地通往山上,
石階旁有著珠簾,襯托出主人的貴氣,走到山上赫然看見五個以蓮花花瓣建成的高台,
這是素還真修練的場所,後方的玉波池具有神聖的力量,可以消除一切的邪惡,一根樹
枝掉落在池面上,引起陣陣的漣漪

LONG);
	setup();
	replace_program(ROOM);
}
