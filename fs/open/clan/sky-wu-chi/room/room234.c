inherit ROOM;
void create() {
	set( "short", "空瓶子招待所2" );
	set( "owner", "ywarter" );
	set( "object", ([
		"amount2"  : 1,
		"file4"    : "/open/ping/obj/ring-2",
		"file1"    : "/open/dancer/obj/yuawaist",
		"amount1"  : 1,
		"file3"    : "/open/killer/weapon/k_torch",
		"amount4"  : 1,
		"file2"    : "/daemon/class/fighter/armband",
		"amount3"  : 1,
	]) );
	set( "build", 10038 );
	set( "light_up", 1 );
	set( "exits", ([
		"west"      : "/open/clan/sky-wu-chi/room/room157.c",
		"enter"     : "/open/clan/sky-wu-chi/room/room332.c",
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
