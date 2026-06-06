// Room: /open/center/room/bank.c

inherit BANK;

void create ()
{
  set ("short", "錢莊");
	set( "build", 24 );
  set ("long", @LONG
這是一間皇家特約錢莊............的分行，自從附近馬賊
強盜危害人間後，這兒已經沒人敢來掌櫃了，不過中央驛站多的
是不怕死的小子，這兒一年到頭二十四小時無休的經營。
    右邊牆角貼著一張說明書(sign)。
LONG);

set("item_desc",([
  "sign" : "這裡是錢莊﹐目前我們提供的服務有﹕

balance		查錢莊有多少存款
withdraw	領取存在錢莊的錢
deposit		把錢存進錢莊
convert    	兌換錢幣。

balance
withdraw <數量> <種類>
deposit <數量> <種類> || deposit all
convert <數量> <貨幣> to <貨幣>

範例:       convert 10 silver to coin

錢幣種類有  1 gold == 100 silver == 10000 coin

",
]));

  set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"road4",
  "enter" : __DIR__"auroom",
]));

  set("objects", ([
      "/open/gsword/mob/officer" : 1,
     ]) );
  set("light_up", 1);

  setup();
}
