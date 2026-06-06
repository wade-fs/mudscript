inherit ROOM;
void create() {
	set( "short", "空瓶子招待所5" );
	set( "owner", "ywarter" );
	set( "build", 10044 );
	set( "light_up", 1 );
	set( "exits", ([
		"north"     : "/open/clan/sky-wu-chi/room/room335",
		"east"      : "/open/clan/sky-wu-chi/room/hall",
		"west"      : "/open/clan/sky-wu-chi/room/hall",
		"south"     : "/open/clan/sky-wu-chi/room/hall.c",
	]) );
	set( "long", @LONG
這裡是屬於要談機密的地方,而四周看起來就像是一個練武場
原來是空瓶子喜歡以武會友,順便說三道四的,所以一些高階的
朋友都在這邊談論事情,但是呢,為了必免有人偷聽,所以空瓶子
就想出一個妙計,使用了八成功力在這裡做一個防護結界
任何人在這裡面只能用say 而傳不出去聲音..
也許是因為有太多秘密的關係了...
LONG);
	setup();
	replace_program(ROOM);
}
