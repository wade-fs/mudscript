inherit ROOM;
void create() {
	set( "short", "$HIC$死靈骨魔爪牙$NOR$" );
	set( "light_up", 1 );
	set( "build", 11965 );
	set( "exits", ([
		"east"      : "/open/clan/ou-cloud-club/room/room357.c",
		"out"       : "/open/clan/ou-cloud-club/room/room162.c",
		"west"      : "/open/clan/ou-cloud-club/room/room365.c",
		"south"     : "/open/clan/ou-cloud-club/room/room362.c",
		"up"        : "/open/clan/ou-cloud-club/room/room380",
		"north"     : "/open/clan/ou-cloud-club/room/room363.c",
	]) );
	set( "long", @LONG
        ～～$BLU$死靈幽谷傳來一陣淒涼的哀嚎聲$NOR$～～

$HIR$焚天魔王大怒：該死的$HIG$波$HIR$～～竟然打敗我的結拜好兄弟幽冥骨魔！！
          看來我應該到人間界跟波討回這筆帳！！
              
              眾魔將們聽命～！！遠征人間界的時間到了！！$NOR$

LONG);
	setup();
	replace_program(ROOM);
}
