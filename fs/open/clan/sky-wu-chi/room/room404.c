inherit ROOM;
void create() {
	set( "short", "白虎上將軍府" );
	set( "owner", "poiiiiop" );
	set( "build", 10254 );
	set( "exits", ([
		"east"      : "/open/clan/sky-wu-chi/room/room407",
	]) );
	set( "long", @LONG
拂天光 照汗青 一步人生終不悔 石中火 夢中身 羽扇逍遙任風流
        風拂急雲撥銀河 日月天光照汗青

        麗人湖畔麗人遊，風流公子幾多愁。
        垂柳依依拂荒塚，舊時親友夢難留。
        三杯兩盞冰冷酒，天人相隔語不求。
        風簷丹心十二月，莫教衰蘭逐水流。

謹慎冷靜、善於以極小兵力獲取最大勝利
被稱為『林之狐狸』的白虎上將軍 - 悅蘭芳
LONG);
	setup();
	replace_program(ROOM);
}
