inherit ROOM;
void create() {
	set( "short", "咽喉" );
	set( "light_up", 1 );
	set( "owner", "saintberii" );
	set( "build", 675 );
	set( "exits", ([
		"south"     : "/open/clan/sky-wu-chi/room/room511",
	]) );
	set( "long", @LONG

這裡是人的咽喉，頭部有許多的管道都連接到這個地方。
咽喉的上方連接到鼻腔，下方是食道，左上和右上方分別
是左右耳咽管。在你的深後有個好大的肉球懸掛在那邊，
每當這個人類吞嚥口水的時候，這個大肉球更是一晃一晃
的，好噁心唷~~

LONG);
	setup();
	replace_program(ROOM);
}
