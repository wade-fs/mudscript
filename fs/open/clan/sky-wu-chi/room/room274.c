inherit ROOM;
void create() {
	set( "short", "一頁書南廂房" );
	set( "owner", "hild" );
	set( "outdoors", "/open/clan/sky-wu-chi" );
	set( "light_up", 1 );
	set( "exits", ([
		"east"      : "/open/clan/sky-wu-chi/room/room277",
		"west"      : "/open/clan/sky-wu-chi/room/room276",
		"north"     : "/open/clan/sky-wu-chi/room/room275",
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
