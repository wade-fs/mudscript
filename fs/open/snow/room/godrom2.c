// Room: /open/snow/room/godrom2.c
// 天靈谷
#include <room.h>
#include <ansi.h>
inherit ROOM;
void create()
{
 set("short",HIM + "天靈谷" + NOR);
 set("long", @LONG
你進到天靈谷的深處,眼前的影像讓你吃了一驚，只見前方平台上發出
了數道不同顏色的光線，在光線的四周有無數的氣流在流動!!實在是非
常驚人。
LONG
        );
 set("no_transmit",1);
 set("no_auc",1);
 set("exits", ([
     "out": "/open/snow/room/water",
     "south":__DIR__"godrom1",]) );
 setup();
}
void init()
{
  add_action("do_stand","stand");
}
int do_stand(string str)
{
  object ob,ob1;
  ob=this_player();
  if( str!="平台")
    return notify_fail("你要站在那裏去呀!!!\n");
  message_vision(HIW + "$N一口氣躍入平台上，此時$N沐浴在光線之中感覺十分舒服!!\n" + NOR,ob);
  message_vision(HIY + "只見$N體內的" + HIB + "青龍之氣" + HIY + "幻化成青龍向天飛去了。\n" + NOR,ob);
  message_vision(HIM + "忽然平台旁的無數氣流，被$N吸入體內了，此時$N發出數十道光茫\n" + NOR,ob);
  message_vision(HIW + "$N得到仙雲之氣了.....(請打Help god_kee及sec_god看說明)\n" + NOR,ob);
  ob->set("sec_kee","god");
  ob->set("max_s_kee",1);
  ob->set("s_kee",0);
    ob->set("quests/sec_god",1);
}

