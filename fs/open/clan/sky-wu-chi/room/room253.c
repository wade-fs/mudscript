inherit ROOM;
void create() {
	set( "short", "西亞神殿" );
	set( "owner", "intel" );
	set( "build", 17142 );
	set( "light_up", 1 );
	set( "exits", ([
		"west"      : "/open/clan/sky-wu-chi/room/room240",
	]) );
	set( "long", @LONG
所謂 多謀者勝,少謀者敗 ,此乃千古不變之真理
一個有勇無謀的莽夫是沒有辦法有所作為的
就如同萬夫莫敵的項羽最後也是要在烏江自刎
神蝶記取前人的教訓,經過幾番思量之後
建立這個神殿,招兵買馬,自己則隱藏於幕後,暗中操縱
LONG);
	setup();
	replace_program(ROOM);
}
