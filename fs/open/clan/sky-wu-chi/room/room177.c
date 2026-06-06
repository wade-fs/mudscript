inherit ROOM;
void create() {
        set( "short", "碎石小路91" );
	set( "build", 29 );
	set( "outdoors", "/open/clan/sky-wu-chi" );
	set( "light_up", 1 );
        set( "exits", ([
		"south"     : "/open/clan/sky-wu-chi/room/room14",
		"north"     : "/open/clan/sky-wu-chi/room/hall.c",
		"west"      : "/open/clan/sky-wu-chi/room/room178.c",
        ]) );
        set( "long", @LONG
北方是眾所皆知的天極殿，西方則是雄偉豪放的鎮
天西門，往天極殿的路程雖不長，但卻也是一個鳥鳴常
叫的美好地方。路旁的樹叢有著許許多多的可愛動物，
活潑的向你討食物呢！看來並不只有天道無極的幫眾們
喜愛這裡了。


LONG);
        setup();
        replace_program(ROOM);
}

