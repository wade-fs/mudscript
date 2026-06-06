// Room: /u/s/sueplan/newplan/area/room1
inherit ROOM;

void create ()
{
  set ("short", "紫薇星");
  set ("long", @LONG
伯邑所住的『紫色的薔薇園』，稱為『絮薇星』。以這紫薇星為主，
推算人的命連，這方法  叫做紫薇斗數或紫薇推命數。 
        紫薇星在推命數中掌管『尊貴』，合意為善良高貴。
    回到周郡落文王，誓天復仇，努力養馬練兵。但是怕的努力尚未達
到目的，他的病死。伯邑的弟弟繼承父王的遺志，立為武王，提倡農耕
，訓練兵士，富國途強，並且得到一個偉大的軍師姜尚，而打敗殷軍，
減亡殷商。武王所以能夠打倒紂王，稱霸天下，建立周朝，可以說完全
得力於大軍師姜尚。       
LONG);

  set("no_transmit", 1);
  set("light_up", 1);
  set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"room2.c",
]));

  setup();
}
