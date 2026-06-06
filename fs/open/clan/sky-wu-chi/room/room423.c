inherit ROOM;
void create() {
	set( "short", "$HIW$當舖$HIR$ソ$HIC$大廳$NOR$" );
	set( "owner", "yuki" );
	set( "light_up", 1 );
	set( "build", 10003 );
	set( "exits", ([
		"west"      : "/open/clan/sky-wu-chi/room/room192.c",
		"north"     : "/open/clan/sky-wu-chi/room/room10",
		"east"      : "/open/clan/sky-wu-chi/room/room422.c",
	]) );
	set( "long", @LONG
你踏進了第八號當舖在你眼出現了當舖的主人”韓諾”他就是當舖的主人，　
也就是剛剛向你的內心發出呼喊的人，他坐在一張古董的太師椅上，前面
擺了一張紫檀金漆的桌子，上面放了一個血玉筆架掛滿了昂貴的毛筆，
他突然對著你笑，跟你說你歡迎來到第八號當舖，你需要什麼樣的願望我將
努力為你達成，但是你必須付出因有的典當物才可以！你不禁思考著你的
願望，和你所能付出的典當物！
LONG);
	setup();
	replace_program(ROOM);
}
