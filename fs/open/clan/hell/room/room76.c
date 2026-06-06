inherit ROOM;
void create() {
	set( "short", "$BLU$地道入口$NOR$" );
	set( "owner", "blur" );
	set( "light_up", 1 );
	set( "build", 1102 );
	set( "exits", ([
		"out"       : "/open/clan/hell/room/room29.c",
		"down"      : "/open/clan/hell/room/room87",
		"east"      : "/open/clan/hell/room/room77",
		"north"     : "/open/clan/hell/room/room75.c",
		"west"      : "/open/clan/hell/room/room78.c",
	]) );
	set( "long", @LONG
咻的一聲，在你不小心觸碰到了外面房間的機關後
不知不覺中飛來到了這裡，在這裡，看起來陰暗無比，
似忽是在關禁犯人的地方，在你來到這後，便開始向裡
面做進一步的蒐尋。不知是否有誰在這個地方。或著是
這裡是否藏有什麼不可告人的秘密。

LONG);
	setup();
	replace_program(ROOM);
}
