inherit ROOM;
void create() {
	set( "short", "$HIB$猜$HIG$心$HIC$園$NOR$" );
	set( "exits", ([
		"west"      : "/open/clan/time-limit/room/room164",
	]) );
	set( "long", @LONG
猜心園是非凡公子的住所,一踏入這裡便有一股花香撲鼻而來,四周種滿花草,而且多是外
來種,看得你驚呼連連,前方有一座涼亭,是非凡公子招待貴賓之處,上頭掛著一個鳥籠,裡
頭的鳥兒又跳又叫的,十分惹人疼愛,到處充滿鳥語花香,仿佛是人間仙境,但是非凡公子
胸懷大志,恐怕爭戰將起,此地也將變成是非之地

LONG);
	setup();
	replace_program(ROOM);
}
