inherit ROOM;
void create() {
	set( "short", "$HIC$【$NOR$秘密東西$HIC$】$NOR$小新" );
	set( "owner", "sir" );
	set( "light_up", 1 );
	set( "build", 10144 );
	set( "exits", ([
		"east"      : "/open/clan/sky-wu-chi/room/room24.c",
	]) );
	set( "long", @LONG
這裡是小新在以前到現在的所有戰役中所拿到的寶貴
物品，更顯出小新平常有在收集東西的習慣，只要是難得
一見的東西，更是要放在這，裡面的東西雖然平常是用不
太到，但如果有事的話，相信這裡面的東西一定能派上用
場，因此這裡的重要性更是大大的提升。

LONG);
	setup();
	replace_program(ROOM);
}
