inherit ROOM;
void create() {
	set( "short", "磐天巨木" );
	set( "owner", "shinny" );
	set( "exits", ([
		"south"     : "/open/clan/13_luck/room/room655",
	]) );
	set( "long", @LONG
        ◢◤        ◢◣        ◥◣  你經過一番搜查，發現在古木綠蔭後果
          ◢◤        ◢◤◥◣        ◥◣然別有洞天，沒想到在一片綠蔭之中既
        ◢◤                            ◥◣
        █████    ████    █████  然暗藏著此字神秘地點，此地為盤古
      ◢◤    ◥◣  ◢◤    ◥◣  ◢◤    ◥◣   天之時墬落之隕石衝擊地面直衝地
    ◢◤        ◥█◤        ◥█◤        ◥◣心，不知是否為天意墬落之處。

LONG);
	setup();
	replace_program(ROOM);
}
