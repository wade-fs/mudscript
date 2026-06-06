inherit ROOM;
void create() {
	set( "short", "$HIB$葬刀塚$NOR$" );
	set( "owner", "hild" );
	set( "build", 10040 );
	set( "light_up", 1 );
	set( "exits", ([
		"north"     : "/open/clan/sky-wu-chi/room/room90.c",
		"down"      : "/open/clan/sky-wu-chi/room/room49",
		"east"      : "/open/clan/sky-wu-chi/room/room80.c",
		"chome"     : "/open/clan/sky-wu-chi/room/hall.c",
	]) );
	set( "long", @LONG
當你來到這裡，一股涼意直撲你而來，你看了看四周，原來這裡是
傳說中葬刀的地方。傳說中妖刀有三把，目前現世的為其一，妖刀村雨
。其擁有者必須有極大的功力及血腥氣息，否則會被其刀所吞噬原來的
本性，剩下的兩把未現世，據長老所說，未現世之兩把妖刀比妖刀村雨
威力更為強大，但終究是一個未解的傳說‧‧‧
LONG);
	setup();
	replace_program(ROOM);
}
