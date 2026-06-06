inherit ROOM;
void create() {
	set( "short", "$HIB$【$HIC$聖  石  碑$HIB$】$NOR$" );
	set( "build", 852 );
	set( "light_up", 1 );
	set( "exits", ([
		"E"         : "/open/clan/sky-wu-chi/room/room29.c",
		"Z"         : "/open/clan/sky-wu-chi/room/room71.c",
		"W"         : "/open/clan/sky-wu-chi/room/room63.c",
		"X"         : "/open/clan/sky-wu-chi/room/room62.c",
		"V"         : "/open/clan/sky-wu-chi/room/room64.c",
		"T"         : "/open/clan/sky-wu-chi/room/room68.c",
		"N"         : "/open/clan/sky-wu-chi/room/room47.c",
		"I"         : "/open/clan/sky-wu-chi/room/room92.c",
		"B"         : "/open/clan/sky-wu-chi/room/room19.c",
		"Q"         : "/open/clan/sky-wu-chi/room/room48.c",
		"chome"     : "/open/clan/sky-wu-chi/room/hall",
		"O"         : "/open/clan/sky-wu-chi/room/room93.c",
		"L"         : "/open/clan/sky-wu-chi/room/room55.c",
		"K"         : "/open/clan/sky-wu-chi/room/room57.c",
		"G"         : "/open/clan/sky-wu-chi/room/room28.c",
		" + U + "         : "/open/clan/sky-wu-chi/room/room65.c",
		"S"         : "/open/clan/sky-wu-chi/room/room36.c",
		"A"         : "/open/clan/sky-wu-chi/room/room13.c",
		"H"         : "/open/clan/sky-wu-chi/room/room26.c",
		"Y"         : "/open/clan/sky-wu-chi/room/room60.c",
		"F"         : "/open/clan/sky-wu-chi/room/room34.c",
		"J"         : "/open/clan/sky-wu-chi/room/room58.c",
		"C"         : "/open/clan/sky-wu-chi/room/room35.c",
		"D"         : "/open/clan/sky-wu-chi/room/room91.c",
		"P"         : "/open/clan/sky-wu-chi/room/room43.c",
		"M"         : "/open/clan/sky-wu-chi/room/room51.c",
		"R"         : "/open/clan/sky-wu-chi/room/room37.c",
	]) );
	set( "long", @LONG
相傳,上古時代,因為天上的作亂人間,導致民不聊生,兵荒馬亂,
這時有二十六位古聖者為了抵抗天神的作弄,奮而群起抵抗,在
一位擁有妖刀的邪燕領導下,跟諸位天神大戰,但還是不敵天上
的諸神這時眾古聖者決定~~以犧牲自我,還換取狂想空間的和平,
在二十六道飛過天際時,天上眾神被重創了...但古聖者也因放出
畢生的功力使他們化為灰燼...在邪燕的傳人<刀神燕仔>的奔走下
終於收集到了二十六位古聖者的遺骸....並且用畢生所學,化成了
二十六顆傳送石...只要你誠心呼喚聖者之名...你便可以傳送到
聖者幻界去了....                                欣
LONG);
	setup();
	replace_program(ROOM);
}
