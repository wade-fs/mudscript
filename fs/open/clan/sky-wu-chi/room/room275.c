inherit ROOM;
void create() {
	set( "short", "一頁書北廂房" );
	set( "owner", "hild" );
	set( "light_up", 1 );
	set( "exits", ([
		"south"     : "/open/clan/sky-wu-chi/room/room273.c",
		"east"      : "/open/clan/sky-wu-chi/room/room277",
		"west"      : "/open/clan/sky-wu-chi/room/room276",
		"chome"     : "/open/clan/sky-wu-chi/room/hall",
	]) );
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
