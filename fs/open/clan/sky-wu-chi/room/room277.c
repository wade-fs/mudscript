inherit ROOM;
void create() {
	set( "short", "一頁書東廂房" );
	set( "owner", "hild" );
	set( "exits", ([
		"south"     : "/open/clan/sky-wu-chi/room/room274",
		"chome"     : "/open/clan/sky-wu-chi/room/hall",
		"north"     : "/open/clan/sky-wu-chi/room/room275",
		"west"      : "/open/clan/sky-wu-chi/room/room276.c",
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
