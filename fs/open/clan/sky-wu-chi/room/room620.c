inherit ROOM;
void create() {
	set( "short", "邪武冰燄穴" );
	set( "build", 1314 );
	set( "exits", ([
		"chome"     : "/open/clan/sky-wu-chi/room/hall",
	]) );
	set( "long", @LONG
一踏入此穴，突然感受到一股莫名的寒氣由穴內向穴外襲來，
穴壁上佈滿了許多的拳、腳、掌印，這些印記發出閃爍的光芒，如同星芒一般，
另你不自覺的伸出手去接觸它，一觸之下發覺寒氣竟是由此些印記散發出來，瞬間手
上凝結了一層霜，在你驚訝之餘，穴中突然閃出數句詩詞：
『邪皇絕學藏、武藝壁中留、冰燄真氣存、燄流如神丹』
手上霜氣轉眼間化成一股真氣往你體內流竄，當你驚訝之餘，本身內功修為登時增長
了一百多年。
LONG);
	setup();
	replace_program(ROOM);
}
