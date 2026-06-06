inherit ROOM;
void create() {
	set( "short", "土地廟" );
	set( "owner", "mill" );
	set( "build", 10001 );
	set( "light_up", 1 );
	set( "exits", ([
		"east"      : "/open/clan/13_luck/room/room488",
	]) );
	set( "long", @LONG

    這是一間十分老舊的土地廟﹐沒有人知道是何時或是誰在此興建的
﹐也許是為了在這個殺戮的土地上﹐祭嗣那些戰死的幽魂﹐另外﹐這裡
也是不歸路唯一安全的地方﹐許多旅者都會在這裡過夜。但在夜裡荒涼
的樹林裡常會出現不尋常的聲音.

LONG);
	setup();
	replace_program(ROOM);
}
