inherit ROOM;
void create() {
	set( "short", "地牢" );
	set( "light_up", 1 );
	set( "build", 10200 );
	set( "owner", "suzukiami" );
	set( "exits", ([
		"up"        : "/open/clan/demon_castle/room/room12",
	]) );
	set( "long", @LONG
這裡是一個地牢
小二用來關抓到的各種奇珍異獸的
在這裡你看到了皮卡丘..波克比...
居然還有可達鴨
另外一頭還有兩隻術碼寶貝
仔細一看居然是鋼鐵加魯魯和戰鬥暴龍獸門口有一隻守門人
它只會一直說就是這樣的..原來是果然翁
LONG);
	setup();
	replace_program(ROOM);
}
