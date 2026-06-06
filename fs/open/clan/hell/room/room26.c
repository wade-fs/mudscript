inherit ROOM;
void create() {
	set( "short", "地獄的審判" );
	set( "long", @LONG
這是住在地府的冤魂在犯錯的時候需要接受審問的地方,也是俗仔
地獄的俗仔凱林最常來的地方,他每天幾乎都會因為做了不同的蠢
事而被關到這來,如果你在這裡遇到他的話,勸你不要問他為何又被
關,畢竟人的腦細胞不是無限的,聽太多蠢事也是會死光

LONG);
	setup();
	replace_program(ROOM);
}
