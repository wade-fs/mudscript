inherit ROOM;
void create() {
	set( "short", "空瓶子招待所3" );
	set( "owner", "ywarter" );
	set( "object", ([
		"file3"    : "/open/firedancer/npc/eq/r_hands",
		"amount3"  : 1,
		"amount1"  : 1,
		"file1"    : "/open/firedancer/npc/eq/r_boots",
		"file2"    : "/open/firedancer/npc/eq/r_pants",
		"amount2"  : 1,
	]) );
	set( "build", 10248 );
	set( "light_up", 1 );
	set( "exits", ([
		"east"      : "/open/clan/sky-wu-chi/room/room333",
		"out"       : "/open/clan/sky-wu-chi/room/room234",
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
