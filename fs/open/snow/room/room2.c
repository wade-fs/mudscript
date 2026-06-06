#include <room.h>
#include <ansi.h>
#include "/open/open.h"
inherit ROOM;

void create()
{
  set("short","雪蒼紫雲寶殿");
  set( "build", 42 );
  set("valid_startroom", 1);
  set ("long", @LONG
這裡是雪蒼派的聖地『紫雲寶殿』，寶殿裡裝飾著無數的珍寶，
雕像顯得華麗非凡，是雪蒼派弟子聚會時，或有貴客來臨時候的一個
重要場所，在寶殿的左方柱子有一個石牌(stone) ，左邊則是一塊木
板，上面刻有雪蒼弟子的排行，可用list來看排行。
LONG);
  set("item_desc",([
    "stone" : "
            雪蒼武學(snow-martial)  help snow-martial
            雪蒼心法(snowforce) help snowforce
            雪蒼護身寒勁(snow-kee) help snow-kee
          \n"]));
  set("exits",([
    "up":__DIR__"eqroom",
    "south":__DIR__"room5_out",
    "north":__DIR__"room6",
    "east":__DIR__"room10",
    "west":__DIR__"room18",
    ]) );
  set("objects",([
    "/daemon/class/fighter/master_liu":1,
    ]));
  set("light_up",1);
  setup();
  call_other("obj/board/fighter_b.c","???");
}

 int valid_leave(object me, string dir)
{
  if( dir=="up" )
    if( me->query("family/family_name")!="雪蒼派")
      return notify_fail("只有雪蒼弟子才可以進入。\n");
  return ::valid_leave(me,dir);
}

void init()
{
  add_action("do_billing","list");
}

int do_billing(string str)
{
  object *user,me,master;
  int i,j;
  switch(str) {
    case "combat_exp" : i = 0; break;
    case "force" : i = 1; break;
    case "master" : i = 2; break;
    default: return notify_fail("使用格式: list <種類>\n"
                                "經驗值(combat_exp)\n"+
                                "內力(force)\n"+
                                "師承(master)\n\n");
  }
  user = users();
  me = this_player();
  user = filter_array(user,"filter_family",this_object());
  j=sizeof(user);
  switch(i) {
    case 0 : user=sort_array(user,"sort_exp",this_object());
             str=sprintf(HIG"雪蒼派經驗值排行榜:\n\n"NOR);
             for(i=0; i<j; i++)
             str+=sprintf(HIC"第%2d名 %30s(%s)\n"NOR,i+1,user[i]->query("name"),user[i]->query("id"));
             str+="\n";
             tell_object(this_player(),str);
             break;
    case 1 : user=sort_array(user,"sort_force",this_object());
             str=sprintf(HIG"雪蒼派內力排行榜:\n\n"NOR);
             for(i=0; i<j; i++)
             str+=sprintf(HIC"第%2d名 %30s(%s)\n"NOR,i+1,user[i]->query("name"),user[i]->query("id"));
             str+="\n";
             tell_object(this_player(),str);
             break;
    case 2 : str=sprintf(HIG"雪蒼派師徒關係:\n\n"NOR);
             for(i=0; i<j; i++) {
               if( user[i]->query("family/master_is_ppl") ) {
                 if( master=find_player(user[i]->query("family/master_id"))) {
                   if( master->query("name") != user[i]->query("family/master_name"))
                     user[i]->set("family/master_name",master->query("name"));
                 }
                 else {
                   if( master=FINGER_D->acquire_login_ob(user[i]->query("family/master_id"))) {
                     if( master->query("name") != user[i]->query("family/master_name"))
                       user[i]->set("family/master_name",master->query("name"));
                     destruct(master);
                   }
                 }
               }
             str+=sprintf(HIC"%|20s(%|10s)     師承  %|20s(%|10s)\n"NOR,user[i]->query("name"),user[i]->query("id"),user[i]->query("family/master_name"),user[i]->query("family/master_id"));
             }
             str+="\n";
             tell_object(this_player(),str);
             break;
        }
  return 1;
}

int filter_family(object family)
{
  if(family->query("family/family_name") == "雪蒼派" && !wizardp(family)) return 1;
  return 0; 
}

int sort_exp(object man1, object man2)
{
  int i,j;
  i = man1->query("combat_exp");
  j = man2->query("combat_exp");
  if (i>j) return -1;
  else if (i<j) return 1;
  else return 0;
}

int sort_force(object man1, object man2)
{
  int i,j;
  i = man1->query("max_force");
  j = man2->query("max_force");
  if (i>j) return -1;
  else if (i<j) return 1;
  else return 0;
}
