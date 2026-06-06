inherit ROOM;
void create() {
	set( "short", "一頁書西廂房" );
	set( "owner", "hild" );
	set( "exits", ([
		"south"     : "/open/clan/sky-wu-chi/room/room274",
		"east"      : "/open/clan/sky-wu-chi/room/room277",
		"chome"     : "/open/clan/sky-wu-chi/room/hall.c",
		"north"     : "/open/clan/sky-wu-chi/room/room275",
	]) );
	set( "light_up", 1 );
	set( "long", @LONG
    
▁▃                 ◢◣    ◢  ◢◣
 ▅ ◢     *       ◤          ●    ◥
    █◣                         ◤    
 *  ◥█◤    *                  ◤    
       ▁▂▄▂        ●        ●    
        ▆▆▄              ο         
                   ◣                ◢ 
                     ▇▆▅▅▅▅▆▇◥ 
                           ◤▔▔ ＊        ﹏  ﹏
                  ▍▔▔▔▔  ＊     ◢
                  ▍ ＊           ◢    ﹏   ﹏
                  ▍  ＊  ▃▄▅██                         
                  ▍ ▃▅█ █*█ █
                         █ █*█ █          ﹏   ﹏
                      ▂▃▅▄▆▄▂▄
LONG);
	setup();
	replace_program(ROOM);
}
