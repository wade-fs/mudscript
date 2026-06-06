inherit ROOM;
void create() {
	set( "short", "血痕居-眾合地獄" );
	set( "owner", "holeman" );
	set( "build", 10169 );
	set( "exits", ([
		"west"      : "/open/clan/sky-wu-chi/room/room528.c",
		"north"     : "/open/clan/sky-wu-chi/room/room534.c",
		"south"     : "/open/clan/sky-wu-chi/room/room536",
	]) );
	set( "long", @LONG

    眾合地獄中有一個像山那樣大的鐵臼，這個地獄的眾生都在這
個大鐵臼中。閻羅的獄卒用如須彌山一樣大的鐵鎚敲打鐵臼裏的眾
鐵鎚打下去時，他們就會粉身碎骨。除此之外，旁邊還有高山峽谷
，山谷中有無數眾生，當高山相互撞擊時，他們全部死亡；當高山
分開時，又全部復活。這種前後夾合受痛苦的地方，就是眾合地獄
。

    這個地獄眾生的壽命是：人間兩百年是夜摩天的一天，夜摩天
的兩千年是眾合地獄的一天，他們要在這裡受苦兩千年。


LONG);
	setup();
	replace_program(ROOM);
}
